---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_5_a_3.test.cpp
    title: test/aoj/dsl_5_a_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dual Disjoint Sparse Table (\u53CC\u5BFE Disjoint Sparse Table)"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/dual_disjoint_sparse_table.cpp\"\
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
    \ A;\n  }\n};\n/**\n * @brief Dual Disjoint Sparse Table (\u53CC\u5BFE Disjoint\
    \ Sparse Table)\n*/\n"
  code: "template <typename T>\nstruct dual_disjoint_sparse_table{\n  vector<T> A;\n\
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
    \ A;\n  }\n};\n/**\n * @brief Dual Disjoint Sparse Table (\u53CC\u5BFE Disjoint\
    \ Sparse Table)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/dual_disjoint_sparse_table.cpp
  requiredBy: []
  timestamp: '2022-07-13 19:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_5_a_3.test.cpp
documentation_of: data_structure/sequence/dual_disjoint_sparse_table.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/dual_disjoint_sparse_table.cpp
- /library/data_structure/sequence/dual_disjoint_sparse_table.cpp.html
title: "Dual Disjoint Sparse Table (\u53CC\u5BFE Disjoint Sparse Table)"
---
