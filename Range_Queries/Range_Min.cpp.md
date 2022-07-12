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
  bundledCode: "#line 1 \"Range_Queries/Range_Min.cpp\"\ntemplate <typename T>\nstruct\
    \ sparse_table{\n\tvector<vector<T>> ST;\n\tsparse_table(vector<T> &A){\n\t\t\
    int N = A.size();\n\t\tint LOG = 32 - __builtin_clz(N);\n\t\tST = vector<vector<T>>(LOG,\
    \ vector<T>(N));\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tST[0][i] = A[i];\n\t\
    \t}\n\t\tfor (int i = 0; i < LOG - 1; i++){\n\t\t\tfor (int j = 0; j < N - (1\
    \ << i); j++){\n\t\t\t\tST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);\n\t\
    \t\t}\n\t\t}\n\t}\n\tT range_min(int L, int R){\n\t\tif (L == R){\n\t\t\tretun\
    \ INF;\n\t\t}\n\t\tint d = 31 - __builtin_clz(R - L);\n\t\treturn min(ST[d][L],\
    \ ST[d][R - (1 << d)]);\n\t}\n};\n"
  code: "template <typename T>\nstruct sparse_table{\n\tvector<vector<T>> ST;\n\t\
    sparse_table(vector<T> &A){\n\t\tint N = A.size();\n\t\tint LOG = 32 - __builtin_clz(N);\n\
    \t\tST = vector<vector<T>>(LOG, vector<T>(N));\n\t\tfor (int i = 0; i < N; i++){\n\
    \t\t\tST[0][i] = A[i];\n\t\t}\n\t\tfor (int i = 0; i < LOG - 1; i++){\n\t\t\t\
    for (int j = 0; j < N - (1 << i); j++){\n\t\t\t\tST[i + 1][j] = min(ST[i][j],\
    \ ST[i][j + (1 << i)]);\n\t\t\t}\n\t\t}\n\t}\n\tT range_min(int L, int R){\n\t\
    \tif (L == R){\n\t\t\tretun INF;\n\t\t}\n\t\tint d = 31 - __builtin_clz(R - L);\n\
    \t\treturn min(ST[d][L], ST[d][R - (1 << d)]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Range_Queries/Range_Min.cpp
  requiredBy: []
  timestamp: '2021-11-14 17:54:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Range_Queries/Range_Min.cpp
layout: document
redirect_from:
- /library/Range_Queries/Range_Min.cpp
- /library/Range_Queries/Range_Min.cpp.html
title: Range_Queries/Range_Min.cpp
---
