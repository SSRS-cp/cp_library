---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl_1_a.test.cpp
    title: test/aoj/dsl/dsl_1_a.test.cpp
  - icon: ':x:'
    path: test/library_checker/data_structure/unionfind.test.cpp
    title: test/library_checker/data_structure/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"data_structure/unionfind/unionfind.hpp\"\n/**\n * @brief\
    \ UnionFind\n*/\nstruct unionfind{\n  vector<int> p;\n  unionfind(int N){\n  \
    \  p = vector<int>(N, -1);\n  }\n  int root(int x){\n    if (p[x] < 0){\n    \
    \  return x;\n    } else {\n      p[x] = root(p[x]);\n      return p[x];\n   \
    \ }\n  }\n  bool same(int x, int y){\n    return root(x) == root(y);\n  }\n  void\
    \ unite(int x, int y){\n    x = root(x);\n    y = root(y);\n    if (x != y){\n\
    \      if (p[x] < p[y]){\n        swap(x, y);\n      }\n      p[y] += p[x];\n\
    \      p[x] = y;\n    }\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief UnionFind\n*/\nstruct unionfind{\n  vector<int>\
    \ p;\n  unionfind(int N){\n    p = vector<int>(N, -1);\n  }\n  int root(int x){\n\
    \    if (p[x] < 0){\n      return x;\n    } else {\n      p[x] = root(p[x]);\n\
    \      return p[x];\n    }\n  }\n  bool same(int x, int y){\n    return root(x)\
    \ == root(y);\n  }\n  void unite(int x, int y){\n    x = root(x);\n    y = root(y);\n\
    \    if (x != y){\n      if (p[x] < p[y]){\n        swap(x, y);\n      }\n   \
    \   p[y] += p[x];\n      p[x] = y;\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/unionfind/unionfind.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/dsl/dsl_1_a.test.cpp
  - test/library_checker/data_structure/unionfind.test.cpp
documentation_of: data_structure/unionfind/unionfind.hpp
layout: document
redirect_from:
- /library/data_structure/unionfind/unionfind.hpp
- /library/data_structure/unionfind/unionfind.hpp.html
title: UnionFind
---
