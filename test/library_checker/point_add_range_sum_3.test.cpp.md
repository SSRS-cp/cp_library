---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/segment_tree.cpp
    title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/point_add_range_sum_3.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/segment_tree.cpp\"\
    \ntemplate <typename T>\nstruct segment_tree{\n  int N;\n  vector<T> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){\n\
    \    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N *\
    \ 2 - 1, E);\n  }\n  segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f),\
    \ E(E){\n    int n = A.size();\n    N = 1;\n    while (N < n){\n      N *= 2;\n\
    \    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i = 0; i < n; i++){\n\
    \      ST[N - 1 + i] = A[i];\n    }\n    for (int i = N - 2; i >= 0; i--){\n \
    \     ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n  }\n  T operator [](int\
    \ k){\n    return ST[N - 1 + k];\n  }\n  void update(int k, T x){\n    k += N\
    \ - 1;\n    ST[k] = x;\n    while (k > 0){\n      k = (k - 1) / 2;\n      ST[k]\
    \ = f(ST[k * 2 + 1], ST[k * 2 + 2]);\n    }\n  }\n  T query(int L, int R, int\
    \ i, int l, int r){\n    if (r <= L || R <= l){\n      return E;\n    } else if\
    \ (L <= l && r <= R){\n      return ST[i];\n    } else {\n      int m = (l + r)\
    \ / 2;\n      return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m,\
    \ r));\n    }\n  }\n  T query(int L, int R){\n    return query(L, R, 0, 0, N);\n\
    \  }\n  T all(){\n    return ST[0];\n  }\n};\n/**\n * @brief Segment Tree (\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n#line 5 \"test/library_checker/point_add_range_sum_3.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  segment_tree<long long> ST(a,\
    \ plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int t;\n    cin\
    \ >> t;\n    if (t == 0){\n      int p, x;\n      cin >> p >> x;\n      a[p] +=\
    \ x;\n      ST.update(p, a[p]);\n    }\n    if (t == 1){\n      int l, r;\n  \
    \    cin >> l >> r;\n      cout << ST.query(l, r) << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/segment_tree.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  segment_tree<long long> ST(a,\
    \ plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int t;\n    cin\
    \ >> t;\n    if (t == 0){\n      int p, x;\n      cin >> p >> x;\n      a[p] +=\
    \ x;\n      ST.update(p, a[p]);\n    }\n    if (t == 1){\n      int l, r;\n  \
    \    cin >> l >> r;\n      cout << ST.query(l, r) << endl;\n    }\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/segment_tree.cpp
  isVerificationFile: true
  path: test/library_checker/point_add_range_sum_3.test.cpp
  requiredBy: []
  timestamp: '2022-07-14 02:11:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/point_add_range_sum_3.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/point_add_range_sum_3.test.cpp
- /verify/test/library_checker/point_add_range_sum_3.test.cpp.html
title: test/library_checker/point_add_range_sum_3.test.cpp
---
