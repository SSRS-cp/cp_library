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
  bundledCode: "#line 1 \"old_Math/Polynomial_Inverse.cpp\"\nvector<long long> polynomial_inverse(vector<long\
    \ long> f){\n  int N = f.size();\n  vector<long long> ans(1);\n  ans[0] = modinv(f[0]);\n\
    \  for (int i = 1; i < N * 2; i *= 2){\n    vector<long long> ans2 = ans;\n  \
    \  ans2.resize(i * 4);\n    int N2 = min(N, i * 2);\n    vector<long long> f2(i\
    \ * 4, 0);\n    for (int j = 0; j < N2; j++){\n      f2[j] = f[j];\n    }\n  \
    \  ans2 = convolution(ans2, ans2, i * 2);\n    ans2 = convolution(ans2, f2, i\
    \ * 2);\n    for (int j = 0; j < i; j++){\n      ans2[j] = MOD - ans2[j] + ans[j]\
    \ * 2;\n      ans2[j] %= MOD;\n    }\n    swap(ans, ans2);\n  }\n  ans.resize(N);\n\
    \  return ans;\n}\n"
  code: "vector<long long> polynomial_inverse(vector<long long> f){\n  int N = f.size();\n\
    \  vector<long long> ans(1);\n  ans[0] = modinv(f[0]);\n  for (int i = 1; i <\
    \ N * 2; i *= 2){\n    vector<long long> ans2 = ans;\n    ans2.resize(i * 4);\n\
    \    int N2 = min(N, i * 2);\n    vector<long long> f2(i * 4, 0);\n    for (int\
    \ j = 0; j < N2; j++){\n      f2[j] = f[j];\n    }\n    ans2 = convolution(ans2,\
    \ ans2, i * 2);\n    ans2 = convolution(ans2, f2, i * 2);\n    for (int j = 0;\
    \ j < i; j++){\n      ans2[j] = MOD - ans2[j] + ans[j] * 2;\n      ans2[j] %=\
    \ MOD;\n    }\n    swap(ans, ans2);\n  }\n  ans.resize(N);\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Math/Polynomial_Inverse.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Math/Polynomial_Inverse.cpp
layout: document
redirect_from:
- /library/old_Math/Polynomial_Inverse.cpp
- /library/old_Math/Polynomial_Inverse.cpp.html
title: old_Math/Polynomial_Inverse.cpp
---
