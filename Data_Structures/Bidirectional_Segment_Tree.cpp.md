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
  bundledCode: "#line 1 \"Data_Structures/Bidirectional_Segment_Tree.cpp\"\ntemplate\
    \ <typename T>\nstruct bidirectional_segment_tree{\n\tint N;\n\tvector<array<T,\
    \ 2>> ST;\n\tfunction<T(T, T)> f;\n\tT E;\n\tbidirectional_segment_tree(vector<T>\
    \ A, function<T(T, T)> f, T E): f(f), E(E){\n\t\tint n = A.size();\n\t\tN = 1;\n\
    \t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<array<T, 2>>(N * 2 -\
    \ 1, array<T, 2>{E, E});\n\t\tfor (int i = 0; i < n; i++){\n\t\t\tST[N - 1 + i][0]\
    \ = A[i];\n\t\t\tST[N - 1 + i][1] = A[i];\n\t\t}\n\t\tfor (int i = N - 2; i >=\
    \ 0; i--){\n\t\t\tST[i][0] = f(ST[i * 2 + 1][0], ST[i * 2 + 2][0]);\n\t\t\tST[i][1]\
    \ = f(ST[i * 2 + 2][1], ST[i * 2 + 1][1]);\n\t\t}\n\t}\n\tT operator [](int k){\n\
    \t\treturn ST[N - 1 + k][0];\n\t}\n\tvoid update(int k, T x){\n\t\tk += N - 1;\n\
    \t\tST[k][0] = x;\n\t\tST[k][1] = x;\n\t\twhile (k > 0){\n\t\t\tk = (k - 1) /\
    \ 2;\n\t\t\tST[k][0] = f(ST[k * 2 + 1][0], ST[k * 2 + 2][0]);\n\t\t\tST[k][1]\
    \ = f(ST[k * 2 + 2][1], ST[k * 2 + 1][1]);\n\t\t}\n\t}\n\tT query(int L, int R,\
    \ int i, int l, int r, int d){\n\t\tif (R <= l || r <= L){\n\t\t\treturn E;\n\t\
    \t} else if (L <= l && r <= R){\n\t\t\treturn ST[i][d];\n\t\t} else {\n\t\t\t\
    int m = (l + r) / 2;\n\t\t\tif (d == 0){\n\t\t\t\treturn f(query(L, R, i * 2 +\
    \ 1, l, m, d), query(L, R, i * 2 + 2, m, r, d));\n\t\t\t} else {\n\t\t\t\treturn\
    \ f(query(L, R, i * 2 + 2, m, r, d), query(L, R, i * 2 + 1, l, m, d));\n\t\t\t\
    }\n\t\t}\n\t}\n\tT query(int L, int R, int d){\n\t\treturn query(L, R, 0, 0, N,\
    \ d);\n\t}\n};\n"
  code: "template <typename T>\nstruct bidirectional_segment_tree{\n\tint N;\n\tvector<array<T,\
    \ 2>> ST;\n\tfunction<T(T, T)> f;\n\tT E;\n\tbidirectional_segment_tree(vector<T>\
    \ A, function<T(T, T)> f, T E): f(f), E(E){\n\t\tint n = A.size();\n\t\tN = 1;\n\
    \t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<array<T, 2>>(N * 2 -\
    \ 1, array<T, 2>{E, E});\n\t\tfor (int i = 0; i < n; i++){\n\t\t\tST[N - 1 + i][0]\
    \ = A[i];\n\t\t\tST[N - 1 + i][1] = A[i];\n\t\t}\n\t\tfor (int i = N - 2; i >=\
    \ 0; i--){\n\t\t\tST[i][0] = f(ST[i * 2 + 1][0], ST[i * 2 + 2][0]);\n\t\t\tST[i][1]\
    \ = f(ST[i * 2 + 2][1], ST[i * 2 + 1][1]);\n\t\t}\n\t}\n\tT operator [](int k){\n\
    \t\treturn ST[N - 1 + k][0];\n\t}\n\tvoid update(int k, T x){\n\t\tk += N - 1;\n\
    \t\tST[k][0] = x;\n\t\tST[k][1] = x;\n\t\twhile (k > 0){\n\t\t\tk = (k - 1) /\
    \ 2;\n\t\t\tST[k][0] = f(ST[k * 2 + 1][0], ST[k * 2 + 2][0]);\n\t\t\tST[k][1]\
    \ = f(ST[k * 2 + 2][1], ST[k * 2 + 1][1]);\n\t\t}\n\t}\n\tT query(int L, int R,\
    \ int i, int l, int r, int d){\n\t\tif (R <= l || r <= L){\n\t\t\treturn E;\n\t\
    \t} else if (L <= l && r <= R){\n\t\t\treturn ST[i][d];\n\t\t} else {\n\t\t\t\
    int m = (l + r) / 2;\n\t\t\tif (d == 0){\n\t\t\t\treturn f(query(L, R, i * 2 +\
    \ 1, l, m, d), query(L, R, i * 2 + 2, m, r, d));\n\t\t\t} else {\n\t\t\t\treturn\
    \ f(query(L, R, i * 2 + 2, m, r, d), query(L, R, i * 2 + 1, l, m, d));\n\t\t\t\
    }\n\t\t}\n\t}\n\tT query(int L, int R, int d){\n\t\treturn query(L, R, 0, 0, N,\
    \ d);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Bidirectional_Segment_Tree.cpp
  requiredBy: []
  timestamp: '2020-06-06 22:03:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Bidirectional_Segment_Tree.cpp
layout: document
redirect_from:
- /library/Data_Structures/Bidirectional_Segment_Tree.cpp
- /library/Data_Structures/Bidirectional_Segment_Tree.cpp.html
title: Data_Structures/Bidirectional_Segment_Tree.cpp
---
