---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_e.test.cpp
    title: test/aoj/dsl_2_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/dual_binary_indexed_tree.cpp\"\n\
    template <typename T>\nstruct dual_binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  dual_binary_indexed_tree(){\n  }\n  dual_binary_indexed_tree(int N):\
    \ N(N), BIT(N + 1, 0){\n  }\n  dual_binary_indexed_tree(vector<T> &A): N(A.size()),\
    \ BIT(N + 1){\n    for (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n  \
    \  }\n    for (int i = 1; i < N; i++){\n      BIT[i + (i & -i)] += BIT[i];\n \
    \   }\n  }\n  void add(int i, T x){\n    while (i > 0){\n      BIT[i] += x;\n\
    \      i -= i & -i;\n    }\n  }\n  void add(int L, int R, T x){\n    add(L, -x);\n\
    \    add(R, x);\n  }\n  T operator [](int i){\n    i++;\n    T ans = 0;\n    while\
    \ (i <= N){\n      ans += BIT[i];\n      i += i & -i;\n    }\n    return ans;\n\
    \  }\n};\n"
  code: "template <typename T>\nstruct dual_binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  dual_binary_indexed_tree(){\n  }\n  dual_binary_indexed_tree(int N):\
    \ N(N), BIT(N + 1, 0){\n  }\n  dual_binary_indexed_tree(vector<T> &A): N(A.size()),\
    \ BIT(N + 1){\n    for (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n  \
    \  }\n    for (int i = 1; i < N; i++){\n      BIT[i + (i & -i)] += BIT[i];\n \
    \   }\n  }\n  void add(int i, T x){\n    while (i > 0){\n      BIT[i] += x;\n\
    \      i -= i & -i;\n    }\n  }\n  void add(int L, int R, T x){\n    add(L, -x);\n\
    \    add(R, x);\n  }\n  T operator [](int i){\n    i++;\n    T ans = 0;\n    while\
    \ (i <= N){\n      ans += BIT[i];\n      i += i & -i;\n    }\n    return ans;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/dual_binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2022-07-13 03:46:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_e.test.cpp
documentation_of: data_structure/sequence/dual_binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/dual_binary_indexed_tree.cpp
- /library/data_structure/sequence/dual_binary_indexed_tree.cpp.html
title: data_structure/sequence/dual_binary_indexed_tree.cpp
---
