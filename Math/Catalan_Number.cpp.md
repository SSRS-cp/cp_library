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
  bundledCode: "#line 1 \"Math/Catalan_Number.cpp\"\n//Input: n, MOD\n//Output: C_n\
    \ mod MOD\n//Time: O(1)\nlong long modpow(long long a, long long b){\n\tlong long\
    \ res = 1;\n\twhile (b > 0){\n\t\tif (b % 2 == 1) res = res * a % MOD;\n\t\ta\
    \ = a * a % MOD;\n\t\tb = b / 2;\n\t}\n\treturn res;\n}\nlong long modinv(long\
    \ long a){\n\treturn modpow(a, MOD - 2);\n}\nvector<long long> mf;\nlong long\
    \ modfact(long long n){\n\tif (n < mf.size()){\n\t\treturn mf[n];\n\t} else {\n\
    \t\tif (mf.empty()) mf.push_back(1);\n\t\tlong long res = mf.back();\n\t\tfor\
    \ (int i = mf.size(); i <= n; i++){\n\t\t\tres = res * i % MOD;\n\t\t\tmf.push_back(res);\n\
    \t\t}\n\t\treturn res;\n\t}\n}\nlong long catalan_number(long long n){\n\tlong\
    \ long res;\n\tres = modfact(n * 2);\n\tres = res * modinv(modfact(n + 1)) % MOD;\n\
    \tres = res * modinv(modfact(n)) % MOD;\n\treturn res;\n}\n"
  code: "//Input: n, MOD\n//Output: C_n mod MOD\n//Time: O(1)\nlong long modpow(long\
    \ long a, long long b){\n\tlong long res = 1;\n\twhile (b > 0){\n\t\tif (b % 2\
    \ == 1) res = res * a % MOD;\n\t\ta = a * a % MOD;\n\t\tb = b / 2;\n\t}\n\treturn\
    \ res;\n}\nlong long modinv(long long a){\n\treturn modpow(a, MOD - 2);\n}\nvector<long\
    \ long> mf;\nlong long modfact(long long n){\n\tif (n < mf.size()){\n\t\treturn\
    \ mf[n];\n\t} else {\n\t\tif (mf.empty()) mf.push_back(1);\n\t\tlong long res\
    \ = mf.back();\n\t\tfor (int i = mf.size(); i <= n; i++){\n\t\t\tres = res * i\
    \ % MOD;\n\t\t\tmf.push_back(res);\n\t\t}\n\t\treturn res;\n\t}\n}\nlong long\
    \ catalan_number(long long n){\n\tlong long res;\n\tres = modfact(n * 2);\n\t\
    res = res * modinv(modfact(n + 1)) % MOD;\n\tres = res * modinv(modfact(n)) %\
    \ MOD;\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Catalan_Number.cpp
  requiredBy: []
  timestamp: '2020-03-22 15:06:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Catalan_Number.cpp
layout: document
redirect_from:
- /library/Math/Catalan_Number.cpp
- /library/Math/Catalan_Number.cpp.html
title: Math/Catalan_Number.cpp
---
