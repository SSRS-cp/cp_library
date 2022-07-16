---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_frequency.test.cpp
    title: test/library_checker/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sequence/wavelet_matrix.cpp\"\nstruct wavelet_matrix{\n\
    \  int N, LOG;\n  vector<bit_vector> D;\n  vector<int> cnt, T;\n  wavelet_matrix(){\n\
    \  }\n  wavelet_matrix(vector<int> &A): N(A.size()){\n    LOG = 1;\n    for (int\
    \ i = 0; i < N; i++){\n      if (A[i] > 0){\n        LOG = max(LOG, 32 - __builtin_clz(A[i]));\n\
    \      }\n    }\n    D.resize(LOG);\n    cnt.resize(LOG, 0);\n    for (int i =\
    \ LOG - 1; i >= 0; i--){\n      vector<bool> B(N, false);\n      for (int j =\
    \ 0; j < N; j++){\n        if ((A[j] >> i & 1) == 1){\n          B[j] = true;\n\
    \        }\n      }\n      D[LOG - 1 - i] = bit_vector(B);\n      vector<int>\
    \ A2;\n      for (int j = 0; j < N; j++){\n        if ((A[j] >> i & 1) == 0){\n\
    \          A2.push_back(A[j]);\n          cnt[LOG - 1 - i]++;\n        }\n   \
    \   }\n      for (int j = 0; j < N; j++){\n        if ((A[j] >> i & 1) == 1){\n\
    \          A2.push_back(A[j]);\n        }\n      }\n      swap(A, A2);\n    }\n\
    \    T = A;\n  }\n  int operator [](int k){\n    int ans = 0;\n    for (int i\
    \ = 0; i < LOG; i++){\n      if (D[i][k] == 0){\n        k = D[i].rank0(k);\n\
    \      } else {\n        ans += 1 << (LOG - 1 - i);\n        k = cnt[i] + D[i].rank1(k);\n\
    \      }\n    }\n    return ans;\n  }\n  int rank(int l, int r, int c){\n    for\
    \ (int i = 0; i < LOG; i++){\n      if ((c >> (LOG - 1 - i) & 1) == 0){\n    \
    \    l = D[i].rank0(l);\n        r = D[i].rank0(r);\n      } else {\n        l\
    \ = cnt[i] + D[i].rank1(l);\n        r = cnt[i] + D[i].rank1(r);\n      }\n  \
    \  }\n    return r - l;\n  }\n};\n"
  code: "struct wavelet_matrix{\n  int N, LOG;\n  vector<bit_vector> D;\n  vector<int>\
    \ cnt, T;\n  wavelet_matrix(){\n  }\n  wavelet_matrix(vector<int> &A): N(A.size()){\n\
    \    LOG = 1;\n    for (int i = 0; i < N; i++){\n      if (A[i] > 0){\n      \
    \  LOG = max(LOG, 32 - __builtin_clz(A[i]));\n      }\n    }\n    D.resize(LOG);\n\
    \    cnt.resize(LOG, 0);\n    for (int i = LOG - 1; i >= 0; i--){\n      vector<bool>\
    \ B(N, false);\n      for (int j = 0; j < N; j++){\n        if ((A[j] >> i & 1)\
    \ == 1){\n          B[j] = true;\n        }\n      }\n      D[LOG - 1 - i] = bit_vector(B);\n\
    \      vector<int> A2;\n      for (int j = 0; j < N; j++){\n        if ((A[j]\
    \ >> i & 1) == 0){\n          A2.push_back(A[j]);\n          cnt[LOG - 1 - i]++;\n\
    \        }\n      }\n      for (int j = 0; j < N; j++){\n        if ((A[j] >>\
    \ i & 1) == 1){\n          A2.push_back(A[j]);\n        }\n      }\n      swap(A,\
    \ A2);\n    }\n    T = A;\n  }\n  int operator [](int k){\n    int ans = 0;\n\
    \    for (int i = 0; i < LOG; i++){\n      if (D[i][k] == 0){\n        k = D[i].rank0(k);\n\
    \      } else {\n        ans += 1 << (LOG - 1 - i);\n        k = cnt[i] + D[i].rank1(k);\n\
    \      }\n    }\n    return ans;\n  }\n  int rank(int l, int r, int c){\n    for\
    \ (int i = 0; i < LOG; i++){\n      if ((c >> (LOG - 1 - i) & 1) == 0){\n    \
    \    l = D[i].rank0(l);\n        r = D[i].rank0(r);\n      } else {\n        l\
    \ = cnt[i] + D[i].rank1(l);\n        r = cnt[i] + D[i].rank1(r);\n      }\n  \
    \  }\n    return r - l;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/wavelet_matrix.cpp
  requiredBy: []
  timestamp: '2022-07-16 18:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/static_range_frequency.test.cpp
documentation_of: data_structure/sequence/wavelet_matrix.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/wavelet_matrix.cpp
- /library/data_structure/sequence/wavelet_matrix.cpp.html
title: data_structure/sequence/wavelet_matrix.cpp
---
