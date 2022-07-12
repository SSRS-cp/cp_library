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
  bundledCode: "#line 1 \"Graph/Lowest_Common_Ancestor.cpp\"\nstruct lowest_common_ancestor{\n\
    \    vector<int> p, sz, in, next;\n    void dfs1(vector<vector<int>> &c, int v\
    \ = 0){\n        sz[v] = 1;\n        for (int &w : c[v]){\n            dfs1(c,\
    \ w);\n            sz[v] += sz[w];\n            if (sz[w] > sz[c[v][0]]){\n  \
    \              swap(w, c[v][0]);\n            }\n        }\n    }\n    void dfs2(vector<vector<int>>\
    \ &c, int &t, int v = 0){\n        in[v] = t;\n        t++;\n        for (int\
    \ w : c[v]){\n            if (w == c[v][0]){\n                next[w] = next[v];\n\
    \            } else {\n                next[w] = w;\n            }\n         \
    \   dfs2(c, t, w);\n        }\n    }\n    lowest_common_ancestor(vector<int> &p,\
    \ vector<vector<int>> &c): p(p){\n        int N = p.size();\n        sz = vector<int>(N);\n\
    \        dfs1(c);\n        in = vector<int>(N);\n        next = vector<int>(N,\
    \ 0);\n        int t = 0;\n        dfs2(c, t);\n    }\n    int lca(int u, int\
    \ v){\n        while (1){\n            if (in[u] > in[v]){\n                swap(u,\
    \ v);\n            }\n            if (next[u] == next[v]){\n                return\
    \ u;\n            }\n            v = p[next[v]];\n        }\n    }\n};\n"
  code: "struct lowest_common_ancestor{\n    vector<int> p, sz, in, next;\n    void\
    \ dfs1(vector<vector<int>> &c, int v = 0){\n        sz[v] = 1;\n        for (int\
    \ &w : c[v]){\n            dfs1(c, w);\n            sz[v] += sz[w];\n        \
    \    if (sz[w] > sz[c[v][0]]){\n                swap(w, c[v][0]);\n          \
    \  }\n        }\n    }\n    void dfs2(vector<vector<int>> &c, int &t, int v =\
    \ 0){\n        in[v] = t;\n        t++;\n        for (int w : c[v]){\n       \
    \     if (w == c[v][0]){\n                next[w] = next[v];\n            } else\
    \ {\n                next[w] = w;\n            }\n            dfs2(c, t, w);\n\
    \        }\n    }\n    lowest_common_ancestor(vector<int> &p, vector<vector<int>>\
    \ &c): p(p){\n        int N = p.size();\n        sz = vector<int>(N);\n      \
    \  dfs1(c);\n        in = vector<int>(N);\n        next = vector<int>(N, 0);\n\
    \        int t = 0;\n        dfs2(c, t);\n    }\n    int lca(int u, int v){\n\
    \        while (1){\n            if (in[u] > in[v]){\n                swap(u,\
    \ v);\n            }\n            if (next[u] == next[v]){\n                return\
    \ u;\n            }\n            v = p[next[v]];\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Lowest_Common_Ancestor.cpp
  requiredBy: []
  timestamp: '2021-01-23 13:48:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Lowest_Common_Ancestor.cpp
layout: document
redirect_from:
- /library/Graph/Lowest_Common_Ancestor.cpp
- /library/Graph/Lowest_Common_Ancestor.cpp.html
title: Graph/Lowest_Common_Ancestor.cpp
---
