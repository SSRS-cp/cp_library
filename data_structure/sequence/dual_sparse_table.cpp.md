---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_945_1.test.cpp
    title: test/yukicoder/yuki_945_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dual Sparse Table (\u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\
      \u30FC\u30D6\u30EB)"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/dual_sparse_table.cpp\"\ntemplate\
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
    \ 1][j]);\n      }\n    }\n    return ST[0];\n  }\n};\n/**\n * @brief Dual Sparse\
    \ Table (\u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB)\n*/\n"
  code: "template <typename T>\nstruct dual_sparse_table{\n  vector<vector<T>> ST;\n\
    \  function<T(T, T)> f;\n  T E;\n  dual_sparse_table(){\n  }\n  dual_sparse_table(int\
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
    \ + (1 << i)], ST[i + 1][j]);\n      }\n    }\n    return ST[0];\n  }\n};\n/**\n\
    \ * @brief Dual Sparse Table (\u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\
    \u30D6\u30EB)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/dual_sparse_table.cpp
  requiredBy: []
  timestamp: '2022-07-13 19:22:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_945_1.test.cpp
documentation_of: data_structure/sequence/dual_sparse_table.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/dual_sparse_table.cpp
- /library/data_structure/sequence/dual_sparse_table.cpp.html
title: "Dual Sparse Table (\u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\
  )"
---
