---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_d.test.cpp
    title: test/aoj/dsl_2_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_e_3.test.cpp
    title: test/aoj/dsl_2_e_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Commutative Dual Segment Tree (\u53EF\u63DB\u53CC\u5BFE\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728\u3001\u3089\u3066\u6728)"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/commutative_dual_segment_tree.cpp\"\
    \ntemplate <typename T>\nstruct commutative_dual_segment_tree{\n  int N;\n  vector<T>\
    \ ST;\n  function<T(T, T)> f;\n  T E;\n  commutative_dual_segment_tree(int n,\
    \ function<T(T, T)> f, T E): f(f), E(E){\n    N = 1;\n    while (N < n){\n   \
    \   N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n  }\n  commutative_dual_segment_tree(vector<T>\
    \ A, function<T(T, T)> f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n\
    \    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n\
    \    for (int i = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n  }\n \
    \ T operator [](int k){\n    k += N - 1;\n    T ans = ST[k];\n    while (k > 0){\n\
    \      k = (k - 1) / 2;\n      ans = f(ans, ST[k]);\n    }\n    return ans;\n\
    \  }\n  void range_apply(int L, int R, T x, int i, int l, int r){\n    if (r <=\
    \ L || R <= l){\n    } else if (L <= l && r <= R){\n      ST[i] = f(ST[i], x);\n\
    \    } else {\n      int m = (l + r) / 2;\n      range_apply(L, R, x, i * 2 +\
    \ 1, l, m);\n      range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n  }\n  void\
    \ range_apply(int L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n  }\n};\n\
    /**\n * @brief Commutative Dual Segment Tree (\u53EF\u63DB\u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3001\u3089\u3066\u6728)\n*/\n"
  code: "template <typename T>\nstruct commutative_dual_segment_tree{\n  int N;\n\
    \  vector<T> ST;\n  function<T(T, T)> f;\n  T E;\n  commutative_dual_segment_tree(int\
    \ n, function<T(T, T)> f, T E): f(f), E(E){\n    N = 1;\n    while (N < n){\n\
    \      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n  }\n  commutative_dual_segment_tree(vector<T>\
    \ A, function<T(T, T)> f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n\
    \    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n\
    \    for (int i = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n  }\n \
    \ T operator [](int k){\n    k += N - 1;\n    T ans = ST[k];\n    while (k > 0){\n\
    \      k = (k - 1) / 2;\n      ans = f(ans, ST[k]);\n    }\n    return ans;\n\
    \  }\n  void range_apply(int L, int R, T x, int i, int l, int r){\n    if (r <=\
    \ L || R <= l){\n    } else if (L <= l && r <= R){\n      ST[i] = f(ST[i], x);\n\
    \    } else {\n      int m = (l + r) / 2;\n      range_apply(L, R, x, i * 2 +\
    \ 1, l, m);\n      range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n  }\n  void\
    \ range_apply(int L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n  }\n};\n\
    /**\n * @brief Commutative Dual Segment Tree (\u53EF\u63DB\u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u3001\u3089\u3066\u6728)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/commutative_dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2022-07-14 01:50:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_d.test.cpp
  - test/aoj/dsl_2_e_3.test.cpp
documentation_of: data_structure/sequence/commutative_dual_segment_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/commutative_dual_segment_tree.cpp
- /library/data_structure/sequence/commutative_dual_segment_tree.cpp.html
title: "Commutative Dual Segment Tree (\u53EF\u63DB\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728\u3001\u3089\u3066\u6728)"
---
