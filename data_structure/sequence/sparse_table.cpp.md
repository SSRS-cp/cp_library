---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/static_rmq_2.test.cpp
    title: test/library_checker/static_rmq_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/sparse_table.cpp\"\ntemplate <typename\
    \ T>\nstruct sparse_table{\n  vector<vector<T>> ST;\n  function<T(T, T)> f;\n\
    \  T E;\n  sparse_table(vector<T> &A, function<T(T, T)> f, T E): f(f), E(E){\n\
    \    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n    ST = vector<vector<int>>(LOG,\
    \ vector<int>(N));\n    for (int i = 0; i < N; i++){\n      ST[0][i] = A[i];\n\
    \    }\n    for (int i = 0; i < LOG - 1; i++){\n      for (int j = 0; j < N -\
    \ (1 << i); j++){\n        ST[i + 1][j] = f(ST[i][j], ST[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n  int range_min(int L, int R){\n    if (L == R){\n     \
    \ return E;\n    }\n    int d = 31 - __builtin_clz(R - L);\n    return f(ST[d][L],\
    \ ST[d][R - (1 << d)]);\n  }\n};\n"
  code: "template <typename T>\nstruct sparse_table{\n  vector<vector<T>> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  sparse_table(vector<T> &A, function<T(T, T)> f, T E): f(f),\
    \ E(E){\n    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n    ST =\
    \ vector<vector<int>>(LOG, vector<int>(N));\n    for (int i = 0; i < N; i++){\n\
    \      ST[0][i] = A[i];\n    }\n    for (int i = 0; i < LOG - 1; i++){\n     \
    \ for (int j = 0; j < N - (1 << i); j++){\n        ST[i + 1][j] = f(ST[i][j],\
    \ ST[i][j + (1 << i)]);\n      }\n    }\n  }\n  int range_min(int L, int R){\n\
    \    if (L == R){\n      return E;\n    }\n    int d = 31 - __builtin_clz(R -\
    \ L);\n    return f(ST[d][L], ST[d][R - (1 << d)]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/sparse_table.cpp
  requiredBy: []
  timestamp: '2022-07-13 10:11:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/static_rmq_2.test.cpp
documentation_of: data_structure/sequence/sparse_table.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/sparse_table.cpp
- /library/data_structure/sequence/sparse_table.cpp.html
title: data_structure/sequence/sparse_table.cpp
---
