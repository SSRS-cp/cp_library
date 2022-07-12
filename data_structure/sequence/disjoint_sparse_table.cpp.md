---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_sum_3.test.cpp
    title: test/library_checker/static_range_sum_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/disjoint_sparse_table.cpp\"\ntemplate\
    \ <typename T>\nstruct disjoint_sparse_table{\n  vector<T> A;\n  vector<vector<T>>\
    \ D;\n  function<T(T, T)> f;\n  disjoint_sparse_table(){\n  }\n  disjoint_sparse_table(vector<T>\
    \ &A, function<T(T, T)> f): A(A), f(f){\n    int N = A.size();\n    int LOG =\
    \ 32 - __builtin_clz(N - 1);\n    D = vector<vector<T>>(LOG, vector<T>(N));\n\
    \    for (int i = 0; i < LOG; i++){\n      int d = 1 << i;\n      for (int j =\
    \ 0; j + d < N; j += d * 2){\n        D[i][j + d - 1] = A[j + d - 1];\n      \
    \  for (int k = j + d - 2; k >= j; k--){\n          D[i][k] = f(A[k], D[i][k +\
    \ 1]);\n        }\n        D[i][j + d] = A[j + d];\n        for (int k = j + d\
    \ + 1; k < min(j + d * 2, N); k++){\n          D[i][k] = f(D[i][k - 1], A[k]);\n\
    \        }\n      }\n    }\n  }\n  T query(int L, int R){\n    if (R - L == 1){\n\
    \      return A[L];\n    } else {\n      R--;\n      int b = 31 - __builtin_clz(R\
    \ ^ L);\n      return f(D[b][L], D[b][R]);\n    }\n  }\n};\n"
  code: "template <typename T>\nstruct disjoint_sparse_table{\n  vector<T> A;\n  vector<vector<T>>\
    \ D;\n  function<T(T, T)> f;\n  disjoint_sparse_table(){\n  }\n  disjoint_sparse_table(vector<T>\
    \ &A, function<T(T, T)> f): A(A), f(f){\n    int N = A.size();\n    int LOG =\
    \ 32 - __builtin_clz(N - 1);\n    D = vector<vector<T>>(LOG, vector<T>(N));\n\
    \    for (int i = 0; i < LOG; i++){\n      int d = 1 << i;\n      for (int j =\
    \ 0; j + d < N; j += d * 2){\n        D[i][j + d - 1] = A[j + d - 1];\n      \
    \  for (int k = j + d - 2; k >= j; k--){\n          D[i][k] = f(A[k], D[i][k +\
    \ 1]);\n        }\n        D[i][j + d] = A[j + d];\n        for (int k = j + d\
    \ + 1; k < min(j + d * 2, N); k++){\n          D[i][k] = f(D[i][k - 1], A[k]);\n\
    \        }\n      }\n    }\n  }\n  T query(int L, int R){\n    if (R - L == 1){\n\
    \      return A[L];\n    } else {\n      R--;\n      int b = 31 - __builtin_clz(R\
    \ ^ L);\n      return f(D[b][L], D[b][R]);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/disjoint_sparse_table.cpp
  requiredBy: []
  timestamp: '2022-07-13 04:35:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_sum_3.test.cpp
documentation_of: data_structure/sequence/disjoint_sparse_table.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/disjoint_sparse_table.cpp
- /library/data_structure/sequence/disjoint_sparse_table.cpp.html
title: data_structure/sequence/disjoint_sparse_table.cpp
---
