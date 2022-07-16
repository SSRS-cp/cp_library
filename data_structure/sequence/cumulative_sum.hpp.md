---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Cumulative Sum (\u7D2F\u7A4D\u548C)"
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/cumulative_sum.hpp\"\ntemplate <typename\
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
  path: data_structure/sequence/cumulative_sum.hpp
  requiredBy: []
  timestamp: '2022-07-17 03:30:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sequence/cumulative_sum.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/cumulative_sum.hpp
- /library/data_structure/sequence/cumulative_sum.hpp.html
title: "Cumulative Sum (\u7D2F\u7A4D\u548C)"
---
