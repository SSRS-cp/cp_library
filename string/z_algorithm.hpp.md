---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm.test.cpp
    title: test/library_checker/string/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\ntemplate <typename T>\nvector<int>\
    \ z_algorithm(const vector<T> &A){\n  int N = A.size();\n  vector<int> Z(N, 0);\n\
    \  for (int i = 1, j = 0; i < N; i++){\n    if (i + Z[i - j] < j + Z[j]){\n  \
    \    Z[i] = Z[i - j];\n    } else {\n      int k = max(0, j + Z[j] - i);\n   \
    \   while (i + k < N && A[k] == A[i + k]){\n        k++;\n      }\n      Z[i]\
    \ = k;\n      j = i;\n    }\n  }\n  Z[0] = N;\n  return Z;\n}\nvector<int> z_algorithm(const\
    \ string &S){\n  int N = S.size();\n  vector<int> A(N);\n  for (int i = 0; i <\
    \ N; i++){\n    A[i] = S[i];\n  }\n  return z_algorithm(A);\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<int> z_algorithm(const vector<T>\
    \ &A){\n  int N = A.size();\n  vector<int> Z(N, 0);\n  for (int i = 1, j = 0;\
    \ i < N; i++){\n    if (i + Z[i - j] < j + Z[j]){\n      Z[i] = Z[i - j];\n  \
    \  } else {\n      int k = max(0, j + Z[j] - i);\n      while (i + k < N && A[k]\
    \ == A[i + k]){\n        k++;\n      }\n      Z[i] = k;\n      j = i;\n    }\n\
    \  }\n  Z[0] = N;\n  return Z;\n}\nvector<int> z_algorithm(const string &S){\n\
    \  int N = S.size();\n  vector<int> A(N);\n  for (int i = 0; i < N; i++){\n  \
    \  A[i] = S[i];\n  }\n  return z_algorithm(A);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2022-08-29 05:52:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/zalgorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
title: Z Algorithm
---

# Z Algorithm
数列のそれぞれの接尾辞について、数列全体との最長共通接頭辞の長さを求める。

## ``vector<int> z_algorithm(const vector<T> &A)``
$A$ を長さ $N$ の数列とするとき、長さ $N$ の数列 $Z$ を返す。ただし、$0 \leq i < N$ について $Z_i$ は $A$ と $A[i,N)$ の最長共通接頭辞の長さである。

時間計算量は $O(N)$ である。

## ``vector<int> z_algorithm(const string &S)``
$S$ を長さ $N$ の文字列とするとき、長さ $N$ の数列 $Z$ を返す。ただし、$0 \leq i < N$ について $Z_i$ は $S$ と $S[i,N)$ の最長共通接頭辞の長さである。

時間計算量は $O(N)$ である。