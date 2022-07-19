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
  bundledCode: "#line 1 \"old_Math/Convolution_(NTT).cpp\"\nlong long modpow(long\
    \ long a, long long b){\n\tlong long ans = 1;\n\twhile (b > 0){\n\t\tif (b % 2\
    \ == 1){\n\t\t\tans *= a;\n\t\t\tans %= MOD;\n\t\t}\n\t\ta *= a;\n\t\ta %= MOD;\n\
    \t\tb /= 2;\n\t}\n\treturn ans;\n}\nlong long modinv(long long a){\n\treturn modpow(a,\
    \ MOD - 2);\n}\nvector<long long> ntt(vector<long long> A, bool inv){\n\tint N\
    \ = A.size();\n\tlong long r = 3;\n\tif (inv){\n\t\tr = modinv(r);\n\t}\n\tvector<long\
    \ long> B(N);\n\tfor (int i = N / 2; i > 0; i /= 2){\n\t\tlong long z = modpow(r,\
    \ (MOD - 1) / (N / i));\n\t\tlong long z2 = 1;\n\t\tfor (int j = 0; j < N; j +=\
    \ i * 2){\n\t\t\tfor (int k = 0; k < i; k++){\n\t\t\t\tA[i + j + k] *= z2;\n\t\
    \t\t\tA[i + j + k] %= MOD;\n\t\t\t\tB[j / 2 + k] = (A[j + k] + A[i + j + k]) %\
    \ MOD;\n\t\t\t\tB[N / 2 + j / 2 + k] = (A[j + k] - A[i + j + k] + MOD) % MOD;\n\
    \t\t\t}\n\t\t\tz2 = z2 * z % MOD;\n\t\t}\n\t\tswap(A, B);\n\t}\n\tif (inv){\n\t\
    \tint Ninv = modinv(N);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tA[i] = A[i] *\
    \ Ninv % MOD;\n\t\t}\n\t}\n\treturn A;\n}\nvector<long long> convolution(vector<long\
    \ long> A, vector<long long> B, int d = -1){\n\tint deg = A.size() + B.size()\
    \ - 1;\n\tint N = 1;\n\twhile (N < deg){\n\t\tN *= 2;\n\t}\n\tA.resize(N);\n\t\
    B.resize(N);\n\tA = ntt(A, false);\n\tB = ntt(B, false);\n\tvector<long long>\
    \ ans(N);\n\tfor (int i = 0; i < N; i++){\n\t\tans[i] = A[i] * B[i] % MOD;\n\t\
    }\n\tans = ntt(ans, true);\n\tif (d != -1){\n\t\tdeg = d;\n\t}\n\tans.resize(deg);\n\
    \treturn ans;\n}\n"
  code: "long long modpow(long long a, long long b){\n\tlong long ans = 1;\n\twhile\
    \ (b > 0){\n\t\tif (b % 2 == 1){\n\t\t\tans *= a;\n\t\t\tans %= MOD;\n\t\t}\n\t\
    \ta *= a;\n\t\ta %= MOD;\n\t\tb /= 2;\n\t}\n\treturn ans;\n}\nlong long modinv(long\
    \ long a){\n\treturn modpow(a, MOD - 2);\n}\nvector<long long> ntt(vector<long\
    \ long> A, bool inv){\n\tint N = A.size();\n\tlong long r = 3;\n\tif (inv){\n\t\
    \tr = modinv(r);\n\t}\n\tvector<long long> B(N);\n\tfor (int i = N / 2; i > 0;\
    \ i /= 2){\n\t\tlong long z = modpow(r, (MOD - 1) / (N / i));\n\t\tlong long z2\
    \ = 1;\n\t\tfor (int j = 0; j < N; j += i * 2){\n\t\t\tfor (int k = 0; k < i;\
    \ k++){\n\t\t\t\tA[i + j + k] *= z2;\n\t\t\t\tA[i + j + k] %= MOD;\n\t\t\t\tB[j\
    \ / 2 + k] = (A[j + k] + A[i + j + k]) % MOD;\n\t\t\t\tB[N / 2 + j / 2 + k] =\
    \ (A[j + k] - A[i + j + k] + MOD) % MOD;\n\t\t\t}\n\t\t\tz2 = z2 * z % MOD;\n\t\
    \t}\n\t\tswap(A, B);\n\t}\n\tif (inv){\n\t\tint Ninv = modinv(N);\n\t\tfor (int\
    \ i = 0; i < N; i++){\n\t\t\tA[i] = A[i] * Ninv % MOD;\n\t\t}\n\t}\n\treturn A;\n\
    }\nvector<long long> convolution(vector<long long> A, vector<long long> B, int\
    \ d = -1){\n\tint deg = A.size() + B.size() - 1;\n\tint N = 1;\n\twhile (N < deg){\n\
    \t\tN *= 2;\n\t}\n\tA.resize(N);\n\tB.resize(N);\n\tA = ntt(A, false);\n\tB =\
    \ ntt(B, false);\n\tvector<long long> ans(N);\n\tfor (int i = 0; i < N; i++){\n\
    \t\tans[i] = A[i] * B[i] % MOD;\n\t}\n\tans = ntt(ans, true);\n\tif (d != -1){\n\
    \t\tdeg = d;\n\t}\n\tans.resize(deg);\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Math/Convolution_(NTT).cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Math/Convolution_(NTT).cpp
layout: document
redirect_from:
- /library/old_Math/Convolution_(NTT).cpp
- /library/old_Math/Convolution_(NTT).cpp.html
title: old_Math/Convolution_(NTT).cpp
---
