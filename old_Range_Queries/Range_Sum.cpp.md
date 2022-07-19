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
  bundledCode: "#line 1 \"old_Range_Queries/Range_Sum.cpp\"\n//Range Sum\ntemplate\
    \ <typename T>\nstruct prefix_sum{\n\tint N;\n\tvector<T> S;\n\tprefix_sum(vector<T>\
    \ A){\n\t\tN = A.size();\n\t\tS = vector<T>(N + 1, 0);\n\t\tfor (int i = 0; i\
    \ < N; i++){\n\t\t\tS[i + 1] = S[i] + A[i];\n\t\t}\n\t}\n\tT range_sum(int p,\
    \ int q){\n\t\treturn S[q] - S[p];\n\t}\n\tT all(){\n\t\treturn S[N];\n\t}\n};\n"
  code: "//Range Sum\ntemplate <typename T>\nstruct prefix_sum{\n\tint N;\n\tvector<T>\
    \ S;\n\tprefix_sum(vector<T> A){\n\t\tN = A.size();\n\t\tS = vector<T>(N + 1,\
    \ 0);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tS[i + 1] = S[i] + A[i];\n\t\t}\n\
    \t}\n\tT range_sum(int p, int q){\n\t\treturn S[q] - S[p];\n\t}\n\tT all(){\n\t\
    \treturn S[N];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Range_Queries/Range_Sum.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Range_Queries/Range_Sum.cpp
layout: document
redirect_from:
- /library/old_Range_Queries/Range_Sum.cpp
- /library/old_Range_Queries/Range_Sum.cpp.html
title: old_Range_Queries/Range_Sum.cpp
---
