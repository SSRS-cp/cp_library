---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: "\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/library_checker/graph/two_edge_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"graph/two_edge_connected_components.hpp\"\
    \n/**\n * @brief \u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\nstruct\
    \ two_edge_connected_components{\n  vector<int> tcc;\n  int cnt = 0;\n  two_edge_connected_components(vector<vector<int>>\
    \ &E){\n    int N = E.size();\n    vector<int> p(N, -1);\n    vector<int> d(N,\
    \ -1);\n    vector<int> imos(N, 0);\n    for (int i = 0; i < N; i++){\n      if\
    \ (p[i] == -1){\n        d[i] = 0;\n        dfs1(E, p, d, imos, i);\n      }\n\
    \    }\n    tcc = vector<int>(N, -1);\n    for (int i = 0; i < N; i++){\n    \
    \  if (tcc[i] == -1){\n        tcc[i] = cnt;\n        cnt++;\n        dfs2(E,\
    \ p, imos, i);\n      }\n    }\n  }\n  void dfs1(vector<vector<int>> &E, vector<int>\
    \ &p, vector<int> &d, vector<int> &imos, int v = 0){\n    bool pe = false;\n \
    \   for (int w : E[v]){\n      if (w != p[v] || pe){\n        if (d[w] == -1){\n\
    \          p[w] = v;\n          d[w] = d[v] + 1;\n          dfs1(E, p, d, imos,\
    \ w);\n          imos[v] += imos[w];\n        } else if (d[w] < d[v]){\n     \
    \     imos[v]++;\n          imos[w]--;\n        }\n      } else {\n        pe\
    \ = true;\n      }\n    }\n  }\n  void dfs2(vector<vector<int>> &E, vector<int>\
    \ &p, vector<int> &imos, int v = 0){\n    for (int w : E[v]){\n      if (tcc[w]\
    \ == -1){\n        if (imos[w] > 0){\n          tcc[w] = tcc[v];\n        } else\
    \ {\n          tcc[w] = cnt;\n          cnt++;\n        }\n        dfs2(E, p,\
    \ imos, w);\n      }\n    }\n  }\n  int operator [](int v){\n    return tcc[v];\n\
    \  }\n};\n#line 5 \"test/library_checker/graph/two_edge_connected_components.test.cpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int a, b;\n    cin >> a >> b;\n    E[a].push_back(b);\n\
    \    E[b].push_back(a);\n  }\n  two_edge_connected_components G(E);\n  int K =\
    \ G.cnt;\n  vector<vector<int>> v(K);\n  for (int i = 0; i < N; i++){\n    v[G[i]].push_back(i);\n\
    \  }\n  cout << K << endl;\n  for (int i = 0; i < K; i++){\n    int l = v[i].size();\n\
    \    cout << l;\n    for (int j = 0; j < l; j++){\n      cout << ' ' << v[i][j];\n\
    \    }\n    cout << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../graph/two_edge_connected_components.hpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int a, b;\n    cin >> a >> b;\n    E[a].push_back(b);\n\
    \    E[b].push_back(a);\n  }\n  two_edge_connected_components G(E);\n  int K =\
    \ G.cnt;\n  vector<vector<int>> v(K);\n  for (int i = 0; i < N; i++){\n    v[G[i]].push_back(i);\n\
    \  }\n  cout << K << endl;\n  for (int i = 0; i < K; i++){\n    int l = v[i].size();\n\
    \    cout << l;\n    for (int j = 0; j < l; j++){\n      cout << ' ' << v[i][j];\n\
    \    }\n    cout << endl;\n  }\n}"
  dependsOn:
  - graph/two_edge_connected_components.hpp
  isVerificationFile: true
  path: test/library_checker/graph/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:19:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/two_edge_connected_components.test.cpp
- /verify/test/library_checker/graph/two_edge_connected_components.test.cpp.html
title: test/library_checker/graph/two_edge_connected_components.test.cpp
---
