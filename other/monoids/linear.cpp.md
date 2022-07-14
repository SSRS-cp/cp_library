---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/point_set_range_composite.test.cpp
    title: test/library_checker/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/library_checker/queue_operate_all_composite.test.cpp
    title: test/library_checker/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/range_affine_point_get.test.cpp
    title: test/library_checker/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/range_affine_range_sum.test.cpp
    title: test/library_checker/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_1891.test.cpp
    title: test/yukicoder/yuki_1891.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/monoids/linear.cpp\"\nstruct linear{\n  long long\
    \ a, b;\n  linear(){\n    a = 1;\n    b = 0;\n  }\n  linear(int a, int b): a(a),\
    \ b(b){\n  }\n};\nlinear composite(linear A, linear B){\n  return linear(A.a *\
    \ B.a % MOD, (A.b * B.a + B.b) % MOD);\n}\nint value(linear A, int x){\n  return\
    \ (A.a * x + A.b) % MOD;\n}\n"
  code: "struct linear{\n  long long a, b;\n  linear(){\n    a = 1;\n    b = 0;\n\
    \  }\n  linear(int a, int b): a(a), b(b){\n  }\n};\nlinear composite(linear A,\
    \ linear B){\n  return linear(A.a * B.a % MOD, (A.b * B.a + B.b) % MOD);\n}\n\
    int value(linear A, int x){\n  return (A.a * x + A.b) % MOD;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/monoids/linear.cpp
  requiredBy: []
  timestamp: '2022-07-14 01:12:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/yuki_1891.test.cpp
  - test/library_checker/queue_operate_all_composite.test.cpp
  - test/library_checker/point_set_range_composite.test.cpp
  - test/library_checker/range_affine_range_sum.test.cpp
  - test/library_checker/range_affine_point_get.test.cpp
documentation_of: other/monoids/linear.cpp
layout: document
redirect_from:
- /library/other/monoids/linear.cpp
- /library/other/monoids/linear.cpp.html
title: other/monoids/linear.cpp
---
