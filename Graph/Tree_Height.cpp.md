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
  bundledCode: "#line 1 \"Graph/Tree_Height.cpp\"\nvector<int> tree_height(vector<vector<int>>\
    \ &E){\n\tint N = E.size();\n\tvector<int> d(N, -1);\n\td[0] = 0;\n\tqueue<int>\
    \ Q;\n\tQ.push(0);\n\twhile (!Q.empty()){\n\t\tint v = Q.front();\n\t\tQ.pop();\n\
    \t\tfor (int w : E[v]){\n\t\t\tif (d[w] == -1){\n\t\t\t\td[w] = d[v] + 1;\n\t\t\
    \t\tQ.push(w);\n\t\t\t}\n\t\t}\n\t}\n\tint s = max_element(d.begin(), d.end())\
    \ - d.begin();\n\tvector<int> d2(N, -1);\n\td2[s] = 0;\n\tqueue<int> Q2;\n\tQ2.push(s);\n\
    \twhile (!Q2.empty()){\n\t\tint v = Q2.front();\n\t\tQ2.pop();\n\t\tfor (int w\
    \ : E[v]){\n\t\t\tif (d2[w] == -1){\n\t\t\t\td2[w] = d2[v] + 1;\n\t\t\t\tQ2.push(w);\n\
    \t\t\t}\n\t\t}\n\t}\n\tint t = max_element(d2.begin(), d2.end()) - d2.begin();\n\
    \tvector<int> d3(N, -1);\n\td3[t] = 0;\n\tqueue<int> Q3;\n\tQ3.push(t);\n\twhile\
    \ (!Q3.empty()){\n\t\tint v = Q3.front();\n\t\tQ3.pop();\n\t\tfor (int w : E[v]){\n\
    \t\t\tif (d3[w] == -1){\n\t\t\t\td3[w] = d3[v] + 1;\n\t\t\t\tQ3.push(w);\n\t\t\
    \t}\n\t\t}\n\t}\n\tvector<int> ans(N);\n\tfor (int i = 0; i < N; i++){\n\t\tans[i]\
    \ = max(d2[i], d3[i]);\n\t}\n\treturn ans;\n}\n"
  code: "vector<int> tree_height(vector<vector<int>> &E){\n\tint N = E.size();\n\t\
    vector<int> d(N, -1);\n\td[0] = 0;\n\tqueue<int> Q;\n\tQ.push(0);\n\twhile (!Q.empty()){\n\
    \t\tint v = Q.front();\n\t\tQ.pop();\n\t\tfor (int w : E[v]){\n\t\t\tif (d[w]\
    \ == -1){\n\t\t\t\td[w] = d[v] + 1;\n\t\t\t\tQ.push(w);\n\t\t\t}\n\t\t}\n\t}\n\
    \tint s = max_element(d.begin(), d.end()) - d.begin();\n\tvector<int> d2(N, -1);\n\
    \td2[s] = 0;\n\tqueue<int> Q2;\n\tQ2.push(s);\n\twhile (!Q2.empty()){\n\t\tint\
    \ v = Q2.front();\n\t\tQ2.pop();\n\t\tfor (int w : E[v]){\n\t\t\tif (d2[w] ==\
    \ -1){\n\t\t\t\td2[w] = d2[v] + 1;\n\t\t\t\tQ2.push(w);\n\t\t\t}\n\t\t}\n\t}\n\
    \tint t = max_element(d2.begin(), d2.end()) - d2.begin();\n\tvector<int> d3(N,\
    \ -1);\n\td3[t] = 0;\n\tqueue<int> Q3;\n\tQ3.push(t);\n\twhile (!Q3.empty()){\n\
    \t\tint v = Q3.front();\n\t\tQ3.pop();\n\t\tfor (int w : E[v]){\n\t\t\tif (d3[w]\
    \ == -1){\n\t\t\t\td3[w] = d3[v] + 1;\n\t\t\t\tQ3.push(w);\n\t\t\t}\n\t\t}\n\t\
    }\n\tvector<int> ans(N);\n\tfor (int i = 0; i < N; i++){\n\t\tans[i] = max(d2[i],\
    \ d3[i]);\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Tree_Height.cpp
  requiredBy: []
  timestamp: '2020-07-20 23:30:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Tree_Height.cpp
layout: document
redirect_from:
- /library/Graph/Tree_Height.cpp
- /library/Graph/Tree_Height.cpp.html
title: Graph/Tree_Height.cpp
---
