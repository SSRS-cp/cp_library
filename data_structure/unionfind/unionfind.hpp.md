---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl_1_a.test.cpp
    title: test/aoj/dsl/dsl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/unionfind.test.cpp
    title: test/library_checker/data_structure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/unionfind.md
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"data_structure/unionfind/unionfind.hpp\"\n/**\n * @brief\
    \ UnionFind\n * @docs docs/data-structure/unionfind.md\n*/\nstruct unionfind{\n\
    \  vector<int> p;\n  unionfind(int N){\n    p = vector<int>(N, -1);\n  }\n  int\
    \ root(int x){\n    if (p[x] < 0){\n      return x;\n    } else {\n      p[x]\
    \ = root(p[x]);\n      return p[x];\n    }\n  }\n  bool same(int x, int y){\n\
    \    return root(x) == root(y);\n  }\n  void unite(int x, int y){\n    x = root(x);\n\
    \    y = root(y);\n    if (x != y){\n      if (p[x] < p[y]){\n        swap(x,\
    \ y);\n      }\n      p[y] += p[x];\n      p[x] = y;\n    }\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief UnionFind\n * @docs docs/data-structure/unionfind.md\n\
    */\nstruct unionfind{\n  vector<int> p;\n  unionfind(int N){\n    p = vector<int>(N,\
    \ -1);\n  }\n  int root(int x){\n    if (p[x] < 0){\n      return x;\n    } else\
    \ {\n      p[x] = root(p[x]);\n      return p[x];\n    }\n  }\n  bool same(int\
    \ x, int y){\n    return root(x) == root(y);\n  }\n  void unite(int x, int y){\n\
    \    x = root(x);\n    y = root(y);\n    if (x != y){\n      if (p[x] < p[y]){\n\
    \        swap(x, y);\n      }\n      p[y] += p[x];\n      p[x] = y;\n    }\n \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/unionfind/unionfind.hpp
  requiredBy: []
  timestamp: '2022-08-06 15:53:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/unionfind.test.cpp
  - test/aoj/dsl/dsl_1_a.test.cpp
documentation_of: data_structure/unionfind/unionfind.hpp
layout: document
redirect_from:
- /library/data_structure/unionfind/unionfind.hpp
- /library/data_structure/unionfind/unionfind.hpp.html
title: UnionFind
---
# UnionFind
## 概要
集合を扱うデータ構造。

## 操作
* `unionfind(N)`: $0, 1, \dots, N-1$ がそれぞれ異なる集合に属している状態で初期化する。
* `root(x)`: $x$ が属する集合を代表する要素を $1$ つ答える。同じ集合の要素について `root` を行ったとき、同じ要素が返ることが保証される。
* `same(x, y)`: $x, y$ が同じ集合に属するか判定する。
* `unite(x, y)`: $x$ の属する集合と $y$ の属する集合を併合する。既に同じ集合に属する場合は何も発生しない。

## 資料
[data-structures](https://scrapbox.io/data-structures/Union_Find)