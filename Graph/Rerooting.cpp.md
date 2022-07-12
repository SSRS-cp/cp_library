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
  bundledCode: "#line 1 \"Graph/Rerooting.cpp\"\ntemplate <typename T>\nstruct rerooting{\n\
    \tvector<T> dp1;\n\tvector<T> dp2;\n\tT E;\n\tfunction<T(T, T)> add;\n\tfunction<T(T)>\
    \ root;\n\tvoid dfs1(vector<vector<int>> &c, int v){\n\t\tdp1[v] = E;\n\t\tfor\
    \ (auto w : c[v]){\n\t\t\tdfs1(c, w);\n\t\t\tdp1[v] = add(dp1[v], root(dp1[w]));\n\
    \t\t}\n\t}\n\tvoid dfs2(vector<vector<int>> &c, int v){\n\t\tint deg = c[v].size();\n\
    \t\tvector<T> L(deg + 1, E);\n\t\tfor (int i = 0; i < deg; i++){\n\t\t\tL[i +\
    \ 1] = add(L[i], root(dp1[c[v][i]]));\n\t\t}\n\t\tvector<T> R(deg + 1, E);\n\t\
    \tfor (int i = deg - 1; i >= 0; i--){\n\t\t\tR[i] = add(R[i + 1], root(dp1[c[v][i]]));\n\
    \t\t}\n\t\tfor (int i = 0; i < deg; i++){\n\t\t\tdp2[c[v][i]] = root(add(dp2[v],\
    \ add(L[i], R[i + 1])));\n\t\t\tdfs2(c, c[v][i]);\n\t\t}\n\t}\n\trerooting(vector<vector<int>>\
    \ &c, function<T(T, T)> add, function<T(T)> root, T E): add(add), root(root),\
    \ E(E){\n\t\tint N = c.size();\n\t\tdp1 = vector<T>(N, E);\n\t\tdfs1(c, 0);\n\t\
    \tdp2 = vector<T>(N, E);\n\t\tdfs2(c, 0);\n\t}\n\tT operator [](int k){\n\t\t\
    return add(dp1[k], dp2[k]);\n\t}\n};\nstruct rerooting{\n\tvector<T> dp1;\n\t\
    vector<T> dp2;\n\tT E;\n\tfunction<T(T, T)> add;\n\tfunction<T(T, T)> root;\n\t\
    void dfs1(vector<vector<pair<int, int>>> &c, int v){\n\t\tdp1[v] = E;\n\t\tfor\
    \ (auto P : c[v]){\n\t\t\tint w = P.second;\n\t\t\tdfs1(c, w);\n\t\t\tdp1[v] =\
    \ add(dp1[v], root(dp1[w], P.first));\n\t\t}\n\t}\n\tvoid dfs2(vector<vector<pair<int,\
    \ int>>> &c, int v){\n\t\tint deg = c[v].size();\n\t\tvector<T> L(deg + 1, E);\n\
    \t\tfor (int i = 0; i < deg; i++){\n\t\t\tL[i + 1] = add(L[i], root(dp1[c[v][i].second],\
    \ c[v][i].first));\n\t\t}\n\t\tvector<T> R(deg + 1, E);\n\t\tfor (int i = deg\
    \ - 1; i >= 0; i--){\n\t\t\tR[i] = add(R[i + 1], root(dp1[c[v][i].second], c[v][i].first));\n\
    \t\t}\n\t\tfor (int i = 0; i < deg; i++){\n\t\t\tdp2[c[v][i].second] = root(add(dp2[v],\
    \ add(L[i], R[i + 1])), c[v][i].first);\n\t\t\tdfs2(c, c[v][i].second);\n\t\t\
    }\n\t}\n\trerooting(vector<vector<pair<int, int>>> &c, function<T(T, T)> add,\
    \ function<T(T, T)> root, T E): add(add), root(root), E(E){\n\t\tint N = c.size();\n\
    \t\tdp1 = vector<T>(N);\n\t\tdfs1(c, 0);\n\t\tdp2 = vector<T>(N);\n\t\tdfs2(c,\
    \ 0);\n\t}\n\tT operator [](int k){\n\t\treturn add(dp1[k], dp2[k]);\n\t}\n};\n"
  code: "template <typename T>\nstruct rerooting{\n\tvector<T> dp1;\n\tvector<T> dp2;\n\
    \tT E;\n\tfunction<T(T, T)> add;\n\tfunction<T(T)> root;\n\tvoid dfs1(vector<vector<int>>\
    \ &c, int v){\n\t\tdp1[v] = E;\n\t\tfor (auto w : c[v]){\n\t\t\tdfs1(c, w);\n\t\
    \t\tdp1[v] = add(dp1[v], root(dp1[w]));\n\t\t}\n\t}\n\tvoid dfs2(vector<vector<int>>\
    \ &c, int v){\n\t\tint deg = c[v].size();\n\t\tvector<T> L(deg + 1, E);\n\t\t\
    for (int i = 0; i < deg; i++){\n\t\t\tL[i + 1] = add(L[i], root(dp1[c[v][i]]));\n\
    \t\t}\n\t\tvector<T> R(deg + 1, E);\n\t\tfor (int i = deg - 1; i >= 0; i--){\n\
    \t\t\tR[i] = add(R[i + 1], root(dp1[c[v][i]]));\n\t\t}\n\t\tfor (int i = 0; i\
    \ < deg; i++){\n\t\t\tdp2[c[v][i]] = root(add(dp2[v], add(L[i], R[i + 1])));\n\
    \t\t\tdfs2(c, c[v][i]);\n\t\t}\n\t}\n\trerooting(vector<vector<int>> &c, function<T(T,\
    \ T)> add, function<T(T)> root, T E): add(add), root(root), E(E){\n\t\tint N =\
    \ c.size();\n\t\tdp1 = vector<T>(N, E);\n\t\tdfs1(c, 0);\n\t\tdp2 = vector<T>(N,\
    \ E);\n\t\tdfs2(c, 0);\n\t}\n\tT operator [](int k){\n\t\treturn add(dp1[k], dp2[k]);\n\
    \t}\n};\nstruct rerooting{\n\tvector<T> dp1;\n\tvector<T> dp2;\n\tT E;\n\tfunction<T(T,\
    \ T)> add;\n\tfunction<T(T, T)> root;\n\tvoid dfs1(vector<vector<pair<int, int>>>\
    \ &c, int v){\n\t\tdp1[v] = E;\n\t\tfor (auto P : c[v]){\n\t\t\tint w = P.second;\n\
    \t\t\tdfs1(c, w);\n\t\t\tdp1[v] = add(dp1[v], root(dp1[w], P.first));\n\t\t}\n\
    \t}\n\tvoid dfs2(vector<vector<pair<int, int>>> &c, int v){\n\t\tint deg = c[v].size();\n\
    \t\tvector<T> L(deg + 1, E);\n\t\tfor (int i = 0; i < deg; i++){\n\t\t\tL[i +\
    \ 1] = add(L[i], root(dp1[c[v][i].second], c[v][i].first));\n\t\t}\n\t\tvector<T>\
    \ R(deg + 1, E);\n\t\tfor (int i = deg - 1; i >= 0; i--){\n\t\t\tR[i] = add(R[i\
    \ + 1], root(dp1[c[v][i].second], c[v][i].first));\n\t\t}\n\t\tfor (int i = 0;\
    \ i < deg; i++){\n\t\t\tdp2[c[v][i].second] = root(add(dp2[v], add(L[i], R[i +\
    \ 1])), c[v][i].first);\n\t\t\tdfs2(c, c[v][i].second);\n\t\t}\n\t}\n\trerooting(vector<vector<pair<int,\
    \ int>>> &c, function<T(T, T)> add, function<T(T, T)> root, T E): add(add), root(root),\
    \ E(E){\n\t\tint N = c.size();\n\t\tdp1 = vector<T>(N);\n\t\tdfs1(c, 0);\n\t\t\
    dp2 = vector<T>(N);\n\t\tdfs2(c, 0);\n\t}\n\tT operator [](int k){\n\t\treturn\
    \ add(dp1[k], dp2[k]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Rerooting.cpp
  requiredBy: []
  timestamp: '2020-06-06 17:10:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Rerooting.cpp
layout: document
redirect_from:
- /library/Graph/Rerooting.cpp
- /library/Graph/Rerooting.cpp.html
title: Graph/Rerooting.cpp
---
