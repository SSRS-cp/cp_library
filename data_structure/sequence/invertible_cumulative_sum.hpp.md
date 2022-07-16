---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_sum_2.test.cpp
    title: test/library_checker/static_range_sum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u53EF\u9006\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/invertible_cumulative_sum.hpp\"\n\
    /**\n * @brief \u53EF\u9006\u7D2F\u7A4D\u548C\n*/\ntemplate <typename T>\nstruct\
    \ invertible_cumulative_sum{\n  vector<T> S;\n  function<T(T, T)> f;\n  function<T(T)>\
    \ inv;\n  T E;\n  invertible_cumulative_sum(){\n  }\n  invertible_cumulative_sum(vector<T>\
    \ A, function<T(T, T)> f, function<T(T)> inv, T E): f(f), inv(inv), E(E){\n  \
    \  int N = A.size();\n    S = vector<T>(N + 1);\n    S[0] = E;\n    for (int i\
    \ = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n    }\n  }\n  T get(int\
    \ i){\n    return S[i];\n  }\n  T get(int l, int r){\n    return f(S[r], inv(S[l]));\n\
    \  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u53EF\u9006\u7D2F\u7A4D\u548C\n*/\ntemplate\
    \ <typename T>\nstruct invertible_cumulative_sum{\n  vector<T> S;\n  function<T(T,\
    \ T)> f;\n  function<T(T)> inv;\n  T E;\n  invertible_cumulative_sum(){\n  }\n\
    \  invertible_cumulative_sum(vector<T> A, function<T(T, T)> f, function<T(T)>\
    \ inv, T E): f(f), inv(inv), E(E){\n    int N = A.size();\n    S = vector<T>(N\
    \ + 1);\n    S[0] = E;\n    for (int i = 0; i < N; i++){\n      S[i + 1] = f(S[i],\
    \ A[i]);\n    }\n  }\n  T get(int i){\n    return S[i];\n  }\n  T get(int l, int\
    \ r){\n    return f(S[r], inv(S[l]));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/invertible_cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_sum_2.test.cpp
documentation_of: data_structure/sequence/invertible_cumulative_sum.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/invertible_cumulative_sum.hpp
- /library/data_structure/sequence/invertible_cumulative_sum.hpp.html
title: "\u53EF\u9006\u7D2F\u7A4D\u548C"
---
