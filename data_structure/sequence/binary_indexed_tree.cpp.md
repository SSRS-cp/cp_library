---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/dsl_2_b.test.cpp
    title: test/aoj/dsl_2_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/point_add_range_sum.test.cpp
    title: test/library_checker/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/binary_indexed_tree.cpp\"\ntemplate\
    \ <typename T>\nstruct binary_indexed_tree{\n  int N;\n  vector<T> BIT;\n  function<T(T,\
    \ T)> f;\n  T E;\n  binary_indexed_tree(){\n  }\n  binary_indexed_tree(int N,\
    \ function<T(T, T)> f, T E): f(f), E(E), N(N), BIT(N + 1, 0){\n  }\n  binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, T E): f(f), E(E), N(A.size()), BIT(N + 1){\n    for\
    \ (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n    for (int i =\
    \ 1; i < N; i++){\n      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n \
    \   }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n      BIT[i]\
    \ = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans\
    \ = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i & -i;\n\
    \    }\n    return ans;\n  }\n};\n"
  code: "template <typename T>\nstruct binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  function<T(T, T)> f;\n  T E;\n  binary_indexed_tree(){\n  }\n  binary_indexed_tree(int\
    \ N, function<T(T, T)> f, T E): f(f), E(E), N(N), BIT(N + 1, 0){\n  }\n  binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, T E): f(f), E(E), N(A.size()), BIT(N + 1){\n    for\
    \ (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n    for (int i =\
    \ 1; i < N; i++){\n      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n \
    \   }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n      BIT[i]\
    \ = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans\
    \ = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i & -i;\n\
    \    }\n    return ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2022-07-13 07:37:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/point_add_range_sum.test.cpp
  - test/aoj/dsl_2_b.test.cpp
documentation_of: data_structure/sequence/binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/binary_indexed_tree.cpp
- /library/data_structure/sequence/binary_indexed_tree.cpp.html
title: data_structure/sequence/binary_indexed_tree.cpp
---
