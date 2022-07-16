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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #include \"../../data_structure/other/sliding_window_aggregation.hpp\"\n#include\
    \ \"../../other/monoids/linear.hpp\"\nint main(){\n  int Q;\n  cin >> Q;\n  sliding_window_aggregation<linear>\
    \ S(composite, linear());\n  for (int i = 0; i < Q; i++){\n    int t;\n    cin\
    \ >> t;\n    if (t == 0){\n      int a, b;\n      cin >> a >> b;\n      S.push(linear(a,\
    \ b));\n    }\n    if (t == 1){\n      S.pop();\n    }\n    if (t == 2){\n   \
    \   int x;\n      cin >> x;\n      cout << value(S.get(),x) << endl;\n    }\n\
    \  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/queue_operate_all_composite.test.cpp
- /verify/test/library_checker/queue_operate_all_composite.test.cpp.html
title: test/library_checker/queue_operate_all_composite.test.cpp
---
