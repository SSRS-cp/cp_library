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
  bundledCode: "#line 1 \"Data_Structures/Heavy_Light_Decomposition.cpp\"\ntemplate\
    \ <typename T>\nstruct heavy_light_decomposition{\n\tlowest_common_ancestor LCA;\n\
    \tvector<int> p;\n\tvector<int> sz, in, out, next;\n\tint t;\n\tbidirectional_segment_tree<T>\
    \ ST;\n\tfunction<T(T, T)> f;\n\tT E;\n\tvoid dfs1(vector<vector<int>> &c, int\
    \ v = 0){\n\t\tsz[v] = 1;\n\t\tfor (int &w : c[v]){\n\t\t\tdfs1(c, w);\n\t\t\t\
    sz[v] += sz[w];\n\t\t\tif (sz[w] > sz[c[v][0]]){\n\t\t\t\tswap(w, c[v][0]);\n\t\
    \t\t}\n\t\t}\n\t}\n\tvoid dfs2(vector<vector<int>> &c, int v = 0){\n\t\tin[v]\
    \ = t;\n\t\tt++;\n\t\tfor (int w : c[v]){\n\t\t\tif (w == c[v][0]){\n\t\t\t\t\
    next[w] = next[v];\n\t\t\t} else {\n\t\t\t\tnext[w] = w;\n\t\t\t}\n\t\t\tdfs2(c,\
    \ w);\n\t\t}\n\t\tout[v] = t;\n\t}\n\theavy_light_decomposition(vector<int> &p,\
    \ vector<vector<int>> &c, vector<T> &A, function<T(T, T)> f, T E): p(p), f(f),\
    \ E(E){\n\t\tLCA = lowest_common_ancestor(p, c);\n\t\tint N = p.size();\n\t\t\
    in = vector<int>(N, -1);\n\t\tout = vector<int>(N, -1);\n\t\tsz = vector<int>(N,\
    \ -1);\n\t\tnext = vector<int>(N, 0);\n\t\tt = 0;\n\t\tdfs1(c);\n\t\tdfs2(c);\n\
    \t\tvector<T> tmp(N);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\ttmp[in[i]] = A[i];\n\
    \t\t}\n\t\tST = bidirectional_segment_tree(tmp, f, E);\n\t}\n\tvoid update(int\
    \ v, T x){\n\t\tST.update(in[v], x);\n\t}\n\tT query(int u, int v){\n\t\tint w\
    \ = LCA.lca(u, v);\n\t\tT tmp1 = E;\n\t\twhile (next[u] != next[w]){\n\t\t\ttmp1\
    \ = f(tmp1, ST.query(in[next[u]], in[u] + 1, 1));\n\t\t\tu = p[next[u]];\n\t\t\
    }\n\t\ttmp1 = f(tmp1, ST.query(in[w], in[u] + 1, 1));\n\t\tT tmp2 = E;\n\t\twhile\
    \ (next[v] != next[w]){\n\t\t\ttmp2 = f(ST.query(in[next[v]], in[v] + 1, 0), tmp2);\n\
    \t\t\tv = p[next[v]];\n\t\t}\n\t\ttmp2 = f(ST.query(in[w] + 1, in[v] + 1, 0),\
    \ tmp2);\n\t\treturn f(tmp1, tmp2);\n\t}\n};\n"
  code: "template <typename T>\nstruct heavy_light_decomposition{\n\tlowest_common_ancestor\
    \ LCA;\n\tvector<int> p;\n\tvector<int> sz, in, out, next;\n\tint t;\n\tbidirectional_segment_tree<T>\
    \ ST;\n\tfunction<T(T, T)> f;\n\tT E;\n\tvoid dfs1(vector<vector<int>> &c, int\
    \ v = 0){\n\t\tsz[v] = 1;\n\t\tfor (int &w : c[v]){\n\t\t\tdfs1(c, w);\n\t\t\t\
    sz[v] += sz[w];\n\t\t\tif (sz[w] > sz[c[v][0]]){\n\t\t\t\tswap(w, c[v][0]);\n\t\
    \t\t}\n\t\t}\n\t}\n\tvoid dfs2(vector<vector<int>> &c, int v = 0){\n\t\tin[v]\
    \ = t;\n\t\tt++;\n\t\tfor (int w : c[v]){\n\t\t\tif (w == c[v][0]){\n\t\t\t\t\
    next[w] = next[v];\n\t\t\t} else {\n\t\t\t\tnext[w] = w;\n\t\t\t}\n\t\t\tdfs2(c,\
    \ w);\n\t\t}\n\t\tout[v] = t;\n\t}\n\theavy_light_decomposition(vector<int> &p,\
    \ vector<vector<int>> &c, vector<T> &A, function<T(T, T)> f, T E): p(p), f(f),\
    \ E(E){\n\t\tLCA = lowest_common_ancestor(p, c);\n\t\tint N = p.size();\n\t\t\
    in = vector<int>(N, -1);\n\t\tout = vector<int>(N, -1);\n\t\tsz = vector<int>(N,\
    \ -1);\n\t\tnext = vector<int>(N, 0);\n\t\tt = 0;\n\t\tdfs1(c);\n\t\tdfs2(c);\n\
    \t\tvector<T> tmp(N);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\ttmp[in[i]] = A[i];\n\
    \t\t}\n\t\tST = bidirectional_segment_tree(tmp, f, E);\n\t}\n\tvoid update(int\
    \ v, T x){\n\t\tST.update(in[v], x);\n\t}\n\tT query(int u, int v){\n\t\tint w\
    \ = LCA.lca(u, v);\n\t\tT tmp1 = E;\n\t\twhile (next[u] != next[w]){\n\t\t\ttmp1\
    \ = f(tmp1, ST.query(in[next[u]], in[u] + 1, 1));\n\t\t\tu = p[next[u]];\n\t\t\
    }\n\t\ttmp1 = f(tmp1, ST.query(in[w], in[u] + 1, 1));\n\t\tT tmp2 = E;\n\t\twhile\
    \ (next[v] != next[w]){\n\t\t\ttmp2 = f(ST.query(in[next[v]], in[v] + 1, 0), tmp2);\n\
    \t\t\tv = p[next[v]];\n\t\t}\n\t\ttmp2 = f(ST.query(in[w] + 1, in[v] + 1, 0),\
    \ tmp2);\n\t\treturn f(tmp1, tmp2);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Heavy_Light_Decomposition.cpp
  requiredBy: []
  timestamp: '2020-08-26 02:54:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Heavy_Light_Decomposition.cpp
layout: document
redirect_from:
- /library/Data_Structures/Heavy_Light_Decomposition.cpp
- /library/Data_Structures/Heavy_Light_Decomposition.cpp.html
title: Data_Structures/Heavy_Light_Decomposition.cpp
---
