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
  bundledCode: "#line 1 \"Dynamic_Programming/Longest_Common_Subsequence.cpp\"\nint\
    \ longest_common_subsequence_length(string &S, string &T){\n\tvector<vector<int>>\
    \ dp(S.size() + 1, vector<int>(T.size() + 1, 0));\n\tfor (int i = 0; i < S.size();\
    \ i++){\n\t\tfor (int j = 0; j < T.size(); j++){\n\t\t\tif (S[i] == T[j]){\n\t\
    \t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\t\t} else {\n\t\t\t\tdp[i + 1][j +\
    \ 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dp[S.size()][T.size()];\n\
    }\nstring longest_common_subsequence(string &S, string &T){\n\tvector<vector<int>>\
    \ dp(S.size() + 1, vector<int>(T.size() + 1, 0));\n\tfor (int i = 0; i < S.size();\
    \ i++){\n\t\tfor (int j = 0; j < T.size(); j++){\n\t\t\tif (S[i] == T[j]){\n\t\
    \t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\t\t} else {\n\t\t\t\tdp[i + 1][j +\
    \ 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\t}\n\t\t}\n\t}\n\tstring ans;\n\t\
    int i = S.size();\n\tint j = T.size();\n\twhile (dp[i][j] > 0){\n\t\tif (dp[i\
    \ - 1][j] == dp[i][j]){\n\t\t\ti--;\n\t\t} else if (dp[i][j - 1] == dp[i][j]){\n\
    \t\t\tj--;\n\t\t} else {\n\t\t\ti--;\n\t\t\tj--;\n\t\t\tans.push_back(S[i]);\n\
    \t\t}\n\t}\n\treverse(ans.begin(), ans.end());\n\treturn ans;\n}\nint longest_common_subsequence_length(vector<int>\
    \ &A, vector<int> &B){\n\tvector<vector<int>> dp(A.size() + 1, vector<int>(B.size()\
    \ + 1, 0));\n\tfor (int i = 0; i < A.size(); i++){\n\t\tfor (int j = 0; j < B.size();\
    \ j++){\n\t\t\tif (A[i] == B[j]){\n\t\t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\
    \t\t} else {\n\t\t\t\tdp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\
    \t}\n\t\t}\n\t}\n\treturn dp[A.size()][B.size()];\n}\nvector<int> longest_common_subsequence(vector<int>\
    \ &A, vector<int> &B){\n\tvector<vector<int>> dp(A.size() + 1, vector<int>(B.size()\
    \ + 1, 0));\n\tfor (int i = 0; i < A.size(); i++){\n\t\tfor (int j = 0; j < B.size();\
    \ j++){\n\t\t\tif (A[i] == B[j]){\n\t\t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\
    \t\t} else {\n\t\t\t\tdp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\
    \t}\n\t\t}\n\t}\n\tvector<int> ans;\n\tint i = A.size();\n\tint j = B.size();\n\
    \twhile (dp[i][j] > 0){\n\t\tif (dp[i - 1][j] == dp[i][j]){\n\t\t\ti--;\n\t\t\
    } else if (dp[i][j - 1] == dp[i][j]){\n\t\t\tj--;\n\t\t} else {\n\t\t\ti--;\n\t\
    \t\tj--;\n\t\t\tans.push_back(A[i]);\n\t\t}\n\t}\n\treverse(ans.begin(), ans.end());\n\
    \treturn ans;\n}\n"
  code: "int longest_common_subsequence_length(string &S, string &T){\n\tvector<vector<int>>\
    \ dp(S.size() + 1, vector<int>(T.size() + 1, 0));\n\tfor (int i = 0; i < S.size();\
    \ i++){\n\t\tfor (int j = 0; j < T.size(); j++){\n\t\t\tif (S[i] == T[j]){\n\t\
    \t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\t\t} else {\n\t\t\t\tdp[i + 1][j +\
    \ 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dp[S.size()][T.size()];\n\
    }\nstring longest_common_subsequence(string &S, string &T){\n\tvector<vector<int>>\
    \ dp(S.size() + 1, vector<int>(T.size() + 1, 0));\n\tfor (int i = 0; i < S.size();\
    \ i++){\n\t\tfor (int j = 0; j < T.size(); j++){\n\t\t\tif (S[i] == T[j]){\n\t\
    \t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\t\t} else {\n\t\t\t\tdp[i + 1][j +\
    \ 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\t}\n\t\t}\n\t}\n\tstring ans;\n\t\
    int i = S.size();\n\tint j = T.size();\n\twhile (dp[i][j] > 0){\n\t\tif (dp[i\
    \ - 1][j] == dp[i][j]){\n\t\t\ti--;\n\t\t} else if (dp[i][j - 1] == dp[i][j]){\n\
    \t\t\tj--;\n\t\t} else {\n\t\t\ti--;\n\t\t\tj--;\n\t\t\tans.push_back(S[i]);\n\
    \t\t}\n\t}\n\treverse(ans.begin(), ans.end());\n\treturn ans;\n}\nint longest_common_subsequence_length(vector<int>\
    \ &A, vector<int> &B){\n\tvector<vector<int>> dp(A.size() + 1, vector<int>(B.size()\
    \ + 1, 0));\n\tfor (int i = 0; i < A.size(); i++){\n\t\tfor (int j = 0; j < B.size();\
    \ j++){\n\t\t\tif (A[i] == B[j]){\n\t\t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\
    \t\t} else {\n\t\t\t\tdp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\
    \t}\n\t\t}\n\t}\n\treturn dp[A.size()][B.size()];\n}\nvector<int> longest_common_subsequence(vector<int>\
    \ &A, vector<int> &B){\n\tvector<vector<int>> dp(A.size() + 1, vector<int>(B.size()\
    \ + 1, 0));\n\tfor (int i = 0; i < A.size(); i++){\n\t\tfor (int j = 0; j < B.size();\
    \ j++){\n\t\t\tif (A[i] == B[j]){\n\t\t\t\tdp[i + 1][j + 1] = dp[i][j] + 1;\n\t\
    \t\t} else {\n\t\t\t\tdp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);\n\t\t\
    \t}\n\t\t}\n\t}\n\tvector<int> ans;\n\tint i = A.size();\n\tint j = B.size();\n\
    \twhile (dp[i][j] > 0){\n\t\tif (dp[i - 1][j] == dp[i][j]){\n\t\t\ti--;\n\t\t\
    } else if (dp[i][j - 1] == dp[i][j]){\n\t\t\tj--;\n\t\t} else {\n\t\t\ti--;\n\t\
    \t\tj--;\n\t\t\tans.push_back(A[i]);\n\t\t}\n\t}\n\treverse(ans.begin(), ans.end());\n\
    \treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/Longest_Common_Subsequence.cpp
  requiredBy: []
  timestamp: '2020-03-22 15:08:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/Longest_Common_Subsequence.cpp
layout: document
redirect_from:
- /library/Dynamic_Programming/Longest_Common_Subsequence.cpp
- /library/Dynamic_Programming/Longest_Common_Subsequence.cpp.html
title: Dynamic_Programming/Longest_Common_Subsequence.cpp
---
