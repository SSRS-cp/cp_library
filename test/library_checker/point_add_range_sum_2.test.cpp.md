---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sequence/invertible_binary_indexed_tree.cpp
    title: data_structure/sequence/invertible_binary_indexed_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/point_add_range_sum_2.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/invertible_binary_indexed_tree.cpp\"\
    \ntemplate <typename T>\nstruct invertible_binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  function<T(T, T)> f;\n  function<T(T)> inv;\n  T E;\n  invertible_binary_indexed_tree(){\n\
    \  }\n  invertible_binary_indexed_tree(int N, function<T(T, T)> f, function<T(T)>\
    \ inv, T E): N(N), BIT(N + 1, E), f(f), inv(inv), E(E){\n  }\n  invertible_binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, function<T(T)> inv, T E): N(A.size()), BIT(N + 1),\
    \ f(f), inv(inv), E(E){\n    for (int i = 0; i < N; i++){\n      BIT[i + 1] =\
    \ A[i];\n    }\n    for (int i = 1; i < N; i++){\n      BIT[i + (i & -i)] = f(BIT[i\
    \ + (i & -i)], BIT[i]);\n    }\n  }\n  void add(int i, T x){\n    i++;\n    while\
    \ (i <= N){\n      BIT[i] = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T\
    \ sum(int i){\n    T ans = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n\
    \      i -= i & -i;\n    }\n    return ans;\n  }\n  T sum(int l, int r){\n   \
    \ return f(sum(r), inv(sum(l)));\n  }\n};\n#line 5 \"test/library_checker/point_add_range_sum_2.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  invertible_binary_indexed_tree<long\
    \ long> BIT(a, plus<long long>(), negate<long long>() 0);\n  for (int i = 0; i\
    \ < Q; i++){\n    int t;\n    cin >> t;\n    if (t == 0){\n      int p, x;\n \
    \     cin >> p >> x;\n      BIT.add(p, x);\n    }\n    if (t == 1){\n      int\
    \ l, r;\n      cin >> l >> r;\n      cout << BIT.sum(l, r) << endl;\n    }\n \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/invertible_binary_indexed_tree.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  invertible_binary_indexed_tree<long\
    \ long> BIT(a, plus<long long>(), negate<long long>() 0);\n  for (int i = 0; i\
    \ < Q; i++){\n    int t;\n    cin >> t;\n    if (t == 0){\n      int p, x;\n \
    \     cin >> p >> x;\n      BIT.add(p, x);\n    }\n    if (t == 1){\n      int\
    \ l, r;\n      cin >> l >> r;\n      cout << BIT.sum(l, r) << endl;\n    }\n \
    \ }\n}\n"
  dependsOn:
  - data_structure/sequence/invertible_binary_indexed_tree.cpp
  isVerificationFile: true
  path: test/library_checker/point_add_range_sum_2.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 08:20:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/point_add_range_sum_2.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/point_add_range_sum_2.test.cpp
- /verify/test/library_checker/point_add_range_sum_2.test.cpp.html
title: test/library_checker/point_add_range_sum_2.test.cpp
---
