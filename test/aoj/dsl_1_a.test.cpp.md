---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/dsl_1_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"data_structure/unionfind/unionfind.hpp\"\
    \n/**\n * @brief UnionFind\n*/\nstruct unionfind{\n  vector<int> p;\n  unionfind(int\
    \ N){\n    p = vector<int>(N, -1);\n  }\n  int root(int x){\n    if (p[x] < 0){\n\
    \      return x;\n    } else {\n      p[x] = root(p[x]);\n      return p[x];\n\
    \    }\n  }\n  bool same(int x, int y){\n    return root(x) == root(y);\n  }\n\
    \  void unite(int x, int y){\n    x = root(x);\n    y = root(y);\n    if (x !=\
    \ y){\n      if (p[x] < p[y]){\n        swap(x, y);\n      }\n      p[y] += p[x];\n\
    \      p[x] = y;\n    }\n  }\n};\n#line 5 \"test/aoj/dsl_1_a.test.cpp\"\nint main(){\n\
    \  int n, q;\n  cin >> n >> q;\n  unionfind UF(n);\n  for (int i = 0; i < q; i++){\n\
    \    int com, x, y;\n    cin >> com >> x >> y;\n    if (com == 0){\n      UF.unite(x,\
    \ y);\n    }\n    if (com == 1){\n      if (UF.same(x, y)){\n        cout << 1\
    \ << endl;\n      } else {\n        cout << 0 << endl;\n      }\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/unionfind/unionfind.hpp\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  unionfind UF(n);\n  for (int i\
    \ = 0; i < q; i++){\n    int com, x, y;\n    cin >> com >> x >> y;\n    if (com\
    \ == 0){\n      UF.unite(x, y);\n    }\n    if (com == 1){\n      if (UF.same(x,\
    \ y)){\n        cout << 1 << endl;\n      } else {\n        cout << 0 << endl;\n\
    \      }\n    }\n  }\n}"
  dependsOn:
  - data_structure/unionfind/unionfind.hpp
  isVerificationFile: true
  path: test/aoj/dsl_1_a.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_1_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_1_a.test.cpp
- /verify/test/aoj/dsl_1_a.test.cpp.html
title: test/aoj/dsl_1_a.test.cpp
---
