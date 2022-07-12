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
  bundledCode: "#line 1 \"Graph/All_Pairs_Shortest_Path_(Warshall_Floyd).cpp\"\nvector<vector<long\
    \ long>> warshall_floyd(vector<vector<pair<int, int>>> &E){\n\tint V = E.size();\n\
    \tvector<vector<long long>> d(V, vector<long long>(V, INF));\n\tfor (int i = 0;\
    \ i < V; i++){\n\t\td[i][i] = 0;\n\t}\n\tfor (int i = 0; i < V; i++){\n\t\tfor\
    \ (int j = 0; j < E[i].size(); j++){\n\t\t\td[i][E[i][j].second] = E[i][j].first;\n\
    \t\t}\n\t}\n\tfor (int k = 0; k < V; k++){\n\t\tfor (int i = 0; i < V; i++){\n\
    \t\t\tfor (int j = 0; j < V; j++){\n\t\t\t\tif (d[i][k] != INF && d[k][j] != INF){\n\
    \t\t\t\t\td[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\treturn d;\n}\n"
  code: "vector<vector<long long>> warshall_floyd(vector<vector<pair<int, int>>> &E){\n\
    \tint V = E.size();\n\tvector<vector<long long>> d(V, vector<long long>(V, INF));\n\
    \tfor (int i = 0; i < V; i++){\n\t\td[i][i] = 0;\n\t}\n\tfor (int i = 0; i < V;\
    \ i++){\n\t\tfor (int j = 0; j < E[i].size(); j++){\n\t\t\td[i][E[i][j].second]\
    \ = E[i][j].first;\n\t\t}\n\t}\n\tfor (int k = 0; k < V; k++){\n\t\tfor (int i\
    \ = 0; i < V; i++){\n\t\t\tfor (int j = 0; j < V; j++){\n\t\t\t\tif (d[i][k] !=\
    \ INF && d[k][j] != INF){\n\t\t\t\t\td[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/All_Pairs_Shortest_Path_(Warshall_Floyd).cpp
  requiredBy: []
  timestamp: '2020-03-23 02:41:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/All_Pairs_Shortest_Path_(Warshall_Floyd).cpp
layout: document
redirect_from:
- /library/Graph/All_Pairs_Shortest_Path_(Warshall_Floyd).cpp
- /library/Graph/All_Pairs_Shortest_Path_(Warshall_Floyd).cpp.html
title: Graph/All_Pairs_Shortest_Path_(Warshall_Floyd).cpp
---
