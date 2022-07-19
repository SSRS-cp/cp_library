---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/tree/heavy_light_decomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library_checker/tree/lowest_common_ancestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"data_structure/tree/heavy_light_decomposition.hpp\"\
    \n/**\n * @brief \u91CD\u8EFD\u5206\u89E3\n*/\nstruct heavy_light_decomposition{\n\
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
    \ + 1;\n      v = p[next[v]];\n    }\n  }\n};\n#line 5 \"test/library_checker/tree/lowest_common_ancestor.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<int> p(N);\n  for (int\
    \ i = 1; i < N; i++){\n    cin >> p[i];\n  }\n  vector<vector<int>> c(N);\n  for\
    \ (int i = 1; i < N; i++){\n    c[p[i]].push_back(i);\n  }\n  heavy_light_decomposition\
    \ T(p, c);\n  for (int i = 0; i < Q; i++){\n    int u, v;\n    cin >> u >> v;\n\
    \    cout << T.lca(u, v) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../../../data_structure/tree/heavy_light_decomposition.hpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<int> p(N);\n  for (int\
    \ i = 1; i < N; i++){\n    cin >> p[i];\n  }\n  vector<vector<int>> c(N);\n  for\
    \ (int i = 1; i < N; i++){\n    c[p[i]].push_back(i);\n  }\n  heavy_light_decomposition\
    \ T(p, c);\n  for (int i = 0; i < Q; i++){\n    int u, v;\n    cin >> u >> v;\n\
    \    cout << T.lca(u, v) << endl;\n  }\n}"
  dependsOn:
  - data_structure/tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/library_checker/tree/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:43:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/tree/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/lowest_common_ancestor.test.cpp
- /verify/test/library_checker/tree/lowest_common_ancestor.test.cpp.html
title: test/library_checker/tree/lowest_common_ancestor.test.cpp
---
