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
  bundledCode: "#line 1 \"Graph/Bipartite_Matching.cpp\"\nint bipartite_matching(vector<pair<int,\
    \ int>> &E, int X, int Y){\n\tint V = X + Y + 2;\n\tvector<set<int>> E2(V);\n\t\
    for (int i = 0; i < X; i++){\n\t\tE2[0].insert(i + 1);\n\t}\n\tfor (int i = 0;\
    \ i < E.size(); i++){\n\t\tint v = E[i].first;\n\t\tint w = E[i].second;\n\t\t\
    E2[v + 1].insert(X + 1 + w);\n\t}\n\tfor (int i = X + 1; i < V - 1; i++){\n\t\t\
    E2[i].insert(V - 1);\n\t}\n\tint F = 0;\n\twhile (1){\n\t\tvector<bool> used(V,\
    \ false);\n\t\tvector<int> prev(V, -1);\n\t\tused[0] = true;\n\t\tqueue<int> Q;\n\
    \t\tQ.push(0);\n\t\twhile (!Q.empty()){\n\t\t\tint v = Q.front();\n\t\t\tQ.pop();\n\
    \t\t\tfor (int w : E2[v]){\n\t\t\t\tif (!used[w]){\n\t\t\t\t\tused[w] = true;\n\
    \t\t\t\t\tprev[w] = v;\n\t\t\t\t\tQ.push(w);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    if (!used[V - 1]){\n\t\t\tbreak;\n\t\t}\n\t\tint c = V - 1;\n\t\twhile (c != 0){\n\
    \t\t\tE2[prev[c]].erase(c);\n\t\t\tE2[c].insert(prev[c]);\n\t\t\tc = prev[c];\n\
    \t\t}\n\t\tF++;\n\t}\n\treturn F;\n}\n"
  code: "int bipartite_matching(vector<pair<int, int>> &E, int X, int Y){\n\tint V\
    \ = X + Y + 2;\n\tvector<set<int>> E2(V);\n\tfor (int i = 0; i < X; i++){\n\t\t\
    E2[0].insert(i + 1);\n\t}\n\tfor (int i = 0; i < E.size(); i++){\n\t\tint v =\
    \ E[i].first;\n\t\tint w = E[i].second;\n\t\tE2[v + 1].insert(X + 1 + w);\n\t\
    }\n\tfor (int i = X + 1; i < V - 1; i++){\n\t\tE2[i].insert(V - 1);\n\t}\n\tint\
    \ F = 0;\n\twhile (1){\n\t\tvector<bool> used(V, false);\n\t\tvector<int> prev(V,\
    \ -1);\n\t\tused[0] = true;\n\t\tqueue<int> Q;\n\t\tQ.push(0);\n\t\twhile (!Q.empty()){\n\
    \t\t\tint v = Q.front();\n\t\t\tQ.pop();\n\t\t\tfor (int w : E2[v]){\n\t\t\t\t\
    if (!used[w]){\n\t\t\t\t\tused[w] = true;\n\t\t\t\t\tprev[w] = v;\n\t\t\t\t\t\
    Q.push(w);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (!used[V - 1]){\n\t\t\tbreak;\n\t\
    \t}\n\t\tint c = V - 1;\n\t\twhile (c != 0){\n\t\t\tE2[prev[c]].erase(c);\n\t\t\
    \tE2[c].insert(prev[c]);\n\t\t\tc = prev[c];\n\t\t}\n\t\tF++;\n\t}\n\treturn F;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Bipartite_Matching.cpp
  requiredBy: []
  timestamp: '2020-06-06 20:48:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Bipartite_Matching.cpp
layout: document
redirect_from:
- /library/Graph/Bipartite_Matching.cpp
- /library/Graph/Bipartite_Matching.cpp.html
title: Graph/Bipartite_Matching.cpp
---
