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
  bundledCode: "#line 1 \"old_String/Manacher.cpp\"\nvector<int> manacher(string &S){\n\
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
  path: old_String/Manacher.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_String/Manacher.cpp
layout: document
redirect_from:
- /library/old_String/Manacher.cpp
- /library/old_String/Manacher.cpp.html
title: old_String/Manacher.cpp
---
