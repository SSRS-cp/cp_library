---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728\u3001\u3073\u30FC\u3068\u6728)"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/dual_segment_tree.cpp\"\ntemplate\
    \ <typename T>\nstruct dual_segment_tree{\n  int N;\n  vector<T> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  dual_segment_tree(int n, function<T(T, T)> f, T E): f(f),\
    \ E(E){\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N\
    \ * 2 - 1, E);\n  }\n  dual_segment_tree(vector<T> A, function<T(T, T)> f, T E):\
    \ f(f), E(E){\n    int n = A.size();\n    N = 1;\n    while (N < n){\n      N\
    \ *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i = 0; i < n;\
    \ i++){\n      ST[N - 1 + i] = A[i];\n    }\n  }\n  void push(int i){\n    if\
    \ (i < N - 1){\n      ST[i * 2 + 1] = f(ST[i * 2 + 1], ST[i]);\n      ST[i * 2\
    \ + 2] = f(ST[i * 2 + 2], ST[i]);\n      ST[i] = E;\n    }\n  }\n  T operator\
    \ [](int k){\n    int v = 0;\n    for (int i = N / 2; i >= 1; i >>= 1){\n    \
    \  push(v);\n      if ((k & i) == 0){\n        v = v * 2 + 1;\n      } else {\n\
    \        v = v * 2 + 2;\n      }\n    }\n    return ST[v];\n  }\n  void range_apply(int\
    \ L, int R, T x, int i, int l, int r){\n    if (r <= L || R <= l){\n    } else\
    \ if (L <= l && r <= R){\n      ST[i] = f(ST[i], x);\n    } else {\n      push(i);\n\
    \      int m = (l + r) / 2;\n      range_apply(L, R, x, i * 2 + 1, l, m);\n  \
    \    range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n  }\n  void range_apply(int\
    \ L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n  }\n};\n/**\n * @brief\
    \ Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001\u3073\
    \u30FC\u3068\u6728)\n*/\n"
  code: "template <typename T>\nstruct dual_segment_tree{\n  int N;\n  vector<T> ST;\n\
    \  function<T(T, T)> f;\n  T E;\n  dual_segment_tree(int n, function<T(T, T)>\
    \ f, T E): f(f), E(E){\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n\
    \    ST = vector<T>(N * 2 - 1, E);\n  }\n  dual_segment_tree(vector<T> A, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n    while (N <\
    \ n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i\
    \ = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n  }\n  void push(int\
    \ i){\n    if (i < N - 1){\n      ST[i * 2 + 1] = f(ST[i * 2 + 1], ST[i]);\n \
    \     ST[i * 2 + 2] = f(ST[i * 2 + 2], ST[i]);\n      ST[i] = E;\n    }\n  }\n\
    \  T operator [](int k){\n    int v = 0;\n    for (int i = N / 2; i >= 1; i >>=\
    \ 1){\n      push(v);\n      if ((k & i) == 0){\n        v = v * 2 + 1;\n    \
    \  } else {\n        v = v * 2 + 2;\n      }\n    }\n    return ST[v];\n  }\n\
    \  void range_apply(int L, int R, T x, int i, int l, int r){\n    if (r <= L ||\
    \ R <= l){\n    } else if (L <= l && r <= R){\n      ST[i] = f(ST[i], x);\n  \
    \  } else {\n      push(i);\n      int m = (l + r) / 2;\n      range_apply(L,\
    \ R, x, i * 2 + 1, l, m);\n      range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n\
    \  }\n  void range_apply(int L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n\
    \  }\n};\n/**\n * @brief Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u3001\u3073\u30FC\u3068\u6728)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2022-07-14 02:03:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sequence/dual_segment_tree.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/dual_segment_tree.cpp
- /library/data_structure/sequence/dual_segment_tree.cpp.html
title: "Dual Segment Tree (\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001\u3073\
  \u30FC\u3068\u6728)"
---
