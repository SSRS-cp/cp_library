---
title: 高さ配列 (LCP Array)
documentation_of: string/lcp_array.hpp
---

# LCP Array
列の高さ配列を求める。

## ``vector<int> lcp_array(const T &A, vector<int> &SA)``
列 $A$ とその接尾辞配列 $SA$ が与えられたとき、$A$ の高さ配列を求める。

列 $A$ の長さを $N$ とすると、高さ配列の長さは $N-1$ であり、各 $i \ (0 \leq i < N-1)$ に対して高さ配列の $i$ 番目の要素は $A[SA_i, N)$ と $A[SA_{i + 1}, N)$ の最長共通接頭辞の長さである。

時間計算量は $O(N)$ である。