---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_b.test.cpp
    title: test/aoj/dsl_2_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/point_add_range_sum.test.cpp
    title: test/library_checker/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/binary_indexed_tree.hpp\"\n/**\n\
    \ * @brief Binary Indexed Tree\n*/\ntemplate <typename T>\nstruct binary_indexed_tree{\n\
    \  int N;\n  vector<T> BIT;\n  function<T(T, T)> f;\n  T E;\n  binary_indexed_tree(){\n\
    \  }\n  binary_indexed_tree(int N, function<T(T, T)> f, T E): N(N), BIT(N + 1,\
    \ E), f(f), E(E){\n  }\n  binary_indexed_tree(vector<T> &A, function<T(T, T)>\
    \ f, T E): N(A.size()), BIT(N + 1), f(f), E(E){\n    for (int i = 0; i < N; i++){\n\
    \      BIT[i + 1] = A[i];\n    }\n    for (int i = 1; i < N; i++){\n      if (i\
    \ + (i & -i) <= N){\n        BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n\
    \      }\n    }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n\
    \      BIT[i] = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n\
    \    T ans = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i\
    \ & -i;\n    }\n    return ans;\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief Binary Indexed Tree\n*/\ntemplate <typename\
    \ T>\nstruct binary_indexed_tree{\n  int N;\n  vector<T> BIT;\n  function<T(T,\
    \ T)> f;\n  T E;\n  binary_indexed_tree(){\n  }\n  binary_indexed_tree(int N,\
    \ function<T(T, T)> f, T E): N(N), BIT(N + 1, E), f(f), E(E){\n  }\n  binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, T E): N(A.size()), BIT(N + 1), f(f), E(E){\n    for\
    \ (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n    for (int i =\
    \ 1; i < N; i++){\n      if (i + (i & -i) <= N){\n        BIT[i + (i & -i)] =\
    \ f(BIT[i + (i & -i)], BIT[i]);\n      }\n    }\n  }\n  void add(int i, T x){\n\
    \    i++;\n    while (i <= N){\n      BIT[i] = f(BIT[i], x);\n      i += i & -i;\n\
    \    }\n  }\n  T sum(int i){\n    T ans = E;\n    while (i > 0){\n      ans =\
    \ f(ans, BIT[i]);\n      i -= i & -i;\n    }\n    return ans;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/point_add_range_sum.test.cpp
  - test/aoj/dsl_2_b.test.cpp
documentation_of: data_structure/sequence/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/binary_indexed_tree.hpp
- /library/data_structure/sequence/binary_indexed_tree.hpp.html
title: Binary Indexed Tree
---
