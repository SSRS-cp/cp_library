---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/commutative_dual_segment_tree.cpp
    title: "Commutative Dual Segment Tree (\u53EF\u63DB\u53CC\u5BFE\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728\u3001\u3089\u3066\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/aoj/dsl_2_d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/commutative_dual_segment_tree.cpp\"\
    \ntemplate <typename T>\nstruct commutative_dual_segment_tree{\n  int N;\n  vector<T>\
    \ ST;\n  function<T(T, T)> f;\n  T E;\n  commutative_dual_segment_tree(int n,\
    \ function<T(T, T)> f, T E): f(f), E(E){\n    N = 1;\n    while (N < n){\n   \
    \   N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n  }\n  commutative_dual_segment_tree(vector<T>\
    \ A, function<T(T, T)> f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n\
    \    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n\
    \    for (int i = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n    for\
    \ (int i = N - 2; i >= 0; i--){\n      ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);\n\
    \    }\n  }\n  T operator [](int k){\n    k += N - 1;\n    T ans = ST[k];\n  \
    \  while (k > 0){\n      k = (k - 1) / 2;\n      ans = f(ans, ST[k]);\n    }\n\
    \    return ans;\n  }\n  void range_apply(int L, int R, T x, int i, int l, int\
    \ r){\n    if (r <= L || R <= l){\n    } else if (L <= l && r <= R){\n      ST[i]\
    \ = f(ST[i], x);\n    } else {\n      int m = (l + r) / 2;\n      range_apply(L,\
    \ R, x, i * 2 + 1, l, m);\n      range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n\
    \  }\n  void range_apply(int L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n\
    \  }\n};\n/**\n * @brief Commutative Dual Segment Tree (\u53EF\u63DB\u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001\u3089\u3066\u6728)\n*/\n#line 5 \"\
    test/aoj/dsl_2_d.test.cpp\"\nint main(){\n  int n, q;\n  cin >> n >> q;\n  commutative_dual_segment_tree<pair<int,\
    \ int>> ST(n, [](pair<int, int> a, pair<int, int> b){return  max(a, b);}, make_pair(-1,\
    \ 2147483647));\n  for (int i = 0; i < q; i++){\n    int c;\n    cin >> c;\n \
    \   if (c == 0){\n      int s, t, x;\n      cin >> s >> t >> x;\n      t++;\n\
    \      ST.range_apply(s, t, make_pair(i, x));\n    }\n    if (c == 1){\n     \
    \ int t;\n      cin >> t;\n      cout << ST[t].second << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/commutative_dual_segment_tree.cpp\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  commutative_dual_segment_tree<pair<int,\
    \ int>> ST(n, [](pair<int, int> a, pair<int, int> b){return  max(a, b);}, make_pair(-1,\
    \ 2147483647));\n  for (int i = 0; i < q; i++){\n    int c;\n    cin >> c;\n \
    \   if (c == 0){\n      int s, t, x;\n      cin >> s >> t >> x;\n      t++;\n\
    \      ST.range_apply(s, t, make_pair(i, x));\n    }\n    if (c == 1){\n     \
    \ int t;\n      cin >> t;\n      cout << ST[t].second << endl;\n    }\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/commutative_dual_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/dsl_2_d.test.cpp
  requiredBy: []
  timestamp: '2022-07-14 01:44:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_2_d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_d.test.cpp
- /verify/test/aoj/dsl_2_d.test.cpp.html
title: test/aoj/dsl_2_d.test.cpp
---
