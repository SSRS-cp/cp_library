---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/lowest_common_ancestor.test.cpp
    title: test/library_checker/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/tree/heavy_light_decomposition.cpp\"\nstruct\
    \ heavy_light_decomposition{\n  vector<int> p, sz, in, next;\n  void dfs1(vector<vector<int>>\
    \ &c, int v){\n    sz[v] = 1;\n    for (int &w : c[v]){\n      dfs1(c, w);\n \
    \     sz[v] += sz[w];\n      if (sz[w] > sz[c[v][0]]){\n        swap(w, c[v][0]);\n\
    \      }\n    }\n  }\n  void dfs2(vector<vector<int>> &c, int &t, int v){\n  \
    \  in[v] = t;\n    t++;\n    for (int w : c[v]){\n      if (w == c[v][0]){\n \
    \       next[w] = next[v];\n      } else {\n        next[w] = w;\n      }\n  \
    \    dfs2(c, t, w);\n    }\n  }\n  heavy_light_decomposition(vector<int> &p, vector<vector<int>>\
    \ &c, int r = 0): p(p){\n    int N = p.size();\n    sz = vector<int>(N);\n   \
    \ dfs1(c, r);\n    in = vector<int>(N);\n    next = vector<int>(N, r);\n    int\
    \ t = 0;\n    dfs2(c, t, r);\n  }\n  int lca(int u, int v){\n    while (true){\n\
    \      if (in[u] > in[v]){\n        swap(u, v);\n      }\n      if (next[u] ==\
    \ next[v]){\n        return u;\n      }\n      v = p[next[v]];\n    }\n  }\n};\n"
  code: "struct heavy_light_decomposition{\n  vector<int> p, sz, in, next;\n  void\
    \ dfs1(vector<vector<int>> &c, int v){\n    sz[v] = 1;\n    for (int &w : c[v]){\n\
    \      dfs1(c, w);\n      sz[v] += sz[w];\n      if (sz[w] > sz[c[v][0]]){\n \
    \       swap(w, c[v][0]);\n      }\n    }\n  }\n  void dfs2(vector<vector<int>>\
    \ &c, int &t, int v){\n    in[v] = t;\n    t++;\n    for (int w : c[v]){\n   \
    \   if (w == c[v][0]){\n        next[w] = next[v];\n      } else {\n        next[w]\
    \ = w;\n      }\n      dfs2(c, t, w);\n    }\n  }\n  heavy_light_decomposition(vector<int>\
    \ &p, vector<vector<int>> &c, int r = 0): p(p){\n    int N = p.size();\n    sz\
    \ = vector<int>(N);\n    dfs1(c, r);\n    in = vector<int>(N);\n    next = vector<int>(N,\
    \ r);\n    int t = 0;\n    dfs2(c, t, r);\n  }\n  int lca(int u, int v){\n   \
    \ while (true){\n      if (in[u] > in[v]){\n        swap(u, v);\n      }\n   \
    \   if (next[u] == next[v]){\n        return u;\n      }\n      v = p[next[v]];\n\
    \    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/tree/heavy_light_decomposition.cpp
  requiredBy: []
  timestamp: '2022-07-15 08:05:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/lowest_common_ancestor.test.cpp
documentation_of: data_structure/tree/heavy_light_decomposition.cpp
layout: document
redirect_from:
- /library/data_structure/tree/heavy_light_decomposition.cpp
- /library/data_structure/tree/heavy_light_decomposition.cpp.html
title: data_structure/tree/heavy_light_decomposition.cpp
---
