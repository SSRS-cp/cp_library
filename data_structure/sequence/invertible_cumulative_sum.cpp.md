---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_sum_2.test.cpp
    title: test/library_checker/static_range_sum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/invertible_cumulative_sum.cpp\"\n\
    template <typename T>\nstruct cumulative_sum{\n  vector<T> S;\n  function<T(T,\
    \ T)> f;\n  function<T(T)> inv;\n  T E;\n  cumulative_sum(){\n  }\n  cumulative_sum(vector<T>\
    \ A, function<T(T, T)> f, function<T(T)> inv, T E): f(f), inv(inv), E(E){\n  \
    \  int N = A.size();\n    S = vector<T>(N + 1);\n    S[0] = E;\n    for (int i\
    \ = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n    }\n  }\n  T get(int\
    \ i){\n    return S[i];\n  }\n  T get(int l, int r){\n    return f(S[r], inv(S[l]));\n\
    \  }\n};\n"
  code: "template <typename T>\nstruct cumulative_sum{\n  vector<T> S;\n  function<T(T,\
    \ T)> f;\n  function<T(T)> inv;\n  T E;\n  cumulative_sum(){\n  }\n  cumulative_sum(vector<T>\
    \ A, function<T(T, T)> f, function<T(T)> inv, T E): f(f), inv(inv), E(E){\n  \
    \  int N = A.size();\n    S = vector<T>(N + 1);\n    S[0] = E;\n    for (int i\
    \ = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n    }\n  }\n  T get(int\
    \ i){\n    return S[i];\n  }\n  T get(int l, int r){\n    return f(S[r], inv(S[l]));\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/invertible_cumulative_sum.cpp
  requiredBy: []
  timestamp: '2022-07-13 04:32:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_sum_2.test.cpp
documentation_of: data_structure/sequence/invertible_cumulative_sum.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/invertible_cumulative_sum.cpp
- /library/data_structure/sequence/invertible_cumulative_sum.cpp.html
title: data_structure/sequence/invertible_cumulative_sum.cpp
---
