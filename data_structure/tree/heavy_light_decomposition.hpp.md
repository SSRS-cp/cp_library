---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/other/2667.test.cpp
    title: test/aoj/other/2667.test.cpp
  - icon: ':x:'
    path: test/library_checker/tree/lowest_common_ancestor.test.cpp
    title: test/library_checker/tree/lowest_common_ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u91CD\u8EFD\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"data_structure/tree/heavy_light_decomposition.hpp\"\n/**\n\
    \ * @brief \u91CD\u8EFD\u5206\u89E3\n*/\nstruct heavy_light_decomposition{\n \
    \ vector<int> p, sz, in, next;\n  void dfs1(vector<vector<int>> &c, int v){\n\
    \    sz[v] = 1;\n    for (int &w : c[v]){\n      dfs1(c, w);\n      sz[v] += sz[w];\n\
    \      if (sz[w] > sz[c[v][0]]){\n        swap(w, c[v][0]);\n      }\n    }\n\
    \  }\n  void dfs2(vector<vector<int>> &c, int &t, int v){\n    in[v] = t;\n  \
    \  t++;\n    for (int w : c[v]){\n      if (w == c[v][0]){\n        next[w] =\
    \ next[v];\n      } else {\n        next[w] = w;\n      }\n      dfs2(c, t, w);\n\
    \    }\n  }\n  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c,\
    \ int r = 0): p(p){\n    int N = p.size();\n    sz = vector<int>(N);\n    dfs1(c,\
    \ r);\n    in = vector<int>(N);\n    next = vector<int>(N, r);\n    int t = 0;\n\
    \    dfs2(c, t, r);\n  }\n  int lca(int u, int v){\n    while (true){\n      if\
    \ (in[u] > in[v]){\n        swap(u, v);\n      }\n      if (next[u] == next[v]){\n\
    \        return u;\n      }\n      v = p[next[v]];\n    }\n  }\n  int dist(int\
    \ u, int v){\n    int ans = 0;\n    while (true){\n      if (in[u] > in[v]){\n\
    \        swap(u, v);\n      }\n      if (next[u] == next[v]){\n        ans +=\
    \ in[v] - in[u];\n        return ans;\n      }\n      ans += in[v] - in[next[v]]\
    \ + 1;\n      v = p[next[v]];\n    }\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u91CD\u8EFD\u5206\u89E3\n*/\nstruct heavy_light_decomposition{\n\
    \  vector<int> p, sz, in, next;\n  void dfs1(vector<vector<int>> &c, int v){\n\
    \    sz[v] = 1;\n    for (int &w : c[v]){\n      dfs1(c, w);\n      sz[v] += sz[w];\n\
    \      if (sz[w] > sz[c[v][0]]){\n        swap(w, c[v][0]);\n      }\n    }\n\
    \  }\n  void dfs2(vector<vector<int>> &c, int &t, int v){\n    in[v] = t;\n  \
    \  t++;\n    for (int w : c[v]){\n      if (w == c[v][0]){\n        next[w] =\
    \ next[v];\n      } else {\n        next[w] = w;\n      }\n      dfs2(c, t, w);\n\
    \    }\n  }\n  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c,\
    \ int r = 0): p(p){\n    int N = p.size();\n    sz = vector<int>(N);\n    dfs1(c,\
    \ r);\n    in = vector<int>(N);\n    next = vector<int>(N, r);\n    int t = 0;\n\
    \    dfs2(c, t, r);\n  }\n  int lca(int u, int v){\n    while (true){\n      if\
    \ (in[u] > in[v]){\n        swap(u, v);\n      }\n      if (next[u] == next[v]){\n\
    \        return u;\n      }\n      v = p[next[v]];\n    }\n  }\n  int dist(int\
    \ u, int v){\n    int ans = 0;\n    while (true){\n      if (in[u] > in[v]){\n\
    \        swap(u, v);\n      }\n      if (next[u] == next[v]){\n        ans +=\
    \ in[v] - in[u];\n        return ans;\n      }\n      ans += in[v] - in[next[v]]\
    \ + 1;\n      v = p[next[v]];\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/other/2667.test.cpp
  - test/library_checker/tree/lowest_common_ancestor.test.cpp
documentation_of: data_structure/tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/data_structure/tree/heavy_light_decomposition.hpp
- /library/data_structure/tree/heavy_light_decomposition.hpp.html
title: "\u91CD\u8EFD\u5206\u89E3"
---
