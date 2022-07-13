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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
  bundledCode: "#line 1 \"test/aoj/dsl_5_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/dual_binary_indexed_tree.cpp\"\
    \ntemplate <typename T>\nstruct dual_binary_indexed_tree{\n  int N;\n  vector<T>\
    \ BIT;\n  function<T(T, T)> f;\n  T E;\n  dual_binary_indexed_tree(){\n  }\n \
    \ dual_binary_indexed_tree(int N, function<T(T, T)> f, T E): N(N), BIT(N + 1,\
    \ E), f(f), E(E){\n  }\n  dual_binary_indexed_tree(vector<T> &A, function<T(T,\
    \ T)> f, T E): N(A.size()), BIT(N + 1), f(f), E(E){\n    for (int i = 0; i < N;\
    \ i++){\n      BIT[i + 1] = A[i];\n    }\n  }\n  void add(int i, T x){\n    while\
    \ (i > 0){\n      BIT[i] = f(BIT[i], x);\n      i -= i & -i;\n    }\n  }\n  T\
    \ operator [](int i){\n    i++;\n    T ans = E;\n    while (i <= N){\n      ans\
    \ = f(ans, BIT[i]);\n      i += i & -i;\n    }\n    return ans;\n  }\n  vector<T>\
    \ get(){\n    vector<T> ans = BIT;\n    for (int i = N - 1; i >= 1; i--){\n  \
    \    if (i + (i & -i) <= N){\n        ans[i] = f(ans[i + (i & -i)], ans[i]);\n\
    \      }\n    }\n    ans.erase(ans.begin());\n    return ans;\n  }\n};\n#line\
    \ 5 \"test/aoj/dsl_5_a.test.cpp\"\nint main(){\n  int N, T;\n  cin >> N >> T;\n\
    \  dual_binary_indexed_tree<int> BIT(T, plus<int>(), 0);\n  for (int i = 0; i\
    \ < N; i++){\n    int l, r;\n    cin >> l >> r;\n    BIT.add(l, -1);\n    BIT.add(r,\
    \ 1);\n  }\n  vector<int> S = BIT.get();\n  int ans = 0;\n  for (int i = 0; i\
    \ < T; i++){\n    ans = max(ans, S[i]);\n  }\n  cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/dual_binary_indexed_tree.cpp\"\
    \nint main(){\n  int N, T;\n  cin >> N >> T;\n  dual_binary_indexed_tree<int>\
    \ BIT(T, plus<int>(), 0);\n  for (int i = 0; i < N; i++){\n    int l, r;\n   \
    \ cin >> l >> r;\n    BIT.add(l, -1);\n    BIT.add(r, 1);\n  }\n  vector<int>\
    \ S = BIT.get();\n  int ans = 0;\n  for (int i = 0; i < T; i++){\n    ans = max(ans,\
    \ S[i]);\n  }\n  cout << ans << endl;\n}\n"
  dependsOn:
  - data_structure/sequence/dual_binary_indexed_tree.cpp
  isVerificationFile: true
  path: test/aoj/dsl_5_a.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 14:42:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_5_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_5_a.test.cpp
- /verify/test/aoj/dsl_5_a.test.cpp.html
title: test/aoj/dsl_5_a.test.cpp
---
