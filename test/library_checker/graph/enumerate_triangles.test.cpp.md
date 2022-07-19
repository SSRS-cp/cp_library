---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../enumerate_triangles.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../enumerate_triangles.hpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<long long> x(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> x[i];\n  }\n  vector<vector<int>> E(N);\n\
    \  for (int i = 0; i < M; i++){\n    int u, v;\n    cin >> u >> v;\n    E[u].push_back(v);\n\
    \    E[v].push_back(u);\n  }\n  vector<tuple<int, int, int>> T = enumerate_triangles(E);\n\
    \  int cnt = T.size();\n  long long ans = 0;\n  for (int i = 0; i < cnt; i++){\n\
    \    int a = get<0>(T[i]);\n    int b = get<1>(T[i]);\n    int c = get<2>(T[i]);\n\
    \    ans += x[a] * x[b] % MOD * x[c] % MOD;\n    ans %= MOD;\n  }\n  cout << ans\
    \ << endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/enumerate_triangles.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/enumerate_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp.html
title: test/library_checker/graph/enumerate_triangles.test.cpp
---
