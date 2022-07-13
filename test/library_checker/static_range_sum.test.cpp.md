---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/cumulative_sum.cpp
    title: "Cumulative Sum (\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/library_checker/static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 1 \"data_structure/sequence/cumulative_sum.cpp\"\n\
    template <typename T>\nstruct cumulative_sum{\n  vector<T> S;\n  function<T(T,\
    \ T)> f;\n  T E;\n  cumulative_sum(){\n  }\n  cumulative_sum(vector<T> A, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    int N = A.size();\n    S = vector<T>(N + 1);\n\
    \    S[0] = E;\n    for (int i = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n\
    \    }\n  }\n  T get(int i){\n    return S[i];\n  }\n};\n/**\n * @brief Cumulative\
    \ Sum (\u7D2F\u7A4D\u548C)\n*/\n#line 5 \"test/library_checker/static_range_sum.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  cumulative_sum<long long>\
    \ S(a, plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int l, r;\n\
    \    cin >> l >> r;\n    cout << S.get(r) - S.get(l) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/cumulative_sum.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  cumulative_sum<long long>\
    \ S(a, plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int l, r;\n\
    \    cin >> l >> r;\n    cout << S.get(r) - S.get(l) << endl;\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/cumulative_sum.cpp
  isVerificationFile: true
  path: test/library_checker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 17:04:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/static_range_sum.test.cpp
- /verify/test/library_checker/static_range_sum.test.cpp.html
title: test/library_checker/static_range_sum.test.cpp
---
