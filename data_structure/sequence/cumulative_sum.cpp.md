---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_sum.test.cpp
    title: test/library_checker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Cumulative Sum (\u7D2F\u7A4D\u548C)"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/cumulative_sum.cpp\"\ntemplate <typename\
    \ T>\nstruct cumulative_sum{\n  vector<T> S;\n  function<T(T, T)> f;\n  T E;\n\
    \  cumulative_sum(){\n  }\n  cumulative_sum(vector<T> A, function<T(T, T)> f,\
    \ T E): f(f), E(E){\n    int N = A.size();\n    S = vector<T>(N + 1);\n    S[0]\
    \ = E;\n    for (int i = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n  \
    \  }\n  }\n  T get(int i){\n    return S[i];\n  }\n};\n/**\n * @brief Cumulative\
    \ Sum (\u7D2F\u7A4D\u548C)\n*/\n"
  code: "template <typename T>\nstruct cumulative_sum{\n  vector<T> S;\n  function<T(T,\
    \ T)> f;\n  T E;\n  cumulative_sum(){\n  }\n  cumulative_sum(vector<T> A, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    int N = A.size();\n    S = vector<T>(N + 1);\n\
    \    S[0] = E;\n    for (int i = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n\
    \    }\n  }\n  T get(int i){\n    return S[i];\n  }\n};\n/**\n * @brief Cumulative\
    \ Sum (\u7D2F\u7A4D\u548C)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/cumulative_sum.cpp
  requiredBy: []
  timestamp: '2022-07-13 17:04:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_sum.test.cpp
documentation_of: data_structure/sequence/cumulative_sum.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/cumulative_sum.cpp
- /library/data_structure/sequence/cumulative_sum.cpp.html
title: "Cumulative Sum (\u7D2F\u7A4D\u548C)"
---
