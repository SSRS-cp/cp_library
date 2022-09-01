---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/enumerate_palindromes.test.cpp
    title: test/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/manacher.hpp\"\ntemplate <typename T>\nvector<int>\
    \ manacher(const T &A){\n  int N = A.size();\n  vector<int> ans(N, 0);\n  int\
    \ i = 0, j = 0;\n  while (i < N){\n    while (i >= j && i + j < N && A[i - j]\
    \ == A[i + j]){\n      j++;\n    }\n    ans[i] = j;\n    int k = 1;\n    while\
    \ (i >= k && i + k < N && k + ans[i - k] < j){\n      ans[i + k] = ans[i - k];\n\
    \      k++;\n    }\n    i += k;\n    j -= k;\n  }\n  return ans;\n}\n"
  code: "#pragma once\ntemplate <typename T>\nvector<int> manacher(const T &A){\n\
    \  int N = A.size();\n  vector<int> ans(N, 0);\n  int i = 0, j = 0;\n  while (i\
    \ < N){\n    while (i >= j && i + j < N && A[i - j] == A[i + j]){\n      j++;\n\
    \    }\n    ans[i] = j;\n    int k = 1;\n    while (i >= k && i + k < N && k +\
    \ ans[i - k] < j){\n      ans[i + k] = ans[i - k];\n      k++;\n    }\n    i +=\
    \ k;\n    j -= k;\n  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-09-02 02:22:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
title: "\u6700\u9577\u56DE\u6587 (Manacher's Algorithm)"
---

# Manacher's Algorithm
列が与えられたとき、各文字を中心とする回文の半径の最大値を求める。

## ``vector<int> manacher(const T &A)``
長さ $N$ の列 $A$ を引数に取り、長さ $N$ の配列を返す。

返り値の $i$ 番目の要素は、$A[i-k+1,i+k-1]$ が回文であるような $k$ の最大値である。

時間計算量は $O(N)$ である。

## 資料
[あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2014/12/02/235837)