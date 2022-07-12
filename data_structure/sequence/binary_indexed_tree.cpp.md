---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/point_add_range_sum.test.cpp
    title: test/library_checker/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/binary_indexed_tree.cpp\"\ntemplate\
    \ <typename T>\nstruct binary_indexed_tree{\n  int N;\n  vector<T> BIT;\n  binary_indexed_tree(){\n\
    \  }\n  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){\n  }\n  binary_indexed_tree(vector<T>\
    \ &A): N(A.size()), BIT(N + 1):{\n    for (int i = 0; i < N; i++){\n      BIT[i\
    \ + 1] = A[i];\n    }\n    for (int i = 1; i < N; i++){\n      BIT[i + (i & -i)]\
    \ += BIT[i];\n    }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n\
    \      BIT[i] += x;\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans\
    \ = 0;\n    while (i > 0){\n      ans += BIT[i];\n      i -= i & -i;\n    }\n\
    \    return ans;\n  }\n  T sum(int L, int R){\n    return sum(R) - sum(L);\n \
    \ }\n};\n"
  code: "template <typename T>\nstruct binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  binary_indexed_tree(){\n  }\n  binary_indexed_tree(int N): N(N), BIT(N\
    \ + 1, 0){\n  }\n  binary_indexed_tree(vector<T> &A): N(A.size()), BIT(N + 1):{\n\
    \    for (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n    for (int\
    \ i = 1; i < N; i++){\n      BIT[i + (i & -i)] += BIT[i];\n    }\n  }\n  void\
    \ add(int i, T x){\n    i++;\n    while (i <= N){\n      BIT[i] += x;\n      i\
    \ += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans = 0;\n    while (i > 0){\n\
    \      ans += BIT[i];\n      i -= i & -i;\n    }\n    return ans;\n  }\n  T sum(int\
    \ L, int R){\n    return sum(R) - sum(L);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2022-07-13 03:11:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/point_add_range_sum.test.cpp
documentation_of: data_structure/sequence/binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/binary_indexed_tree.cpp
- /library/data_structure/sequence/binary_indexed_tree.cpp.html
title: data_structure/sequence/binary_indexed_tree.cpp
---
