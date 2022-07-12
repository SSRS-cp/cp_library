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
  bundledCode: "#line 1 \"Range_Queries/Range_Add_Range_Sum.cpp\"\n//range add range\
    \ sum\ntemplate <typename T>\nstruct lazy_segment_tree{\n\tint N;\n\tvector<T>\
    \ ST;\n\tvector<T> lazy;\n\tlazy_segment_tree(int n){\n\t\tN = 1;\n\t\twhile (N\
    \ < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, 0);\n\t\tlazy = vector<T>(N\
    \ * 2 - 1, 0);\n\t}\n\tlazy_segment_tree(vector<T> &a){\n\t\tint n = a.size();\n\
    \t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2\
    \ - 1, 0);\n\t\tlazy = vector<T>(N * 2 - 1, 0);\n\t\tfor (int i = 0; i < n; i++){\n\
    \t\t\tST[N - 1 + i] = a[i];\n\t\t}\n\t\tfor (int i = N - 2; i >= 0; i--){\n\t\t\
    \tST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];\n\t\t}\n\t}\n\tvoid eval(int i){\n\t\t\
    if (i < N - 1){\n\t\t\tlazy[i * 2 + 1] += lazy[i] / 2;\n\t\t\tlazy[i * 2 + 2]\
    \ += lazy[i] / 2;\n\t\t}\n\t\tST[i] += lazy[i];\n\t\tlazy[i] = 0;\n\t}\n\tvoid\
    \ range_add(int L, int R, T x, int i, int l, int r){\n\t\teval(i);\n\t\tif (R\
    \ <= l || r <= L){\n\t\t\treturn;\n\t\t} else if (L <= l && r <= R){\n\t\t\tlazy[i]\
    \ += (r - l) * x;\n\t\t\teval(i);\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\
    \t\trange_add(L, R, x, i * 2 + 1, l, m);\n\t\t\trange_add(L, R, x, i * 2 + 2,\
    \ m, r);\n\t\t\tST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];\n\t\t}\n\t}\n\tvoid range_add(int\
    \ L, int R, T x){\n\t\trange_add(L, R, x, 0, 0, N);\n\t}\n\tT range_sum(int L,\
    \ int R, int i, int l, int r){\n\t\teval(i);\n\t\tif (R <= l || r <= L){\n\t\t\
    \treturn 0;\n\t\t} else if (L <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else\
    \ {\n\t\t\tint m = (l + r) / 2;\n\t\t\treturn range_sum(L, R, i * 2 + 1, l, m)\
    \ + range_sum(L, R, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tT range_sum(int L, int R){\n\
    \t\treturn range_sum(L, R, 0, 0, N);\n\t}\n\tT all(){\n\t\teval(0);\n\t\treturn\
    \ ST[0];\n\t}\n};\n"
  code: "//range add range sum\ntemplate <typename T>\nstruct lazy_segment_tree{\n\
    \tint N;\n\tvector<T> ST;\n\tvector<T> lazy;\n\tlazy_segment_tree(int n){\n\t\t\
    N = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1,\
    \ 0);\n\t\tlazy = vector<T>(N * 2 - 1, 0);\n\t}\n\tlazy_segment_tree(vector<T>\
    \ &a){\n\t\tint n = a.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\
    \t\t}\n\t\tST = vector<T>(N * 2 - 1, 0);\n\t\tlazy = vector<T>(N * 2 - 1, 0);\n\
    \t\tfor (int i = 0; i < n; i++){\n\t\t\tST[N - 1 + i] = a[i];\n\t\t}\n\t\tfor\
    \ (int i = N - 2; i >= 0; i--){\n\t\t\tST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];\n\
    \t\t}\n\t}\n\tvoid eval(int i){\n\t\tif (i < N - 1){\n\t\t\tlazy[i * 2 + 1] +=\
    \ lazy[i] / 2;\n\t\t\tlazy[i * 2 + 2] += lazy[i] / 2;\n\t\t}\n\t\tST[i] += lazy[i];\n\
    \t\tlazy[i] = 0;\n\t}\n\tvoid range_add(int L, int R, T x, int i, int l, int r){\n\
    \t\teval(i);\n\t\tif (R <= l || r <= L){\n\t\t\treturn;\n\t\t} else if (L <= l\
    \ && r <= R){\n\t\t\tlazy[i] += (r - l) * x;\n\t\t\teval(i);\n\t\t} else {\n\t\
    \t\tint m = (l + r) / 2;\n\t\t\trange_add(L, R, x, i * 2 + 1, l, m);\n\t\t\trange_add(L,\
    \ R, x, i * 2 + 2, m, r);\n\t\t\tST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];\n\t\t\
    }\n\t}\n\tvoid range_add(int L, int R, T x){\n\t\trange_add(L, R, x, 0, 0, N);\n\
    \t}\n\tT range_sum(int L, int R, int i, int l, int r){\n\t\teval(i);\n\t\tif (R\
    \ <= l || r <= L){\n\t\t\treturn 0;\n\t\t} else if (L <= l && r <= R){\n\t\t\t\
    return ST[i];\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\t\treturn range_sum(L,\
    \ R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tT range_sum(int\
    \ L, int R){\n\t\treturn range_sum(L, R, 0, 0, N);\n\t}\n\tT all(){\n\t\teval(0);\n\
    \t\treturn ST[0];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Range_Queries/Range_Add_Range_Sum.cpp
  requiredBy: []
  timestamp: '2020-10-08 22:32:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Range_Queries/Range_Add_Range_Sum.cpp
layout: document
redirect_from:
- /library/Range_Queries/Range_Add_Range_Sum.cpp
- /library/Range_Queries/Range_Add_Range_Sum.cpp.html
title: Range_Queries/Range_Add_Range_Sum.cpp
---
