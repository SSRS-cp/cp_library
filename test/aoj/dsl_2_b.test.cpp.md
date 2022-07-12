---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sequence/binary_indexed_tree.cpp
    title: data_structure/sequence/binary_indexed_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/dsl_2_b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/binary_indexed_tree.cpp\"\
    \ntemplate <typename T>\nstruct binary_indexed_tree{\n  int N;\n  vector<T> BIT;\n\
    \  function<T(T, T)> f;\n  T E;\n  binary_indexed_tree(){\n  }\n  binary_indexed_tree(int\
    \ N, function<T(T, T)> f, T E): f(f), E(E), N(N), BIT(N + 1, 0){\n  }\n  binary_indexed_tree(vector<T>\
    \ &A, function<T(T, T)> f, T E): f(f), E(E), N(A.size()), BIT(N + 1){\n    for\
    \ (int i = 0; i < N; i++){\n      BIT[i + 1] = A[i];\n    }\n    for (int i =\
    \ 1; i < N; i++){\n      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);\n \
    \   }\n  }\n  void add(int i, T x){\n    i++;\n    while (i <= N){\n      BIT[i]\
    \ = f(BIT[i], x);\n      i += i & -i;\n    }\n  }\n  T sum(int i){\n    T ans\
    \ = E;\n    while (i > 0){\n      ans = f(ans, BIT[i]);\n      i -= i & -i;\n\
    \    }\n    return ans;\n  }\n};\n#line 5 \"test/aoj/dsl_2_b.test.cpp\"\nint main(){\n\
    \  int n, q;\n  cin >> n >> q;\n  binary_indexed_tree<int> BIT(n);\n  for (int\
    \ i = 0; i < q; i++){\n    int com, x, y;\n    cin >> com >> x >> y;\n    if (com\
    \ == 0){\n      x--;\n      BIT.add(x, y);\n    }\n    if (com == 1){\n      x--;\n\
    \      cout << BIT.sum(x, y) <<endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/binary_indexed_tree.cpp\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  binary_indexed_tree<int> BIT(n);\n\
    \  for (int i = 0; i < q; i++){\n    int com, x, y;\n    cin >> com >> x >> y;\n\
    \    if (com == 0){\n      x--;\n      BIT.add(x, y);\n    }\n    if (com == 1){\n\
    \      x--;\n      cout << BIT.sum(x, y) <<endl;\n    }\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/binary_indexed_tree.cpp
  isVerificationFile: true
  path: test/aoj/dsl_2_b.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 07:37:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/dsl_2_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_b.test.cpp
- /verify/test/aoj/dsl_2_b.test.cpp.html
title: test/aoj/dsl_2_b.test.cpp
---
