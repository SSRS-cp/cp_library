---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/tree/heavy_light_decomposition.cpp
    title: data_structure/tree/heavy_light_decomposition.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library_checker/lowest_common_ancestor.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 1 \"data_structure/tree/heavy_light_decomposition.cpp\"\
    \nstruct heavy_light_decomposition{\n  vector<int> p, sz, in, next;\n  void dfs1(vector<vector<int>>\
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
    \ next[v]){\n        return u;\n      }\n      v = p[next[v]];\n    }\n  }\n};\n\
    #line 5 \"test/library_checker/lowest_common_ancestor.test.cpp\"\nint main(){\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<int> p(N);\n  for (int i = 1; i < N;\
    \ i++){\n    cin >> p[i];\n  }\n  vector<vector<int>> c(N);\n  for (int i = 1;\
    \ i < N; i++){\n    c[p[i]].push_back(i);\n  }\n  heavy_light_decomposition T(p,\
    \ c);\n  for (int i = 0; i < Q; i++){\n    int u, v;\n    cin >> u >> v;\n   \
    \ cout << T.lca(u, v) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../../data_structure/tree/heavy_light_decomposition.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<int> p(N);\n  for (int\
    \ i = 1; i < N; i++){\n    cin >> p[i];\n  }\n  vector<vector<int>> c(N);\n  for\
    \ (int i = 1; i < N; i++){\n    c[p[i]].push_back(i);\n  }\n  heavy_light_decomposition\
    \ T(p, c);\n  for (int i = 0; i < Q; i++){\n    int u, v;\n    cin >> u >> v;\n\
    \    cout << T.lca(u, v) << endl;\n  }\n}\n"
  dependsOn:
  - data_structure/tree/heavy_light_decomposition.cpp
  isVerificationFile: true
  path: test/library_checker/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2022-07-15 08:06:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/lowest_common_ancestor.test.cpp
- /verify/test/library_checker/lowest_common_ancestor.test.cpp.html
title: test/library_checker/lowest_common_ancestor.test.cpp
---
