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
  bundledCode: "#line 1 \"old_String/Z-algorithm.cpp\"\nvector<int> z_algorithm(string\
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
  path: old_String/Z-algorithm.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_String/Z-algorithm.cpp
layout: document
redirect_from:
- /library/old_String/Z-algorithm.cpp
- /library/old_String/Z-algorithm.cpp.html
title: old_String/Z-algorithm.cpp
---
