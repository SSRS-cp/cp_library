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
  bundledCode: "#line 1 \"Math/Matrix_Multiplication.cpp\"\nvector<vector<long long>>\
    \ matmul(vector<vector<long long>> A, vector<vector<long long>> B){\n\tint N =\
    \ A.size();\n\tvector<vector<long long>> ans(N, vector<long long>(N, 0));\n\t\
    for (int i = 0; i < N; i++){\n\t\tfor (int j = 0; j < N; j++){\n\t\t\tfor (int\
    \ k = 0; k < N; k++){\n\t\t\t\tans[i][k] += A[i][j] * B[j][k];\n\t\t\t\tans[i][k]\
    \ %= MOD;\n\t\t\t}\n\t\t}\n\t}\n\treturn ans;\n}\nvector<vector<long long>> matexp(vector<vector<long\
    \ long>> A, long long b){\n\tint N = A.size();\n\tvector<vector<long long>> ans(N,\
    \ vector<long long>(N, 0));\n\tfor (int i = 0; i < N; i++){\n\t\tans[i][i] = 1;\n\
    \t}\n\twhile (b > 0){\n\t\tif (b % 2 == 1){\n\t\t\tans = matmul(ans, A);\n\t\t\
    }\n\t\tA = matmul(A, A);\n\t\tb /= 2;\n\t}\n\treturn ans;\n}\n"
  code: "vector<vector<long long>> matmul(vector<vector<long long>> A, vector<vector<long\
    \ long>> B){\n\tint N = A.size();\n\tvector<vector<long long>> ans(N, vector<long\
    \ long>(N, 0));\n\tfor (int i = 0; i < N; i++){\n\t\tfor (int j = 0; j < N; j++){\n\
    \t\t\tfor (int k = 0; k < N; k++){\n\t\t\t\tans[i][k] += A[i][j] * B[j][k];\n\t\
    \t\t\tans[i][k] %= MOD;\n\t\t\t}\n\t\t}\n\t}\n\treturn ans;\n}\nvector<vector<long\
    \ long>> matexp(vector<vector<long long>> A, long long b){\n\tint N = A.size();\n\
    \tvector<vector<long long>> ans(N, vector<long long>(N, 0));\n\tfor (int i = 0;\
    \ i < N; i++){\n\t\tans[i][i] = 1;\n\t}\n\twhile (b > 0){\n\t\tif (b % 2 == 1){\n\
    \t\t\tans = matmul(ans, A);\n\t\t}\n\t\tA = matmul(A, A);\n\t\tb /= 2;\n\t}\n\t\
    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix_Multiplication.cpp
  requiredBy: []
  timestamp: '2020-10-08 22:27:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Matrix_Multiplication.cpp
layout: document
redirect_from:
- /library/Math/Matrix_Multiplication.cpp
- /library/Math/Matrix_Multiplication.cpp.html
title: Math/Matrix_Multiplication.cpp
---
