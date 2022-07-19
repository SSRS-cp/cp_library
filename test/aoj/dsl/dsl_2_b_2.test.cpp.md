---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/invertible_binary_indexed_tree.hpp
    title: "\u53EF\u9006 Binary Indexed Tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/dsl/dsl_2_b_2.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"data_structure/sequence/invertible_binary_indexed_tree.hpp\"\
    \n/**\n * @brief \u53EF\u9006 Binary Indexed Tree\n*/\ntemplate <typename T>\n\
    struct invertible_binary_indexed_tree{\n  int N;\n  vector<T> BIT;\n  function<T(T,\
    \ T)> f;\n  function<T(T)> inv;\n  T E;\n  invertible_binary_indexed_tree(){\n\
    \  }\n  invertible_binary_indexed_tree(int N, function<T(T, T)> f, function<T(T)>\
    \ inv, T E): N(N), BIT(N + 1, E), f(f), inv(inv), E(E){\n  }\n  invertible_binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, function<T(T)> inv, T E): N(A.size()), BIT(N + 1),\
    \ f(f), inv(inv), E(E){\n    for (int i = 0; i < N; i++){\n      BIT[i + 1] =\
    \ A[i];\n    }\n    for (int i = 1; i < N; i++){\n      if (i + (i & -i) <= N){\n\
    \        BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n      }\n    }\n \
    \ }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n      BIT[i] = f(BIT[i],\
    \ x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans = E;\n    while\
    \ (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i & -i;\n    }\n    return\
    \ ans;\n  }\n  T sum(int l, int r){\n    return f(sum(r), inv(sum(l)));\n  }\n\
    };\n#line 5 \"test/aoj/dsl/dsl_2_b_2.test.cpp\"\nint main(){\n  int n, q;\n  cin\
    \ >> n >> q;\n  invertible_binary_indexed_tree<int> BIT(n, plus<int>(), negate<int>(),\
    \ 0);\n  for (int i = 0; i < q; i++){\n    int com, x, y;\n    cin >> com >> x\
    \ >> y;\n    if (com == 0){\n      x--;\n      BIT.add(x, y);\n    }\n    if (com\
    \ == 1){\n      x--;\n      cout << BIT.sum(x, y) << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../data_structure/sequence/invertible_binary_indexed_tree.hpp\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  invertible_binary_indexed_tree<int>\
    \ BIT(n, plus<int>(), negate<int>(), 0);\n  for (int i = 0; i < q; i++){\n   \
    \ int com, x, y;\n    cin >> com >> x >> y;\n    if (com == 0){\n      x--;\n\
    \      BIT.add(x, y);\n    }\n    if (com == 1){\n      x--;\n      cout << BIT.sum(x,\
    \ y) << endl;\n    }\n  }\n}"
  dependsOn:
  - data_structure/sequence/invertible_binary_indexed_tree.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl_2_b_2.test.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:43:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl_2_b_2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl_2_b_2.test.cpp
- /verify/test/aoj/dsl/dsl_2_b_2.test.cpp.html
title: test/aoj/dsl/dsl_2_b_2.test.cpp
---
