---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/sequence/disjoint_sparse_table.hpp
    title: Disjoint Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/static_range_sum_3.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 2 \"data_structure/sequence/disjoint_sparse_table.hpp\"\
    \n/**\n * @brief Disjoint Sparse Table\n*/\ntemplate <typename T>\nstruct disjoint_sparse_table{\n\
    \  vector<T> A;\n  vector<vector<T>> D;\n  function<T(T, T)> f;\n  T E;\n  disjoint_sparse_table(){\n\
    \  }\n  disjoint_sparse_table(int N, function<T(T, T)> f, T E): A(N, E), f(f),\
    \ E(E){\n    if (N > 1){\n      int LOG = 32 - __builtin_clz(N - 1);\n      D\
    \ = vector<vector<T>>(LOG, vector<T>(N));\n    }\n  }\n  disjoint_sparse_table(vector<T>\
    \ &A, function<T(T, T)> f, T E): A(A), f(f), E(E){\n    int N = A.size();\n  \
    \  if (N > 1){\n      int LOG = 32 - __builtin_clz(N - 1);\n      D = vector<vector<T>>(LOG,\
    \ vector<T>(N));\n      for (int i = 0; i < LOG; i++){\n        int d = 1 << i;\n\
    \        for (int j = 0; j + d < N; j += d * 2){\n          D[i][j + d - 1] =\
    \ A[j + d - 1];\n          for (int k = j + d - 2; k >= j; k--){\n           \
    \ D[i][k] = f(A[k], D[i][k + 1]);\n          }\n          D[i][j + d] = A[j +\
    \ d];\n          for (int k = j + d + 1; k < min(j + d * 2, N); k++){\n      \
    \      D[i][k] = f(D[i][k - 1], A[k]);\n          }\n        }\n      }\n    }\n\
    \  }\n  T query(int L, int R){\n    if (R == L){\n      return E;\n    } else\
    \ if (R - L == 1){\n      return A[L];\n    } else {\n      R--;\n      int b\
    \ = 31 - __builtin_clz(R ^ L);\n      return f(D[b][L], D[b][R]);\n    }\n  }\n\
    };\n#line 5 \"test/library_checker/data_structure/static_range_sum_3.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  disjoint_sparse_table<long\
    \ long> DST(a, plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int\
    \ l, r;\n    cin >> l >> r;\n    cout << DST.query(l, r) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../../data_structure/sequence/disjoint_sparse_table.hpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cin >> a[i];\n  }\n  disjoint_sparse_table<long\
    \ long> DST(a, plus<long long>(), 0);\n  for (int i = 0; i < Q; i++){\n    int\
    \ l, r;\n    cin >> l >> r;\n    cout << DST.query(l, r) << endl;\n  }\n}"
  dependsOn:
  - data_structure/sequence/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/static_range_sum_3.test.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:43:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/static_range_sum_3.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/static_range_sum_3.test.cpp
- /verify/test/library_checker/data_structure/static_range_sum_3.test.cpp.html
title: test/library_checker/data_structure/static_range_sum_3.test.cpp
---
