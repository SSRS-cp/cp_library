---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/extended_block_cut_tree.hpp
    title: "\u62E1\u5F35 Block Cut Tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/aoj/grl/grl_3_a_2.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"graph/extended_block_cut_tree.hpp\"\
    \n/**\n * @brief \u62E1\u5F35 Block Cut Tree\n*/\nstruct extended_block_cut_tree{\n\
    \  int N, cnt;\n  vector<vector<int>> G;\n  extended_block_cut_tree(vector<vector<int>>\
    \ &E){\n    N = E.size();\n    vector<int> next(N, -1);\n    vector<int> d(N,\
    \ -1);\n    vector<int> imos(N, 0);\n    for (int i = 0; i < N; i++){\n      if\
    \ (d[i] == -1){\n        d[i] = 0;\n        dfs1(E, next, d, imos, i);\n     \
    \ }\n    }\n    cnt = 0;\n    G.resize(N + 1);\n    vector<bool> used(N, false);\n\
    \    for (int i = 0; i < N; i++){\n      if (d[i] == 0){\n        dfs2(E, d, imos,\
    \ used, cnt, i);\n      }\n      if (E[i].empty()){\n        G[i].push_back(N\
    \ + cnt);\n        G[N + cnt].push_back(i);\n        cnt++;\n        G.push_back({});\n\
    \      }\n    }\n    G.pop_back();\n  }\n  void dfs1(vector<vector<int>> &E, vector<int>\
    \ &next, vector<int> &d, vector<int> &imos, int v){\n    for (int w : E[v]){\n\
    \      if (d[w] == -1){\n        d[w] = d[v] + 1;\n        next[v] = w;\n    \
    \    dfs1(E, next, d, imos, w);\n        imos[v] += imos[w];\n      } else if\
    \ (d[w] < d[v] - 1){\n        imos[v]++;\n        imos[next[w]]--;\n      }\n\
    \    }\n  }\n  void dfs2(vector<vector<int>> &E, vector<int> &d, vector<int> &imos,\
    \ vector<bool> &used, int b, int v){\n    used[v] = true;\n    bool ok = false;\n\
    \    for (int w : E[v]){\n      if (d[w] == d[v] + 1 && !used[w]){\n        if\
    \ (imos[w] > 0){\n          if (!ok){\n            ok = true;\n            G[v].push_back(N\
    \ + b);\n            G[N + b].push_back(v);\n          }\n          dfs2(E, d,\
    \ imos, used, b, w);\n        } else {\n          G[v].push_back(N + cnt);\n \
    \         G[N + cnt].push_back(v);\n          cnt++;\n          G.push_back({});\n\
    \          dfs2(E, d, imos, used, cnt - 1, w);\n        }\n      }\n    }\n  \
    \  if (!ok && d[v] > 0){\n      G[v].push_back(N + b);\n      G[N + b].push_back(v);\n\
    \    }\n  }\n  int size(){\n    return G.size();\n  }\n  vector<int> &operator\
    \ [](int v){\n    return G[v];\n  }\n};\n#line 5 \"test/aoj/grl/grl_3_a_2.test.cpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int s, t;\n    cin >> s >> t;\n    E[s].push_back(t);\n\
    \    E[t].push_back(s);\n  }\n  extended_block_cut_tree T(E);\n  for (int i =\
    \ 0; i < N; i++){\n    if (T[i].size() >= 2){\n      cout << i << endl;\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../graph/extended_block_cut_tree.hpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int s, t;\n    cin >> s >> t;\n    E[s].push_back(t);\n\
    \    E[t].push_back(s);\n  }\n  extended_block_cut_tree T(E);\n  for (int i =\
    \ 0; i < N; i++){\n    if (T[i].size() >= 2){\n      cout << i << endl;\n    }\n\
    \  }\n}"
  dependsOn:
  - graph/extended_block_cut_tree.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_3_a_2.test.cpp
  requiredBy: []
  timestamp: '2022-07-24 02:46:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl_3_a_2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_3_a_2.test.cpp
- /verify/test/aoj/grl/grl_3_a_2.test.cpp.html
title: test/aoj/grl/grl_3_a_2.test.cpp
---
