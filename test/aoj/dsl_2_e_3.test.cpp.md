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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/sequence/commutative_dual_segment_tree:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/commutative_dual_segment_tree\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  commutative_dual_segment_tree<int>\
    \ ST(n, plus<int>(), 0);\n  for (int i = 0; i < q; i++){\n    int c;\n    cin\
    \ >> c;\n    if (c == 0){\n      int s, t, x;\n      cin >> s >> t >> x;\n   \
    \   s--;\n      ST.range_apply(s, t, x);\n    }\n    if (c == 1){\n      int t;\n\
    \      cin >> t;\n      t--;\n      cout << ST[t] << endl;\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/dsl_2_e_3.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/dsl_2_e_3.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_e_3.test.cpp
- /verify/test/aoj/dsl_2_e_3.test.cpp.html
title: test/aoj/dsl_2_e_3.test.cpp
---
