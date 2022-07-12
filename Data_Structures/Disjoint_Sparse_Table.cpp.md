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
  bundledCode: "#line 1 \"Data_Structures/Disjoint_Sparse_Table.cpp\"\ntemplate <typename\
    \ T>\nstruct disjoint_sparse_table{\n  function<T(T, T)> f;\n  vector<T> A;\n\
    \  vector<vector<T>> D;\n  disjoint_sparse_table(){\n  }\n  disjoint_sparse_table(vector<T>\
    \ &A, function<T(T, T)> f): A(A), f(f){\n    int N = A.size();\n    int LOG =\
    \ 32 - __builtin_clz(N - 1);\n    D = vector<vector<T>>(LOG, vector<T>(N));\n\
    \    for (int i = 0; i < LOG; i++){\n      int d = 1 << i;\n      for (int j =\
    \ 0; j + d < N; j += d * 2){\n        D[i][j + d - 1] = A[j + d - 1];\n      \
    \  for (int k = j + d - 2; k >= j; k--){\n          if (k == j + (d >> 1)){\n\
    \            D[i][k] = D[i - 1][j + d - 1];\n          } else {\n            D[i][k]\
    \ = f(A[k], D[i][k + 1]);\n          }\n        }\n        D[i][j + d] = A[j +\
    \ d];\n        for (int k = j + d + 1; k < min(j + d * 2, N); k++){\n        \
    \  if (k == j + d + (d >> 1) - 1){\n            D[i][k] = D[i - 1][j + d];\n \
    \         } else {\n            D[i][k] = f(D[i][k - 1], A[k]);\n          }\n\
    \        }\n      }\n    }\n  }\n  T query(int L, int R){\n    if (R - L == 1){\n\
    \      return A[L];\n    } else {\n      R--;\n      int b = 31 - __builtin_clz(R\
    \ ^ L);\n      return f(D[b][L], D[b][R]);\n    }\n  }\n};\n"
  code: "template <typename T>\nstruct disjoint_sparse_table{\n  function<T(T, T)>\
    \ f;\n  vector<T> A;\n  vector<vector<T>> D;\n  disjoint_sparse_table(){\n  }\n\
    \  disjoint_sparse_table(vector<T> &A, function<T(T, T)> f): A(A), f(f){\n   \
    \ int N = A.size();\n    int LOG = 32 - __builtin_clz(N - 1);\n    D = vector<vector<T>>(LOG,\
    \ vector<T>(N));\n    for (int i = 0; i < LOG; i++){\n      int d = 1 << i;\n\
    \      for (int j = 0; j + d < N; j += d * 2){\n        D[i][j + d - 1] = A[j\
    \ + d - 1];\n        for (int k = j + d - 2; k >= j; k--){\n          if (k ==\
    \ j + (d >> 1)){\n            D[i][k] = D[i - 1][j + d - 1];\n          } else\
    \ {\n            D[i][k] = f(A[k], D[i][k + 1]);\n          }\n        }\n   \
    \     D[i][j + d] = A[j + d];\n        for (int k = j + d + 1; k < min(j + d *\
    \ 2, N); k++){\n          if (k == j + d + (d >> 1) - 1){\n            D[i][k]\
    \ = D[i - 1][j + d];\n          } else {\n            D[i][k] = f(D[i][k - 1],\
    \ A[k]);\n          }\n        }\n      }\n    }\n  }\n  T query(int L, int R){\n\
    \    if (R - L == 1){\n      return A[L];\n    } else {\n      R--;\n      int\
    \ b = 31 - __builtin_clz(R ^ L);\n      return f(D[b][L], D[b][R]);\n    }\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Disjoint_Sparse_Table.cpp
  requiredBy: []
  timestamp: '2022-05-22 03:13:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Disjoint_Sparse_Table.cpp
layout: document
redirect_from:
- /library/Data_Structures/Disjoint_Sparse_Table.cpp
- /library/Data_Structures/Disjoint_Sparse_Table.cpp.html
title: Data_Structures/Disjoint_Sparse_Table.cpp
---
