---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl_3_c.test.cpp
    title: test/aoj/grl/grl_3_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/strongly_connected_components.test.cpp
    title: test/library_checker/graph/strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"graph/strongly_connected_components.hpp\"\n/**\n * @brief\
    \ \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\nstruct strongly_connected_components{\n\
    \  vector<int> scc;\n  int cnt = 0;\n  void dfs1(vector<vector<int>> &E, vector<int>\
    \ &t, vector<bool> &used, int v){\n    for (int w : E[v]){\n      if (!used[w]){\n\
    \        used[w] = true;\n        dfs1(E, t, used, w);\n      }\n    }\n    t.push_back(v);\n\
    \  }\n  void dfs2(vector<vector<int>> &E2, vector<bool> &used2, int v){\n    scc[v]\
    \ = cnt;\n    for (int w : E2[v]){\n      if (!used2[w]){\n        used2[w] =\
    \ true;\n        dfs2(E2, used2, w);\n      }\n    }\n  }\n  strongly_connected_components(vector<vector<int>>\
    \ &E){\n    int N = E.size();\n    vector<vector<int>> E2(N);\n    for (int i\
    \ = 0; i < N; i++){\n      for (int j : E[i]){\n        E2[j].push_back(i);\n\
    \      }\n    }\n    vector<int> t;\n    vector<bool> used(N, false);\n    for\
    \ (int i = 0; i < N; i++){\n      if (!used[i]){\n        used[i] = true;\n  \
    \      dfs1(E, t, used, i);\n      }\n    }\n    reverse(t.begin(), t.end());\n\
    \    vector<bool> used2(N, false);\n    scc = vector<int>(N);\n    for (int i\
    \ = 0; i < N; i++){\n      if (!used2[t[i]]){\n        used2[t[i]] = true;\n \
    \       dfs2(E2, used2, t[i]);\n        cnt++;\n      }\n    }\n  }\n  int operator\
    \ [](int k){\n    return scc[k];\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n\
    */\nstruct strongly_connected_components{\n  vector<int> scc;\n  int cnt = 0;\n\
    \  void dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v){\n\
    \    for (int w : E[v]){\n      if (!used[w]){\n        used[w] = true;\n    \
    \    dfs1(E, t, used, w);\n      }\n    }\n    t.push_back(v);\n  }\n  void dfs2(vector<vector<int>>\
    \ &E2, vector<bool> &used2, int v){\n    scc[v] = cnt;\n    for (int w : E2[v]){\n\
    \      if (!used2[w]){\n        used2[w] = true;\n        dfs2(E2, used2, w);\n\
    \      }\n    }\n  }\n  strongly_connected_components(vector<vector<int>> &E){\n\
    \    int N = E.size();\n    vector<vector<int>> E2(N);\n    for (int i = 0; i\
    \ < N; i++){\n      for (int j : E[i]){\n        E2[j].push_back(i);\n      }\n\
    \    }\n    vector<int> t;\n    vector<bool> used(N, false);\n    for (int i =\
    \ 0; i < N; i++){\n      if (!used[i]){\n        used[i] = true;\n        dfs1(E,\
    \ t, used, i);\n      }\n    }\n    reverse(t.begin(), t.end());\n    vector<bool>\
    \ used2(N, false);\n    scc = vector<int>(N);\n    for (int i = 0; i < N; i++){\n\
    \      if (!used2[t[i]]){\n        used2[t[i]] = true;\n        dfs2(E2, used2,\
    \ t[i]);\n        cnt++;\n      }\n    }\n  }\n  int operator [](int k){\n   \
    \ return scc[k];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2022-07-20 00:19:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl/grl_3_c.test.cpp
  - test/library_checker/graph/strongly_connected_components.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.hpp
- /library/graph/strongly_connected_components.hpp.html
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
