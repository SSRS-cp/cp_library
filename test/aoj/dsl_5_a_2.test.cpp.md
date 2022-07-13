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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/sequence/invertible_dual_binary_indexed_tree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/invertible_dual_binary_indexed_tree.cpp\"\
    \nint main(){\n  int N, T;\n  cin >> N >> T;\n  invertible_dual_binary_indexed_tree<int>\
    \ BIT(T, plus<int>(), negate<int>(), 0);\n  for (int i = 0; i < N; i++){\n   \
    \ int l, r;\n    cin >> l >> r;\n    BIT.add(l, r, 1);\n  }\n  vector<int> S =\
    \ BIT.get();\n  int ans = 0;\n  for (int i = 0; i < T; i++){\n    ans = max(ans,\
    \ S[i]);\n  }\n  cout << ans << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/dsl_5_a_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/dsl_5_a_2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_5_a_2.test.cpp
- /verify/test/aoj/dsl_5_a_2.test.cpp.html
title: test/aoj/dsl_5_a_2.test.cpp
---
