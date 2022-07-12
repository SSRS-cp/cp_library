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
  bundledCode: "#line 1 \"Graph/Convert_to_Rooted_Tree.cpp\"\nvector<int> parent(vector<vector<int>>\
    \ &E, int r){\n\tint N = E.size();\n\tvector<int> p(N, -1);\n\tqueue<int> Q;\n\
    \tQ.push(r);\n\twhile (!Q.empty()){\n\t\tint v = Q.front();\n\t\tQ.pop();\n\t\t\
    for (int w : E[v]){\n\t\t\tif (p[w] == -1){\n\t\t\t\tp[w] = v;\n\t\t\t\tQ.push(w);\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn p;\n}\nvector<vector<int>> child(vector<vector<int>>\
    \ E, int r){\n\tint N = E.size();\n\tvector<vector<int>> c(N);\n\tqueue<int> Q;\n\
    \tQ.push(r);\n\twhile (!Q.empty()){\n\t\tint v = Q.front();\n\t\tQ.pop();\n\t\t\
    for (int w : E[v]){\n\t\t\tif (c[w].empty()){\n\t\t\t\tc[v].push_back(w);\n\t\t\
    \t\tQ.push(w);\n\t\t\t}\n\t\t}\n\t}\n\treturn c;\n}\nvector<vector<int>> child_2(vector<int>\
    \ &p, int r){\n\tint N = p.size();\n\tvector<vector<int>> c(N);\n\tfor (int i\
    \ = 0; i < N; i++){\n\t\tif (i != r){\n\t\t\tc[p[i]].push_back(i);\n\t\t}\n\t\
    }\n\treturn c;\n}\n"
  code: "vector<int> parent(vector<vector<int>> &E, int r){\n\tint N = E.size();\n\
    \tvector<int> p(N, -1);\n\tqueue<int> Q;\n\tQ.push(r);\n\twhile (!Q.empty()){\n\
    \t\tint v = Q.front();\n\t\tQ.pop();\n\t\tfor (int w : E[v]){\n\t\t\tif (p[w]\
    \ == -1){\n\t\t\t\tp[w] = v;\n\t\t\t\tQ.push(w);\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ p;\n}\nvector<vector<int>> child(vector<vector<int>> E, int r){\n\tint N = E.size();\n\
    \tvector<vector<int>> c(N);\n\tqueue<int> Q;\n\tQ.push(r);\n\twhile (!Q.empty()){\n\
    \t\tint v = Q.front();\n\t\tQ.pop();\n\t\tfor (int w : E[v]){\n\t\t\tif (c[w].empty()){\n\
    \t\t\t\tc[v].push_back(w);\n\t\t\t\tQ.push(w);\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ c;\n}\nvector<vector<int>> child_2(vector<int> &p, int r){\n\tint N = p.size();\n\
    \tvector<vector<int>> c(N);\n\tfor (int i = 0; i < N; i++){\n\t\tif (i != r){\n\
    \t\t\tc[p[i]].push_back(i);\n\t\t}\n\t}\n\treturn c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Convert_to_Rooted_Tree.cpp
  requiredBy: []
  timestamp: '2020-03-31 22:25:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Convert_to_Rooted_Tree.cpp
layout: document
redirect_from:
- /library/Graph/Convert_to_Rooted_Tree.cpp
- /library/Graph/Convert_to_Rooted_Tree.cpp.html
title: Graph/Convert_to_Rooted_Tree.cpp
---
