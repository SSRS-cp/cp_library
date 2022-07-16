---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/sequence/dual_sparse_table.hpp
    title: "\u53CC\u5BFE\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/945
    links:
    - https://yukicoder.me/problems/no/945
  bundledCode: "#line 1 \"test/yukicoder/yuki_945.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/945\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst int INF = 1000000;\n#line\
    \ 2 \"data_structure/sequence/dual_sparse_table.hpp\"\n/**\n * @brief \u53CC\u5BFE\
    \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n*/\ntemplate <typename T>\n\
    struct dual_sparse_table{\n  vector<vector<T>> ST;\n  function<T(T, T)> f;\n \
    \ T E;\n  dual_sparse_table(){\n  }\n  dual_sparse_table(int N, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    int LOG = 32 - __builtin_clz(N);\n    ST = vector<vector<T>>(LOG,\
    \ vector<T>(N, E));\n  }\n  dual_sparse_table(vector<T> &A, function<T(T, T)>\
    \ f, T E): f(f), E(E){\n    int N = A.size();\n    int LOG = 32 - __builtin_clz(N);\n\
    \    ST = vector<vector<T>>(LOG, vector<T>(N, E));\n    ST[0] = A;\n  }\n  void\
    \ apply(int L, int R, T x){\n    if (L == R){\n      return;\n    }\n    int d\
    \ = 31 - __builtin_clz(R - L);\n    ST[d][L] = f(ST[d][L], x);\n    ST[d][R -\
    \ (1 << d)] = f(ST[d][R - (1 << d)], x);\n  }\n  vector<T> get(){\n    int LOG\
    \ = ST.size();\n    int N = ST[0].size();\n    for (int i = LOG - 2; i >= 0; i--){\n\
    \      for (int j = 0; j < N - (1 << i); j++){\n        ST[i][j] = f(ST[i][j],\
    \ ST[i + 1][j]);\n        ST[i][j + (1 << i)] = f(ST[i][j + (1 << i)], ST[i +\
    \ 1][j]);\n      }\n    }\n    return ST[0];\n  }\n};\n#line 6 \"test/yukicoder/yuki_945.test.cpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  dual_sparse_table<pair<int, int>>\
    \ ST(N, [](pair<int, int> a, pair<int, int> b){return min(a, b);}, make_pair(INF,\
    \ 0));\n  for (int i = 0; i < M; i++){\n    int L, R;\n    char T;\n    cin >>\
    \ L >> R >> T;\n    L--;\n    if (T == 'Y'){\n      ST.apply(L, R, make_pair(i,\
    \ 0));\n    }\n    if (T == 'K'){\n      ST.apply(L, R, make_pair(i, 1));\n  \
    \  }\n    if (T == 'C'){\n      ST.apply(L, R, make_pair(i, 2));\n    }\n  }\n\
    \  vector<pair<int, int>> A = ST.get();\n  vector<int> ans(3, 0);\n  for (int\
    \ i = 0; i < N; i++){\n    if (A[i].first != INF){\n      ans[A[i].second]++;\n\
    \    }\n  }\n  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;\n\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/945\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nconst int INF = 1000000;\n#include \"../../data_structure/sequence/dual_sparse_table.hpp\"\
    \nint main(){\n  int N, M;\n  cin >> N >> M;\n  dual_sparse_table<pair<int, int>>\
    \ ST(N, [](pair<int, int> a, pair<int, int> b){return min(a, b);}, make_pair(INF,\
    \ 0));\n  for (int i = 0; i < M; i++){\n    int L, R;\n    char T;\n    cin >>\
    \ L >> R >> T;\n    L--;\n    if (T == 'Y'){\n      ST.apply(L, R, make_pair(i,\
    \ 0));\n    }\n    if (T == 'K'){\n      ST.apply(L, R, make_pair(i, 1));\n  \
    \  }\n    if (T == 'C'){\n      ST.apply(L, R, make_pair(i, 2));\n    }\n  }\n\
    \  vector<pair<int, int>> A = ST.get();\n  vector<int> ans(3, 0);\n  for (int\
    \ i = 0; i < N; i++){\n    if (A[i].first != INF){\n      ans[A[i].second]++;\n\
    \    }\n  }\n  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;\n\n"
  dependsOn:
  - data_structure/sequence/dual_sparse_table.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_945.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/yuki_945.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_945.test.cpp
- /verify/test/yukicoder/yuki_945.test.cpp.html
title: test/yukicoder/yuki_945.test.cpp
---
