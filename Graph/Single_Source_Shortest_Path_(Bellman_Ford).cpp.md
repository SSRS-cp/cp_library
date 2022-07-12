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
  bundledCode: "#line 1 \"Graph/Single_Source_Shortest_Path_(Bellman_Ford).cpp\"\n\
    vector<long long> bellman_ford(vector<vector<pair<int, int>>> &E, int s){\n\t\
    int V = E.size();\n\tvector<long long> d(V, INF);\n\td[s] = 0;\n\twhile (1){\n\
    \t\tbool update = false;\n\t\tfor (int i = 0; i < V; i++){\n\t\t\tfor (int j =\
    \ 0; j < E[i].size(); j++){\n\t\t\t\tint c = E[i][j].first;\n\t\t\t\tint v = E[i][j].second;\n\
    \t\t\t\tif (d[v] > d[i] + c && d[i] != INF){\n\t\t\t\t\td[v] = d[i] + c;\n\t\t\
    \t\t\tupdate = true;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (!update){\n\t\t\tbreak;\n\
    \t\t}\n\t}\n\treturn d;\n}\nbool detect_negative_cycles(vector<vector<pair<int,\
    \ int>>> &E, int s){\n\tint V = E.size();\n\tvector<long long> d(V, INF);\n\t\
    d[s] = 0;\n\tfor (int i = 0; i < V; i++){\n\t\tbool update = false;\n\t\tfor (int\
    \ j = 0; j < V; j++){\n\t\t\tfor (int k = 0; k < E[j].size(); k++){\n\t\t\t\t\
    int c = E[j][k].first;\n\t\t\t\tint v = E[j][k].second;\n\t\t\t\tif (d[v] > d[j]\
    \ + c && d[j] != INF){\n\t\t\t\t\td[v] = d[j] + c;\n\t\t\t\t\tupdate = true;\n\
    \t\t\t\t\tif (i == V - 1){\n\t\t\t\t\t\treturn true;\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\tif (!update){\n\t\t\tbreak;\n\t\t}\n\t}\n\treturn false;\n\
    }\nbool detect_negative_cycles_2(vector<vector<pair<int, int>>> &E){\n\tint V\
    \ = E.size();\n\tvector<long long> d(V, 0);\n\tfor (int i = 0; i < V; i++){\n\t\
    \tbool update = false;\n\t\tfor (int j = 0; j < V; j++){\n\t\t\tfor (int k = 0;\
    \ k < E[j].size(); k++){\n\t\t\t\tint c = E[j][k].first;\n\t\t\t\tint v = E[j][k].second;\n\
    \t\t\t\tif (d[v] > d[j] + c && d[j] != INF){\n\t\t\t\t\td[v] = d[j] + c;\n\t\t\
    \t\t\tupdate = true;\n\t\t\t\t\tif (i == V - 1){\n\t\t\t\t\t\treturn true;\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (!update){\n\t\t\tbreak;\n\t\t}\n\
    \t}\n\treturn false;\n}\nvector<bool> find_negative_cycles(vector<vector<pair<int,\
    \ int>>> &E){\n\tint V = E.size();\n\tvector<long long> d(V, 0);\n\tfor (int i\
    \ = 0; i < V; i++){\n\t\tbool update = false;\n\t\tfor (int j = 0; j < V; j++){\n\
    \t\t\tfor (int k = 0; k < E[j].size(); k++){\n\t\t\t\tint c = E[j][k].first;\n\
    \t\t\t\tint v = E[j][k].second;\n\t\t\t\tif (d[v] > d[j] + c){\n\t\t\t\t\td[v]\
    \ = d[j] + c;\n\t\t\t\t\tupdate = true;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (!update){\n\
    \t\t\tbreak;\n\t\t}\n\t}\n\tvector<bool> res(V, false);\n\tfor (int i = 0; i <\
    \ V; i++){\n\t\tif (d[i] < 0){\n\t\t\tres[i] = true;\n\t\t}\n\t}\n\treturn res;\n\
    }\n"
  code: "vector<long long> bellman_ford(vector<vector<pair<int, int>>> &E, int s){\n\
    \tint V = E.size();\n\tvector<long long> d(V, INF);\n\td[s] = 0;\n\twhile (1){\n\
    \t\tbool update = false;\n\t\tfor (int i = 0; i < V; i++){\n\t\t\tfor (int j =\
    \ 0; j < E[i].size(); j++){\n\t\t\t\tint c = E[i][j].first;\n\t\t\t\tint v = E[i][j].second;\n\
    \t\t\t\tif (d[v] > d[i] + c && d[i] != INF){\n\t\t\t\t\td[v] = d[i] + c;\n\t\t\
    \t\t\tupdate = true;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (!update){\n\t\t\tbreak;\n\
    \t\t}\n\t}\n\treturn d;\n}\nbool detect_negative_cycles(vector<vector<pair<int,\
    \ int>>> &E, int s){\n\tint V = E.size();\n\tvector<long long> d(V, INF);\n\t\
    d[s] = 0;\n\tfor (int i = 0; i < V; i++){\n\t\tbool update = false;\n\t\tfor (int\
    \ j = 0; j < V; j++){\n\t\t\tfor (int k = 0; k < E[j].size(); k++){\n\t\t\t\t\
    int c = E[j][k].first;\n\t\t\t\tint v = E[j][k].second;\n\t\t\t\tif (d[v] > d[j]\
    \ + c && d[j] != INF){\n\t\t\t\t\td[v] = d[j] + c;\n\t\t\t\t\tupdate = true;\n\
    \t\t\t\t\tif (i == V - 1){\n\t\t\t\t\t\treturn true;\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\tif (!update){\n\t\t\tbreak;\n\t\t}\n\t}\n\treturn false;\n\
    }\nbool detect_negative_cycles_2(vector<vector<pair<int, int>>> &E){\n\tint V\
    \ = E.size();\n\tvector<long long> d(V, 0);\n\tfor (int i = 0; i < V; i++){\n\t\
    \tbool update = false;\n\t\tfor (int j = 0; j < V; j++){\n\t\t\tfor (int k = 0;\
    \ k < E[j].size(); k++){\n\t\t\t\tint c = E[j][k].first;\n\t\t\t\tint v = E[j][k].second;\n\
    \t\t\t\tif (d[v] > d[j] + c && d[j] != INF){\n\t\t\t\t\td[v] = d[j] + c;\n\t\t\
    \t\t\tupdate = true;\n\t\t\t\t\tif (i == V - 1){\n\t\t\t\t\t\treturn true;\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (!update){\n\t\t\tbreak;\n\t\t}\n\
    \t}\n\treturn false;\n}\nvector<bool> find_negative_cycles(vector<vector<pair<int,\
    \ int>>> &E){\n\tint V = E.size();\n\tvector<long long> d(V, 0);\n\tfor (int i\
    \ = 0; i < V; i++){\n\t\tbool update = false;\n\t\tfor (int j = 0; j < V; j++){\n\
    \t\t\tfor (int k = 0; k < E[j].size(); k++){\n\t\t\t\tint c = E[j][k].first;\n\
    \t\t\t\tint v = E[j][k].second;\n\t\t\t\tif (d[v] > d[j] + c){\n\t\t\t\t\td[v]\
    \ = d[j] + c;\n\t\t\t\t\tupdate = true;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (!update){\n\
    \t\t\tbreak;\n\t\t}\n\t}\n\tvector<bool> res(V, false);\n\tfor (int i = 0; i <\
    \ V; i++){\n\t\tif (d[i] < 0){\n\t\t\tres[i] = true;\n\t\t}\n\t}\n\treturn res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Single_Source_Shortest_Path_(Bellman_Ford).cpp
  requiredBy: []
  timestamp: '2020-03-22 17:12:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Single_Source_Shortest_Path_(Bellman_Ford).cpp
layout: document
redirect_from:
- /library/Graph/Single_Source_Shortest_Path_(Bellman_Ford).cpp
- /library/Graph/Single_Source_Shortest_Path_(Bellman_Ford).cpp.html
title: Graph/Single_Source_Shortest_Path_(Bellman_Ford).cpp
---
