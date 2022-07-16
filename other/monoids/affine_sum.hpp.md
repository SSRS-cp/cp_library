---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/range_affine_range_sum.test.cpp
    title: test/library_checker/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/monoids/affine_sum.hpp\"\nstruct affine_sum{\n  int\
    \ cnt;\n  long long sum;\n  affine_sum(): cnt(0), sum(0){\n  }\n};\naffine_sum\
    \ op(affine_sum A, affine_sum B){\n  A.cnt += B.cnt;\n  A.sum += B.sum;\n  A.sum\
    \ %= MOD;\n  return A;\n}\naffine_sum mp(linear f, affine_sum A){\n  A.sum = (A.sum\
    \ * f.a + A.cnt * f.b) % MOD;\n  return A;\n}\n"
  code: "#pragma once\nstruct affine_sum{\n  int cnt;\n  long long sum;\n  affine_sum():\
    \ cnt(0), sum(0){\n  }\n};\naffine_sum op(affine_sum A, affine_sum B){\n  A.cnt\
    \ += B.cnt;\n  A.sum += B.sum;\n  A.sum %= MOD;\n  return A;\n}\naffine_sum mp(linear\
    \ f, affine_sum A){\n  A.sum = (A.sum * f.a + A.cnt * f.b) % MOD;\n  return A;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: other/monoids/affine_sum.hpp
  requiredBy: []
  timestamp: '2022-07-17 07:03:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/range_affine_range_sum.test.cpp
documentation_of: other/monoids/affine_sum.hpp
layout: document
redirect_from:
- /library/other/monoids/affine_sum.hpp
- /library/other/monoids/affine_sum.hpp.html
title: other/monoids/affine_sum.hpp
---
