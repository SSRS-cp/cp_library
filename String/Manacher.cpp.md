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
  bundledCode: "#line 1 \"String/Manacher.cpp\"\nvector<int> manacher(string &S){\n\
    \  int N = S.size();\n  vector<int> ans(N, 0);\n  int i = 0, j = 0;\n  while (i\
    \ < N){\n    while (i >= j && i + j < N && S[i - j] == S[i + j]){\n      j++;\n\
    \    }\n    ans[i] = j;\n    int k = 1;\n    while (i >= k && i + k < N && k +\
    \ ans[i - k] < j){\n      ans[i + k] = ans[i - k];\n      k++;\n    }\n    i +=\
    \ k;\n    j -= k;\n  }\n  return ans;\n}\n"
  code: "vector<int> manacher(string &S){\n  int N = S.size();\n  vector<int> ans(N,\
    \ 0);\n  int i = 0, j = 0;\n  while (i < N){\n    while (i >= j && i + j < N &&\
    \ S[i - j] == S[i + j]){\n      j++;\n    }\n    ans[i] = j;\n    int k = 1;\n\
    \    while (i >= k && i + k < N && k + ans[i - k] < j){\n      ans[i + k] = ans[i\
    \ - k];\n      k++;\n    }\n    i += k;\n    j -= k;\n  }\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/Manacher.cpp
  requiredBy: []
  timestamp: '2021-12-01 17:44:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Manacher.cpp
layout: document
redirect_from:
- /library/String/Manacher.cpp
- /library/String/Manacher.cpp.html
title: String/Manacher.cpp
---
