---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structures/UnionFind.cpp\"\nstruct unionfind{\n\tvector<int>\
    \ p;\n\tunionfind(int N){\n\t\tp = vector<int>(N, -1);\n\t}\n\tint root(int x){\n\
    \t\tif (p[x] < 0){\n\t\t\treturn x;\n\t\t} else {\n\t\t\tp[x] = root(p[x]);\n\t\
    \t\treturn p[x];\n\t\t}\n\t}\n\tbool same(int x, int y){\n\t\treturn root(x) ==\
    \ root(y);\n\t}\n\tvoid unite(int x, int y){\n\t\tx = root(x);\n\t\ty = root(y);\n\
    \t\tif (x != y){\n\t\t\tif (p[x] < p[y]){\n\t\t\t\tswap(x, y);\n\t\t\t}\n\t\t\t\
    p[y] += p[x];\n\t\t\tp[x] = y;\n\t\t}\n\t}\n};\n"
  code: "struct unionfind{\n\tvector<int> p;\n\tunionfind(int N){\n\t\tp = vector<int>(N,\
    \ -1);\n\t}\n\tint root(int x){\n\t\tif (p[x] < 0){\n\t\t\treturn x;\n\t\t} else\
    \ {\n\t\t\tp[x] = root(p[x]);\n\t\t\treturn p[x];\n\t\t}\n\t}\n\tbool same(int\
    \ x, int y){\n\t\treturn root(x) == root(y);\n\t}\n\tvoid unite(int x, int y){\n\
    \t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x != y){\n\t\t\tif (p[x] < p[y]){\n\
    \t\t\t\tswap(x, y);\n\t\t\t}\n\t\t\tp[y] += p[x];\n\t\t\tp[x] = y;\n\t\t}\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-01-23 14:11:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/UnionFind.cpp
layout: document
redirect_from:
- /library/Data_Structures/UnionFind.cpp
- /library/Data_Structures/UnionFind.cpp.html
title: Data_Structures/UnionFind.cpp
---
