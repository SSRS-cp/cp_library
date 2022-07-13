---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/sequence/sparse_table.cpp
    title: data_structure/sequence/sparse_table.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library_checker/static_rmq_2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nconst int INF = 1000000000;\n#line 1 \"data_structure/sequence/sparse_table.cpp\"\
    \ntemplate <typename T>\nstruct sparse_table{\n  vector<vector<T>> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  sparse_table(vector<T> &A, function<T(T, T)> f, T E): f(f),\
    \ E(E){\n    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n    ST =\
    \ vector<vector<int>>(LOG, vector<int>(N));\n    for (int i = 0; i < N; i++){\n\
    \      ST[0][i] = A[i];\n    }\n    for (int i = 0; i < LOG - 1; i++){\n     \
    \ for (int j = 0; j < N - (1 << i); j++){\n        ST[i + 1][j] = f(ST[i][j],\
    \ ST[i][j + (1 << i)]);\n      }\n    }\n  }\n  int range_min(int L, int R){\n\
    \    if (L == R){\n      return E;\n    }\n    int d = 31 - __builtin_clz(R -\
    \ L);\n    return f(ST[d][L], ST[d][R - (1 << d)]);\n  }\n};\n#line 6 \"test/library_checker/static_rmq_2.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<int> a(N);\n  for (int\
    \ i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  sparse_table<int> DST(a, [](int\
    \ a, int b){return min(a, b);}, INF);\n  for (int i = 0; i < Q; i++){\n    int\
    \ l, r;\n    cin >> l >> r;\n    cout << DST.query(l, r) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nconst int INF = 1000000000;\n#include \"../../data_structure/sequence/sparse_table.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<int> a(N);\n  for (int\
    \ i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  sparse_table<int> DST(a, [](int\
    \ a, int b){return min(a, b);}, INF);\n  for (int i = 0; i < Q; i++){\n    int\
    \ l, r;\n    cin >> l >> r;\n    cout << DST.query(l, r) << endl;\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/sparse_table.cpp
  isVerificationFile: true
  path: test/library_checker/static_rmq_2.test.cpp
  requiredBy: []
  timestamp: '2022-07-13 10:13:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/static_rmq_2.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/static_rmq_2.test.cpp
- /verify/test/library_checker/static_rmq_2.test.cpp.html
title: test/library_checker/static_rmq_2.test.cpp
---
