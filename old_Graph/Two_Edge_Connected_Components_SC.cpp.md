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
  bundledCode: "#line 1 \"old_Graph/Two_Edge_Connected_Components_SC.cpp\"\nstruct\
    \ two_edge_connected_components{\n  vector<int> tcc;\n  int cnt;\n  two_edge_connected_components(vector<vector<int>>\
    \ &E){\n    int N = E.size();\n    vector<int> p(N, -1);\n    vector<int> d(N,\
    \ -1);\n    d[0] = 0;\n    vector<int> imos(N, 0);\n    dfs1(E, p, d, imos);\n\
    \    tcc = vector<int>(N, -1);\n    tcc[0] = 0;\n    cnt = 1;\n    dfs2(E, p,\
    \ imos);\n  }\n  void dfs1(vector<vector<int>> &E, vector<int> &p, vector<int>\
    \ &d, vector<int> &imos, int v = 0){\n    for (int w : E[v]){\n      if (w !=\
    \ p[v]){\n      \tif (d[w] == -1){\n          p[w] = v;\n          d[w] = d[v]\
    \ + 1;\n          dfs1(E, p, d, imos, w);\n          imos[v] += imos[w];\n   \
    \     } else if (d[w] < d[v]){\n          imos[v]++;\n          imos[w]--;\n \
    \       }\n      }\n    }\n  }\n  void dfs2(vector<vector<int>> &E, vector<int>\
    \ &p, vector<int> &imos, int v = 0){\n    for (int w : E[v]){\n      if (tcc[w]\
    \ == -1){\n        if (imos[w] > 0){\n          tcc[w] = tcc[v];\n        } else\
    \ {\n          tcc[w] = cnt;\n          cnt++;\n        }\n        dfs2(E, p,\
    \ imos, w);\n      }\n    }\n  }\n  int operator [](int v){\n    return tcc[v];\n\
    \  }\n  int count(){\n    return cnt;\n  }\n};\n"
  code: "struct two_edge_connected_components{\n  vector<int> tcc;\n  int cnt;\n \
    \ two_edge_connected_components(vector<vector<int>> &E){\n    int N = E.size();\n\
    \    vector<int> p(N, -1);\n    vector<int> d(N, -1);\n    d[0] = 0;\n    vector<int>\
    \ imos(N, 0);\n    dfs1(E, p, d, imos);\n    tcc = vector<int>(N, -1);\n    tcc[0]\
    \ = 0;\n    cnt = 1;\n    dfs2(E, p, imos);\n  }\n  void dfs1(vector<vector<int>>\
    \ &E, vector<int> &p, vector<int> &d, vector<int> &imos, int v = 0){\n    for\
    \ (int w : E[v]){\n      if (w != p[v]){\n      \tif (d[w] == -1){\n         \
    \ p[w] = v;\n          d[w] = d[v] + 1;\n          dfs1(E, p, d, imos, w);\n \
    \         imos[v] += imos[w];\n        } else if (d[w] < d[v]){\n          imos[v]++;\n\
    \          imos[w]--;\n        }\n      }\n    }\n  }\n  void dfs2(vector<vector<int>>\
    \ &E, vector<int> &p, vector<int> &imos, int v = 0){\n    for (int w : E[v]){\n\
    \      if (tcc[w] == -1){\n        if (imos[w] > 0){\n          tcc[w] = tcc[v];\n\
    \        } else {\n          tcc[w] = cnt;\n          cnt++;\n        }\n    \
    \    dfs2(E, p, imos, w);\n      }\n    }\n  }\n  int operator [](int v){\n  \
    \  return tcc[v];\n  }\n  int count(){\n    return cnt;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Two_Edge_Connected_Components_SC.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Two_Edge_Connected_Components_SC.cpp
layout: document
redirect_from:
- /library/old_Graph/Two_Edge_Connected_Components_SC.cpp
- /library/old_Graph/Two_Edge_Connected_Components_SC.cpp.html
title: old_Graph/Two_Edge_Connected_Components_SC.cpp
---
