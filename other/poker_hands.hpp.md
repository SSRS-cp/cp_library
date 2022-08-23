---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/other/2535.test.cpp
    title: test/aoj/other/2535.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/poker_hands.hpp\"\nstruct card{\n  char suit;\n  int\
    \ rank;\n  card(){\n  }\n  bool operator <(card C){\n    return rank < C.rank\
    \ || rank == C.rank && suit < C.suit;\n  }\n};\nistream& operator >>(istream&\
    \ is, card& C){\n  string S;\n  is >> S;\n  C.suit = S[0];\n  if (S[1] == 'A'){\n\
    \    C.rank = 14;\n  } else if (S[1] == 'K'){\n    C.rank = 13;\n  } else if (S[1]\
    \ == 'Q'){\n    C.rank = 12;\n  } else if (S[1] == 'J'){\n    C.rank = 11;\n \
    \ } else if (S[1] == 'T'){\n    C.rank = 10;\n  } else {\n    C.rank = S[1] -\
    \ '0';\n  }\n  return is;\n}\nenum poker_hand{HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND,\
    \ STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_STRAIGHT_FLUSH};\n\
    vector<int> hand(array<card, 5> C){\n  sort(C.begin(), C.end());\n  bool is_flush\
    \ = true;\n  for (int i = 1; i < 5; i++){\n    if (C[i].suit != C[0].suit){\n\
    \      is_flush = false;\n    }\n  }\n  if (is_flush && C[4].rank == 14 && C[0].rank\
    \ == 10){\n    return {ROYAL_STRAIGHT_FLUSH};\n  } else if (is_flush && C[4].rank\
    \ - C[0].rank == 4){\n    return {STRAIGHT_FLUSH, C[4].rank};\n  } else if (is_flush\
    \ && C[3].rank == 5 && C[4].rank == 14){\n    return {STRAIGHT_FLUSH, 5};\n  }\
    \ else if (C[0].rank == C[3].rank){\n    return {FOUR_OF_A_KIND, C[0].rank, C[4].rank};\n\
    \  } else if (C[1].rank == C[4].rank){\n    return {FOUR_OF_A_KIND, C[1].rank,\
    \ C[0].rank};\n  } else if (C[0].rank == C[2].rank && C[3].rank == C[4].rank){\n\
    \    return {FULL_HOUSE, C[0].rank, C[3].rank};\n  } else if (C[2].rank == C[4].rank\
    \ && C[0].rank == C[1].rank){\n    return {FULL_HOUSE, C[2].rank, C[0].rank};\n\
    \  } else if (is_flush){\n    return {FLUSH, C[4].rank, C[3].rank, C[2].rank,\
    \ C[1].rank, C[0].rank};\n  } else if (C[1].rank - C[0].rank == 1 && C[2].rank\
    \ - C[1].rank == 1 && C[3].rank - C[2].rank == 1 && C[4].rank - C[3].rank == 1){\n\
    \    return {STRAIGHT, C[4].rank};\n  } else if (C[0].rank == 2 && C[1].rank ==\
    \ 3 && C[2].rank == 4 && C[3].rank == 5 && C[4].rank == 14){\n    return {STRAIGHT,\
    \ 5};\n  } else if (C[0].rank == C[2].rank){\n    return {THREE_OF_A_KIND, C[0].rank,\
    \ C[4].rank, C[3].rank};\n  } else if (C[1].rank == C[3].rank){\n    return {THREE_OF_A_KIND,\
    \ C[1].rank, C[4].rank, C[0].rank};\n  } else if (C[2].rank == C[4].rank){\n \
    \   return {THREE_OF_A_KIND, C[2].rank, C[1].rank, C[0].rank};\n  } else if (C[0].rank\
    \ == C[1].rank && C[2].rank == C[3].rank){\n    return {TWO_PAIR, C[2].rank, C[0].rank,\
    \ C[4].rank};\n  } else if (C[0].rank == C[1].rank && C[3].rank == C[4].rank){\n\
    \    return {TWO_PAIR, C[3].rank, C[0].rank, C[2].rank};\n  } else if (C[1].rank\
    \ == C[2].rank && C[3].rank == C[4].rank){\n    return {TWO_PAIR, C[3].rank, C[1].rank,\
    \ C[0].rank};\n  } else if (C[0].rank == C[1].rank){\n    return {ONE_PAIR, C[0].rank,\
    \ C[4].rank, C[3].rank, C[2].rank};\n  } else if (C[1].rank == C[2].rank){\n \
    \   return {ONE_PAIR, C[1].rank, C[4].rank, C[3].rank, C[0].rank};\n  } else if\
    \ (C[2].rank == C[3].rank){\n    return {ONE_PAIR, C[2].rank, C[4].rank, C[1].rank,\
    \ C[0].rank};\n  } else if (C[3].rank == C[4].rank){\n    return {ONE_PAIR, C[3].rank,\
    \ C[2].rank, C[1].rank, C[0].rank};\n  } else {\n    return {HIGH_CARD, C[4].rank,\
    \ C[3].rank, C[2].rank, C[1].rank, C[0].rank};\n  }\n}\n"
  code: "#pragma once\nstruct card{\n  char suit;\n  int rank;\n  card(){\n  }\n \
    \ bool operator <(card C){\n    return rank < C.rank || rank == C.rank && suit\
    \ < C.suit;\n  }\n};\nistream& operator >>(istream& is, card& C){\n  string S;\n\
    \  is >> S;\n  C.suit = S[0];\n  if (S[1] == 'A'){\n    C.rank = 14;\n  } else\
    \ if (S[1] == 'K'){\n    C.rank = 13;\n  } else if (S[1] == 'Q'){\n    C.rank\
    \ = 12;\n  } else if (S[1] == 'J'){\n    C.rank = 11;\n  } else if (S[1] == 'T'){\n\
    \    C.rank = 10;\n  } else {\n    C.rank = S[1] - '0';\n  }\n  return is;\n}\n\
    enum poker_hand{HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH,\
    \ FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_STRAIGHT_FLUSH};\nvector<int>\
    \ hand(array<card, 5> C){\n  sort(C.begin(), C.end());\n  bool is_flush = true;\n\
    \  for (int i = 1; i < 5; i++){\n    if (C[i].suit != C[0].suit){\n      is_flush\
    \ = false;\n    }\n  }\n  if (is_flush && C[4].rank == 14 && C[0].rank == 10){\n\
    \    return {ROYAL_STRAIGHT_FLUSH};\n  } else if (is_flush && C[4].rank - C[0].rank\
    \ == 4){\n    return {STRAIGHT_FLUSH, C[4].rank};\n  } else if (is_flush && C[3].rank\
    \ == 5 && C[4].rank == 14){\n    return {STRAIGHT_FLUSH, 5};\n  } else if (C[0].rank\
    \ == C[3].rank){\n    return {FOUR_OF_A_KIND, C[0].rank, C[4].rank};\n  } else\
    \ if (C[1].rank == C[4].rank){\n    return {FOUR_OF_A_KIND, C[1].rank, C[0].rank};\n\
    \  } else if (C[0].rank == C[2].rank && C[3].rank == C[4].rank){\n    return {FULL_HOUSE,\
    \ C[0].rank, C[3].rank};\n  } else if (C[2].rank == C[4].rank && C[0].rank ==\
    \ C[1].rank){\n    return {FULL_HOUSE, C[2].rank, C[0].rank};\n  } else if (is_flush){\n\
    \    return {FLUSH, C[4].rank, C[3].rank, C[2].rank, C[1].rank, C[0].rank};\n\
    \  } else if (C[1].rank - C[0].rank == 1 && C[2].rank - C[1].rank == 1 && C[3].rank\
    \ - C[2].rank == 1 && C[4].rank - C[3].rank == 1){\n    return {STRAIGHT, C[4].rank};\n\
    \  } else if (C[0].rank == 2 && C[1].rank == 3 && C[2].rank == 4 && C[3].rank\
    \ == 5 && C[4].rank == 14){\n    return {STRAIGHT, 5};\n  } else if (C[0].rank\
    \ == C[2].rank){\n    return {THREE_OF_A_KIND, C[0].rank, C[4].rank, C[3].rank};\n\
    \  } else if (C[1].rank == C[3].rank){\n    return {THREE_OF_A_KIND, C[1].rank,\
    \ C[4].rank, C[0].rank};\n  } else if (C[2].rank == C[4].rank){\n    return {THREE_OF_A_KIND,\
    \ C[2].rank, C[1].rank, C[0].rank};\n  } else if (C[0].rank == C[1].rank && C[2].rank\
    \ == C[3].rank){\n    return {TWO_PAIR, C[2].rank, C[0].rank, C[4].rank};\n  }\
    \ else if (C[0].rank == C[1].rank && C[3].rank == C[4].rank){\n    return {TWO_PAIR,\
    \ C[3].rank, C[0].rank, C[2].rank};\n  } else if (C[1].rank == C[2].rank && C[3].rank\
    \ == C[4].rank){\n    return {TWO_PAIR, C[3].rank, C[1].rank, C[0].rank};\n  }\
    \ else if (C[0].rank == C[1].rank){\n    return {ONE_PAIR, C[0].rank, C[4].rank,\
    \ C[3].rank, C[2].rank};\n  } else if (C[1].rank == C[2].rank){\n    return {ONE_PAIR,\
    \ C[1].rank, C[4].rank, C[3].rank, C[0].rank};\n  } else if (C[2].rank == C[3].rank){\n\
    \    return {ONE_PAIR, C[2].rank, C[4].rank, C[1].rank, C[0].rank};\n  } else\
    \ if (C[3].rank == C[4].rank){\n    return {ONE_PAIR, C[3].rank, C[2].rank, C[1].rank,\
    \ C[0].rank};\n  } else {\n    return {HIGH_CARD, C[4].rank, C[3].rank, C[2].rank,\
    \ C[1].rank, C[0].rank};\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/poker_hands.hpp
  requiredBy: []
  timestamp: '2022-08-15 03:29:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/other/2535.test.cpp
documentation_of: other/poker_hands.hpp
layout: document
title: "\u30DD\u30FC\u30AB\u30FC\u5F79\u5224\u5B9A"
---

# ポーカー役判定
ポーカーの役を判定する。

## ``struct card``
各カードを扱う構造体である。

``char suit`` はカードのスートを表す文字である。各スートにどの文字を割り当てるかは自由に決められる。

``int rank`` はカードのランクを表す数である。2～10 のカードの ``rank`` はその数と同じである。J (ジャック)、Q (クイーン)、K (キング)、A (エース) の ``rank`` はそれぞれ ``11, 12, 13, 14`` である。

カードを ``std::istream`` から ``operator>>`` を用いて入力できる。入力は以下の形式で行われる。

* 2 文字の文字列を入力する。
* 文字列の 1 文字目はカードのスートを表す。
* 文字列の 2 文字目はカードのランクを表す。
  * 2～9 の文字はそれぞれランクが 2～9 のカードとして扱われる。
  * ``T, J, Q, K, A`` はそれぞれ 10、J (ジャック)、Q (クイーン)、K (キング)、A (エース) のカードとして扱われる。

## `` enum poker_hand``
ポーカーの役の種類を表す。

``poker_hand`` の要素と役の対応は以下のようである。

|``poker_hand`` の要素|役|
|-|-|
|``HIGH_CARD``|ハイカード|
|``ONE_PAIR``|ワンペア|
|``TWO_PAIR``|ツーペア|
|``THREE_OF_A_KIND``|スリー・オブ・ア・カインド|
|``STRAIGHT``|ストレート|
|``FLUSH``|フラッシュ|
|``FULL_HOUSE``|フルハウス|
|``FOUR_OF_A_KIND``|フォー・オブ・ア・カインド|
|``STRAIGHT_FLUSH``|ストレートフラッシュ|
|``ROYAL_STRAIGHT_FLUSH``|ロイヤルストレートフラッシュ|

``poker_hand`` の各要素には、上の表で示した順に 0～9 の整数が割り当てられている。

## ``vector<int> hand(array<card, 5> C)``
手札を表す 5 枚のカードの配列 ``C`` が与えられたとき、そのカードの役と役のうちの相対的な強さを表す配列を返す。ただし、スートもランクも同じカードが 2 枚含まれることはないことを仮定する。

返り値の最初の整数は ``poker_hand`` の要素であり、役の種類を表す。残りの要素は、その役のうちの相対的な強さを表す。

それぞれの役に対し、返り値は以下のようになる。

### ロイヤルストレートフラッシュ

``{ROYAL_STRAIGHT_FLUSH}`` を返す。

### ストレートフラッシュ
手札のうち最も大きい ``rank`` を a としたとき、``{STRAIGHT_FLUSH, a}`` を返す。ただし、手札のランクが A,2,3,4,5 のとき、``{STRAIGHT_FLUSH, 5}`` を返す。

### フォー・オブ・ア・カインド
4 枚ある ``rank`` を a、残りのカードの ``rank`` を b としたとき、``{FOUR_OF_A_KIND, a, b}`` を返す。

### フルハウス
3 枚ある ``rank`` を a、残りの 2 枚のカードの ``rank`` を b としたとき、``{FULL_HOUSE, a, b}`` を返す。

### フラッシュ
5 枚のカードの ``rank`` を大きい順に a, b, c, d, e としたとき、``{FLUSH, a, b, c, d, e}`` を返す。

### ストレート
手札のうち最も大きい ``rank`` を a としたとき、``{STRAIGHT, a}`` を返す。ただし、手札のランクが A,2,3,4,5 のとき、``{STRAIGHT, 5}`` を返す。

### スリー・オブ・ア・カインド
3 枚ある ``rank`` を a、残りの 2 枚のカードの ``rank`` を大きい順に b, c としたとき、``{THREE_OF_A_KIND, a, b, c}`` を返す。

### ツーペア
2 枚ある ``rank`` を大きい順に a, b、残りのカードの ``rank`` を c としたとき、``{TWO_PAIR, a, b, c}`` を返す。

### ワンペア
2 枚ある ``rank`` を a、残りの 3 枚のカードの ``rank`` を大きい順に b, c, d としたとき、``{ONE_PAIR, a, b, c, d}`` を返す。

### ハイカード
5 枚のカードの ``rank`` を大きい順に a, b, c, d, e としたとき、``{HIGH_CARD, a, b, c, d, e}`` を返す。

``hand`` の返り値は、2 つの手札に対する ``hand`` の返り値を辞書順に比較した結果が役の強さの比較と一致するようになっている。