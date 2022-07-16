---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u3073\u30FC\
      \u3068\u6728)"
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/dual_segment_tree.hpp\"\n/**\n *\
    \ @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u3073\u30FC\u3068\u6728\
    )\n*/\ntemplate <typename T>\nstruct dual_segment_tree{\n  int N;\n  vector<T>\
    \ ST;\n  function<T(T, T)> f;\n  T E;\n  dual_segment_tree(int n, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    N = 1;\n    while (N < n){\n      N *= 2;\n  \
    \  }\n    ST = vector<T>(N * 2 - 1, E);\n  }\n  dual_segment_tree(vector<T> A,\
    \ function<T(T, T)> f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n\
    \    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n\
    \    for (int i = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n  }\n \
    \ void push(int i){\n    if (i < N - 1){\n      ST[i * 2 + 1] = f(ST[i * 2 + 1],\
    \ ST[i]);\n      ST[i * 2 + 2] = f(ST[i * 2 + 2], ST[i]);\n      ST[i] = E;\n\
    \    }\n  }\n  T operator [](int k){\n    int v = 0;\n    for (int i = N / 2;\
    \ i >= 1; i >>= 1){\n      push(v);\n      if ((k & i) == 0){\n        v = v *\
    \ 2 + 1;\n      } else {\n        v = v * 2 + 2;\n      }\n    }\n    return ST[v];\n\
    \  }\n  void range_apply(int L, int R, T x, int i, int l, int r){\n    if (r <=\
    \ L || R <= l){\n    } else if (L <= l && r <= R){\n      ST[i] = f(ST[i], x);\n\
    \    } else {\n      push(i);\n      int m = (l + r) / 2;\n      range_apply(L,\
    \ R, x, i * 2 + 1, l, m);\n      range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n\
    \  }\n  void range_apply(int L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n\
    \  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \ (\u3073\u30FC\u3068\u6728)\n*/\ntemplate <typename T>\nstruct dual_segment_tree{\n\
    \  int N;\n  vector<T> ST;\n  function<T(T, T)> f;\n  T E;\n  dual_segment_tree(int\
    \ n, function<T(T, T)> f, T E): f(f), E(E){\n    N = 1;\n    while (N < n){\n\
    \      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n  }\n  dual_segment_tree(vector<T>\
    \ A, function<T(T, T)> f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n\
    \    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n\
    \    for (int i = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n  }\n \
    \ void push(int i){\n    if (i < N - 1){\n      ST[i * 2 + 1] = f(ST[i * 2 + 1],\
    \ ST[i]);\n      ST[i * 2 + 2] = f(ST[i * 2 + 2], ST[i]);\n      ST[i] = E;\n\
    \    }\n  }\n  T operator [](int k){\n    int v = 0;\n    for (int i = N / 2;\
    \ i >= 1; i >>= 1){\n      push(v);\n      if ((k & i) == 0){\n        v = v *\
    \ 2 + 1;\n      } else {\n        v = v * 2 + 2;\n      }\n    }\n    return ST[v];\n\
    \  }\n  void range_apply(int L, int R, T x, int i, int l, int r){\n    if (r <=\
    \ L || R <= l){\n    } else if (L <= l && r <= R){\n      ST[i] = f(ST[i], x);\n\
    \    } else {\n      push(i);\n      int m = (l + r) / 2;\n      range_apply(L,\
    \ R, x, i * 2 + 1, l, m);\n      range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n\
    \  }\n  void range_apply(int L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sequence/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/dual_segment_tree.hpp
- /library/data_structure/sequence/dual_segment_tree.hpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u3073\u30FC\u3068\u6728\
  )"
---
