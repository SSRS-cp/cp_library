---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind/unionfind.hpp
    title: data_structure/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"data_structure/unionfind/unionfind.hpp\"\nstruct\
    \ unionfind{\n  vector<int> p;\n  unionfind(int N){\n    p = vector<int>(N, -1);\n\
    \  }\n  int root(int x){\n    if (p[x] < 0){\n      return x;\n    } else {\n\
    \      p[x] = root(p[x]);\n      return p[x];\n    }\n  }\n  bool same(int x,\
    \ int y){\n    return root(x) == root(y);\n  }\n  void unite(int x, int y){\n\
    \    x = root(x);\n    y = root(y);\n    if (x != y){\n      if (p[x] < p[y]){\n\
    \        swap(x, y);\n      }\n      p[y] += p[x];\n      p[x] = y;\n    }\n \
    \ }\n};\n#line 5 \"test/library_checker/data_structure/unionfind.test.cpp\"\n\
    int main(){\n  int N, Q;\n  cin >> N >> Q;\n  unionfind UF(N);\n  for (int i =\
    \ 0; i < Q; i++){\n    int t, u, v;\n    cin >> t >> u >> v;\n    if (t == 0){\n\
    \      UF.unite(u, v);\n    }\n    if (t == 1){\n      if (UF.same(u, v)){\n \
    \       cout << 1 << endl;\n      } else {\n        cout << 0 << endl;\n     \
    \ }\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../../../data_structure/unionfind/unionfind.hpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  unionfind UF(N);\n  for (int i\
    \ = 0; i < Q; i++){\n    int t, u, v;\n    cin >> t >> u >> v;\n    if (t == 0){\n\
    \      UF.unite(u, v);\n    }\n    if (t == 1){\n      if (UF.same(u, v)){\n \
    \       cout << 1 << endl;\n      } else {\n        cout << 0 << endl;\n     \
    \ }\n    }\n  }\n}"
  dependsOn:
  - data_structure/unionfind/unionfind.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-08-24 00:37:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/unionfind.test.cpp
- /verify/test/library_checker/data_structure/unionfind.test.cpp.html
title: test/library_checker/data_structure/unionfind.test.cpp
---
