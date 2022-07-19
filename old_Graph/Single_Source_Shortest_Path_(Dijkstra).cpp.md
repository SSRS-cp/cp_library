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
  bundledCode: "#line 1 \"old_Graph/Single_Source_Shortest_Path_(Dijkstra).cpp\"\n\
    vector<long long> dijkstra(vector<vector<pair<int, int>>> &E, int s){\n\tint V\
    \ = E.size();\n\tvector<long long> d(V, INF);\n\td[s] = 0;\n\tpriority_queue<pair<long\
    \ long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;\n\
    \tQ.push(make_pair(0, s));\n\twhile (!Q.empty()){\n\t\tlong long c = Q.top().first;\n\
    \t\tint v = Q.top().second;\n\t\tQ.pop();\n\t\tif (d[v] >= c){\n\t\t\tfor (auto\
    \ P : E[v]){\n\t\t\t\tint w = P.second;\n\t\t\t\tif (d[w] > d[v] + P.first){\n\
    \t\t\t\t\td[w] = d[v] + P.first;\n\t\t\t\t\tQ.push(make_pair(d[w], w));\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\npair<long long, vector<int>> dijkstra_path(vector<vector<pair<int,\
    \ int>>> &E, int s, int t){\n\tint V = E.size();\n\tvector<long long> d(V, INF);\n\
    \td[s] = 0;\n\tvector<int> prev(V);\n\tpriority_queue<pair<long long, int>, vector<pair<long\
    \ long, int>>, greater<pair<long long, int>>> Q;\n\tQ.push(make_pair(0, s));\n\
    \twhile (!Q.empty()){\n\t\tlong long c = Q.top().first;\n\t\tint v = Q.top().second;\n\
    \t\tQ.pop();\n\t\tif (d[v] >= c){\n\t\t\tfor (auto P : E[v]){\n\t\t\t\tint w =\
    \ P.second;\n\t\t\t\tif (d[w] > d[v] + P.first){\n\t\t\t\t\td[w] = d[v] + P.first;\n\
    \t\t\t\t\tQ.push(make_pair(d[w], w));\n\t\t\t\t\tprev[w] = v;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t}\n\tif (d[t] == INF){\n\t\treturn make_pair(-1, vector<int>());\n\
    \t} else {\n\t\tvector<int> path;\n\t\tpath.push_back(t);\n\t\twhile (path.back()\
    \ != s){\n\t\t\tpath.push_back(prev[path.back()]);\n\t\t}\n\t\treverse(path.begin(),\
    \ path.end());\n\t\treturn make_pair(d[t], path);\n\t}\n}\n"
  code: "vector<long long> dijkstra(vector<vector<pair<int, int>>> &E, int s){\n\t\
    int V = E.size();\n\tvector<long long> d(V, INF);\n\td[s] = 0;\n\tpriority_queue<pair<long\
    \ long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;\n\
    \tQ.push(make_pair(0, s));\n\twhile (!Q.empty()){\n\t\tlong long c = Q.top().first;\n\
    \t\tint v = Q.top().second;\n\t\tQ.pop();\n\t\tif (d[v] >= c){\n\t\t\tfor (auto\
    \ P : E[v]){\n\t\t\t\tint w = P.second;\n\t\t\t\tif (d[w] > d[v] + P.first){\n\
    \t\t\t\t\td[w] = d[v] + P.first;\n\t\t\t\t\tQ.push(make_pair(d[w], w));\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\t}\n\treturn d;\n}\npair<long long, vector<int>> dijkstra_path(vector<vector<pair<int,\
    \ int>>> &E, int s, int t){\n\tint V = E.size();\n\tvector<long long> d(V, INF);\n\
    \td[s] = 0;\n\tvector<int> prev(V);\n\tpriority_queue<pair<long long, int>, vector<pair<long\
    \ long, int>>, greater<pair<long long, int>>> Q;\n\tQ.push(make_pair(0, s));\n\
    \twhile (!Q.empty()){\n\t\tlong long c = Q.top().first;\n\t\tint v = Q.top().second;\n\
    \t\tQ.pop();\n\t\tif (d[v] >= c){\n\t\t\tfor (auto P : E[v]){\n\t\t\t\tint w =\
    \ P.second;\n\t\t\t\tif (d[w] > d[v] + P.first){\n\t\t\t\t\td[w] = d[v] + P.first;\n\
    \t\t\t\t\tQ.push(make_pair(d[w], w));\n\t\t\t\t\tprev[w] = v;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t}\n\tif (d[t] == INF){\n\t\treturn make_pair(-1, vector<int>());\n\
    \t} else {\n\t\tvector<int> path;\n\t\tpath.push_back(t);\n\t\twhile (path.back()\
    \ != s){\n\t\t\tpath.push_back(prev[path.back()]);\n\t\t}\n\t\treverse(path.begin(),\
    \ path.end());\n\t\treturn make_pair(d[t], path);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Single_Source_Shortest_Path_(Dijkstra).cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Single_Source_Shortest_Path_(Dijkstra).cpp
layout: document
redirect_from:
- /library/old_Graph/Single_Source_Shortest_Path_(Dijkstra).cpp
- /library/old_Graph/Single_Source_Shortest_Path_(Dijkstra).cpp.html
title: old_Graph/Single_Source_Shortest_Path_(Dijkstra).cpp
---
