# UnionFind
## 概要
集合を扱うデータ構造。

## 操作
* `unionfind(N)`: $0, 1, \dots, N-1$ がそれぞれ異なる集合に属している状態で初期化する。
* `root(x)`: $x$ が属する集合を代表する要素を $1$ つ答える。同じ集合の要素について `root` を行ったとき、同じ要素が返ることが保証される。
* `same(x, y)`: $x, y$ が同じ集合に属するか判定する。
* `unite(x, y)`: $x$ の属する集合と $y$ の属する集合を併合する。既に同じ集合に属する場合は何も発生しない。

## 資料
[data-structures](https://scrapbox.io/data-structures/Union_Find)