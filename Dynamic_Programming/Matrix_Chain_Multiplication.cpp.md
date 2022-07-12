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
  bundledCode: "#line 1 \"Dynamic_Programming/Matrix_Chain_Multiplication.cpp\"\n\
    long long matrix_chain_multiplication(vector<long long> &A){\n\tint n = A.size()\
    \ - 1;\n\tvector<vector<long long>> dp(n, vector<long long>(n, INF));\n\tfor (int\
    \ i = 0; i < n; i++){\n\t\tdp[i][i] = 0;\n\t}\n\tfor (int i = 1; i < n; i++){\n\
    \t\tfor (int j = 0; j < n - i; j++){\n\t\t\tfor (int k = j; k < j + i; k++){\n\
    \t\t\t\tdp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + A[j] *\
    \ A[k + 1] * A[j + i + 1]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dp[0][n - 1];\n}\n"
  code: "long long matrix_chain_multiplication(vector<long long> &A){\n\tint n = A.size()\
    \ - 1;\n\tvector<vector<long long>> dp(n, vector<long long>(n, INF));\n\tfor (int\
    \ i = 0; i < n; i++){\n\t\tdp[i][i] = 0;\n\t}\n\tfor (int i = 1; i < n; i++){\n\
    \t\tfor (int j = 0; j < n - i; j++){\n\t\t\tfor (int k = j; k < j + i; k++){\n\
    \t\t\t\tdp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + A[j] *\
    \ A[k + 1] * A[j + i + 1]);\n\t\t\t}\n\t\t}\n\t}\n\treturn dp[0][n - 1];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/Matrix_Chain_Multiplication.cpp
  requiredBy: []
  timestamp: '2020-03-22 15:09:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/Matrix_Chain_Multiplication.cpp
layout: document
redirect_from:
- /library/Dynamic_Programming/Matrix_Chain_Multiplication.cpp
- /library/Dynamic_Programming/Matrix_Chain_Multiplication.cpp.html
title: Dynamic_Programming/Matrix_Chain_Multiplication.cpp
---