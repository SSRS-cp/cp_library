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
  bundledCode: "#line 1 \"old_Math/Euler_phi.cpp\"\nlong long euler_phi(long long\
    \ x){\n\tlong long ans = x;\n\tfor (long long i = 2; i * i <= x; i++){\n\t\tif\
    \ (x % i == 0){\n\t\t\tans /= i;\n\t\t\tans *= i - 1;\n\t\t\twhile (x % i == 0){\n\
    \t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif (x > 1){\n\t\tans /= x;\n\t\tans *=\
    \ x - 1;\n\t}\n\treturn ans;\n}\n"
  code: "long long euler_phi(long long x){\n\tlong long ans = x;\n\tfor (long long\
    \ i = 2; i * i <= x; i++){\n\t\tif (x % i == 0){\n\t\t\tans /= i;\n\t\t\tans *=\
    \ i - 1;\n\t\t\twhile (x % i == 0){\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\t\
    if (x > 1){\n\t\tans /= x;\n\t\tans *= x - 1;\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Math/Euler_phi.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Math/Euler_phi.cpp
layout: document
redirect_from:
- /library/old_Math/Euler_phi.cpp
- /library/old_Math/Euler_phi.cpp.html
title: old_Math/Euler_phi.cpp
---
