---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/invertible_cumulative_sum.hpp
    title: "\u53EF\u9006\u7D2F\u7A4D\u548C"
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
  bundledCode: "#line 1 \"test/library_checker/static_range_sum_2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"data_structure/sequence/invertible_cumulative_sum.hpp\"\
    \n/**\n * @brief \u53EF\u9006\u7D2F\u7A4D\u548C\n*/\ntemplate <typename T>\nstruct\
    \ invertible_cumulative_sum{\n  vector<T> S;\n  function<T(T, T)> f;\n  function<T(T)>\
    \ inv;\n  T E;\n  invertible_cumulative_sum(){\n  }\n  invertible_cumulative_sum(vector<T>\
    \ A, function<T(T, T)> f, function<T(T)> inv, T E): f(f), inv(inv), E(E){\n  \
    \  int N = A.size();\n    S = vector<T>(N + 1);\n    S[0] = E;\n    for (int i\
    \ = 0; i < N; i++){\n      S[i + 1] = f(S[i], A[i]);\n    }\n  }\n  T get(int\
    \ i){\n    return S[i];\n  }\n  T get(int l, int r){\n    return f(S[r], inv(S[l]));\n\
    \  }\n};\n#line 5 \"test/library_checker/static_range_sum_2.test.cpp\"\nint main(){\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for (int i = 0; i\
    \ < N; i++){\n    cin >> a[i];\n  }\n  invertible_cumulative_sum<long long> S(a,\
    \ plus<long long>(), negate<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << S.get(l, r) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/invertible_cumulative_sum.hpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  invertible_cumulative_sum<long\
    \ long> S(a, plus<long long>(), negate<long long>(), 0);\n  for (int i = 0; i\
    \ < Q; i++){\n    int l, r;\n    cin >> l >> r;\n    cout << S.get(l, r) << endl;\n\
    \  }\n}"
  dependsOn:
  - data_structure/sequence/invertible_cumulative_sum.hpp
  isVerificationFile: true
  path: test/library_checker/static_range_sum_2.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/static_range_sum_2.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/static_range_sum_2.test.cpp
- /verify/test/library_checker/static_range_sum_2.test.cpp.html
title: test/library_checker/static_range_sum_2.test.cpp
---
