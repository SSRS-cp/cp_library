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
  bundledCode: "#line 1 \"old_Graph/Minimum_Spanning_Tree_(Kruskal).cpp\"\nlong long\
    \ kruskal(vector<vector<pair<int, int>>> &E){\n\tint V = E.size();\n\tvector<tuple<int,\
    \ int, int>> edges;\n\tfor (int i = 0; i < V; i++){\n\t\tfor (auto P : E[i]){\n\
    \t\t\tedges.push_back(make_tuple(P.first, i, P.second));\n\t\t}\n\t}\n\tsort(edges.begin(),\
    \ edges.end());\n\tunionfind UF(V);\n\tlong long ans = 0;\n\tfor (auto e : edges){\n\
    \t\tint c = get<0>(e);\n\t\tint v = get<1>(e);\n\t\tint w = get<2>(e);\n\t\tif\
    \ (!UF.same(v, w)){\n\t\t\tUF.unite(v, w);\n\t\t\tans += c;\n\t\t}\n\t}\n\treturn\
    \ ans;\n}\n"
  code: "long long kruskal(vector<vector<pair<int, int>>> &E){\n\tint V = E.size();\n\
    \tvector<tuple<int, int, int>> edges;\n\tfor (int i = 0; i < V; i++){\n\t\tfor\
    \ (auto P : E[i]){\n\t\t\tedges.push_back(make_tuple(P.first, i, P.second));\n\
    \t\t}\n\t}\n\tsort(edges.begin(), edges.end());\n\tunionfind UF(V);\n\tlong long\
    \ ans = 0;\n\tfor (auto e : edges){\n\t\tint c = get<0>(e);\n\t\tint v = get<1>(e);\n\
    \t\tint w = get<2>(e);\n\t\tif (!UF.same(v, w)){\n\t\t\tUF.unite(v, w);\n\t\t\t\
    ans += c;\n\t\t}\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Minimum_Spanning_Tree_(Kruskal).cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Minimum_Spanning_Tree_(Kruskal).cpp
layout: document
redirect_from:
- /library/old_Graph/Minimum_Spanning_Tree_(Kruskal).cpp
- /library/old_Graph/Minimum_Spanning_Tree_(Kruskal).cpp.html
title: old_Graph/Minimum_Spanning_Tree_(Kruskal).cpp
---
