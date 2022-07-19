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
  bundledCode: "#line 1 \"old_String/LCP_Array.cpp\"\nvector<int> lcp_array(string\
    \ &S, vector<int> &SA){\n  int N = S.size();\n  vector<int> rank(N);\n  for (int\
    \ i = 0; i < N; i++){\n    rank[SA[i]] = i;\n  }\n  vector<int> lcp(N - 1, 0);\n\
    \  int h = 0;\n  for (int i = 0; i < N; i++){\n    if (rank[i] > 0){\n      int\
    \ prev = SA[rank[i] - 1];\n      if (h > 0){\n        h--;\n      }\n      while\
    \ (i + h < N && prev + h < N){\n        if (S[i + h] != S[prev + h]){\n      \
    \    break;\n        }\n        h++;\n      }\n      lcp[rank[i] - 1] = h;\n \
    \   }\n  }\n  return lcp;\n}\n"
  code: "vector<int> lcp_array(string &S, vector<int> &SA){\n  int N = S.size();\n\
    \  vector<int> rank(N);\n  for (int i = 0; i < N; i++){\n    rank[SA[i]] = i;\n\
    \  }\n  vector<int> lcp(N - 1, 0);\n  int h = 0;\n  for (int i = 0; i < N; i++){\n\
    \    if (rank[i] > 0){\n      int prev = SA[rank[i] - 1];\n      if (h > 0){\n\
    \        h--;\n      }\n      while (i + h < N && prev + h < N){\n        if (S[i\
    \ + h] != S[prev + h]){\n          break;\n        }\n        h++;\n      }\n\
    \      lcp[rank[i] - 1] = h;\n    }\n  }\n  return lcp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_String/LCP_Array.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_String/LCP_Array.cpp
layout: document
redirect_from:
- /library/old_String/LCP_Array.cpp
- /library/old_String/LCP_Array.cpp.html
title: old_String/LCP_Array.cpp
---