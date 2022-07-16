---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/monoids/linear_.hpp\"\nstruct linear{\n  long long\
    \ a, b;\n  linear(){\n    a = 1;\n    b = 0;\n  }\n  linear(int a, int b): a(a),\
    \ b(b){\n  }\n};\nlinear composite(linear A, linear B){\n  return linear(A.a *\
    \ B.a % MOD, (A.b * B.a + B.b) % MOD);\n}\nint value(linear A, int x){\n  return\
    \ (A.a * x + A.b) % MOD;\n}\n"
  code: "#pragma once\nstruct linear{\n  long long a, b;\n  linear(){\n    a = 1;\n\
    \    b = 0;\n  }\n  linear(int a, int b): a(a), b(b){\n  }\n};\nlinear composite(linear\
    \ A, linear B){\n  return linear(A.a * B.a % MOD, (A.b * B.a + B.b) % MOD);\n\
    }\nint value(linear A, int x){\n  return (A.a * x + A.b) % MOD;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/monoids/linear_.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:54:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/monoids/linear_.hpp
layout: document
redirect_from:
- /library/other/monoids/linear_.hpp
- /library/other/monoids/linear_.hpp.html
title: other/monoids/linear_.hpp
---
