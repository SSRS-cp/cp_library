---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/enumerate_triangles.hpp
    title: "\u4E09\u89D2\u5F62\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"test/library_checker/graph/enumerate_triangles.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n#line\
    \ 2 \"graph/enumerate_triangles.hpp\"\n/**\n * @brief \u4E09\u89D2\u5F62\u5217\
    \u6319\n*/\nvector<tuple<int, int, int>> enumerate_triangles(vector<vector<int>>\
    \ &E){\n  int N = E.size();\n  vector<int> d(N);\n  for (int i = 0; i < N; i++){\n\
    \    d[i] = E[i].size();\n  }\n  vector<vector<int>> E2(N);\n  for (int i = 0;\
    \ i < N; i++){\n    for (int j : E[i]){\n      if (d[i] < d[j] || d[i] == d[j]\
    \ && i < j){\n        E2[i].push_back(j);\n      }\n    }\n  }\n  vector<bool>\
    \ flg(N, false);\n  vector<tuple<int, int, int>> ans;\n  for (int i = 0; i < N;\
    \ i++){\n    for (int j : E2[i]){\n      for (int k : E2[i]){\n        flg[k]\
    \ = true;\n      }\n      for (int k : E2[j]){\n        if (flg[k]){\n       \
    \   ans.push_back(make_tuple(i, j, k));\n        }\n      }\n      for (int k\
    \ : E2[i]){\n        flg[k] = false;\n      }\n    }\n  }\n  return ans;\n}\n\
    #line 6 \"test/library_checker/graph/enumerate_triangles.test.cpp\"\nint main(){\n\
    \  int N, M;\n  cin >> N >> M;\n  vector<long long> x(N);\n  for (int i = 0; i\
    \ < N; i++){\n    cin >> x[i];\n  }\n  vector<vector<int>> E(N);\n  for (int i\
    \ = 0; i < M; i++){\n    int u, v;\n    cin >> u >> v;\n    E[u].push_back(v);\n\
    \    E[v].push_back(u);\n  }\n  vector<tuple<int, int, int>> T = enumerate_triangles(E);\n\
    \  int cnt = T.size();\n  long long ans = 0;\n  for (int i = 0; i < cnt; i++){\n\
    \    int a = get<0>(T[i]);\n    int b = get<1>(T[i]);\n    int c = get<2>(T[i]);\n\
    \    ans += x[a] * x[b] % MOD * x[c] % MOD;\n    ans %= MOD;\n  }\n  cout << ans\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #include \"../../../graph/enumerate_triangles.hpp\"\nint main(){\n  int N, M;\n\
    \  cin >> N >> M;\n  vector<long long> x(N);\n  for (int i = 0; i < N; i++){\n\
    \    cin >> x[i];\n  }\n  vector<vector<int>> E(N);\n  for (int i = 0; i < M;\
    \ i++){\n    int u, v;\n    cin >> u >> v;\n    E[u].push_back(v);\n    E[v].push_back(u);\n\
    \  }\n  vector<tuple<int, int, int>> T = enumerate_triangles(E);\n  int cnt =\
    \ T.size();\n  long long ans = 0;\n  for (int i = 0; i < cnt; i++){\n    int a\
    \ = get<0>(T[i]);\n    int b = get<1>(T[i]);\n    int c = get<2>(T[i]);\n    ans\
    \ += x[a] * x[b] % MOD * x[c] % MOD;\n    ans %= MOD;\n  }\n  cout << ans << endl;\n\
    }"
  dependsOn:
  - graph/enumerate_triangles.hpp
  isVerificationFile: true
  path: test/library_checker/graph/enumerate_triangles.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 01:50:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/enumerate_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp.html
title: test/library_checker/graph/enumerate_triangles.test.cpp
---
