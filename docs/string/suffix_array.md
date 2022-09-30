---
title: 接尾辞配列 (SA-IS)
documentation_of: string/suffix_array.hpp
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