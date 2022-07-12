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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/sequence/abstract_binary_indexed_tree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/abstract_binary_indexed_tree.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  binary_indexed_tree<long\
    \ long> BIT(a, plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int\
    \ t;\n    cin >> t;\n    if (t == 0){\n      int p, x;\n      cin >> p >> x;\n\
    \      BIT.add(p, x);\n    }\n    if (t == 1){\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << BIT.sum(r) - BIT.sum(l) << endl;\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/point_add_range_sum_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/point_add_range_sum_2.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/point_add_range_sum_2.test.cpp
- /verify/test/library_checker/point_add_range_sum_2.test.cpp.html
title: test/library_checker/point_add_range_sum_2.test.cpp
---
