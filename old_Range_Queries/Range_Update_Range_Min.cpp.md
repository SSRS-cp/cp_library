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
  bundledCode: "#line 1 \"old_Range_Queries/Range_Update_Range_Min.cpp\"\n//Range\
    \ Update Range Min\ntemplate <typename T>\nstruct lazy_segment_tree{\n\tint N;\n\
    \tvector<T> ST;\n\tvector<T> lazy;\n\tlazy_segment_tree(int n){\n\t\tN = 1;\n\t\
    \twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, INF);\n\t\
    \tlazy = vector<T>(N * 2 - 1, -1);\n\t}\n\tlazy_segment_tree(vector<T> A){\n\t\
    \tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\t\
    ST = vector<T>(N * 2 - 1, INF);\n\t\tlazy = vector<T>(N * 2 - 1, -1);\n\t\tfor\
    \ (int i = 0; i < n; i++){\n\t\t\tST[N - 1 + i] = A[i];\n\t\t}\n\t\tfor (int i\
    \ = N - 2; i >= 0; i--){\n\t\t\tST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);\n\t\
    \t}\n\t}\n\tvoid eval(int i){\n\t\tif (lazy[i] != -1){\n\t\t\tif (i < N - 1){\n\
    \t\t\t\tlazy[i * 2 + 1] = lazy[i];\n\t\t\t\tlazy[i * 2 + 2] = lazy[i];\n\t\t\t\
    }\n\t\t\tST[i] = lazy[i];\n\t\t\tlazy[i] = -1;\n\t\t}\n\t}\n\tvoid range_update(int\
    \ L, int R, T x, int i, int l, int r){\n\t\teval(i);\n\t\tif (R <= l || r <= L){\n\
    \t\t\treturn;\n\t\t} else if (L <= l && r <= R){\n\t\t\tlazy[i] = x;\n\t\t\teval(i);\n\
    \t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\t\trange_update(L, R, x, i * 2 +\
    \ 1, l, m);\n\t\t\trange_update(L, R, x, i * 2 + 2, m, r);\n\t\t\tST[i] = min(ST[i\
    \ * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t}\n\tvoid range_update(int L, int R, T x){\n\
    \t\treturn range_update(L, R, x, 0, 0, N);\n\t}\n\tT range_min(int L, int R, int\
    \ i, int l, int r){\n\t\teval(i);\n\t\tif (R <= l || r <= L){\n\t\t\treturn INF;\n\
    \t\t} else if (L <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint\
    \ m = (l + r) / 2;\n\t\t\treturn min(range_min(L, R, i * 2 + 1, l, m), range_min(L,\
    \ R, i * 2 + 2, m, r));\n\t\t}\n\t}\n\tT range_min(int L, int R){\n\t\treturn\
    \ range_min(L, R, 0, 0, N);\n\t}\n};\n"
  code: "//Range Update Range Min\ntemplate <typename T>\nstruct lazy_segment_tree{\n\
    \tint N;\n\tvector<T> ST;\n\tvector<T> lazy;\n\tlazy_segment_tree(int n){\n\t\t\
    N = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1,\
    \ INF);\n\t\tlazy = vector<T>(N * 2 - 1, -1);\n\t}\n\tlazy_segment_tree(vector<T>\
    \ A){\n\t\tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\
    \t}\n\t\tST = vector<T>(N * 2 - 1, INF);\n\t\tlazy = vector<T>(N * 2 - 1, -1);\n\
    \t\tfor (int i = 0; i < n; i++){\n\t\t\tST[N - 1 + i] = A[i];\n\t\t}\n\t\tfor\
    \ (int i = N - 2; i >= 0; i--){\n\t\t\tST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);\n\
    \t\t}\n\t}\n\tvoid eval(int i){\n\t\tif (lazy[i] != -1){\n\t\t\tif (i < N - 1){\n\
    \t\t\t\tlazy[i * 2 + 1] = lazy[i];\n\t\t\t\tlazy[i * 2 + 2] = lazy[i];\n\t\t\t\
    }\n\t\t\tST[i] = lazy[i];\n\t\t\tlazy[i] = -1;\n\t\t}\n\t}\n\tvoid range_update(int\
    \ L, int R, T x, int i, int l, int r){\n\t\teval(i);\n\t\tif (R <= l || r <= L){\n\
    \t\t\treturn;\n\t\t} else if (L <= l && r <= R){\n\t\t\tlazy[i] = x;\n\t\t\teval(i);\n\
    \t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\t\trange_update(L, R, x, i * 2 +\
    \ 1, l, m);\n\t\t\trange_update(L, R, x, i * 2 + 2, m, r);\n\t\t\tST[i] = min(ST[i\
    \ * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t}\n\tvoid range_update(int L, int R, T x){\n\
    \t\treturn range_update(L, R, x, 0, 0, N);\n\t}\n\tT range_min(int L, int R, int\
    \ i, int l, int r){\n\t\teval(i);\n\t\tif (R <= l || r <= L){\n\t\t\treturn INF;\n\
    \t\t} else if (L <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint\
    \ m = (l + r) / 2;\n\t\t\treturn min(range_min(L, R, i * 2 + 1, l, m), range_min(L,\
    \ R, i * 2 + 2, m, r));\n\t\t}\n\t}\n\tT range_min(int L, int R){\n\t\treturn\
    \ range_min(L, R, 0, 0, N);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Range_Queries/Range_Update_Range_Min.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Range_Queries/Range_Update_Range_Min.cpp
layout: document
redirect_from:
- /library/old_Range_Queries/Range_Update_Range_Min.cpp
- /library/old_Range_Queries/Range_Update_Range_Min.cpp.html
title: old_Range_Queries/Range_Update_Range_Min.cpp
---
