---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 2 \"data_structure/sequence/binary_indexed_tree.hpp\"\
    \n/**\n * @brief Binary Indexed Tree\n*/\ntemplate <typename T>\nstruct binary_indexed_tree{\n\
    \  int N;\n  vector<T> BIT;\n  function<T(T, T)> f;\n  T E;\n  binary_indexed_tree(){\n\
    \  }\n  binary_indexed_tree(int N, function<T(T, T)> f, T E): N(N), BIT(N + 1,\
    \ E), f(f), E(E){\n  }\n  binary_indexed_tree(vector<T> &A, function<T(T, T)>\
    \ f, T E): N(A.size()), BIT(N + 1), f(f), E(E){\n    for (int i = 0; i < N; i++){\n\
    \      BIT[i + 1] = A[i];\n    }\n    for (int i = 1; i < N; i++){\n      if (i\
    \ + (i & -i) <= N){\n        BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n\
    \      }\n    }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n\
    \      BIT[i] = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n\
    \    T ans = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i\
    \ & -i;\n    }\n    return ans;\n  }\n};\n#line 5 \"test/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  binary_indexed_tree<long\
    \ long> BIT(a, plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int\
    \ t;\n    cin >> t;\n    if (t == 0){\n      int p, x;\n      cin >> p >> x;\n\
    \      BIT.add(p, x);\n    }\n    if (t == 1){\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << BIT.sum(r) - BIT.sum(l) << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../data_structure/sequence/binary_indexed_tree.hpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  binary_indexed_tree<long\
    \ long> BIT(a, plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int\
    \ t;\n    cin >> t;\n    if (t == 0){\n      int p, x;\n      cin >> p >> x;\n\
    \      BIT.add(p, x);\n    }\n    if (t == 1){\n      int l, r;\n      cin >>\
    \ l >> r;\n      cout << BIT.sum(r) - BIT.sum(l) << endl;\n    }\n  }\n}"
  dependsOn:
  - data_structure/sequence/binary_indexed_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:43:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/point_add_range_sum.test.cpp
- /verify/test/library_checker/data_structure/point_add_range_sum.test.cpp.html
title: test/library_checker/data_structure/point_add_range_sum.test.cpp
---
