---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/unionfind.test.cpp
    title: test/library_checker/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/unionfind.cpp\"\nstruct unionfind{\n  vector<int>\
    \ p;\n  unionfind(int N){\n    p = vector<int>(N, -1);\n  }\n  int root(int x){\n\
    \    if (p[x] < 0){\n      return x;\n    } else {\n      p[x] = root(p[x]);\n\
    \      return p[x];\n    }\n  }\n  bool same(int x, int y){\n    return root(x)\
    \ == root(y);\n  }\n  void unite(int x, int y){\n    x = root(x);\n    y = root(y);\n\
    \    if (x != y){\n      if (p[x] < p[y]){\n        swap(x, y);\n      }\n   \
    \   p[y] += p[x];\n      p[x] = y;\n    }\n  }\n};\n"
  code: "struct unionfind{\n  vector<int> p;\n  unionfind(int N){\n    p = vector<int>(N,\
    \ -1);\n  }\n  int root(int x){\n    if (p[x] < 0){\n      return x;\n    } else\
    \ {\n      p[x] = root(p[x]);\n      return p[x];\n    }\n  }\n  bool same(int\
    \ x, int y){\n    return root(x) == root(y);\n  }\n  void unite(int x, int y){\n\
    \    x = root(x);\n    y = root(y);\n    if (x != y){\n      if (p[x] < p[y]){\n\
    \        swap(x, y);\n      }\n      p[y] += p[x];\n      p[x] = y;\n    }\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/unionfind.cpp
  requiredBy: []
  timestamp: '2022-07-13 02:28:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/unionfind.test.cpp
documentation_of: data_structure/unionfind.cpp
layout: document
redirect_from:
- /library/data_structure/unionfind.cpp
- /library/data_structure/unionfind.cpp.html
title: data_structure/unionfind.cpp
---
