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
  bundledCode: "#line 1 \"Graph/Strongly_Connected_Component_Decomposition.cpp\"\n\
    struct strongly_connected_components{\n\tint cnt = 0;\n\tvector<int> scc;\n\t\
    void dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v){\n\
    \t\tfor (int w : E[v]){\n\t\t\tif (!used[w]){\n\t\t\t\tused[w] = true;\n\t\t\t\
    \tdfs1(E, t, used, w);\n\t\t\t}\n\t\t}\n\t\tt.push_back(v);\n\t}\n\tvoid dfs2(vector<vector<int>>\
    \ &E2, vector<bool> &used2, int v){\n\t\tscc[v] = cnt;\n\t\tfor (int w : E2[v]){\n\
    \t\t\tif (!used2[w]){\n\t\t\t\tused2[w] = true;\n\t\t\t\tdfs2(E2, used2, w);\n\
    \t\t\t}\n\t\t}\n\t}\n\tstrongly_connected_components(vector<vector<int>> &E){\n\
    \t\tint N = E.size();\n\t\tvector<vector<int>> E2(N);\n\t\tfor (int i = 0; i <\
    \ N; i++){\n\t\t\tfor (int j : E[i]){\n\t\t\t\tE2[j].push_back(i);\n\t\t\t}\n\t\
    \t}\n\t\tvector<int> t;\n\t\tvector<bool> used(N, false);\n\t\tfor (int i = 0;\
    \ i < N; i++){\n\t\t\tif (!used[i]){\n\t\t\t\tused[i] = true;\n\t\t\t\tdfs1(E,\
    \ t, used, i);\n\t\t\t}\n\t\t}\n\t\treverse(t.begin(), t.end());\n\t\tvector<bool>\
    \ used2(N, false);\n\t\tscc = vector<int>(N);\n\t\tfor (int i = 0; i < N; i++){\n\
    \t\t\tif (!used2[t[i]]){\n\t\t\t\tused2[t[i]] = true;\n\t\t\t\tdfs2(E2, used2,\
    \ t[i]);\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\t}\n\tint operator [](int k){\n\t\t\
    return scc[k];\n\t}\n\tint size(){\n\t\treturn cnt;\n\t}\n};\n"
  code: "struct strongly_connected_components{\n\tint cnt = 0;\n\tvector<int> scc;\n\
    \tvoid dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v){\n\
    \t\tfor (int w : E[v]){\n\t\t\tif (!used[w]){\n\t\t\t\tused[w] = true;\n\t\t\t\
    \tdfs1(E, t, used, w);\n\t\t\t}\n\t\t}\n\t\tt.push_back(v);\n\t}\n\tvoid dfs2(vector<vector<int>>\
    \ &E2, vector<bool> &used2, int v){\n\t\tscc[v] = cnt;\n\t\tfor (int w : E2[v]){\n\
    \t\t\tif (!used2[w]){\n\t\t\t\tused2[w] = true;\n\t\t\t\tdfs2(E2, used2, w);\n\
    \t\t\t}\n\t\t}\n\t}\n\tstrongly_connected_components(vector<vector<int>> &E){\n\
    \t\tint N = E.size();\n\t\tvector<vector<int>> E2(N);\n\t\tfor (int i = 0; i <\
    \ N; i++){\n\t\t\tfor (int j : E[i]){\n\t\t\t\tE2[j].push_back(i);\n\t\t\t}\n\t\
    \t}\n\t\tvector<int> t;\n\t\tvector<bool> used(N, false);\n\t\tfor (int i = 0;\
    \ i < N; i++){\n\t\t\tif (!used[i]){\n\t\t\t\tused[i] = true;\n\t\t\t\tdfs1(E,\
    \ t, used, i);\n\t\t\t}\n\t\t}\n\t\treverse(t.begin(), t.end());\n\t\tvector<bool>\
    \ used2(N, false);\n\t\tscc = vector<int>(N);\n\t\tfor (int i = 0; i < N; i++){\n\
    \t\t\tif (!used2[t[i]]){\n\t\t\t\tused2[t[i]] = true;\n\t\t\t\tdfs2(E2, used2,\
    \ t[i]);\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\t}\n\tint operator [](int k){\n\t\t\
    return scc[k];\n\t}\n\tint size(){\n\t\treturn cnt;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Strongly_Connected_Component_Decomposition.cpp
  requiredBy: []
  timestamp: '2022-06-14 03:20:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Strongly_Connected_Component_Decomposition.cpp
layout: document
redirect_from:
- /library/Graph/Strongly_Connected_Component_Decomposition.cpp
- /library/Graph/Strongly_Connected_Component_Decomposition.cpp.html
title: Graph/Strongly_Connected_Component_Decomposition.cpp
---
