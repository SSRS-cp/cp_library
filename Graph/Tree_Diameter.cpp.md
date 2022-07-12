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
  bundledCode: "#line 1 \"Graph/Tree_Diameter.cpp\"\nlong long tree_diameter(vector<vector<pair<int,\
    \ int>>> &E){\n\tint N = E.size();\n\tvector<long long> d1(N, INF);\n\td1[0] =\
    \ 0;\n\tqueue<int> Q1;\n\tQ1.push(0);\n\twhile (!Q1.empty()){\n\t\tint v = Q1.front();\n\
    \t\tQ1.pop();\n\t\tfor (auto P : E[v]){\n\t\t\tint c = P.first;\n\t\t\tint w =\
    \ P.second;\n\t\t\tif (d1[w] == INF){\n\t\t\t\td1[w] = d1[v] + c;\n\t\t\t\tQ1.push(w);\n\
    \t\t\t}\n\t\t}\n\t}\n\tint s = max_element(d1.begin(), d1.end()) - d1.begin();\n\
    \tvector<long long> d2(N, INF);\n\td2[s] = 0;\n\tqueue<int> Q2;\n\tQ2.push(s);\n\
    \twhile (!Q2.empty()){\n\t\tint v = Q2.front();\n\t\tQ2.pop();\n\t\tfor (auto\
    \ P : E[v]){\n\t\t\tint c = P.first;\n\t\t\tint w = P.second;\n\t\t\tif (d2[w]\
    \ == INF){\n\t\t\t\td2[w] = d2[v] + c;\n\t\t\t\tQ2.push(w);\n\t\t\t}\n\t\t}\n\t\
    }\n\treturn *max_element(d2.begin(), d2.end());\n}\n"
  code: "long long tree_diameter(vector<vector<pair<int, int>>> &E){\n\tint N = E.size();\n\
    \tvector<long long> d1(N, INF);\n\td1[0] = 0;\n\tqueue<int> Q1;\n\tQ1.push(0);\n\
    \twhile (!Q1.empty()){\n\t\tint v = Q1.front();\n\t\tQ1.pop();\n\t\tfor (auto\
    \ P : E[v]){\n\t\t\tint c = P.first;\n\t\t\tint w = P.second;\n\t\t\tif (d1[w]\
    \ == INF){\n\t\t\t\td1[w] = d1[v] + c;\n\t\t\t\tQ1.push(w);\n\t\t\t}\n\t\t}\n\t\
    }\n\tint s = max_element(d1.begin(), d1.end()) - d1.begin();\n\tvector<long long>\
    \ d2(N, INF);\n\td2[s] = 0;\n\tqueue<int> Q2;\n\tQ2.push(s);\n\twhile (!Q2.empty()){\n\
    \t\tint v = Q2.front();\n\t\tQ2.pop();\n\t\tfor (auto P : E[v]){\n\t\t\tint c\
    \ = P.first;\n\t\t\tint w = P.second;\n\t\t\tif (d2[w] == INF){\n\t\t\t\td2[w]\
    \ = d2[v] + c;\n\t\t\t\tQ2.push(w);\n\t\t\t}\n\t\t}\n\t}\n\treturn *max_element(d2.begin(),\
    \ d2.end());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Tree_Diameter.cpp
  requiredBy: []
  timestamp: '2020-06-06 11:31:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Tree_Diameter.cpp
layout: document
redirect_from:
- /library/Graph/Tree_Diameter.cpp
- /library/Graph/Tree_Diameter.cpp.html
title: Graph/Tree_Diameter.cpp
---
