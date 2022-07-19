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
  bundledCode: "#line 1 \"old_Graph/Rerooting_1.cpp\"\nint dfs1(vector<int> &dp, vector<vector<int>>\
    \ &c, int v){\n\tfor (int w : c[v]) {\n\t\tvp[v] = add(dp[v], root(dfs1(dp, c,\
    \ w)));\n\t}\n\treturn dp[v];\n}\nvoid dfs2(vector<int> &dp, vector<vector<int>>\
    \ &c, int v){\n\tfor (int w : c[v]){\n\t\tdp[w] = add(dp[w], root(sub(dp[v], root(dp[w]))));\n\
    \t\tdfs2(dp, c, w);\n\t}\n}\n"
  code: "int dfs1(vector<int> &dp, vector<vector<int>> &c, int v){\n\tfor (int w :\
    \ c[v]) {\n\t\tvp[v] = add(dp[v], root(dfs1(dp, c, w)));\n\t}\n\treturn dp[v];\n\
    }\nvoid dfs2(vector<int> &dp, vector<vector<int>> &c, int v){\n\tfor (int w :\
    \ c[v]){\n\t\tdp[w] = add(dp[w], root(sub(dp[v], root(dp[w]))));\n\t\tdfs2(dp,\
    \ c, w);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Rerooting_1.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Rerooting_1.cpp
layout: document
redirect_from:
- /library/old_Graph/Rerooting_1.cpp
- /library/old_Graph/Rerooting_1.cpp.html
title: old_Graph/Rerooting_1.cpp
---
