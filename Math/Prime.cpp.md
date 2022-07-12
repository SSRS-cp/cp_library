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
  bundledCode: "#line 1 \"Math/Prime.cpp\"\nbool is_prime(long long N){\n\tfor (long\
    \ long i = 2; i * i <= N; i++){\n\t\tif (N % i == 0){\n\t\t\treturn false;\n\t\
    \t}\n\t}\n\treturn true;\n}\nvector<long long> prime_factorization(long long N){\n\
    \tvector<long long> ans;\n\tfor (long long i = 2; i * i <= N; i++){\n\t\tif (N\
    \ % i == 0){\n\t\t\twhile (N % i == 0){\n\t\t\t\tN /= i;\n\t\t\t\tans.push_back(i);\n\
    \t\t\t}\n\t\t}\n\t}\n\tif (N != 1){\n\t\tans.push_back(N);\n\t}\n\treturn ans;\n\
    }\nint factor_count(long long N){\n\tint ans = 1;\n\tfor (long long i = 2; i *\
    \ i <= N; i++){\n\t\tif (N % i == 0){\n\t\t\tint e = 0;\n\t\t\twhile (N % i ==\
    \ 0){\n\t\t\t\tN /= i;\n\t\t\t\te++;\n\t\t\t}\n\t\t\tans *= e + 1;\n\t\t}\n\t\
    }\n\tif (N != 1){\n\t\tans *= 2;\n\t}\n\treturn ans;\n}\n"
  code: "bool is_prime(long long N){\n\tfor (long long i = 2; i * i <= N; i++){\n\t\
    \tif (N % i == 0){\n\t\t\treturn false;\n\t\t}\n\t}\n\treturn true;\n}\nvector<long\
    \ long> prime_factorization(long long N){\n\tvector<long long> ans;\n\tfor (long\
    \ long i = 2; i * i <= N; i++){\n\t\tif (N % i == 0){\n\t\t\twhile (N % i == 0){\n\
    \t\t\t\tN /= i;\n\t\t\t\tans.push_back(i);\n\t\t\t}\n\t\t}\n\t}\n\tif (N != 1){\n\
    \t\tans.push_back(N);\n\t}\n\treturn ans;\n}\nint factor_count(long long N){\n\
    \tint ans = 1;\n\tfor (long long i = 2; i * i <= N; i++){\n\t\tif (N % i == 0){\n\
    \t\t\tint e = 0;\n\t\t\twhile (N % i == 0){\n\t\t\t\tN /= i;\n\t\t\t\te++;\n\t\
    \t\t}\n\t\t\tans *= e + 1;\n\t\t}\n\t}\n\tif (N != 1){\n\t\tans *= 2;\n\t}\n\t\
    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime.cpp
  requiredBy: []
  timestamp: '2020-04-11 02:12:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Prime.cpp
layout: document
redirect_from:
- /library/Math/Prime.cpp
- /library/Math/Prime.cpp.html
title: Math/Prime.cpp
---
