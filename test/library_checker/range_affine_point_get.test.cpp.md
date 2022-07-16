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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #include \"../../data_structure/sequence/dual_segment_tree.hpp\"\n#include \"\
    ../../other/monoids/linear.hpp\"\nint main(){\n  int N, Q;\n  cin >> N >> Q;\n\
    \  vector<linear> a(N);\n  for (int i = 0; i < N; i++){\n    a[i].a = 0;\n   \
    \ cin >> a[i].b;\n  }\n  dual_segment_tree<linear> ST(a, composite, linear());\n\
    \  for (int i = 0; i < Q; i++){\n    int t;\n    cin >> t;\n    if (t == 0){\n\
    \      int l, r, b, c;\n      cin >> l >> r >> b >> c;\n      ST.range_apply(l,\
    \ r, linear(b, c));\n    }\n    if (t == 1){\n      int p;\n      cin >> p;\n\
    \      cout << ST[p].b << endl;\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/range_affine_point_get.test.cpp
- /verify/test/library_checker/range_affine_point_get.test.cpp.html
title: test/library_checker/range_affine_point_get.test.cpp
---
