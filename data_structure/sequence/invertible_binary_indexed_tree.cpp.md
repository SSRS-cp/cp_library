---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/invertible_binary_indexed_tree.cpp\"\
    \ntemplate <typename T>\nstruct invertible_binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  function<T(T, T)> f;\n  function<T(T)> inv;\n  T E;\n  invertible_binary_indexed_tree(){\n\
    \  }\n  invertible_binary_indexed_tree(int N, function<T(T, T)> f, function<T(T)>\
    \ inv, T E): N(N), BIT(N + 1, E), f(f), inv(inv), E(E){\n  }\n  invertible_binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, T E): N(A.size()), BIT(N + 1), f(f), inv(inv), E(E){\n\
    \    for (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n    for (int\
    \ i = 1; i < N; i++){\n      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n\
    \    }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n      BIT[i]\
    \ = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans\
    \ = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i & -i;\n\
    \    }\n    return ans;\n  }\n  T sum(int l, int r){\n    return f(sum(r), inv(sum(l)));\n\
    \  }\n};\n"
  code: "template <typename T>\nstruct invertible_binary_indexed_tree{\n  int N;\n\
    \  vector<T> BIT;\n  function<T(T, T)> f;\n  function<T(T)> inv;\n  T E;\n  invertible_binary_indexed_tree(){\n\
    \  }\n  invertible_binary_indexed_tree(int N, function<T(T, T)> f, function<T(T)>\
    \ inv, T E): N(N), BIT(N + 1, E), f(f), inv(inv), E(E){\n  }\n  invertible_binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, T E): N(A.size()), BIT(N + 1), f(f), inv(inv), E(E){\n\
    \    for (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n    for (int\
    \ i = 1; i < N; i++){\n      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n\
    \    }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n      BIT[i]\
    \ = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans\
    \ = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i & -i;\n\
    \    }\n    return ans;\n  }\n  T sum(int l, int r){\n    return f(sum(r), inv(sum(l)));\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/invertible_binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2022-07-13 08:10:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sequence/invertible_binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/invertible_binary_indexed_tree.cpp
- /library/data_structure/sequence/invertible_binary_indexed_tree.cpp.html
title: data_structure/sequence/invertible_binary_indexed_tree.cpp
---
