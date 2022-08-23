---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/staticrmq_2.test.cpp
    title: test/library_checker/data_structure/staticrmq_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/sparse_table.hpp\"\n/**\n * @brief\
    \ \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n*/\ntemplate <typename T>\n\
    struct sparse_table{\n  vector<vector<T>> ST;\n  function<T(T, T)> f;\n  T E;\n\
    \  sparse_table(){\n  }\n  sparse_table(int N, function<T(T, T)> f, T E): f(f),\
    \ E(E){\n    int LOG = 32 - __builtin_clz(N);\n    ST = vector<vector<T>>(LOG,\
    \ vector<T>(N, E));\n  }\n  sparse_table(vector<T> &A, function<T(T, T)> f, T\
    \ E): f(f), E(E){\n    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n\
    \    ST = vector<vector<T>>(LOG, vector<T>(N));\n    for (int i = 0; i < N; i++){\n\
    \      ST[0][i] = A[i];\n    }\n    for (int i = 0; i < LOG - 1; i++){\n     \
    \ for (int j = 0; j < N - (1 << i); j++){\n        ST[i + 1][j] = f(ST[i][j],\
    \ ST[i][j + (1 << i)]);\n      }\n    }\n  }\n  int query(int L, int R){\n   \
    \ if (L == R){\n      return E;\n    }\n    int d = 31 - __builtin_clz(R - L);\n\
    \    return f(ST[d][L], ST[d][R - (1 << d)]);\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\
    \n*/\ntemplate <typename T>\nstruct sparse_table{\n  vector<vector<T>> ST;\n \
    \ function<T(T, T)> f;\n  T E;\n  sparse_table(){\n  }\n  sparse_table(int N,\
    \ function<T(T, T)> f, T E): f(f), E(E){\n    int LOG = 32 - __builtin_clz(N);\n\
    \    ST = vector<vector<T>>(LOG, vector<T>(N, E));\n  }\n  sparse_table(vector<T>\
    \ &A, function<T(T, T)> f, T E): f(f), E(E){\n    int N = A.size();\n    int LOG\
    \ = 32 - __builtin_clz(N);\n    ST = vector<vector<T>>(LOG, vector<T>(N));\n \
    \   for (int i = 0; i < N; i++){\n      ST[0][i] = A[i];\n    }\n    for (int\
    \ i = 0; i < LOG - 1; i++){\n      for (int j = 0; j < N - (1 << i); j++){\n \
    \       ST[i + 1][j] = f(ST[i][j], ST[i][j + (1 << i)]);\n      }\n    }\n  }\n\
    \  int query(int L, int R){\n    if (L == R){\n      return E;\n    }\n    int\
    \ d = 31 - __builtin_clz(R - L);\n    return f(ST[d][L], ST[d][R - (1 << d)]);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/staticrmq_2.test.cpp
documentation_of: data_structure/sequence/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/sparse_table.hpp
- /library/data_structure/sequence/sparse_table.hpp.html
title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
---
