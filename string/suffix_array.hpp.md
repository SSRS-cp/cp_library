---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/lcp_array.hpp
    title: "\u9AD8\u3055\u914D\u5217 (LCP Array)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_substrings.test.cpp
    title: test/library_checker/string/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffixarray.test.cpp
    title: test/library_checker/string/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\nvector<int> suffix_array(const\
    \ vector<int> &A, int mx){\n  int N = A.size();\n  vector<int> sum(mx + 1, 0);\n\
    \  for (int i = 0; i < N; i++){\n    sum[A[i] + 1]++;\n  }\n  for (int i = 0;\
    \ i < mx; i++){\n    sum[i + 1] += sum[i];\n  }\n  vector<bool> is_s(N);\n  is_s[N\
    \ - 1] = false;\n  for (int i = N - 2; i >= 0; i--){\n    is_s[i] = A[i] < A[i\
    \ + 1] || A[i] == A[i + 1] && is_s[i + 1];\n  }\n  vector<int> id(N, -1);\n  vector<int>\
    \ pos;\n  int M = 0;\n  for (int i = 1; i < N; i++){\n    if (is_s[i] && !is_s[i\
    \ - 1]){\n      id[i] = M;\n      pos.push_back(i);\n      M++;\n    }\n  }\n\
    \  vector<int> sa(N);\n  auto induce = [&](vector<int>& lms){\n    sa = vector<int>(N,\
    \ -1);\n    vector<bool> used(N, false);\n    vector<int> p(mx);\n    vector<int>\
    \ p2(mx);\n    for (int i = 0; i < mx; i++){\n      p[i] = sum[i + 1] - 1;\n \
    \     p2[i] = sum[i];\n    }\n    for (int i = M - 1; i >= 0; i--){\n      sa[p[A[lms[i]]]]\
    \ = lms[i];\n      p[A[lms[i]]]--;\n      used[lms[i]] = true;\n    }\n    sa[p2[A[N\
    \ - 1]]] = N - 1;\n    p2[A[N - 1]]++;\n    used[N - 1] = true;\n    for (int\
    \ i = 0; i < N; i++){\n      if (sa[i] > 0){\n        if (!is_s[sa[i] - 1] &&\
    \ !used[sa[i] - 1]){\n          sa[p2[A[sa[i] - 1]]] = sa[i] - 1;\n          p2[A[sa[i]\
    \ - 1]]++;\n          used[sa[i] - 1] = true;\n        }\n      }\n    }\n   \
    \ for (int i = 0; i < N; i++){\n      if (sa[i] != -1){\n        if (id[sa[i]]\
    \ != -1){\n          used[sa[i]] = false;\n          sa[i] = -1;\n        }\n\
    \      }\n    }\n    for (int i = 0; i < mx; i++){\n      p[i] = sum[i + 1] -\
    \ 1;\n    }\n    for (int i = N - 1; i >= 0; i--){\n      if (sa[i] > 0){\n  \
    \      if (is_s[sa[i] - 1] && !used[sa[i] - 1]){\n          sa[p[A[sa[i] - 1]]]\
    \ = sa[i] - 1;\n          p[A[sa[i] - 1]]--;\n          used[sa[i] - 1] = true;\n\
    \        }\n      }\n    }\n  };\n  induce(pos);\n  if (M == 0){\n    return sa;\n\
    \  }\n  vector<int> lms;\n  for (int i = 0; i < N; i++){\n    if (id[sa[i]] !=\
    \ -1){\n      lms.push_back(sa[i]);\n    }\n  }\n  vector<int> c(M);\n  c[0] =\
    \ 0;\n  for (int i = 0; i < M - 1; i++){\n    c[i + 1] = c[i];\n    int x = lms[i];\n\
    \    int y = lms[i + 1];\n    bool ok = true;\n    while (x < N && y < N){\n \
    \     if (A[x] != A[y]){\n        ok = false;\n        break;\n      }\n     \
    \ x++;\n      y++;\n      if (id[x] != -1){\n        if (id[y] == -1){\n     \
    \     ok = false;\n        }\n        break;\n      }\n    }\n    if (x == N ||\
    \ y == N){\n      ok = false;\n    }\n    if (!ok){\n      c[i + 1]++;\n    }\n\
    \  }\n  vector<int> rec(M);\n  for (int i = 0; i < M; i++){\n    rec[id[lms[i]]]\
    \ = c[i];\n  }\n  vector<int> sa2 = suffix_array(rec, c[M - 1] + 1);\n  vector<int>\
    \ pos2(M);\n  for (int i = 0; i < M; i++){\n    pos2[i] = pos[sa2[i]];\n  }\n\
    \  induce(pos2);\n  return sa;\n}\nvector<int> suffix_array(const string &S){\n\
    \  int N = S.size();\n  vector<int> A(N);\n  for (int i = 0; i < N; i++){\n  \
    \  A[i] = S[i];\n  }\n  return suffix_array(A, 256);\n}\n"
  code: "#pragma once\nvector<int> suffix_array(const vector<int> &A, int mx){\n \
    \ int N = A.size();\n  vector<int> sum(mx + 1, 0);\n  for (int i = 0; i < N; i++){\n\
    \    sum[A[i] + 1]++;\n  }\n  for (int i = 0; i < mx; i++){\n    sum[i + 1] +=\
    \ sum[i];\n  }\n  vector<bool> is_s(N);\n  is_s[N - 1] = false;\n  for (int i\
    \ = N - 2; i >= 0; i--){\n    is_s[i] = A[i] < A[i + 1] || A[i] == A[i + 1] &&\
    \ is_s[i + 1];\n  }\n  vector<int> id(N, -1);\n  vector<int> pos;\n  int M = 0;\n\
    \  for (int i = 1; i < N; i++){\n    if (is_s[i] && !is_s[i - 1]){\n      id[i]\
    \ = M;\n      pos.push_back(i);\n      M++;\n    }\n  }\n  vector<int> sa(N);\n\
    \  auto induce = [&](vector<int>& lms){\n    sa = vector<int>(N, -1);\n    vector<bool>\
    \ used(N, false);\n    vector<int> p(mx);\n    vector<int> p2(mx);\n    for (int\
    \ i = 0; i < mx; i++){\n      p[i] = sum[i + 1] - 1;\n      p2[i] = sum[i];\n\
    \    }\n    for (int i = M - 1; i >= 0; i--){\n      sa[p[A[lms[i]]]] = lms[i];\n\
    \      p[A[lms[i]]]--;\n      used[lms[i]] = true;\n    }\n    sa[p2[A[N - 1]]]\
    \ = N - 1;\n    p2[A[N - 1]]++;\n    used[N - 1] = true;\n    for (int i = 0;\
    \ i < N; i++){\n      if (sa[i] > 0){\n        if (!is_s[sa[i] - 1] && !used[sa[i]\
    \ - 1]){\n          sa[p2[A[sa[i] - 1]]] = sa[i] - 1;\n          p2[A[sa[i] -\
    \ 1]]++;\n          used[sa[i] - 1] = true;\n        }\n      }\n    }\n    for\
    \ (int i = 0; i < N; i++){\n      if (sa[i] != -1){\n        if (id[sa[i]] !=\
    \ -1){\n          used[sa[i]] = false;\n          sa[i] = -1;\n        }\n   \
    \   }\n    }\n    for (int i = 0; i < mx; i++){\n      p[i] = sum[i + 1] - 1;\n\
    \    }\n    for (int i = N - 1; i >= 0; i--){\n      if (sa[i] > 0){\n       \
    \ if (is_s[sa[i] - 1] && !used[sa[i] - 1]){\n          sa[p[A[sa[i] - 1]]] = sa[i]\
    \ - 1;\n          p[A[sa[i] - 1]]--;\n          used[sa[i] - 1] = true;\n    \
    \    }\n      }\n    }\n  };\n  induce(pos);\n  if (M == 0){\n    return sa;\n\
    \  }\n  vector<int> lms;\n  for (int i = 0; i < N; i++){\n    if (id[sa[i]] !=\
    \ -1){\n      lms.push_back(sa[i]);\n    }\n  }\n  vector<int> c(M);\n  c[0] =\
    \ 0;\n  for (int i = 0; i < M - 1; i++){\n    c[i + 1] = c[i];\n    int x = lms[i];\n\
    \    int y = lms[i + 1];\n    bool ok = true;\n    while (x < N && y < N){\n \
    \     if (A[x] != A[y]){\n        ok = false;\n        break;\n      }\n     \
    \ x++;\n      y++;\n      if (id[x] != -1){\n        if (id[y] == -1){\n     \
    \     ok = false;\n        }\n        break;\n      }\n    }\n    if (x == N ||\
    \ y == N){\n      ok = false;\n    }\n    if (!ok){\n      c[i + 1]++;\n    }\n\
    \  }\n  vector<int> rec(M);\n  for (int i = 0; i < M; i++){\n    rec[id[lms[i]]]\
    \ = c[i];\n  }\n  vector<int> sa2 = suffix_array(rec, c[M - 1] + 1);\n  vector<int>\
    \ pos2(M);\n  for (int i = 0; i < M; i++){\n    pos2[i] = pos[sa2[i]];\n  }\n\
    \  induce(pos2);\n  return sa;\n}\nvector<int> suffix_array(const string &S){\n\
    \  int N = S.size();\n  vector<int> A(N);\n  for (int i = 0; i < N; i++){\n  \
    \  A[i] = S[i];\n  }\n  return suffix_array(A, 256);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy:
  - string/lcp_array.hpp
  timestamp: '2022-08-24 03:58:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/suffixarray.test.cpp
  - test/library_checker/string/number_of_substrings.test.cpp
documentation_of: string/suffix_array.hpp
layout: document
title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (SA-IS)"
---

# Suffix Array

<span style="font-size:200%; color: red; ">バグが発見されています。使用しないでください。</span>

文字列 `cabcab` の接尾辞配列を求めようとすると配列外参照をします。原因を調査中です。


数列の接尾辞配列を求める。

## ``vector<int> suffix_array(const vector<int> &A, int mx)``
各要素が $0$ 以上 $\text{mx}$ 未満の数列 $A$ が与えられたとき、$A$ の接尾辞配列を返す。

長さ $N$ の数列 $A$ の接尾辞配列とは、$\{0, 1, \dots, N-1\}$ の順列 $P$ であって、任意の $i \ (0 \leq i < N-1)$ に対し $A[P_i,N) < A[P_{i+1},N)$ が成り立つようなものである。

時間計算量は $O(N + \text{mx})$ である。

## ``vector<int> suffix_array(const string &S)``
文字列 $S$ が与えられたとき、$S$ の接尾辞配列を返す。

文字列の接尾辞配列は数列と同様に定義される。

文字列の長さを $N$ とすると、時間計算量は $O(N)$ である。

## 資料
[nekolib](https://rsk0315.github.io/library-rs/nekolib/seq/struct.SuffixArray.html)