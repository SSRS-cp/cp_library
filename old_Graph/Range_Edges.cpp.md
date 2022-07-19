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
  bundledCode: "#line 1 \"old_Graph/Range_Edges.cpp\"\ntemplate <typename T>\nstruct\
    \ range_edges{\n\tint N;\n\tint V;\n\tvector<vector<pair<T, int>>> E;\n\trange_edges(int\
    \ n){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tV = N * 5 - 2;\n\
    \t\tE = vector<vector<pair<T, int>>>(V);\n\t\tfor (int i = 0; i < N - 1; i++){\n\
    \t\t\tE[i].emplace_back(0, i * 2 + 1);\n\t\t\tE[i].emplace_back(0, i * 2 + 2);\n\
    \t\t\tE[i * 2 + N * 2].emplace_back(0, i + N * 2 - 1);\n\t\t\tE[i * 2 + N * 2\
    \ + 1].emplace_back(0, i + N * 2 - 1);\n\t\t}\n\t\tfor (int i = 0; i < N; i++){\n\
    \t\t\tE[N - 1 + i].emplace_back(0, N * 4 - 2 + i);\n\t\t\tE[N * 4 - 2 + i].emplace_back(0,\
    \ N * 3 - 2 + i);\n\t\t}\n\t}\n\tvoid add_edge_from(int L, int R, int v, int i,\
    \ int l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn;\n\t\t} else if (L\
    \ <= l && r <= R){\n\t\t\tE[i + N * 2 - 1].emplace_back(0, v);\n\t\t} else {\n\
    \t\t\tint m = (l + r) / 2;\n\t\t\tadd_edge_from(L, R, v, i * 2 + 1, l, m);\n\t\
    \t\tadd_edge_from(L, R, v, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tvoid add_edge_from(int\
    \ L, int R, int v){\n\t\tadd_edge_from(L, R, v, 0, 0, N);\n\t}\n\tvoid add_edge_to(int\
    \ L, int R, int v, int i, int l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn;\n\
    \t\t} else if (L <= l && r <= R){\n\t\t\tE[v].emplace_back(0, i);\n\t\t} else\
    \ {\n\t\t\tint m = (l + r) / 2;\n\t\t\tadd_edge_to(L, R, v, i * 2 + 1, l, m);\n\
    \t\t\tadd_edge_to(L, R, v, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tvoid add_edge_to(int\
    \ L, int R, int v){\n\t\tadd_edge_to(L, R, v, 0, 0, N);\n\t}\n\tvoid add_edge(int\
    \ L1, int R1, int L2, int R2, T cost){\n\t\tE.emplace_back();\n\t\tE.emplace_back();\n\
    \t\tV += 2;\n\t\tadd_edge_from(L1, R1, V - 2);\n\t\tadd_edge_to(L2, R2, V - 1);\n\
    \t\tE[V - 2].emplace_back(cost, V - 1);\n\t}\n\tvoid debug(){\n\t\tfor (int i\
    \ = 0; i < V; i++){\n\t\t\tcout << i << \":\";\n\t\t\tfor (auto P : E[i]){\n\t\
    \t\t\tcout << \" (\" << P.first << \",\" << P.second << \")\";\n\t\t\t}\n\t\t\t\
    cout << endl;\n\t\t}\n\t}\n};\n"
  code: "template <typename T>\nstruct range_edges{\n\tint N;\n\tint V;\n\tvector<vector<pair<T,\
    \ int>>> E;\n\trange_edges(int n){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *=\
    \ 2;\n\t\t}\n\t\tV = N * 5 - 2;\n\t\tE = vector<vector<pair<T, int>>>(V);\n\t\t\
    for (int i = 0; i < N - 1; i++){\n\t\t\tE[i].emplace_back(0, i * 2 + 1);\n\t\t\
    \tE[i].emplace_back(0, i * 2 + 2);\n\t\t\tE[i * 2 + N * 2].emplace_back(0, i +\
    \ N * 2 - 1);\n\t\t\tE[i * 2 + N * 2 + 1].emplace_back(0, i + N * 2 - 1);\n\t\t\
    }\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tE[N - 1 + i].emplace_back(0, N * 4\
    \ - 2 + i);\n\t\t\tE[N * 4 - 2 + i].emplace_back(0, N * 3 - 2 + i);\n\t\t}\n\t\
    }\n\tvoid add_edge_from(int L, int R, int v, int i, int l, int r){\n\t\tif (R\
    \ <= l || r <= L){\n\t\t\treturn;\n\t\t} else if (L <= l && r <= R){\n\t\t\tE[i\
    \ + N * 2 - 1].emplace_back(0, v);\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\
    \t\t\tadd_edge_from(L, R, v, i * 2 + 1, l, m);\n\t\t\tadd_edge_from(L, R, v, i\
    \ * 2 + 2, m, r);\n\t\t}\n\t}\n\tvoid add_edge_from(int L, int R, int v){\n\t\t\
    add_edge_from(L, R, v, 0, 0, N);\n\t}\n\tvoid add_edge_to(int L, int R, int v,\
    \ int i, int l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn;\n\t\t} else\
    \ if (L <= l && r <= R){\n\t\t\tE[v].emplace_back(0, i);\n\t\t} else {\n\t\t\t\
    int m = (l + r) / 2;\n\t\t\tadd_edge_to(L, R, v, i * 2 + 1, l, m);\n\t\t\tadd_edge_to(L,\
    \ R, v, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tvoid add_edge_to(int L, int R, int v){\n\
    \t\tadd_edge_to(L, R, v, 0, 0, N);\n\t}\n\tvoid add_edge(int L1, int R1, int L2,\
    \ int R2, T cost){\n\t\tE.emplace_back();\n\t\tE.emplace_back();\n\t\tV += 2;\n\
    \t\tadd_edge_from(L1, R1, V - 2);\n\t\tadd_edge_to(L2, R2, V - 1);\n\t\tE[V -\
    \ 2].emplace_back(cost, V - 1);\n\t}\n\tvoid debug(){\n\t\tfor (int i = 0; i <\
    \ V; i++){\n\t\t\tcout << i << \":\";\n\t\t\tfor (auto P : E[i]){\n\t\t\t\tcout\
    \ << \" (\" << P.first << \",\" << P.second << \")\";\n\t\t\t}\n\t\t\tcout <<\
    \ endl;\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Range_Edges.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Range_Edges.cpp
layout: document
redirect_from:
- /library/old_Graph/Range_Edges.cpp
- /library/old_Graph/Range_Edges.cpp.html
title: old_Graph/Range_Edges.cpp
---
