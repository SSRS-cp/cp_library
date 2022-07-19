---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/compact_bit_vector.hpp
    title: "\u30B3\u30F3\u30D1\u30AF\u30C8 Bit Vector"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1_6_a.test.cpp
    title: test/aoj/itp1_6_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/range_kth_smallest.test.cpp
    title: test/library_checker/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/static_range_frequency.test.cpp
    title: test/library_checker/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/wavelet_matrix.hpp\"\n/**\n * @brief\
    \ \u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\n*/\n#line 2 \"data_structure/sequence/compact_bit_vector.hpp\"\
    \n/**\n * @brief \u30B3\u30F3\u30D1\u30AF\u30C8 Bit Vector\n*/\nstruct bit_vector{\n\
    \  vector<unsigned long long> A;\n  vector<int> S;\n  bit_vector(){\n  }\n  bit_vector(vector<bool>\
    \ &a){\n    int N = a.size();\n    int M = (N + 64 - 1) >> 6;\n    A = vector<unsigned\
    \ long long>(M, 0);\n    for (int i = 0; i < M; i++){\n      for (int j = i <<\
    \ 6; j < min((i + 1) << 6, N); j++){\n        if (a[j]){\n          A[i] |= (unsigned\
    \ long long) 1 << (j - (i << 6));\n        }\n      }\n    }\n    S = vector<int>(M\
    \ + 1, 0);\n    for (int i = 0; i < M; i++){\n      S[i + 1] = S[i] + __builtin_popcountll(A[i]);\n\
    \    }\n  }\n  int operator [](int k){\n    return A[k >> 6] >> (k & 63) & 1;\n\
    \  }\n  int rank0(int k){\n    return k - rank1(k);\n  }\n  int rank1(int k){\n\
    \    if ((k & 63) == 0){\n      return S[k >> 6];\n    } else {\n      return\
    \ S[k >> 6] + __builtin_popcountll(A[k >> 6] << (64 - k + (k >> 6 << 6)));\n \
    \   }\n  }\n};\n#line 6 \"data_structure/sequence/wavelet_matrix.hpp\"\nstruct\
    \ wavelet_matrix{\n  int N, LOG;\n  vector<bit_vector> D;\n  vector<int> cnt,\
    \ T;\n  wavelet_matrix(){\n  }\n  wavelet_matrix(vector<int> &A): N(A.size()){\n\
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
    \  }\n    return r - l;\n  }\n  int quantile(int l, int r, int k){\n    int ans\
    \ = 0;\n    for (int i = 0; i < LOG; i++){\n      int cnt0 = D[i].rank0(r) - D[i].rank0(l);\n\
    \      if (k < cnt0){\n        l = D[i].rank0(l);\n        r = D[i].rank0(r);\n\
    \      } else {\n        ans += 1 << (LOG - 1 - i);\n        k -= cnt0;\n    \
    \    l = cnt[i] + D[i].rank1(l);\n        r = cnt[i] + D[i].rank1(r);\n      }\n\
    \    }\n    return ans;\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\
    \u5217\n*/\n#include \"compact_bit_vector.hpp\"\nstruct wavelet_matrix{\n  int\
    \ N, LOG;\n  vector<bit_vector> D;\n  vector<int> cnt, T;\n  wavelet_matrix(){\n\
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
    \  }\n    return r - l;\n  }\n  int quantile(int l, int r, int k){\n    int ans\
    \ = 0;\n    for (int i = 0; i < LOG; i++){\n      int cnt0 = D[i].rank0(r) - D[i].rank0(l);\n\
    \      if (k < cnt0){\n        l = D[i].rank0(l);\n        r = D[i].rank0(r);\n\
    \      } else {\n        ans += 1 << (LOG - 1 - i);\n        k -= cnt0;\n    \
    \    l = cnt[i] + D[i].rank1(l);\n        r = cnt[i] + D[i].rank1(r);\n      }\n\
    \    }\n    return ans;\n  }\n};"
  dependsOn:
  - data_structure/sequence/compact_bit_vector.hpp
  isVerificationFile: false
  path: data_structure/sequence/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2022-07-19 22:00:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1_6_a.test.cpp
  - test/library_checker/static_range_frequency.test.cpp
  - test/library_checker/range_kth_smallest.test.cpp
documentation_of: data_structure/sequence/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/wavelet_matrix.hpp
- /library/data_structure/sequence/wavelet_matrix.hpp.html
title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
---
