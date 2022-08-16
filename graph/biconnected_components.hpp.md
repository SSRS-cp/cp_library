---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/block_cut_tree.hpp
    title: Block Cut Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl_3_a.test.cpp
    title: test/aoj/grl/grl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/biconnected_components.test.cpp
    title: test/library_checker/graph/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_1326.test.cpp
    title: test/yukicoder/yuki_1326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"graph/biconnected_components.hpp\"\n/**\n * @brief \u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\nstruct biconnected_components{\n\
    \  vector<int> bcc;\n  int cnt = 0;\n  biconnected_components(vector<vector<pair<int,\
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
    \  }\n  }\n  int operator [](int k){\n    return bcc[k];\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\n*/\nstruct biconnected_components{\n  vector<int> bcc;\n  int cnt\
    \ = 0;\n  biconnected_components(vector<vector<pair<int, int>>> &E){\n    int\
    \ N = E.size();\n    vector<int> next(N, -1);\n    vector<int> d(N, -1);\n   \
    \ vector<int> imos(N, 0);\n    for (int i = 0; i < N; i++){\n      if (d[i] ==\
    \ -1){\n        d[i] = 0;\n        dfs1(E, next, d, imos, i);\n      }\n    }\n\
    \    int M = 0;\n    for (int i = 0; i < N; i++){\n      M += E[i].size();\n \
    \   }\n    M /= 2;\n    bcc = vector<int>(M, -1);\n    for (int i = 0; i < N;\
    \ i++){\n      if (d[i] == 0){\n        dfs2(E, d, imos, cnt, i);\n      }\n \
    \   }\n  }\n  void dfs1(vector<vector<pair<int, int>>> &E, vector<int> &next,\
    \ vector<int> &d, vector<int> &imos, int v){\n    for (auto P : E[v]){\n     \
    \ int w = P.second;\n      if (d[w] == -1){\n        d[w] = d[v] + 1;\n      \
    \  next[v] = w;\n        dfs1(E, next, d, imos, w);\n        imos[v] += imos[w];\n\
    \      } else if (d[w] < d[v] - 1){\n        imos[v]++;\n        imos[next[w]]--;\n\
    \      }\n    }\n  }\n  void dfs2(vector<vector<pair<int, int>>> &E, vector<int>\
    \ &d, vector<int> &imos, int b, int v){\n    for (auto P : E[v]){\n      int x\
    \ = P.first;\n      int w = P.second;\n      if (d[w] < d[v]){\n        bcc[x]\
    \ = b;\n      } else if (d[w] == d[v] + 1 && bcc[x] == -1){\n        if (imos[w]\
    \ > 0){\n          bcc[x] = b;\n        } else {\n          bcc[x] = cnt;\n  \
    \        cnt++;\n        }\n        dfs2(E, d, imos, bcc[x], w);\n      }\n  \
    \  }\n  }\n  int operator [](int k){\n    return bcc[k];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/biconnected_components.hpp
  requiredBy:
  - graph/block_cut_tree.hpp
  timestamp: '2022-07-20 01:24:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_1326.test.cpp
  - test/library_checker/graph/biconnected_components.test.cpp
  - test/aoj/grl/grl_3_a.test.cpp
documentation_of: graph/biconnected_components.hpp
layout: document
redirect_from:
- /library/graph/biconnected_components.hpp
- /library/graph/biconnected_components.hpp.html
title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
