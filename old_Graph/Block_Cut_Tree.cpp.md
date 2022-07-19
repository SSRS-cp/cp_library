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
  bundledCode: "#line 1 \"old_Graph/Block_Cut_Tree.cpp\"\nstruct block_cut_tree{\n\
    \  int V;\n  vector<bool> cut;\n  vector<vector<int>> G;\n  vector<vector<int>>\
    \ node;\n  block_cut_tree(vector<vector<int>> &E){\n    int N = E.size();\n  \
    \  int M = 0;\n    vector<vector<pair<int, int>>> E2(N);\n    for (int i = 0;\
    \ i < N; i++){\n      for (int j : E[i]){\n        if (j > i){\n          E2[i].push_back(make_pair(M,\
    \ j));\n          E2[j].push_back(make_pair(M, i));\n          M++;\n        }\n\
    \      }\n    }\n    biconnected_components B(E2);\n    vector<bool> art(N, false);\n\
    \    int cnt = 0;\n    for (int i = 0; i < N; i++){\n      for (auto P : E2[i]){\n\
    \        if (B[P.first] != B[E2[i][0].first]){\n          art[i] = true;\n   \
    \     }\n      }\n      if (art[i]){\n        cnt++;\n      }\n    }\n    V =\
    \ cnt + B.count();\n    cut = vector<bool>(V, false);\n    G.resize(V);\n    node.resize(V);\n\
    \    int cnt2 = 0;\n    vector<bool> used(B.count(), false);\n    for (int i =\
    \ 0; i < N; i++){\n      if (art[i]){\n        cut[cnt2] = true;\n        node[cnt2].push_back(i);\n\
    \        for (auto P : E2[i]){\n          int b = B[P.first];\n          if (!used[b]){\n\
    \            used[b] = true;\n            G[cnt + b].push_back(cnt2);\n      \
    \      G[cnt2].push_back(cnt + b);\n            node[cnt + b].push_back(i);\n\
    \          }\n        }\n        for (auto P : E2[i]){\n          int b = B[P.first];\n\
    \          used[b] = false;\n        }\n        cnt2++;\n      } else {\n    \
    \    if (!E2[i].empty()){\n          int b = B[E2[i][0].first];\n          node[cnt\
    \ + b].push_back(i);\n        }\n      }\n    }\n  }\n};\n"
  code: "struct block_cut_tree{\n  int V;\n  vector<bool> cut;\n  vector<vector<int>>\
    \ G;\n  vector<vector<int>> node;\n  block_cut_tree(vector<vector<int>> &E){\n\
    \    int N = E.size();\n    int M = 0;\n    vector<vector<pair<int, int>>> E2(N);\n\
    \    for (int i = 0; i < N; i++){\n      for (int j : E[i]){\n        if (j >\
    \ i){\n          E2[i].push_back(make_pair(M, j));\n          E2[j].push_back(make_pair(M,\
    \ i));\n          M++;\n        }\n      }\n    }\n    biconnected_components\
    \ B(E2);\n    vector<bool> art(N, false);\n    int cnt = 0;\n    for (int i =\
    \ 0; i < N; i++){\n      for (auto P : E2[i]){\n        if (B[P.first] != B[E2[i][0].first]){\n\
    \          art[i] = true;\n        }\n      }\n      if (art[i]){\n        cnt++;\n\
    \      }\n    }\n    V = cnt + B.count();\n    cut = vector<bool>(V, false);\n\
    \    G.resize(V);\n    node.resize(V);\n    int cnt2 = 0;\n    vector<bool> used(B.count(),\
    \ false);\n    for (int i = 0; i < N; i++){\n      if (art[i]){\n        cut[cnt2]\
    \ = true;\n        node[cnt2].push_back(i);\n        for (auto P : E2[i]){\n \
    \         int b = B[P.first];\n          if (!used[b]){\n            used[b] =\
    \ true;\n            G[cnt + b].push_back(cnt2);\n            G[cnt2].push_back(cnt\
    \ + b);\n            node[cnt + b].push_back(i);\n          }\n        }\n   \
    \     for (auto P : E2[i]){\n          int b = B[P.first];\n          used[b]\
    \ = false;\n        }\n        cnt2++;\n      } else {\n        if (!E2[i].empty()){\n\
    \          int b = B[E2[i][0].first];\n          node[cnt + b].push_back(i);\n\
    \        }\n      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Block_Cut_Tree.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Block_Cut_Tree.cpp
layout: document
redirect_from:
- /library/old_Graph/Block_Cut_Tree.cpp
- /library/old_Graph/Block_Cut_Tree.cpp.html
title: old_Graph/Block_Cut_Tree.cpp
---
