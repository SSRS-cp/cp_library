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
  bundledCode: "#line 1 \"Math/Bitwise_And_Convolution.cpp\"\nvector<long long> and_fwt(vector<long\
    \ long> A, bool inv){\n\tint N = A.size();\n\tfor (int i = 1; i < N; i <<= 1){\n\
    \t\tfor (int j = 0; j < N; j++){\n\t\t\tif ((j & i) == 0){\n\t\t\t\tif (!inv){\n\
    \t\t\t\t\tA[j] += A[j | i];\n\t\t\t\t\tA[j] %= MOD;\n\t\t\t\t} else {\n\t\t\t\t\
    \tA[j] -= A[j | i];\n\t\t\t\t\tA[j] += MOD;\n\t\t\t\t\tA[j] %= MOD;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t}\n\treturn A;\n}\nvector<long long> and_convolution(vector<long\
    \ long> A, vector<long long> B){\n\tint N = A.size();\n\tA = and_fwt(A, false);\n\
    \tB = and_fwt(B, false);\n\tvector<long long> C(N);\n\tfor (int i = 0; i < N;\
    \ i++){\n\t\tC[i] = A[i] * B[i] % MOD;\n\t}\n\tC = and_fwt(C, true);\n\treturn\
    \ C;\n}\n"
  code: "vector<long long> and_fwt(vector<long long> A, bool inv){\n\tint N = A.size();\n\
    \tfor (int i = 1; i < N; i <<= 1){\n\t\tfor (int j = 0; j < N; j++){\n\t\t\tif\
    \ ((j & i) == 0){\n\t\t\t\tif (!inv){\n\t\t\t\t\tA[j] += A[j | i];\n\t\t\t\t\t\
    A[j] %= MOD;\n\t\t\t\t} else {\n\t\t\t\t\tA[j] -= A[j | i];\n\t\t\t\t\tA[j] +=\
    \ MOD;\n\t\t\t\t\tA[j] %= MOD;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn A;\n\
    }\nvector<long long> and_convolution(vector<long long> A, vector<long long> B){\n\
    \tint N = A.size();\n\tA = and_fwt(A, false);\n\tB = and_fwt(B, false);\n\tvector<long\
    \ long> C(N);\n\tfor (int i = 0; i < N; i++){\n\t\tC[i] = A[i] * B[i] % MOD;\n\
    \t}\n\tC = and_fwt(C, true);\n\treturn C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Bitwise_And_Convolution.cpp
  requiredBy: []
  timestamp: '2021-01-03 01:53:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Bitwise_And_Convolution.cpp
layout: document
redirect_from:
- /library/Math/Bitwise_And_Convolution.cpp
- /library/Math/Bitwise_And_Convolution.cpp.html
title: Math/Bitwise_And_Convolution.cpp
---
