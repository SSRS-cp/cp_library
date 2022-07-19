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
  bundledCode: "#line 1 \"old_Graph/Biconnected_Components.cpp\"\nstruct biconnected_components{\n\
    \  int cnt;\n  vector<int> bcc;\n  biconnected_components(vector<vector<pair<int,\
    \ int>>> &E){\n    int N = E.size();\n    vector<int> next(N, -1);\n    vector<int>\
    \ d(N, -1);\n    vector<int> imos(N, 0);\n    for (int i = 0; i < N; i++){\n \
    \     if (d[i] == -1){\n        d[i] = 0;\n        dfs1(E, next, d, imos, i);\n\
    \      }\n    }\n    int M = 0;\n    for (int i = 0; i < N; i++){\n      M +=\
    \ E[i].size();\n    }\n    M /= 2;\n    bcc = vector<int>(M, -1);\n    cnt = 0;\n\
    \    for (int i = 0; i < N; i++){\n      if (d[i] == 0){\n        dfs2(E, d, imos,\
    \ cnt, i);\n      }\n    }\n  }\n  void dfs1(vector<vector<pair<int, int>>> &E,\
    \ vector<int> &next, vector<int> &d, vector<int> &imos, int v){\n    for (auto\
    \ P : E[v]){\n      int w = P.second;\n      if (d[w] == -1){\n        d[w] =\
    \ d[v] + 1;\n        next[v] = w;\n        dfs1(E, next, d, imos, w);\n      \
    \  imos[v] += imos[w];\n      } else if (d[w] < d[v] - 1){\n        imos[v]++;\n\
    \        imos[next[w]]--;\n      }\n    }\n  }\n  void dfs2(vector<vector<pair<int,\
    \ int>>> &E, vector<int> &d, vector<int> &imos, int b, int v){\n    for (auto\
    \ P : E[v]){\n      int x = P.first;\n      int w = P.second;\n      if (d[w]\
    \ < d[v]){\n        bcc[x] = b;\n      } else if (d[w] == d[v] + 1 && bcc[x] ==\
    \ -1){\n        if (imos[w] > 0){\n          bcc[x] = b;\n        } else {\n \
    \         bcc[x] = cnt;\n          cnt++;\n        }\n        dfs2(E, d, imos,\
    \ bcc[x], w);\n      }\n    }\n  }\n  int operator [](int k){\n    return bcc[k];\n\
    \  }\n  int count(){\n    return cnt;\n  }\n};\n"
  code: "struct biconnected_components{\n  int cnt;\n  vector<int> bcc;\n  biconnected_components(vector<vector<pair<int,\
    \ int>>> &E){\n    int N = E.size();\n    vector<int> next(N, -1);\n    vector<int>\
    \ d(N, -1);\n    vector<int> imos(N, 0);\n    for (int i = 0; i < N; i++){\n \
    \     if (d[i] == -1){\n        d[i] = 0;\n        dfs1(E, next, d, imos, i);\n\
    \      }\n    }\n    int M = 0;\n    for (int i = 0; i < N; i++){\n      M +=\
    \ E[i].size();\n    }\n    M /= 2;\n    bcc = vector<int>(M, -1);\n    cnt = 0;\n\
    \    for (int i = 0; i < N; i++){\n      if (d[i] == 0){\n        dfs2(E, d, imos,\
    \ cnt, i);\n      }\n    }\n  }\n  void dfs1(vector<vector<pair<int, int>>> &E,\
    \ vector<int> &next, vector<int> &d, vector<int> &imos, int v){\n    for (auto\
    \ P : E[v]){\n      int w = P.second;\n      if (d[w] == -1){\n        d[w] =\
    \ d[v] + 1;\n        next[v] = w;\n        dfs1(E, next, d, imos, w);\n      \
    \  imos[v] += imos[w];\n      } else if (d[w] < d[v] - 1){\n        imos[v]++;\n\
    \        imos[next[w]]--;\n      }\n    }\n  }\n  void dfs2(vector<vector<pair<int,\
    \ int>>> &E, vector<int> &d, vector<int> &imos, int b, int v){\n    for (auto\
    \ P : E[v]){\n      int x = P.first;\n      int w = P.second;\n      if (d[w]\
    \ < d[v]){\n        bcc[x] = b;\n      } else if (d[w] == d[v] + 1 && bcc[x] ==\
    \ -1){\n        if (imos[w] > 0){\n          bcc[x] = b;\n        } else {\n \
    \         bcc[x] = cnt;\n          cnt++;\n        }\n        dfs2(E, d, imos,\
    \ bcc[x], w);\n      }\n    }\n  }\n  int operator [](int k){\n    return bcc[k];\n\
    \  }\n  int count(){\n    return cnt;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Biconnected_Components.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Biconnected_Components.cpp
layout: document
redirect_from:
- /library/old_Graph/Biconnected_Components.cpp
- /library/old_Graph/Biconnected_Components.cpp.html
title: old_Graph/Biconnected_Components.cpp
---
