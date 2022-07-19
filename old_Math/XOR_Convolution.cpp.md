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
  bundledCode: "#line 1 \"old_Math/XOR_Convolution.cpp\"\nvector<long long> xor_fwt(vector<long\
    \ long> A, bool inv){\n\tint N = A.size();\n\tfor (int i = 1; i < N; i <<= 1){\n\
    \t\tfor (int j = 0; j < N; j++){\n\t\t\tif ((j & i) == 0){\n\t\t\t\tlong long\
    \ x = A[j];\n\t\t\t\tlong long y = A[j | i];\n\t\t\t\tA[j] = (x + y) % MOD;\n\t\
    \t\t\tA[j | i] = (x + MOD - y) % MOD;\n\t\t\t\tif (inv){\n\t\t\t\t\tA[j] *= (MOD\
    \ + 1) / 2;\n\t\t\t\t\tA[j] %= MOD;\n\t\t\t\t\tA[j | i] *= (MOD + 1) / 2;\n\t\t\
    \t\t\tA[j | i] %= MOD;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn A;\n}\nvector<long\
    \ long> xor_convolution(vector<long long> A, vector<long long> B){\n\tint N =\
    \ A.size();\n\tA = xor_fwt(A, false);\n\tB = xor_fwt(B, false);\n\tvector<long\
    \ long> C(N);\n\tfor (int i = 0; i < N; i++){\n\t\tC[i] = A[i] * B[i] % MOD;\n\
    \t}\n\tC = xor_fwt(C, true);\n\treturn C;\n}\n"
  code: "vector<long long> xor_fwt(vector<long long> A, bool inv){\n\tint N = A.size();\n\
    \tfor (int i = 1; i < N; i <<= 1){\n\t\tfor (int j = 0; j < N; j++){\n\t\t\tif\
    \ ((j & i) == 0){\n\t\t\t\tlong long x = A[j];\n\t\t\t\tlong long y = A[j | i];\n\
    \t\t\t\tA[j] = (x + y) % MOD;\n\t\t\t\tA[j | i] = (x + MOD - y) % MOD;\n\t\t\t\
    \tif (inv){\n\t\t\t\t\tA[j] *= (MOD + 1) / 2;\n\t\t\t\t\tA[j] %= MOD;\n\t\t\t\t\
    \tA[j | i] *= (MOD + 1) / 2;\n\t\t\t\t\tA[j | i] %= MOD;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\treturn A;\n}\nvector<long long> xor_convolution(vector<long long>\
    \ A, vector<long long> B){\n\tint N = A.size();\n\tA = xor_fwt(A, false);\n\t\
    B = xor_fwt(B, false);\n\tvector<long long> C(N);\n\tfor (int i = 0; i < N; i++){\n\
    \t\tC[i] = A[i] * B[i] % MOD;\n\t}\n\tC = xor_fwt(C, true);\n\treturn C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Math/XOR_Convolution.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Math/XOR_Convolution.cpp
layout: document
redirect_from:
- /library/old_Math/XOR_Convolution.cpp
- /library/old_Math/XOR_Convolution.cpp.html
title: old_Math/XOR_Convolution.cpp
---
