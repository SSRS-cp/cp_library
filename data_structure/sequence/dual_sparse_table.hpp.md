---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_945.test.cpp
    title: test/yukicoder/yuki_945.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/dual_sparse_table.hpp\"\n/**\n *\
    \ @brief \u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n*/\ntemplate\
    \ <typename T>\nstruct dual_sparse_table{\n  vector<vector<T>> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  dual_sparse_table(){\n  }\n  dual_sparse_table(int N, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    int LOG = 32 - __builtin_clz(N);\n    ST = vector<vector<T>>(LOG,\
    \ vector<T>(N, E));\n  }\n  dual_sparse_table(vector<T> &A, function<T(T, T)>\
    \ f, T E): f(f), E(E){\n    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n\
    \    ST = vector<vector<T>>(LOG, vector<T>(N, E));\n    ST[0] = A;\n  }\n  void\
    \ apply(int L, int R, T x){\n    if (L == R){\n      return;\n    }\n    int d\
    \ = 31 - __builtin_clz(R - L);\n    ST[d][L] = f(ST[d][L], x);\n    ST[d][R -\
    \ (1 << d)] = f(ST[d][R - (1 << d)], x);\n  }\n  vector<T> get(){\n    int LOG\
    \ = ST.size();\n    int N = ST[0].size();\n    for (int i = LOG - 2; i >= 0; i--){\n\
    \      for (int j = 0; j < N - (1 << i); j++){\n        ST[i][j] = f(ST[i][j],\
    \ ST[i + 1][j]);\n        ST[i][j + (1 << i)] = f(ST[i][j + (1 << i)], ST[i +\
    \ 1][j]);\n      }\n    }\n    return ST[0];\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\
    \u30D6\u30EB\n*/\ntemplate <typename T>\nstruct dual_sparse_table{\n  vector<vector<T>>\
    \ ST;\n  function<T(T, T)> f;\n  T E;\n  dual_sparse_table(){\n  }\n  dual_sparse_table(int\
    \ N, function<T(T, T)> f, T E): f(f), E(E){\n    int LOG = 32 - __builtin_clz(N);\n\
    \    ST = vector<vector<T>>(LOG, vector<T>(N, E));\n  }\n  dual_sparse_table(vector<T>\
    \ &A, function<T(T, T)> f, T E): f(f), E(E){\n    int N = A.size();\n    int LOG\
    \ = 32 - __builtin_clz(N);\n    ST = vector<vector<T>>(LOG, vector<T>(N, E));\n\
    \    ST[0] = A;\n  }\n  void apply(int L, int R, T x){\n    if (L == R){\n   \
    \   return;\n    }\n    int d = 31 - __builtin_clz(R - L);\n    ST[d][L] = f(ST[d][L],\
    \ x);\n    ST[d][R - (1 << d)] = f(ST[d][R - (1 << d)], x);\n  }\n  vector<T>\
    \ get(){\n    int LOG = ST.size();\n    int N = ST[0].size();\n    for (int i\
    \ = LOG - 2; i >= 0; i--){\n      for (int j = 0; j < N - (1 << i); j++){\n  \
    \      ST[i][j] = f(ST[i][j], ST[i + 1][j]);\n        ST[i][j + (1 << i)] = f(ST[i][j\
    \ + (1 << i)], ST[i + 1][j]);\n      }\n    }\n    return ST[0];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/dual_sparse_table.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_945.test.cpp
documentation_of: data_structure/sequence/dual_sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/dual_sparse_table.hpp
- /library/data_structure/sequence/dual_sparse_table.hpp.html
title: "\u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
---
