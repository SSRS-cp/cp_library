---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nstruct unionfind{\n\tvector<int>\
    \ p;\n\tunionfind(int N){\n\t\tp = vector<int>(N, -1);\n\t}\n\tint root(int x){\n\
    \t\tif (p[x] < 0){\n\t\t\treturn x;\n\t\t} else {\n\t\t\tp[x] = root(p[x]);\n\t\
    \t\treturn p[x];\n\t\t}\n\t}\n\tbool same(int x, int y){\n\t\treturn root(x) ==\
    \ root(y);\n\t}\n\tvoid unite(int x, int y){\n\t\tx = root(x);\n\t\ty = root(y);\n\
    \t\tif (x != y){\n\t\t\tif (p[x] < p[y]){\n\t\t\t\tswap(x, y);\n\t\t\t}\n\t\t\t\
    p[y] += p[x];\n\t\t\tp[x] = y;\n\t\t}\n\t}\n};\nint main(){\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  unionfind UF(N);\n  for (int i = 0; i < Q; i++){\n    int t, u,\
    \ v;\n    cin >> t >> u >> v;\n    if (t == 0){\n      UF.unite(u, v);\n    }\n\
    \    if (t == 1){\n      if (UF.same(u, v)){\n        cout << 1 << endl;\n   \
    \   } else {\n        cout << 0 << endl;\n      }\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nstruct unionfind{\n\tvector<int> p;\n\tunionfind(int N){\n\
    \t\tp = vector<int>(N, -1);\n\t}\n\tint root(int x){\n\t\tif (p[x] < 0){\n\t\t\
    \treturn x;\n\t\t} else {\n\t\t\tp[x] = root(p[x]);\n\t\t\treturn p[x];\n\t\t\
    }\n\t}\n\tbool same(int x, int y){\n\t\treturn root(x) == root(y);\n\t}\n\tvoid\
    \ unite(int x, int y){\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x != y){\n\
    \t\t\tif (p[x] < p[y]){\n\t\t\t\tswap(x, y);\n\t\t\t}\n\t\t\tp[y] += p[x];\n\t\
    \t\tp[x] = y;\n\t\t}\n\t}\n};\nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  unionfind\
    \ UF(N);\n  for (int i = 0; i < Q; i++){\n    int t, u, v;\n    cin >> t >> u\
    \ >> v;\n    if (t == 0){\n      UF.unite(u, v);\n    }\n    if (t == 1){\n  \
    \    if (UF.same(u, v)){\n        cout << 1 << endl;\n      } else {\n       \
    \ cout << 0 << endl;\n      }\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 01:42:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unionfind.test.cpp
layout: document
redirect_from:
- /verify/unionfind.test.cpp
- /verify/unionfind.test.cpp.html
title: unionfind.test.cpp
---
