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
  bundledCode: "#line 1 \"old_Math/Multipoint_Evaluation.cpp\"\nvector<long long>\
    \ multipoint_evaluation(vector<long long> &f, vector<long long> x){\n  int M =\
    \ x.size();\n  int M2 = 1;\n  while (M2 < M){\n    M2 *= 2;\n  }\n  vector<vector<long\
    \ long>> g(M2 * 2 - 1, {1});\n  for (int i = 0; i < M; i++){\n    g[M2 - 1 + i]\
    \ = vector<long long>{MOD - x[i], 1};\n  }\n  for (int i = M2 - 2; i >= 0; i--){\n\
    \    g[i] = convolution(g[i * 2 + 1], g[i * 2 + 2]);\n  }\n  g[0] = polynomial_remainder(f,\
    \ g[0]);\n  for (int i = 1; i < M2 * 2 - 1; i++){\n    g[i] = polynomial_remainder(g[(i\
    \ - 1) / 2], g[i]);\n  }\n  vector<long long> ans(M);\n  for (int i = 0; i < M;\
    \ i++){\n    ans[i] = g[M2 - 1 + i][0];\n  }\n  return ans;\n}\n"
  code: "vector<long long> multipoint_evaluation(vector<long long> &f, vector<long\
    \ long> x){\n  int M = x.size();\n  int M2 = 1;\n  while (M2 < M){\n    M2 *=\
    \ 2;\n  }\n  vector<vector<long long>> g(M2 * 2 - 1, {1});\n  for (int i = 0;\
    \ i < M; i++){\n    g[M2 - 1 + i] = vector<long long>{MOD - x[i], 1};\n  }\n \
    \ for (int i = M2 - 2; i >= 0; i--){\n    g[i] = convolution(g[i * 2 + 1], g[i\
    \ * 2 + 2]);\n  }\n  g[0] = polynomial_remainder(f, g[0]);\n  for (int i = 1;\
    \ i < M2 * 2 - 1; i++){\n    g[i] = polynomial_remainder(g[(i - 1) / 2], g[i]);\n\
    \  }\n  vector<long long> ans(M);\n  for (int i = 0; i < M; i++){\n    ans[i]\
    \ = g[M2 - 1 + i][0];\n  }\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Math/Multipoint_Evaluation.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Math/Multipoint_Evaluation.cpp
layout: document
redirect_from:
- /library/old_Math/Multipoint_Evaluation.cpp
- /library/old_Math/Multipoint_Evaluation.cpp.html
title: old_Math/Multipoint_Evaluation.cpp
---
