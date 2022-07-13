---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/dual_disjoint_sparse_table.cpp
    title: data_structure/sequence/dual_disjoint_sparse_table.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
  bundledCode: "#line 1 \"test/aoj/dsl_5_a_3.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/dual_disjoint_sparse_table.cpp\"\
    \ntemplate <typename T>\nstruct dual_disjoint_sparse_table{\n  vector<T> A;\n\
    \  vector<vector<T>> D;\n  function<T(T, T)> f;\n  T E;\n  dual_disjoint_sparse_table(){\n\
    \  }\n  dual_disjoint_sparse_table(int N, function<T(T, T)> f, T E): A(N, E),\
    \ f(f), E(E){\n    if (N > 1){\n      int LOG = 32 - __builtin_clz(N - 1);\n \
    \     D = vector<vector<T>>(LOG, vector<T>(N, E));\n    }\n  }\n  dual_disjoint_sparse_table(vector<T>\
    \ &A, function<T(T, T)> f, T E): A(A), f(f), E(E){\n    int N = A.size();\n  \
    \  if (N > 1){\n      int LOG = 32 - __builtin_clz(N - 1);\n      D = vector<vector<T>>(LOG,\
    \ vector<T>(N, E));\n    }\n  }\n  void apply(int L, int R, T x){\n    if (L ==\
    \ R){\n      return;\n    } else if (R - L == 1){\n      A[L] = f(A[L], x);\n\
    \    } else {\n      R--;\n      int b = 31 - __builtin_clz(R ^ L);\n      D[b][L]\
    \ = f(D[b][L], x);\n      D[b][R] = f(D[b][R], x);\n    }\n  }\n  vector<T> get(){\n\
    \    int LOG = D.size();\n    int N = A.size();\n    for (int i = 0; i < LOG;\
    \ i++){\n      int d = 1 << i;\n      for (int j = 0; j + d < N; j += d * 2){\n\
    \        T L = E;\n        for (int k = j; k < j + d; k++){\n          L = f(L,\
    \ D[i][k]);\n          A[k] = f(A[k], L);\n        }\n        T R = E;\n     \
    \   for (int k = min(j + d * 2, N) - 1; k >= j + d; k--){\n          R = f(R,\
    \ D[i][k]);\n          A[k] = f(A[k], R);\n        }\n      }\n    }\n    return\
    \ A;\n  }\n};\n#line 5 \"test/aoj/dsl_5_a_3.test.cpp\"\nint main(){\n  int N,\
    \ T;\n  cin >> N >> T;\n  dual_disjoint_sparse_table<int> DST(T, plus<int>(),\
    \ 0);\n  for (int i = 0; i < N; i++){\n    int l, r;\n    cin >> l >> r;\n   \
    \ DST.apply(l, r, 1);\n  }\n  vector<int> S = DST.get();\n  int ans = 0;\n  for\
    \ (int i = 0; i < T; i++){\n    ans = max(ans, S[i]);\n  }\n  cout << ans << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/dual_disjoint_sparse_table.cpp\"\
    \nint main(){\n  int N, T;\n  cin >> N >> T;\n  dual_disjoint_sparse_table<int>\
    \ DST(T, plus<int>(), 0);\n  for (int i = 0; i < N; i++){\n    int l, r;\n   \
    \ cin >> l >> r;\n    DST.apply(l, r, 1);\n  }\n  vector<int> S = DST.get();\n\
    \  int ans = 0;\n  for (int i = 0; i < T; i++){\n    ans = max(ans, S[i]);\n \
    \ }\n  cout << ans << endl;\n}\n"
  dependsOn:
  - data_structure/sequence/dual_disjoint_sparse_table.cpp
  isVerificationFile: true
  path: test/aoj/dsl_5_a_3.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 16:40:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_5_a_3.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_5_a_3.test.cpp
- /verify/test/aoj/dsl_5_a_3.test.cpp.html
title: test/aoj/dsl_5_a_3.test.cpp
---
