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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/unionfind.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../../data_structure/unionfind.cpp\"\nint main(){\n\
    \  int N, Q;\n  cin >> N >> Q;\n  unionfind UF(N);\n  for (int i = 0; i < Q; i++){\n\
    \    int t, u, v;\n    cin >> t >> u >> v;\n    if (t == 0){\n      UF.unite(u,\
    \ v);\n    }\n    if (t == 1){\n      if (UF.same(u, v)){\n        cout << 1 <<\
    \ endl;\n      } else {\n        cout << 0 << endl;\n      }\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/unionfind.test.cpp
- /verify/test/library_checker/unionfind.test.cpp.html
title: test/library_checker/unionfind.test.cpp
---
