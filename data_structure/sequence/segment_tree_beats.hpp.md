---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library_checker/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tre Beats
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/segment_tree_beats.hpp\"\n/**\n\
    \ * @brief Segment Tre Beats\n*/\ntemplate <typename T, typename F>\nstruct segment_tree_beats{\n\
    \  int N;\n  vector<T> ST;\n  vector<F> lazy;\n  function<T(T, T)> op;\n  function<T(F,\
    \ T)> mp;\n  function<F(F, F)> comp;\n  T E;\n  F id;\n  segment_tree_beats(vector<T>\
    \ &A, function<T(T, T)> op, function<T(F, T)> mp, function<F(F, F)> comp, T E,\
    \ F id): op(op), mp(mp), comp(comp), E(E), id(id){\n    int n = A.size();\n  \
    \  N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2\
    \ - 1, E);\n    for (int i = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n  \
    \  }\n    for (int i = N - 2; i >= 0; i--){\n      update(i);\n    }\n    lazy\
    \ = vector<F>(N * 2 - 1, id);\n  }\n  void update(int i){\n    ST[i] = op(ST[i\
    \ * 2 + 1], ST[i * 2 + 2]);\n  }\n  void push(int i){\n    ST[i] = mp(lazy[i],\
    \ ST[i]);\n    if (i < N - 1){\n      lazy[i * 2 + 1] = comp(lazy[i], lazy[i *\
    \ 2 + 1]);\n      lazy[i * 2 + 2] = comp(lazy[i], lazy[i * 2 + 2]);\n      if\
    \ (ST[i].fail){\n        push(i * 2 + 1);\n        push(i * 2 + 2);\n        update(i);\n\
    \      }\n    }\n    lazy[i] = id;\n  }\n  void range_apply(int L, int R, F f,\
    \ int i, int l, int r){\n    push(i);\n    if (r <= L || R <= l){\n      return;\n\
    \    } else if (L <= l && r <= R){\n      lazy[i] = f;\n      push(i);\n    }\
    \ else {\n      int m = (l + r) / 2;\n      range_apply(L, R, f, i * 2 + 1, l,\
    \ m);\n      range_apply(L, R, f, i * 2 + 2, m, r);\n      update(i);\n    }\n\
    \  }\n  void range_apply(int L, int R, F f){\n    range_apply(L, R, f, 0, 0, N);\n\
    \  }\n  T range_fold(int L, int R, int i, int l, int r){\n    push(i);\n    if\
    \ (r <= L || R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n  \
    \    return ST[i];\n    } else {\n      int m = (l + r) / 2;\n      return op(range_fold(L,\
    \ R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));\n    }\n  }\n  T range_fold(int\
    \ L, int R){\n    return range_fold(L, R, 0, 0, N);\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief Segment Tre Beats\n*/\ntemplate <typename T,\
    \ typename F>\nstruct segment_tree_beats{\n  int N;\n  vector<T> ST;\n  vector<F>\
    \ lazy;\n  function<T(T, T)> op;\n  function<T(F, T)> mp;\n  function<F(F, F)>\
    \ comp;\n  T E;\n  F id;\n  segment_tree_beats(vector<T> &A, function<T(T, T)>\
    \ op, function<T(F, T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp),\
    \ comp(comp), E(E), id(id){\n    int n = A.size();\n    N = 1;\n    while (N <\
    \ n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i\
    \ = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n    for (int i = N -\
    \ 2; i >= 0; i--){\n      update(i);\n    }\n    lazy = vector<F>(N * 2 - 1, id);\n\
    \  }\n  void update(int i){\n    ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n \
    \ }\n  void push(int i){\n    ST[i] = mp(lazy[i], ST[i]);\n    if (i < N - 1){\n\
    \      lazy[i * 2 + 1] = comp(lazy[i], lazy[i * 2 + 1]);\n      lazy[i * 2 + 2]\
    \ = comp(lazy[i], lazy[i * 2 + 2]);\n      if (ST[i].fail){\n        push(i *\
    \ 2 + 1);\n        push(i * 2 + 2);\n        update(i);\n      }\n    }\n    lazy[i]\
    \ = id;\n  }\n  void range_apply(int L, int R, F f, int i, int l, int r){\n  \
    \  push(i);\n    if (r <= L || R <= l){\n      return;\n    } else if (L <= l\
    \ && r <= R){\n      lazy[i] = f;\n      push(i);\n    } else {\n      int m =\
    \ (l + r) / 2;\n      range_apply(L, R, f, i * 2 + 1, l, m);\n      range_apply(L,\
    \ R, f, i * 2 + 2, m, r);\n      update(i);\n    }\n  }\n  void range_apply(int\
    \ L, int R, F f){\n    range_apply(L, R, f, 0, 0, N);\n  }\n  T range_fold(int\
    \ L, int R, int i, int l, int r){\n    push(i);\n    if (r <= L || R <= l){\n\
    \      return E;\n    } else if (L <= l && r <= R){\n      return ST[i];\n   \
    \ } else {\n      int m = (l + r) / 2;\n      return op(range_fold(L, R, i * 2\
    \ + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));\n    }\n  }\n  T range_fold(int\
    \ L, int R){\n    return range_fold(L, R, 0, 0, N);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/segment_tree_beats.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: data_structure/sequence/segment_tree_beats.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/segment_tree_beats.hpp
- /library/data_structure/sequence/segment_tree_beats.hpp.html
title: Segment Tre Beats
---
