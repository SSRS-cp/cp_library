---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library_checker/graph/strongly_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"graph/strongly_connected_components.hpp\"\n/**\n\
    \ * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\nstruct strongly_connected_components{\n\
    \  int cnt = 0;\n  vector<int> scc;\n  void dfs1(vector<vector<int>> &E, vector<int>\
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
    \ [](int k){\n    return scc[k];\n  }\n  int size(){\n    return cnt;\n  }\n};\n\
    #line 5 \"test/library_checker/graph/strongly_connected_components.test.cpp\"\n\
    int main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int a, b;\n    cin >> a >> b;\n    E[a].push_back(b);\n\
    \  }\n  strongly_connected_components G(E);\n  int K = G.size();\n  vector<vector<int>>\
    \ v(K);\n  for (int i = 0; i < N; i++){\n    v[G[i]].push_back(i);\n  }\n  cout\
    \ << K << endl;\n  for (int i = 0; i < K; i++){\n    int l = v[i].size();\n  \
    \  cout << l;\n    for (int j = 0; j < l; j++){\n      cout << ' ' << v[i][j];\n\
    \    }\n    cout << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../../../graph/strongly_connected_components.hpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> E(N);\n  for\
    \ (int i = 0; i < M; i++){\n    int a, b;\n    cin >> a >> b;\n    E[a].push_back(b);\n\
    \  }\n  strongly_connected_components G(E);\n  int K = G.size();\n  vector<vector<int>>\
    \ v(K);\n  for (int i = 0; i < N; i++){\n    v[G[i]].push_back(i);\n  }\n  cout\
    \ << K << endl;\n  for (int i = 0; i < K; i++){\n    int l = v[i].size();\n  \
    \  cout << l;\n    for (int j = 0; j < l; j++){\n      cout << ' ' << v[i][j];\n\
    \    }\n    cout << endl;\n  }\n}"
  dependsOn:
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/library_checker/graph/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:43:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/strongly_connected_components.test.cpp
- /verify/test/library_checker/graph/strongly_connected_components.test.cpp.html
title: test/library_checker/graph/strongly_connected_components.test.cpp
---
