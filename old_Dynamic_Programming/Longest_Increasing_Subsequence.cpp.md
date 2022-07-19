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
  bundledCode: "#line 1 \"old_Dynamic_Programming/Longest_Increasing_Subsequence.cpp\"\
    \nint longest_increasing_subsequence_length(vector<int> &A){\n\tint N = A.size();\n\
    \tvector<int> dp(N, INF);\n\tfor (int i = 0; i < N; i++){\n\t\t*lower_bound(dp.begin(),\
    \ dp.end(), A[i]) = A[i];\n\t}\n\treturn lower_bound(dp.begin(), dp.end(), INF)\
    \ - dp.begin();\n}\n"
  code: "int longest_increasing_subsequence_length(vector<int> &A){\n\tint N = A.size();\n\
    \tvector<int> dp(N, INF);\n\tfor (int i = 0; i < N; i++){\n\t\t*lower_bound(dp.begin(),\
    \ dp.end(), A[i]) = A[i];\n\t}\n\treturn lower_bound(dp.begin(), dp.end(), INF)\
    \ - dp.begin();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Dynamic_Programming/Longest_Increasing_Subsequence.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Dynamic_Programming/Longest_Increasing_Subsequence.cpp
layout: document
redirect_from:
- /library/old_Dynamic_Programming/Longest_Increasing_Subsequence.cpp
- /library/old_Dynamic_Programming/Longest_Increasing_Subsequence.cpp.html
title: old_Dynamic_Programming/Longest_Increasing_Subsequence.cpp
---
