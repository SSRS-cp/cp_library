---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/data_structure/static_range_sum.test.cpp
    title: test/library_checker/data_structure/static_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/cumulative_sum.hpp\"\n/**\n * @brief\
    \ \u7D2F\u7A4D\u548C\n*/\ntemplate <typename T>\nstruct cumulative_sum{\n  vector<T>\
    \ S;\n  function<T(T, T)> f;\n  T E;\n  cumulative_sum(){\n  }\n  cumulative_sum(vector<T>\
    \ A, function<T(T, T)> f, T E): f(f), E(E){\n    int N = A.size();\n    S = vector<T>(N\
    \ + 1);\n    S[0] = E;\n    for (int i = 0; i < N; i++){\n      S[i + 1] = f(S[i],\
    \ A[i]);\n    }\n  }\n  T get(int i){\n    return S[i];\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u7D2F\u7A4D\u548C\n*/\ntemplate <typename T>\n\
    struct cumulative_sum{\n  vector<T> S;\n  function<T(T, T)> f;\n  T E;\n  cumulative_sum(){\n\
    \  }\n  cumulative_sum(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){\n \
    \   int N = A.size();\n    S = vector<T>(N + 1);\n    S[0] = E;\n    for (int\
    \ i = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n    }\n  }\n  T get(int\
    \ i){\n    return S[i];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/data_structure/static_range_sum.test.cpp
documentation_of: data_structure/sequence/cumulative_sum.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/cumulative_sum.hpp
- /library/data_structure/sequence/cumulative_sum.hpp.html
title: "\u7D2F\u7A4D\u548C"
---
