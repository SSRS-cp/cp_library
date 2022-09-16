---
title: Li Chao Tree
documentation_of: data_structure/other/li_chao_tree.hpp
---

# Li Chao Tree

## ``li_chao_tree(const vector<T> &x2)``
座標の列が $x2$ であるような Li Chao Tree を構築する。

## ``void line_add(T a, T b)``
直線 $y=ax+b$ を追加する。

## ``void segment_add(T l, T r, T a, T b)``
線分 $y=ax+b \ (l \leq x < r)$ を追加する。

## ``vector<int> manacher(const T &A)``
長さ $N$ の列 $A$ を引数に取り、長さ $N$ の配列を返す。

## ``T get(T x2)``
$x=x2$ における最小値を求める。$x2$ は構築時に与えられた座標に含まれる必要がある。