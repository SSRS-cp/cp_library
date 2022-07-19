---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl_3_b.test.cpp
    title: test/aoj/grl/grl_3_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/two_edge_connected_components.test.cpp
    title: test/library_checker/graph/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"graph/two_edge_connected_components.hpp\"\n/**\n * @brief\
    \ \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\nstruct two_edge_connected_components{\n\
    \  vector<int> tcc;\n  int cnt = 0;\n  two_edge_connected_components(vector<vector<int>>\
    \ &E){\n    int N = E.size();\n    vector<int> p(N, -1);\n    vector<int> d(N,\
    \ -1);\n    vector<int> imos(N, 0);\n    for (int i = 0; i < N; i++){\n      if\
    \ (p[i] == -1){\n        d[i] = 0;\n        dfs1(E, p, d, imos, i);\n      }\n\
    \    }\n    tcc = vector<int>(N, -1);\n    for (int i = 0; i < N; i++){\n    \
    \  if (tcc[i] == -1){\n        tcc[i] = cnt;\n        cnt++;\n        dfs2(E,\
    \ p, imos, i);\n      }\n    }\n  }\n  void dfs1(vector<vector<int>> &E, vector<int>\
    \ &p, vector<int> &d, vector<int> &imos, int v = 0){\n    bool pe = false;\n \
    \   for (int w : E[v]){\n      if (w != p[v] || pe){\n        if (d[w] == -1){\n\
    \          p[w] = v;\n          d[w] = d[v] + 1;\n          dfs1(E, p, d, imos,\
    \ w);\n          imos[v] += imos[w];\n        } else if (d[w] < d[v]){\n     \
    \     imos[v]++;\n          imos[w]--;\n        }\n      } else {\n        pe\
    \ = true;\n      }\n    }\n  }\n  void dfs2(vector<vector<int>> &E, vector<int>\
    \ &p, vector<int> &imos, int v = 0){\n    for (int w : E[v]){\n      if (tcc[w]\
    \ == -1){\n        if (imos[w] > 0){\n          tcc[w] = tcc[v];\n        } else\
    \ {\n          tcc[w] = cnt;\n          cnt++;\n        }\n        dfs2(E, p,\
    \ imos, w);\n      }\n    }\n  }\n  int operator [](int v){\n    return tcc[v];\n\
    \  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\n*/\nstruct two_edge_connected_components{\n  vector<int> tcc;\n  int cnt\
    \ = 0;\n  two_edge_connected_components(vector<vector<int>> &E){\n    int N =\
    \ E.size();\n    vector<int> p(N, -1);\n    vector<int> d(N, -1);\n    vector<int>\
    \ imos(N, 0);\n    for (int i = 0; i < N; i++){\n      if (p[i] == -1){\n    \
    \    d[i] = 0;\n        dfs1(E, p, d, imos, i);\n      }\n    }\n    tcc = vector<int>(N,\
    \ -1);\n    for (int i = 0; i < N; i++){\n      if (tcc[i] == -1){\n        tcc[i]\
    \ = cnt;\n        cnt++;\n        dfs2(E, p, imos, i);\n      }\n    }\n  }\n\
    \  void dfs1(vector<vector<int>> &E, vector<int> &p, vector<int> &d, vector<int>\
    \ &imos, int v = 0){\n    bool pe = false;\n    for (int w : E[v]){\n      if\
    \ (w != p[v] || pe){\n        if (d[w] == -1){\n          p[w] = v;\n        \
    \  d[w] = d[v] + 1;\n          dfs1(E, p, d, imos, w);\n          imos[v] += imos[w];\n\
    \        } else if (d[w] < d[v]){\n          imos[v]++;\n          imos[w]--;\n\
    \        }\n      } else {\n        pe = true;\n      }\n    }\n  }\n  void dfs2(vector<vector<int>>\
    \ &E, vector<int> &p, vector<int> &imos, int v = 0){\n    for (int w : E[v]){\n\
    \      if (tcc[w] == -1){\n        if (imos[w] > 0){\n          tcc[w] = tcc[v];\n\
    \        } else {\n          tcc[w] = cnt;\n          cnt++;\n        }\n    \
    \    dfs2(E, p, imos, w);\n      }\n    }\n  }\n  int operator [](int v){\n  \
    \  return tcc[v];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2022-07-20 01:24:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl/grl_3_b.test.cpp
  - test/library_checker/graph/two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_connected_components.hpp
layout: document
redirect_from:
- /library/graph/two_edge_connected_components.hpp
- /library/graph/two_edge_connected_components.hpp.html
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
