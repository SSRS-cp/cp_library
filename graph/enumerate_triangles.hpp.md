---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E09\u89D2\u5F62\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"graph/enumerate_triangles.hpp\"\n/**\n * @brief \u4E09\u89D2\
    \u5F62\u5217\u6319\n*/\nvector<tuple<int, int, int>> enumerate_triangles(vector<vector<int>>\
    \ &E){\n  int N = E.size();\n  vector<int> d(N);\n  for (int i = 0; i < N; i++){\n\
    \    d[i] = E[i].size();\n  }\n  vector<vector<int>> E2(N);\n  for (int i = 0;\
    \ i < N; i++){\n    for (int j : E[i]){\n      if (d[i] < d[j] || d[i] == d[j]\
    \ && i < j){\n        E2[i].push_back(j);\n      }\n    }\n  }\n  vector<bool>\
    \ flg(N, false);\n  vector<tuple<int, int, int>> ans;\n  for (int i = 0; i < N;\
    \ i++){\n    for (int j : E2[i]){\n      for (int k : E2[i]){\n        flg[k]\
    \ = true;\n      }\n      for (int k : E2[j]){\n        if (flg[k]){\n       \
    \   ans.push_back(make_tuple(i, j, k));\n        }\n      }\n      for (int k\
    \ : E2[i]){\n        flg[k] = false;\n      }\n    }\n  }\n  return ans;\n}\n"
  code: "#pragma once\n/**\n * @brief \u4E09\u89D2\u5F62\u5217\u6319\n*/\nvector<tuple<int,\
    \ int, int>> enumerate_triangles(vector<vector<int>> &E){\n  int N = E.size();\n\
    \  vector<int> d(N);\n  for (int i = 0; i < N; i++){\n    d[i] = E[i].size();\n\
    \  }\n  vector<vector<int>> E2(N);\n  for (int i = 0; i < N; i++){\n    for (int\
    \ j : E[i]){\n      if (d[i] < d[j] || d[i] == d[j] && i < j){\n        E2[i].push_back(j);\n\
    \      }\n    }\n  }\n  vector<bool> flg(N, false);\n  vector<tuple<int, int,\
    \ int>> ans;\n  for (int i = 0; i < N; i++){\n    for (int j : E2[i]){\n     \
    \ for (int k : E2[i]){\n        flg[k] = true;\n      }\n      for (int k : E2[j]){\n\
    \        if (flg[k]){\n          ans.push_back(make_tuple(i, j, k));\n       \
    \ }\n      }\n      for (int k : E2[i]){\n        flg[k] = false;\n      }\n \
    \   }\n  }\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumerate_triangles.hpp
  requiredBy: []
  timestamp: '2022-07-20 01:45:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/enumerate_triangles.hpp
layout: document
redirect_from:
- /library/graph/enumerate_triangles.hpp
- /library/graph/enumerate_triangles.hpp.html
title: "\u4E09\u89D2\u5F62\u5217\u6319"
---
