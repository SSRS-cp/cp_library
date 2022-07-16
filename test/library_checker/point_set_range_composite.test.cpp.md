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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../other/monoids/linear.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #include \"../../data_structure/sequence/segment_tree.hpp\"\n#include \"../../other/monoids/linear.hpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<linear> f(N);\n  for (int\
    \ i = 0; i < N; i++){\n    cin >> f[i].a >> f[i].b;\n  }\n  segment_tree<linear>\
    \ ST(f, composite, linear());\n  for (int i = 0; i < Q; i++){\n    int t;\n  \
    \  cin >> t;\n    if (t == 0){\n      int p, c, d;\n      cin >> p >> c >> d;\n\
    \      ST.update(p, linear(c, d));\n    }\n    if (t == 1){\n      int l, r, x;\n\
    \      cin >> l >> r >> x;\n      cout << value(ST.query(l, r), x) << endl;\n\
    \    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/point_set_range_composite.test.cpp
- /verify/test/library_checker/point_set_range_composite.test.cpp.html
title: test/library_checker/point_set_range_composite.test.cpp
---
