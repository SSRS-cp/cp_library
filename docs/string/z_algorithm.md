---
title: Z Algorithm
documentation_of: string/z_algorithm.hpp
---

# Z Algorithm
列のそれぞれの接尾辞について、列全体との最長共通接頭辞の長さを求める。

## ``vector<int> z_algorithm(const T &A)``
$A$ を長さ $N$ の列とするとき、長さ $N$ の列 $Z$ を返す。ただし、$0 \leq i < N$ について $Z_i$ は $A$ と $A[i,N)$ の最長共通接頭辞の長さである。

時間計算量は $O(N)$ である。