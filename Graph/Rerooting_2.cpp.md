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
  bundledCode: "#line 1 \"Graph/Rerooting_2.cpp\"\nint dfs1(vector<int> &dp, vector<vector<int>>\
    \ &c, int v){\n\tdp[v] = 1;\n\tfor (int w : c[v]) dp[v] = add(dp[v], root(dfs1(dp,\
    \ c, w)));\n\treturn dp[v];\n}\nvoid dfs2(vector<int> &dp1, vector<int> &dp2,\
    \ vector<vector<int>> &c, int v){\n\tint deg = c[v].size();\n\tvector<int> L(deg\
    \ + 1, 1), R(deg + 1, 1);\n\tfor (int i = 0; i < deg; i++) L[i + 1] = add(L[i],\
    \ root(dp1[c[v][i]]));\n\tfor (int i = deg - 1; i >= 0; i--) R[i] = add(R[i +\
    \ 1], root(dp1[c[v][i]]));\n\tfor (int i = 0; i < deg; i++){\n\t\tdp2[c[v][i]]\
    \ = root(add(dp2[v], add(L[i], R[i + 1])));\n\t\tdfs2(dp1, dp2, c, c[v][i]);\n\
    \t}\n}\n"
  code: "int dfs1(vector<int> &dp, vector<vector<int>> &c, int v){\n\tdp[v] = 1;\n\
    \tfor (int w : c[v]) dp[v] = add(dp[v], root(dfs1(dp, c, w)));\n\treturn dp[v];\n\
    }\nvoid dfs2(vector<int> &dp1, vector<int> &dp2, vector<vector<int>> &c, int v){\n\
    \tint deg = c[v].size();\n\tvector<int> L(deg + 1, 1), R(deg + 1, 1);\n\tfor (int\
    \ i = 0; i < deg; i++) L[i + 1] = add(L[i], root(dp1[c[v][i]]));\n\tfor (int i\
    \ = deg - 1; i >= 0; i--) R[i] = add(R[i + 1], root(dp1[c[v][i]]));\n\tfor (int\
    \ i = 0; i < deg; i++){\n\t\tdp2[c[v][i]] = root(add(dp2[v], add(L[i], R[i + 1])));\n\
    \t\tdfs2(dp1, dp2, c, c[v][i]);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Rerooting_2.cpp
  requiredBy: []
  timestamp: '2020-03-31 22:31:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Rerooting_2.cpp
layout: document
redirect_from:
- /library/Graph/Rerooting_2.cpp
- /library/Graph/Rerooting_2.cpp.html
title: Graph/Rerooting_2.cpp
---
