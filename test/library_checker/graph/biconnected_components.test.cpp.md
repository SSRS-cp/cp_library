---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/block_cut_tree.hpp
    title: Block Cut Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/library_checker/graph/biconnected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"graph/block_cut_tree.hpp\"\
    \n/**\n * @brief Block Cut Tree\n*/\n#line 2 \"graph/biconnected_components.hpp\"\
    \n/**\n * @brief \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\n\
    */\nstruct biconnected_components{\n  vector<int> bcc;\n  int cnt = 0;\n  biconnected_components(vector<vector<pair<int,\
    \ int>>> &E){\n    int N = E.size();\n    vector<int> next(N, -1);\n    vector<int>\
    \ d(N, -1);\n    vector<int> imos(N, 0);\n    for (int i = 0; i < N; i++){\n \
    \     if (d[i] == -1){\n        d[i] = 0;\n        dfs1(E, next, d, imos, i);\n\
    \      }\n    }\n    int M = 0;\n    for (int i = 0; i < N; i++){\n      M +=\
    \ E[i].size();\n    }\n    M /= 2;\n    bcc = vector<int>(M, -1);\n    for (int\
    \ i = 0; i < N; i++){\n      if (d[i] == 0){\n        dfs2(E, d, imos, cnt, i);\n\
    \      }\n    }\n  }\n  void dfs1(vector<vector<pair<int, int>>> &E, vector<int>\
    \ &next, vector<int> &d, vector<int> &imos, int v){\n    for (auto P : E[v]){\n\
    \      int w = P.second;\n      if (d[w] == -1){\n        d[w] = d[v] + 1;\n \
    \       next[v] = w;\n        dfs1(E, next, d, imos, w);\n        imos[v] += imos[w];\n\
    \      } else if (d[w] < d[v] - 1){\n        imos[v]++;\n        imos[next[w]]--;\n\
    \      }\n    }\n  }\n  void dfs2(vector<vector<pair<int, int>>> &E, vector<int>\
    \ &d, vector<int> &imos, int b, int v){\n    for (auto P : E[v]){\n      int x\
    \ = P.first;\n      int w = P.second;\n      if (d[w] < d[v]){\n        bcc[x]\
    \ = b;\n      } else if (d[w] == d[v] + 1 && bcc[x] == -1){\n        if (imos[w]\
    \ > 0){\n          bcc[x] = b;\n        } else {\n          bcc[x] = cnt;\n  \
    \        cnt++;\n        }\n        dfs2(E, d, imos, bcc[x], w);\n      }\n  \
    \  }\n  }\n  int operator [](int k){\n    return bcc[k];\n  }\n};\n#line 6 \"\
    graph/block_cut_tree.hpp\"\nstruct block_cut_tree{\n  int V;\n  vector<bool> art;\n\
    \  vector<bool> cut;\n  vector<vector<int>> G;\n  vector<vector<int>> node;\n\
    \  block_cut_tree(vector<vector<int>> &E){\n    int N = E.size();\n    int M =\
    \ 0;\n    vector<vector<pair<int, int>>> E2(N);\n    for (int i = 0; i < N; i++){\n\
    \      for (int j : E[i]){\n        if (j > i){\n          E2[i].push_back(make_pair(M,\
    \ j));\n          E2[j].push_back(make_pair(M, i));\n          M++;\n        }\n\
    \      }\n    }\n    biconnected_components B(E2);\n    art = vector<bool>(N,\
    \ false);\n    int cnt = 0;\n    for (int i = 0; i < N; i++){\n      for (auto\
    \ P : E2[i]){\n        if (B[P.first] != B[E2[i][0].first]){\n          art[i]\
    \ = true;\n        }\n      }\n      if (art[i]){\n        cnt++;\n      }\n \
    \     if (E[i].empty()){\n        cnt++;\n      }\n    }\n    V = cnt + B.cnt;\n\
    \    cut = vector<bool>(V, false);\n    G.resize(V);\n    node.resize(V);\n  \
    \  int cnt2 = 0;\n    vector<bool> used(B.cnt, false);\n    for (int i = 0; i\
    \ < N; i++){\n      if (art[i]){\n        cut[cnt2] = true;\n        node[cnt2].push_back(i);\n\
    \        for (auto P : E2[i]){\n          int b = B[P.first];\n          if (!used[b]){\n\
    \            used[b] = true;\n            G[cnt + b].push_back(cnt2);\n      \
    \      G[cnt2].push_back(cnt + b);\n            node[cnt + b].push_back(i);\n\
    \          }\n        }\n        for (auto P : E2[i]){\n          int b = B[P.first];\n\
    \          used[b] = false;\n        }\n        cnt2++;\n      } else if (!E2[i].empty()){\n\
    \        int b = B[E2[i][0].first];\n        node[cnt + b].push_back(i);\n   \
    \   } else {\n        node[cnt2].push_back(i);\n        cnt2++;\n      }\n   \
    \ }\n  }\n};\n#line 5 \"test/library_checker/graph/biconnected_components.test.cpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int s, t;\n    cin >> s >> t;\n    E[s].push_back(t);\n\
    \    E[t].push_back(s);\n  }\n  block_cut_tree G(E);\n  int V = G.V;\n  vector<vector<int>>\
    \ v;\n  for (int i = 0; i < V; i++){\n    if (!G.cut[i]){\n      v.push_back(G.node[i]);\n\
    \    }\n  }\n  int K = v.size();\n  cout << K << endl;\n  for (int i = 0; i <\
    \ K; i++){\n    int l = v[i].size();\n    cout << l;\n    for (int j = 0; j <\
    \ l; j++){\n      cout << ' ' << v[i][j];\n    }\n    cout << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../graph/block_cut_tree.hpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int s, t;\n    cin >> s >> t;\n    E[s].push_back(t);\n\
    \    E[t].push_back(s);\n  }\n  block_cut_tree G(E);\n  int V = G.V;\n  vector<vector<int>>\
    \ v;\n  for (int i = 0; i < V; i++){\n    if (!G.cut[i]){\n      v.push_back(G.node[i]);\n\
    \    }\n  }\n  int K = v.size();\n  cout << K << endl;\n  for (int i = 0; i <\
    \ K; i++){\n    int l = v[i].size();\n    cout << l;\n    for (int j = 0; j <\
    \ l; j++){\n      cout << ' ' << v[i][j];\n    }\n    cout << endl;\n  }\n}"
  dependsOn:
  - graph/block_cut_tree.hpp
  - graph/biconnected_components.hpp
  isVerificationFile: true
  path: test/library_checker/graph/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 01:33:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/biconnected_components.test.cpp
- /verify/test/library_checker/graph/biconnected_components.test.cpp.html
title: test/library_checker/graph/biconnected_components.test.cpp
---