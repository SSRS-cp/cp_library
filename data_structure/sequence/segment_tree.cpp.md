---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_a.test.cpp
    title: test/aoj/dsl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_b_3.test.cpp
    title: test/aoj/dsl_2_b_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/point_add_range_sum_3.test.cpp
    title: test/library_checker/point_add_range_sum_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_rmq_3.test.cpp
    title: test/library_checker/static_rmq_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/segment_tree.cpp\"\ntemplate <typename\
    \ T>\nstruct segment_tree{\n  int N;\n  vector<T> ST;\n  function<T(T, T)> f;\n\
    \  T E;\n  segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){\n    N =\
    \ 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1,\
    \ E);\n  }\n  segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){\n\
    \    int n = A.size();\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n\
    \    ST = vector<T>(N * 2 - 1, E);\n    for (int i = 0; i < n; i++){\n      ST[N\
    \ - 1 + i] = A[i];\n    }\n    for (int i = N - 2; i >= 0; i--){\n      ST[i]\
    \ = f(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n  }\n  T operator [](int k){\n  \
    \  return ST[N - 1 + k];\n  }\n  void update(int k, T x){\n    k += N - 1;\n \
    \   ST[k] = x;\n    while (k > 0){\n      k = (k - 1) / 2;\n      ST[k] = f(ST[k\
    \ * 2 + 1], ST[k * 2 + 2]);\n    }\n  }\n  T query(int L, int R, int i, int l,\
    \ int r){\n    if (R <= l || r <= L){\n      return E;\n    } else if (L <= l\
    \ && r <= R){\n      return ST[i];\n    } else {\n      int m = (l + r) / 2;\n\
    \      return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));\n\
    \    }\n  }\n  T query(int L, int R){\n    return query(L, R, 0, 0, N);\n  }\n\
    \  T all(){\n    return ST[0];\n  }\n};\n/**\n * @brief Segment Tree (\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728)\n*/\n"
  code: "template <typename T>\nstruct segment_tree{\n  int N;\n  vector<T> ST;\n\
    \  function<T(T, T)> f;\n  T E;\n  segment_tree(int n, function<T(T, T)> f, T\
    \ E): f(f), E(E){\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST\
    \ = vector<T>(N * 2 - 1, E);\n  }\n  segment_tree(vector<T> A, function<T(T, T)>\
    \ f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n    while (N < n){\n\
    \      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i = 0;\
    \ i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n    for (int i = N - 2; i\
    \ >= 0; i--){\n      ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n  }\n  T\
    \ operator [](int k){\n    return ST[N - 1 + k];\n  }\n  void update(int k, T\
    \ x){\n    k += N - 1;\n    ST[k] = x;\n    while (k > 0){\n      k = (k - 1)\
    \ / 2;\n      ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);\n    }\n  }\n  T query(int\
    \ L, int R, int i, int l, int r){\n    if (R <= l || r <= L){\n      return E;\n\
    \    } else if (L <= l && r <= R){\n      return ST[i];\n    } else {\n      int\
    \ m = (l + r) / 2;\n      return f(query(L, R, i * 2 + 1, l, m), query(L, R, i\
    \ * 2 + 2, m, r));\n    }\n  }\n  T query(int L, int R){\n    return query(L,\
    \ R, 0, 0, N);\n  }\n  T all(){\n    return ST[0];\n  }\n};\n/**\n * @brief Segment\
    \ Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/segment_tree.cpp
  requiredBy: []
  timestamp: '2022-07-13 20:08:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/point_add_range_sum_3.test.cpp
  - test/library_checker/static_rmq_3.test.cpp
  - test/aoj/dsl_2_a.test.cpp
  - test/aoj/dsl_2_b_3.test.cpp
documentation_of: data_structure/sequence/segment_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/segment_tree.cpp
- /library/data_structure/sequence/segment_tree.cpp.html
title: "Segment Tree (\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
