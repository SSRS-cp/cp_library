---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"test/aoj/grl/grl_3_c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"graph/strongly_connected_components.hpp\"\
    \n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\nstruct strongly_connected_components{\n\
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
    \ [](int k){\n    return scc[k];\n  }\n};\n#line 5 \"test/aoj/grl/grl_3_c.test.cpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int s, t;\n    cin >> s >> t;\n    E[s].push_back(t);\n\
    \  }\n  strongly_connected_components G(E);\n  int Q;\n  cin >> Q;\n  for (int\
    \ i = 0; i < Q; i++){\n    int u, v;\n    cin >> u >> v;\n    if (G[u] == G[v]){\n\
    \      cout << 1 << endl;\n    } else {\n      cout << 0 << endl;\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../graph/strongly_connected_components.hpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int s, t;\n    cin >> s >> t;\n    E[s].push_back(t);\n\
    \  }\n  strongly_connected_components G(E);\n  int Q;\n  cin >> Q;\n  for (int\
    \ i = 0; i < Q; i++){\n    int u, v;\n    cin >> u >> v;\n    if (G[u] == G[v]){\n\
    \      cout << 1 << endl;\n    } else {\n      cout << 0 << endl;\n    }\n  }\n\
    }"
  dependsOn:
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_3_c.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:19:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl_3_c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_3_c.test.cpp
- /verify/test/aoj/grl/grl_3_c.test.cpp.html
title: test/aoj/grl/grl_3_c.test.cpp
---
