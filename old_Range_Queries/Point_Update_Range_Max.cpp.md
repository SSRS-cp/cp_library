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
  bundledCode: "#line 1 \"old_Range_Queries/Point_Update_Range_Max.cpp\"\n//point\
    \ update range max\ntemplate <typename T>\nstruct segment_tree{\n\tint N;\n\t\
    vector<T> ST;\n\tsegment_tree(int n){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\t\
    N *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, -INF);\n\t}\n\tsegment_tree(vector<T>\
    \ A){\n\t\tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\
    \t}\n\t\tST = vector<T>(N * 2 - 1, -INF);\n\t\tfor (int i = 0; i < n; i++){\n\t\
    \t\tST[N - 1 + i] = A[i];\n\t\t}\n\t\tfor (int i = N - 2; i >= 0; i--){\n\t\t\t\
    ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t}\n\tT operator [](int k){\n\
    \t\treturn ST[N - 1 + k];\n\t}\n\tvoid update(int k, T x){\n\t\tk += N - 1;\n\t\
    \tST[k] = x;\n\t\twhile (k > 0){\n\t\t\tk = (k - 1) / 2;\n\t\t\tST[k] = max(ST[k\
    \ * 2 + 1], ST[k * 2 + 2]);\n\t\t}\n\t}\n\tT range_max(int L, int R, int i, int\
    \ l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn -INF;\n\t\t} else if (L\
    \ <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint m = (l + r) /\
    \ 2;\n\t\t\treturn max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2\
    \ + 2, m, r));\n\t\t}\n\t}\n\tT range_max(int L, int R){\n\t\treturn range_max(L,\
    \ R, 0, 0, N);\n\t}\n\tT all(){\n\t\treturn ST[0];\n\t}\n};\n"
  code: "//point update range max\ntemplate <typename T>\nstruct segment_tree{\n\t\
    int N;\n\tvector<T> ST;\n\tsegment_tree(int n){\n\t\tN = 1;\n\t\twhile (N < n){\n\
    \t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, -INF);\n\t}\n\tsegment_tree(vector<T>\
    \ A){\n\t\tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\
    \t}\n\t\tST = vector<T>(N * 2 - 1, -INF);\n\t\tfor (int i = 0; i < n; i++){\n\t\
    \t\tST[N - 1 + i] = A[i];\n\t\t}\n\t\tfor (int i = N - 2; i >= 0; i--){\n\t\t\t\
    ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t}\n\tT operator [](int k){\n\
    \t\treturn ST[N - 1 + k];\n\t}\n\tvoid update(int k, T x){\n\t\tk += N - 1;\n\t\
    \tST[k] = x;\n\t\twhile (k > 0){\n\t\t\tk = (k - 1) / 2;\n\t\t\tST[k] = max(ST[k\
    \ * 2 + 1], ST[k * 2 + 2]);\n\t\t}\n\t}\n\tT range_max(int L, int R, int i, int\
    \ l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn -INF;\n\t\t} else if (L\
    \ <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint m = (l + r) /\
    \ 2;\n\t\t\treturn max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2\
    \ + 2, m, r));\n\t\t}\n\t}\n\tT range_max(int L, int R){\n\t\treturn range_max(L,\
    \ R, 0, 0, N);\n\t}\n\tT all(){\n\t\treturn ST[0];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Range_Queries/Point_Update_Range_Max.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Range_Queries/Point_Update_Range_Max.cpp
layout: document
redirect_from:
- /library/old_Range_Queries/Point_Update_Range_Max.cpp
- /library/old_Range_Queries/Point_Update_Range_Max.cpp.html
title: old_Range_Queries/Point_Update_Range_Max.cpp
---
