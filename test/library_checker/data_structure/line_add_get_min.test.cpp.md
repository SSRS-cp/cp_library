---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/other/li_chao_tree.hpp
    title: Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nconst long long INF = 3000000000000000000;\n\
    #line 2 \"data_structure/other/li_chao_tree.hpp\"\ntemplate <typename T>\nstruct\
    \ li_chao_tree{\n  struct line{\n    T a, b;\n    line(): a(0), b(INF){\n    }\n\
    \    line(T a, T b): a(a), b(b){\n    }\n    T get(T x){\n      return a * x +\
    \ b;\n    }\n  };\n  int N;\n  vector<T> x;\n  vector<line> ST;\n  li_chao_tree(){\n\
    \  }\n  li_chao_tree(const vector<T> &x2){\n    x = x2;\n    sort(x.begin(), x.end());\n\
    \    int N2 = x.size();\n    N = 1;\n    while (N < N2){\n      N *= 2;\n    }\n\
    \    x.resize(N);\n    for (int i = N2; i < N; i++){\n      x[i] = x[N2 - 1];\n\
    \    }\n    ST = vector<line>(N * 2 - 1);\n  }\n  void line_add(line L, int i,\
    \ int l, int r){\n    T la = L.get(x[l]);\n    T lb = ST[i].get(x[l]);\n    T\
    \ ra = L.get(x[r - 1]);\n    T rb = ST[i].get(x[r - 1]);\n    if (la >= lb &&\
    \ ra >= rb){\n      return;\n    } else if (la <= lb && ra <= rb){\n      ST[i]\
    \ = L;\n    } else {\n      int m = (l + r) / 2;\n      T ma = L.get(x[m]);\n\
    \      T mb = ST[i].get(x[m]);\n      if (ma < mb){\n        swap(L, ST[i]);\n\
    \        swap(la, lb);\n        swap(ra, rb);\n      }\n      if (la < lb){\n\
    \        line_add(L, i * 2 + 1, l, m);\n      }\n      if (ra < rb){\n       \
    \ line_add(L, i * 2 + 2, m, r);\n      }\n    }\n  }\n  void line_add(T a, T b){\n\
    \    line_add(line(a, b), 0, 0, N);\n  }\n  void segment_add(int L, int R, line\
    \ S, int i, int l, int r){\n    if (r <= L || R <= l){\n      return;\n    } else\
    \ if (L <= l && r <= R){\n      line_add(S, i, l, r);\n    } else {\n      int\
    \ m = (l + r) / 2;\n      segment_add(L, R, S, i * 2 + 1, l, m);\n      segment_add(L,\
    \ R, S, i * 2 + 2, m, r);\n    }\n  }\n  void segment_add(T l, T r, T a, T b){\n\
    \    int pl = lower_bound(x.begin(), x.end(), l) - x.begin();\n    int pr = lower_bound(x.begin(),\
    \ x.end(), r) - x.begin();\n    segment_add(pl, pr, line(a, b), 0, 0, N);\n  }\n\
    \  T get(T x2){\n    int p = lower_bound(x.begin(), x.end(), x2) - x.begin();\n\
    \    p += N - 1;\n    T ans = INF;\n    ans = min(ans, ST[p].get(x2));\n    while\
    \ (p > 0){\n      p = (p - 1) / 2;\n      ans = min(ans, ST[p].get(x2));\n   \
    \ }\n    return ans;\n  }\n};\n#line 6 \"test/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N), b(N);\n\
    \  for (int i = 0; i < N; i++){\n    cin >> a[i] >> b[i];\n  }\n  vector<int>\
    \ t(Q);\n  vector<long long> a2(Q), b2(Q);\n  vector<long long> p(Q);\n  for (int\
    \ i = 0; i < Q; i++){\n    cin >> t[i];\n    if (t[i] == 0){\n      cin >> a2[i]\
    \ >> b2[i];\n    }\n    if (t[i] == 1){\n      cin >> p[i];\n    }\n  }\n  vector<long\
    \ long> x;\n  for (int i = 0; i < Q; i++){\n    if (t[i] == 1){\n      x.push_back(p[i]);\n\
    \    }\n  }\n  li_chao_tree<long long> T(x);\n  for (int i = 0; i < N; i++){\n\
    \    T.line_add(a[i], b[i]);\n  }\n  for (int i = 0; i < Q; i++){\n    if (t[i]\
    \ == 0){\n      T.line_add(a2[i], b2[i]);\n    }\n    if (t[i] == 1){\n      cout\
    \ << T.get(p[i]) << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nconst long long INF = 3000000000000000000;\n\
    #include \"../../../data_structure/other/li_chao_tree.hpp\"\nint main(){\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N), b(N);\n  for (int i = 0;\
    \ i < N; i++){\n    cin >> a[i] >> b[i];\n  }\n  vector<int> t(Q);\n  vector<long\
    \ long> a2(Q), b2(Q);\n  vector<long long> p(Q);\n  for (int i = 0; i < Q; i++){\n\
    \    cin >> t[i];\n    if (t[i] == 0){\n      cin >> a2[i] >> b2[i];\n    }\n\
    \    if (t[i] == 1){\n      cin >> p[i];\n    }\n  }\n  vector<long long> x;\n\
    \  for (int i = 0; i < Q; i++){\n    if (t[i] == 1){\n      x.push_back(p[i]);\n\
    \    }\n  }\n  li_chao_tree<long long> T(x);\n  for (int i = 0; i < N; i++){\n\
    \    T.line_add(a[i], b[i]);\n  }\n  for (int i = 0; i < Q; i++){\n    if (t[i]\
    \ == 0){\n      T.line_add(a2[i], b2[i]);\n    }\n    if (t[i] == 1){\n      cout\
    \ << T.get(p[i]) << endl;\n    }\n  }\n}"
  dependsOn:
  - data_structure/other/li_chao_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2022-09-17 03:51:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/line_add_get_min.test.cpp
- /verify/test/library_checker/data_structure/line_add_get_min.test.cpp.html
title: test/library_checker/data_structure/line_add_get_min.test.cpp
---
