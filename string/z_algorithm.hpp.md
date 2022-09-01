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
    \ z_algorithm(const T &A){\n  int N = A.size();\n  vector<int> Z(N, 0);\n  for\
    \ (int i = 1, j = 0; i < N; i++){\n    if (i + Z[i - j] < j + Z[j]){\n      Z[i]\
    \ = Z[i - j];\n    } else {\n      int k = max(0, j + Z[j] - i);\n      while\
    \ (i + k < N && A[k] == A[i + k]){\n        k++;\n      }\n      Z[i] = k;\n \
    \     j = i;\n    }\n  }\n  Z[0] = N;\n  return Z;\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<int> z_algorithm(const T &A){\n\
    \  int N = A.size();\n  vector<int> Z(N, 0);\n  for (int i = 1, j = 0; i < N;\
    \ i++){\n    if (i + Z[i - j] < j + Z[j]){\n      Z[i] = Z[i - j];\n    } else\
    \ {\n      int k = max(0, j + Z[j] - i);\n      while (i + k < N && A[k] == A[i\
    \ + k]){\n        k++;\n      }\n      Z[i] = k;\n      j = i;\n    }\n  }\n \
    \ Z[0] = N;\n  return Z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2022-09-02 02:22:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/zalgorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
title: Z Algorithm
---

# Z Algorithm
列のそれぞれの接尾辞について、列全体との最長共通接頭辞の長さを求める。

## ``vector<int> z_algorithm(const T &A)``
$A$ を長さ $N$ の列とするとき、長さ $N$ の列 $Z$ を返す。ただし、$0 \leq i < N$ について $Z_i$ は $A$ と $A[i,N)$ の最長共通接頭辞の長さである。

時間計算量は $O(N)$ である。