---
title: 最長回文 (Manacher's Algorithm)
documentation_of: string/manacher.hpp
---

# Manacher's Algorithm
文字列が与えられたとき、各文字を中心とする回文の半径の最大値を求める。

## ``vector<int> manacher(string &S)``
長さ $N$ の文字列 $S$ を引数に取り、長さ $N$ の配列を返す。

返り値の $i$ 番目の要素は、$S[i-k+1,i+k-1]$ が回文であるような $k$ の最大値である。

時間計算量は $O(N)$ である。

## 資料
[あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2014/12/02/235837)