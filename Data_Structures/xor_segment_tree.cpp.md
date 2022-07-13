---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "XOR Segment Tree (XOR \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 1 \"Data_Structures/xor_segment_tree.cpp\"\ntemplate <typename\
    \ T>\nstruct xor_segment_tree{\n  int N;\n  vector<vector<T>> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  xor_segment_tree(vector<T> &A, function<T(T, T)> f, T E):\
    \ f(f), E(E){\n    N = A.size();\n    ST = vector<vector<T>>(N * 2 - 1);\n   \
    \ for (int i = 0; i < N; i++){\n      ST[N - 1 + i].push_back(A[i]);\n    }\n\
    \    for (int i = N - 2; i >= 0; i--){\n      int cnt = ST[i * 2 + 1].size();\n\
    \      for (int j = 0; j < cnt; j++){\n        ST[i].push_back(f(ST[i * 2 + 1][j],\
    \ ST[i * 2 + 2][j]));\n      }\n      for (int j = 0; j < cnt; j++){\n       \
    \ ST[i].push_back(f(ST[i * 2 + 2][j], ST[i * 2 + 1][j]));\n      }\n    }\n  }\n\
    \  T range_fold(int L, int R, int x, int i, int l, int r){\n    if (r <= L ||\
    \ R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n      return ST[i][x];\n\
    \    } else {\n      int p = (r - l) / 2;\n      int m = (l + r) / 2;\n      if\
    \ ((x & p) == 0){\n        T resL = range_fold(L, R, x, i * 2 + 1, l, m);\n  \
    \      T resR = range_fold(L, R, x, i * 2 + 2, m, r);\n        return f(resL,\
    \ resR);\n      } else {\n        T resL = E;\n        if (R >= m){\n        \
    \  resL = range_fold(max(L, m) - p, R - p, x ^ p, i * 2 + 1, l, m);\n        }\n\
    \        T resR = E;\n        if (L < m){\n          resR = range_fold(L + p,\
    \ min(R, m) + p, x ^ p, i * 2 + 2, m, r);\n        }\n        return f(resR, resL);\n\
    \      }\n    }\n  }\n  T range_fold(int L, int R, int x){\n    return range_fold(L,\
    \ R, x, 0, 0, N);\n  }\n};\n/**\n * @brief XOR Segment Tree (XOR \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n*/\n"
  code: "template <typename T>\nstruct xor_segment_tree{\n  int N;\n  vector<vector<T>>\
    \ ST;\n  function<T(T, T)> f;\n  T E;\n  xor_segment_tree(vector<T> &A, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    N = A.size();\n    ST = vector<vector<T>>(N *\
    \ 2 - 1);\n    for (int i = 0; i < N; i++){\n      ST[N - 1 + i].push_back(A[i]);\n\
    \    }\n    for (int i = N - 2; i >= 0; i--){\n      int cnt = ST[i * 2 + 1].size();\n\
    \      for (int j = 0; j < cnt; j++){\n        ST[i].push_back(f(ST[i * 2 + 1][j],\
    \ ST[i * 2 + 2][j]));\n      }\n      for (int j = 0; j < cnt; j++){\n       \
    \ ST[i].push_back(f(ST[i * 2 + 2][j], ST[i * 2 + 1][j]));\n      }\n    }\n  }\n\
    \  T range_fold(int L, int R, int x, int i, int l, int r){\n    if (r <= L ||\
    \ R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n      return ST[i][x];\n\
    \    } else {\n      int p = (r - l) / 2;\n      int m = (l + r) / 2;\n      if\
    \ ((x & p) == 0){\n        T resL = range_fold(L, R, x, i * 2 + 1, l, m);\n  \
    \      T resR = range_fold(L, R, x, i * 2 + 2, m, r);\n        return f(resL,\
    \ resR);\n      } else {\n        T resL = E;\n        if (R >= m){\n        \
    \  resL = range_fold(max(L, m) - p, R - p, x ^ p, i * 2 + 1, l, m);\n        }\n\
    \        T resR = E;\n        if (L < m){\n          resR = range_fold(L + p,\
    \ min(R, m) + p, x ^ p, i * 2 + 2, m, r);\n        }\n        return f(resR, resL);\n\
    \      }\n    }\n  }\n  T range_fold(int L, int R, int x){\n    return range_fold(L,\
    \ R, x, 0, 0, N);\n  }\n};\n/**\n * @brief XOR Segment Tree (XOR \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/xor_segment_tree.cpp
  requiredBy: []
  timestamp: '2022-07-14 02:18:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/xor_segment_tree.cpp
layout: document
redirect_from:
- /library/Data_Structures/xor_segment_tree.cpp
- /library/Data_Structures/xor_segment_tree.cpp.html
title: "XOR Segment Tree (XOR \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
