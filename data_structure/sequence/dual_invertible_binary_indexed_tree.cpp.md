---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_e_2.test.cpp
    title: test/aoj/dsl_2_e_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_5_a_2.test.cpp
    title: test/aoj/dsl_5_a_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/dual_invertible_binary_indexed_tree.cpp\"\
    \ntemplate <typename T>\nstruct dual_invertible_binary_indexed_tree{\n  int N;\n\
    \  vector<T> BIT;\n  function<T(T, T)> f;\n  function<T(T)> inv;\n  T E;\n  dual_invertible_binary_indexed_tree(){\n\
    \  }\n  dual_invertible_binary_indexed_tree(int N, function<T(T, T)> f, function<T(T)>\
    \ inv, T E): N(N), BIT(N + 1, E), f(f), inv(inv), E(E){\n  }\n  dual_invertible_binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, function<T(T)> inv, T E): N(A.size()), BIT(N + 1),\
    \ f(f), inv(inv), E(E){\n    for (int i = 0; i < N; i++){\n      BIT[i + 1] =\
    \ A[i];\n    }\n  }\n  void add(int i, T x){\n    while (i > 0){\n      BIT[i]\
    \ = f(BIT[i], x);\n      i -= i & -i;\n    }\n  }\n  void add(int l, int r, T\
    \ x){\n    add(l, inv(x));\n    add(r, x);\n  }\n  T operator [](int i){\n   \
    \ i++;\n    T ans = E;\n    while (i <= N){\n      ans = f(ans, BIT[i]);\n   \
    \   i += i & -i;\n    }\n    return ans;\n  }\n  vector<T> get(){\n    vector<T>\
    \ ans = BIT;\n    for (int i = N - 1; i >= 1; i--){\n      if (i + (i & -i) <=\
    \ N){\n        ans[i] = f(ans[i + (i & -i)], ans[i]);\n      }\n    }\n    ans.erase(ans.begin());\n\
    \    return ans;\n  }\n};\n"
  code: "template <typename T>\nstruct dual_invertible_binary_indexed_tree{\n  int\
    \ N;\n  vector<T> BIT;\n  function<T(T, T)> f;\n  function<T(T)> inv;\n  T E;\n\
    \  dual_invertible_binary_indexed_tree(){\n  }\n  dual_invertible_binary_indexed_tree(int\
    \ N, function<T(T, T)> f, function<T(T)> inv, T E): N(N), BIT(N + 1, E), f(f),\
    \ inv(inv), E(E){\n  }\n  dual_invertible_binary_indexed_tree(vector<T> &A, function<T(T,\
    \ T)> f, function<T(T)> inv, T E): N(A.size()), BIT(N + 1), f(f), inv(inv), E(E){\n\
    \    for (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n  }\n  void\
    \ add(int i, T x){\n    while (i > 0){\n      BIT[i] = f(BIT[i], x);\n      i\
    \ -= i & -i;\n    }\n  }\n  void add(int l, int r, T x){\n    add(l, inv(x));\n\
    \    add(r, x);\n  }\n  T operator [](int i){\n    i++;\n    T ans = E;\n    while\
    \ (i <= N){\n      ans = f(ans, BIT[i]);\n      i += i & -i;\n    }\n    return\
    \ ans;\n  }\n  vector<T> get(){\n    vector<T> ans = BIT;\n    for (int i = N\
    \ - 1; i >= 1; i--){\n      if (i + (i & -i) <= N){\n        ans[i] = f(ans[i\
    \ + (i & -i)], ans[i]);\n      }\n    }\n    ans.erase(ans.begin());\n    return\
    \ ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/dual_invertible_binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2022-07-13 14:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_5_a_2.test.cpp
  - test/aoj/dsl_2_e_2.test.cpp
documentation_of: data_structure/sequence/dual_invertible_binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/dual_invertible_binary_indexed_tree.cpp
- /library/data_structure/sequence/dual_invertible_binary_indexed_tree.cpp.html
title: data_structure/sequence/dual_invertible_binary_indexed_tree.cpp
---