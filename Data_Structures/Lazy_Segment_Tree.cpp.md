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
  bundledCode: "#line 1 \"Data_Structures/Lazy_Segment_Tree.cpp\"\ntemplate <typename\
    \ T, typename F>\nstruct lazy_segment_tree{\n\tint N;\n\tvector<T> ST;\n\tvector<F>\
    \ lazy;\n\tfunction<T(T, T)> op;\n\tfunction<T(F, T)> mp;\n\tfunction<F(F, F)>\
    \ comp;\n\tT E;\n\tF id;\n\tlazy_segment_tree(int n, function<T(T, T)> op, function<T(F,\
    \ T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E),\
    \ id(id){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N\
    \ * 2 - 1, E);\n\t\tfor (int i = N - 2; i >= 0; i--){\n\t\t\tST[i] = op(ST[i *\
    \ 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t\tlazy = vector<F>(N * 2 - 1, id);\n\t}\n\t\
    lazy_segment_tree(vector<T> &A, function<T(T, T)> op, function<T(F, T)> mp, function<F(F,\
    \ F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E), id(id){\n\t\tint n =\
    \ A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N\
    \ * 2 - 1, E);\n\t\tfor (int i = 0; i < n; i++){\n\t\t\tST[N - 1 + i] = A[i];\n\
    \t\t}\n\t\tfor (int i = N - 2; i >= 0; i--){\n\t\t\tST[i] = op(ST[i * 2 + 1],\
    \ ST[i * 2 + 2]);\n\t\t}\n\t\tlazy = vector<F>(N * 2 - 1, id);\n\t}\n\tvoid eval(int\
    \ i){\n\t\tif (i < N - 1){\n\t\t\tlazy[i * 2 + 1] = comp(lazy[i * 2 + 1], lazy[i]);\n\
    \t\t\tlazy[i * 2 + 2] = comp(lazy[i * 2 + 2], lazy[i]);\n\t\t}\n\t\tST[i] = mp(lazy[i],\
    \ ST[i]);\n\t\tlazy[i] = id;\n\t}\n\tvoid range_apply(int L, int R, F f, int i,\
    \ int l, int r){\n\t\teval(i);\n\t\tif (r <= L || R <= l){\n\t\t\treturn;\n\t\t\
    } else if (L <= l && r <= R){\n\t\t\tlazy[i] = f;\n\t\t\teval(i);\n\t\t} else\
    \ {\n\t\t\tint m = (l + r) / 2;\n\t\t\trange_apply(L, R, f, i * 2 + 1, l, m);\n\
    \t\t\trange_apply(L, R, f, i * 2 + 2, m, r);\n\t\t\tST[i] = op(ST[i * 2 + 1],\
    \ ST[i * 2 + 2]);\n\t\t}\n\t}\n\tvoid range_apply(int L, int R, F f){\n\t\trange_apply(L,\
    \ R, f, 0, 0, N);\n\t}\n\tT range_fold(int L, int R, int i, int l, int r){\n\t\
    \teval(i);\n\t\tif (r <= L || R <= l){\n\t\t\treturn E;\n\t\t} else if (L <= l\
    \ && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\
    \t\t\treturn op(range_fold(L, R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2,\
    \ m, r));\n\t\t}\n\t}\n\tT range_fold(int L, int R){\n\t\treturn range_fold(L,\
    \ R, 0, 0, N);\n\t}\n};\n"
  code: "template <typename T, typename F>\nstruct lazy_segment_tree{\n\tint N;\n\t\
    vector<T> ST;\n\tvector<F> lazy;\n\tfunction<T(T, T)> op;\n\tfunction<T(F, T)>\
    \ mp;\n\tfunction<F(F, F)> comp;\n\tT E;\n\tF id;\n\tlazy_segment_tree(int n,\
    \ function<T(T, T)> op, function<T(F, T)> mp, function<F(F, F)> comp, T E, F id):\
    \ op(op), mp(mp), comp(comp), E(E), id(id){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\
    \t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, E);\n\t\tfor (int i = N - 2;\
    \ i >= 0; i--){\n\t\t\tST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t\t\
    lazy = vector<F>(N * 2 - 1, id);\n\t}\n\tlazy_segment_tree(vector<T> &A, function<T(T,\
    \ T)> op, function<T(F, T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp),\
    \ comp(comp), E(E), id(id){\n\t\tint n = A.size();\n\t\tN = 1;\n\t\twhile (N <\
    \ n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, E);\n\t\tfor (int i\
    \ = 0; i < n; i++){\n\t\t\tST[N - 1 + i] = A[i];\n\t\t}\n\t\tfor (int i = N -\
    \ 2; i >= 0; i--){\n\t\t\tST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t\
    \tlazy = vector<F>(N * 2 - 1, id);\n\t}\n\tvoid eval(int i){\n\t\tif (i < N -\
    \ 1){\n\t\t\tlazy[i * 2 + 1] = comp(lazy[i * 2 + 1], lazy[i]);\n\t\t\tlazy[i *\
    \ 2 + 2] = comp(lazy[i * 2 + 2], lazy[i]);\n\t\t}\n\t\tST[i] = mp(lazy[i], ST[i]);\n\
    \t\tlazy[i] = id;\n\t}\n\tvoid range_apply(int L, int R, F f, int i, int l, int\
    \ r){\n\t\teval(i);\n\t\tif (r <= L || R <= l){\n\t\t\treturn;\n\t\t} else if\
    \ (L <= l && r <= R){\n\t\t\tlazy[i] = f;\n\t\t\teval(i);\n\t\t} else {\n\t\t\t\
    int m = (l + r) / 2;\n\t\t\trange_apply(L, R, f, i * 2 + 1, l, m);\n\t\t\trange_apply(L,\
    \ R, f, i * 2 + 2, m, r);\n\t\t\tST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n\t\
    \t}\n\t}\n\tvoid range_apply(int L, int R, F f){\n\t\trange_apply(L, R, f, 0,\
    \ 0, N);\n\t}\n\tT range_fold(int L, int R, int i, int l, int r){\n\t\teval(i);\n\
    \t\tif (r <= L || R <= l){\n\t\t\treturn E;\n\t\t} else if (L <= l && r <= R){\n\
    \t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\t\treturn op(range_fold(L,\
    \ R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));\n\t\t}\n\t}\n\tT range_fold(int\
    \ L, int R){\n\t\treturn range_fold(L, R, 0, 0, N);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Lazy_Segment_Tree.cpp
  requiredBy: []
  timestamp: '2021-02-04 00:58:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Lazy_Segment_Tree.cpp
layout: document
redirect_from:
- /library/Data_Structures/Lazy_Segment_Tree.cpp
- /library/Data_Structures/Lazy_Segment_Tree.cpp.html
title: Data_Structures/Lazy_Segment_Tree.cpp
---
