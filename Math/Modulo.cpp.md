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
  bundledCode: "#line 1 \"Math/Modulo.cpp\"\nconst long long MOD = 1000000007;\nlong\
    \ long modsub(long long a, long long b){\n\treturn (a % MOD - b % MOD + MOD) %\
    \ MOD;\n}\nlong long modpow(long long a, long long b){\n\tlong long ans = 1;\n\
    \twhile (b > 0){\n\t\tif (b % 2 == 1){\n\t\t\tans *= a;\n\t\t\tans %= MOD;\n\t\
    \t}\n\t\ta *= a;\n\t\ta %= MOD;\n\t\tb /= 2;\n\t}\n\treturn ans;\n}\nlong long\
    \ modinv(long long a){\n\treturn modpow(a, MOD - 2);\n}\nvector<long long> mf\
    \ = {1};\nvector<long long> mfi = {1};\nlong long modfact(int n){\n\tif (mf.size()\
    \ > n){\n\t\treturn mf[n];\n\t} else {\n\t\tfor (int i = mf.size(); i <= n; i++){\n\
    \t\t\tlong long next = mf.back() * i % MOD;\n\t\t\tmf.push_back(next);\n\t\t\t\
    mfi.push_back(modinv(next));\n\t\t}\n\t\treturn mf[n];\n\t}\n}\nlong long modfactinv(int\
    \ n){\n\tif (mfi.size() > n){\n\t\treturn mfi[n];\n\t} else {\n\t\treturn modinv(modfact(n));\n\
    \t}\n}\nlong long modbinom(int n, int k){\n\tif (n < 0 || k < 0 || k > n){\n\t\
    \treturn 0;\n\t} else {\n\t\treturn modfact(n) * modfactinv(k) % MOD * modfactinv(n\
    \ - k) % MOD;\n\t}\n}\nlong long modbinom2(long long n, int r){\n\tlong long ans\
    \ = 1;\n\tfor (int i = 0; i < r; i++){\n\t\tans = ans * ((n - i) % MOD) % MOD;\n\
    \t\tans = ans * modinv(i + 1) % MOD;\n\t}\n\treturn ans;\n}\n"
  code: "const long long MOD = 1000000007;\nlong long modsub(long long a, long long\
    \ b){\n\treturn (a % MOD - b % MOD + MOD) % MOD;\n}\nlong long modpow(long long\
    \ a, long long b){\n\tlong long ans = 1;\n\twhile (b > 0){\n\t\tif (b % 2 == 1){\n\
    \t\t\tans *= a;\n\t\t\tans %= MOD;\n\t\t}\n\t\ta *= a;\n\t\ta %= MOD;\n\t\tb /=\
    \ 2;\n\t}\n\treturn ans;\n}\nlong long modinv(long long a){\n\treturn modpow(a,\
    \ MOD - 2);\n}\nvector<long long> mf = {1};\nvector<long long> mfi = {1};\nlong\
    \ long modfact(int n){\n\tif (mf.size() > n){\n\t\treturn mf[n];\n\t} else {\n\
    \t\tfor (int i = mf.size(); i <= n; i++){\n\t\t\tlong long next = mf.back() *\
    \ i % MOD;\n\t\t\tmf.push_back(next);\n\t\t\tmfi.push_back(modinv(next));\n\t\t\
    }\n\t\treturn mf[n];\n\t}\n}\nlong long modfactinv(int n){\n\tif (mfi.size() >\
    \ n){\n\t\treturn mfi[n];\n\t} else {\n\t\treturn modinv(modfact(n));\n\t}\n}\n\
    long long modbinom(int n, int k){\n\tif (n < 0 || k < 0 || k > n){\n\t\treturn\
    \ 0;\n\t} else {\n\t\treturn modfact(n) * modfactinv(k) % MOD * modfactinv(n -\
    \ k) % MOD;\n\t}\n}\nlong long modbinom2(long long n, int r){\n\tlong long ans\
    \ = 1;\n\tfor (int i = 0; i < r; i++){\n\t\tans = ans * ((n - i) % MOD) % MOD;\n\
    \t\tans = ans * modinv(i + 1) % MOD;\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Modulo.cpp
  requiredBy: []
  timestamp: '2020-07-04 23:42:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Modulo.cpp
layout: document
redirect_from:
- /library/Math/Modulo.cpp
- /library/Math/Modulo.cpp.html
title: Math/Modulo.cpp
---
