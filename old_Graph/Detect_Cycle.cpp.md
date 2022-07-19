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
  bundledCode: "#line 1 \"old_Graph/Detect_Cycle.cpp\"\nbool detect_cycle(vector<vector<int>>\
    \ &E){\n\tint V = E.size();\n\tvector<int> deg(V, 0);\n\tfor (int i = 0; i < V;\
    \ i++){\n\t\tfor (int j : E[i]){\n\t\t\tdeg[j]++;\n\t\t}\n\t}\n\tqueue<int> Q;\n\
    \tfor (int i = 0; i < V; i++){\n\t\tif (deg[i] == 0){\n\t\t\tQ.push(i);\n\t\t\
    }\n\t}\n\twhile (!Q.empty()){\n\t\tint v = Q.front();\n\t\tQ.pop();\n\t\tfor (int\
    \ w : E[v]){\n\t\t\tdeg[w]--;\n\t\t\tif (deg[w] == 0){\n\t\t\t\tQ.push(w);\n\t\
    \t\t}\n\t\t}\n\t}\n\tfor (int i = 0; i < V; i++){\n\t\tif (deg[i] != 0){\n\t\t\
    \treturn true;\n\t\t}\n\t}\n\treturn false;\n}\n"
  code: "bool detect_cycle(vector<vector<int>> &E){\n\tint V = E.size();\n\tvector<int>\
    \ deg(V, 0);\n\tfor (int i = 0; i < V; i++){\n\t\tfor (int j : E[i]){\n\t\t\t\
    deg[j]++;\n\t\t}\n\t}\n\tqueue<int> Q;\n\tfor (int i = 0; i < V; i++){\n\t\tif\
    \ (deg[i] == 0){\n\t\t\tQ.push(i);\n\t\t}\n\t}\n\twhile (!Q.empty()){\n\t\tint\
    \ v = Q.front();\n\t\tQ.pop();\n\t\tfor (int w : E[v]){\n\t\t\tdeg[w]--;\n\t\t\
    \tif (deg[w] == 0){\n\t\t\t\tQ.push(w);\n\t\t\t}\n\t\t}\n\t}\n\tfor (int i = 0;\
    \ i < V; i++){\n\t\tif (deg[i] != 0){\n\t\t\treturn true;\n\t\t}\n\t}\n\treturn\
    \ false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Detect_Cycle.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Detect_Cycle.cpp
layout: document
redirect_from:
- /library/old_Graph/Detect_Cycle.cpp
- /library/old_Graph/Detect_Cycle.cpp.html
title: old_Graph/Detect_Cycle.cpp
---
