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
  bundledCode: "#line 1 \"String/Z-algorithm.cpp\"\nvector<int> z_algorithm(string\
    \ S){\n  int N = S.size();\n  vector<int> ans(N);\n  for (int i = 1, j = 0; i\
    \ < N; i++){\n    if (i + ans[i - j] < j + ans[j]){\n      ans[i] = ans[i - j];\n\
    \    } else {\n      int k = max(0, j + ans[j] - i);\n      while (i + k < N &&\
    \ S[k] == S[i + k]){\n        k++;\n      }\n      ans[i] = k;\n      j = i;\n\
    \    }\n  }\n  ans[0] = N;\n  return ans;\n}\n"
  code: "vector<int> z_algorithm(string S){\n  int N = S.size();\n  vector<int> ans(N);\n\
    \  for (int i = 1, j = 0; i < N; i++){\n    if (i + ans[i - j] < j + ans[j]){\n\
    \      ans[i] = ans[i - j];\n    } else {\n      int k = max(0, j + ans[j] - i);\n\
    \      while (i + k < N && S[k] == S[i + k]){\n        k++;\n      }\n      ans[i]\
    \ = k;\n      j = i;\n    }\n  }\n  ans[0] = N;\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/Z-algorithm.cpp
  requiredBy: []
  timestamp: '2021-12-01 17:46:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Z-algorithm.cpp
layout: document
redirect_from:
- /library/String/Z-algorithm.cpp
- /library/String/Z-algorithm.cpp.html
title: String/Z-algorithm.cpp
---
