---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/dual_binary_indexed_tree.cpp
    title: data_structure/sequence/dual_binary_indexed_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/aoj/dsl_2_e.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/dual_binary_indexed_tree.cpp\"\
    \ntemplate <typename T>\nstruct dual_binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  dual_binary_indexed_tree(){\n  }\n  dual_binary_indexed_tree(int N):\
    \ N(N), BIT(N + 1, 0){\n  }\n  dual_binary_indexed_tree(vector<T> &A): N(A.size()),\
    \ BIT(N + 1){\n    for (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n  \
    \  }\n    for (int i = 1; i < N; i++){\n      BIT[i + (i & -i)] += BIT[i];\n \
    \   }\n  }\n  void add(int i, T x){\n    while (i > 0){\n      BIT[i] += x;\n\
    \      i -= i & -i;\n    }\n  }\n  void add(int L, int R, T x){\n    add(L, -x);\n\
    \    add(R, x);\n  }\n  T operator [](int i){\n    i++;\n    T ans = 0;\n    while\
    \ (i <= N){\n      ans += BIT[i];\n      i += i & -i;\n    }\n    return ans;\n\
    \  }\n};\n#line 5 \"test/aoj/dsl_2_e.test.cpp\"\nint main(){\n  int n, q;\n  cin\
    \ >> n >> q;\n  dual_binary_indexed_tree<int> BIT(n);\n  for (int i = 0; i < q;\
    \ i++){\n    int c;\n    cin >> c;\n    if (c == 0){\n      int s, t, x;\n   \
    \   cin >> s >> t >> x;\n      s--;\n      BIT.add(s, t, x);\n    }\n    if (c\
    \ == 1){\n      int t;\n      cin >> t;\n      t--;\n      cout << BIT[t] << endl;\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/dual_binary_indexed_tree.cpp\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  dual_binary_indexed_tree<int>\
    \ BIT(n);\n  for (int i = 0; i < q; i++){\n    int c;\n    cin >> c;\n    if (c\
    \ == 0){\n      int s, t, x;\n      cin >> s >> t >> x;\n      s--;\n      BIT.add(s,\
    \ t, x);\n    }\n    if (c == 1){\n      int t;\n      cin >> t;\n      t--;\n\
    \      cout << BIT[t] << endl;\n    }\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/dual_binary_indexed_tree.cpp
  isVerificationFile: true
  path: test/aoj/dsl_2_e.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 03:46:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_2_e.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_e.test.cpp
- /verify/test/aoj/dsl_2_e.test.cpp.html
title: test/aoj/dsl_2_e.test.cpp
---