---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_rmq_2.test.cpp
    title: test/library_checker/static_rmq_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Sparse Table (\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\
      )"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/sparse_table.cpp\"\ntemplate <typename\
    \ T>\nstruct sparse_table{\n  vector<vector<T>> ST;\n  function<T(T, T)> f;\n\
    \  T E;\n  sparse_table(){\n  }\n  sparse_table(int N, function<T(T, T)> f, T\
    \ E): f(f), E(E){\n    int LOG = 32 - __builtin_clz(N);\n    ST = vector<vector<T>>(LOG,\
    \ vector<T>(N, E));\n  }\n  sparse_table(vector<T> &A, function<T(T, T)> f, T\
    \ E): f(f), E(E){\n    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n\
    \    ST = vector<vector<T>>(LOG, vector<T>(N));\n    for (int i = 0; i < N; i++){\n\
    \      ST[0][i] = A[i];\n    }\n    for (int i = 0; i < LOG - 1; i++){\n     \
    \ for (int j = 0; j < N - (1 << i); j++){\n        ST[i + 1][j] = f(ST[i][j],\
    \ ST[i][j + (1 << i)]);\n      }\n    }\n  }\n  int query(int L, int R){\n   \
    \ if (L == R){\n      return E;\n    }\n    int d = 31 - __builtin_clz(R - L);\n\
    \    return f(ST[d][L], ST[d][R - (1 << d)]);\n  }\n};\n/**\n * @brief Sparse\
    \ Table (\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB)\n*/\n"
  code: "template <typename T>\nstruct sparse_table{\n  vector<vector<T>> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  sparse_table(){\n  }\n  sparse_table(int N, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    int LOG = 32 - __builtin_clz(N);\n    ST = vector<vector<T>>(LOG,\
    \ vector<T>(N, E));\n  }\n  sparse_table(vector<T> &A, function<T(T, T)> f, T\
    \ E): f(f), E(E){\n    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n\
    \    ST = vector<vector<T>>(LOG, vector<T>(N));\n    for (int i = 0; i < N; i++){\n\
    \      ST[0][i] = A[i];\n    }\n    for (int i = 0; i < LOG - 1; i++){\n     \
    \ for (int j = 0; j < N - (1 << i); j++){\n        ST[i + 1][j] = f(ST[i][j],\
    \ ST[i][j + (1 << i)]);\n      }\n    }\n  }\n  int query(int L, int R){\n   \
    \ if (L == R){\n      return E;\n    }\n    int d = 31 - __builtin_clz(R - L);\n\
    \    return f(ST[d][L], ST[d][R - (1 << d)]);\n  }\n};\n/**\n * @brief Sparse\
    \ Table (\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/sparse_table.cpp
  requiredBy: []
  timestamp: '2022-07-13 19:21:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_rmq_2.test.cpp
documentation_of: data_structure/sequence/sparse_table.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/sparse_table.cpp
- /library/data_structure/sequence/sparse_table.cpp.html
title: "Sparse Table (\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB)"
---
