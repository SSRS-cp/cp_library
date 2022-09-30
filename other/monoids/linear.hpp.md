---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_set_range_composite.test.cpp
    title: test/library_checker/data_structure/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/range_affine_point_get.test.cpp
    title: test/library_checker/data_structure/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/range_affine_range_sum.test.cpp
    title: test/library_checker/data_structure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_1891.test.cpp
    title: test/yukicoder/yuki_1891.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/monoids/linear.hpp\"\nstruct linear{\n  long long\
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
  path: other/monoids/linear.hpp
  requiredBy: []
  timestamp: '2022-07-17 07:03:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_1891.test.cpp
  - test/library_checker/data_structure/range_affine_point_get.test.cpp
  - test/library_checker/data_structure/point_set_range_composite.test.cpp
  - test/library_checker/data_structure/queue_operate_all_composite.test.cpp
  - test/library_checker/data_structure/range_affine_range_sum.test.cpp
documentation_of: other/monoids/linear.hpp
layout: document
redirect_from:
- /library/other/monoids/linear.hpp
- /library/other/monoids/linear.hpp.html
title: other/monoids/linear.hpp
---
