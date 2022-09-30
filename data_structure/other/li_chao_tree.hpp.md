---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/line_add_get_min.test.cpp
    title: test/library_checker/data_structure/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/segment_add_get_min.test.cpp
    title: test/library_checker/data_structure/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/other/li_chao_tree.hpp\"\ntemplate <typename\
    \ T>\nstruct li_chao_tree{\n  struct line{\n    T a, b;\n    line(): a(0), b(INF){\n\
    \    }\n    line(T a, T b): a(a), b(b){\n    }\n    T get(T x){\n      return\
    \ a * x + b;\n    }\n  };\n  int N;\n  vector<T> x;\n  vector<line> ST;\n  li_chao_tree(){\n\
    \  }\n  li_chao_tree(const vector<T> &x2){\n    x = x2;\n    sort(x.begin(), x.end());\n\
    \    int N2 = x.size();\n    N = 1;\n    while (N < N2){\n      N *= 2;\n    }\n\
    \    x.resize(N);\n    for (int i = N2; i < N; i++){\n      x[i] = x[N2 - 1];\n\
    \    }\n    ST = vector<line>(N * 2 - 1);\n  }\n  void line_add(line L, int i,\
    \ int l, int r){\n    T la = L.get(x[l]);\n    T lb = ST[i].get(x[l]);\n    T\
    \ ra = L.get(x[r - 1]);\n    T rb = ST[i].get(x[r - 1]);\n    if (la >= lb &&\
    \ ra >= rb){\n      return;\n    } else if (la <= lb && ra <= rb){\n      ST[i]\
    \ = L;\n    } else {\n      int m = (l + r) / 2;\n      T ma = L.get(x[m]);\n\
    \      T mb = ST[i].get(x[m]);\n      if (ma < mb){\n        swap(L, ST[i]);\n\
    \        swap(la, lb);\n        swap(ra, rb);\n      }\n      if (la < lb){\n\
    \        line_add(L, i * 2 + 1, l, m);\n      }\n      if (ra < rb){\n       \
    \ line_add(L, i * 2 + 2, m, r);\n      }\n    }\n  }\n  void line_add(T a, T b){\n\
    \    line_add(line(a, b), 0, 0, N);\n  }\n  void segment_add(int L, int R, line\
    \ S, int i, int l, int r){\n    if (r <= L || R <= l){\n      return;\n    } else\
    \ if (L <= l && r <= R){\n      line_add(S, i, l, r);\n    } else {\n      int\
    \ m = (l + r) / 2;\n      segment_add(L, R, S, i * 2 + 1, l, m);\n      segment_add(L,\
    \ R, S, i * 2 + 2, m, r);\n    }\n  }\n  void segment_add(T l, T r, T a, T b){\n\
    \    int pl = lower_bound(x.begin(), x.end(), l) - x.begin();\n    int pr = lower_bound(x.begin(),\
    \ x.end(), r) - x.begin();\n    segment_add(pl, pr, line(a, b), 0, 0, N);\n  }\n\
    \  T get(T x2){\n    int p = lower_bound(x.begin(), x.end(), x2) - x.begin();\n\
    \    p += N - 1;\n    T ans = INF;\n    ans = min(ans, ST[p].get(x2));\n    while\
    \ (p > 0){\n      p = (p - 1) / 2;\n      ans = min(ans, ST[p].get(x2));\n   \
    \ }\n    return ans;\n  }\n};\n"
  code: "#pragma once\ntemplate <typename T>\nstruct li_chao_tree{\n  struct line{\n\
    \    T a, b;\n    line(): a(0), b(INF){\n    }\n    line(T a, T b): a(a), b(b){\n\
    \    }\n    T get(T x){\n      return a * x + b;\n    }\n  };\n  int N;\n  vector<T>\
    \ x;\n  vector<line> ST;\n  li_chao_tree(){\n  }\n  li_chao_tree(const vector<T>\
    \ &x2){\n    x = x2;\n    sort(x.begin(), x.end());\n    int N2 = x.size();\n\
    \    N = 1;\n    while (N < N2){\n      N *= 2;\n    }\n    x.resize(N);\n   \
    \ for (int i = N2; i < N; i++){\n      x[i] = x[N2 - 1];\n    }\n    ST = vector<line>(N\
    \ * 2 - 1);\n  }\n  void line_add(line L, int i, int l, int r){\n    T la = L.get(x[l]);\n\
    \    T lb = ST[i].get(x[l]);\n    T ra = L.get(x[r - 1]);\n    T rb = ST[i].get(x[r\
    \ - 1]);\n    if (la >= lb && ra >= rb){\n      return;\n    } else if (la <=\
    \ lb && ra <= rb){\n      ST[i] = L;\n    } else {\n      int m = (l + r) / 2;\n\
    \      T ma = L.get(x[m]);\n      T mb = ST[i].get(x[m]);\n      if (ma < mb){\n\
    \        swap(L, ST[i]);\n        swap(la, lb);\n        swap(ra, rb);\n     \
    \ }\n      if (la < lb){\n        line_add(L, i * 2 + 1, l, m);\n      }\n   \
    \   if (ra < rb){\n        line_add(L, i * 2 + 2, m, r);\n      }\n    }\n  }\n\
    \  void line_add(T a, T b){\n    line_add(line(a, b), 0, 0, N);\n  }\n  void segment_add(int\
    \ L, int R, line S, int i, int l, int r){\n    if (r <= L || R <= l){\n      return;\n\
    \    } else if (L <= l && r <= R){\n      line_add(S, i, l, r);\n    } else {\n\
    \      int m = (l + r) / 2;\n      segment_add(L, R, S, i * 2 + 1, l, m);\n  \
    \    segment_add(L, R, S, i * 2 + 2, m, r);\n    }\n  }\n  void segment_add(T\
    \ l, T r, T a, T b){\n    int pl = lower_bound(x.begin(), x.end(), l) - x.begin();\n\
    \    int pr = lower_bound(x.begin(), x.end(), r) - x.begin();\n    segment_add(pl,\
    \ pr, line(a, b), 0, 0, N);\n  }\n  T get(T x2){\n    int p = lower_bound(x.begin(),\
    \ x.end(), x2) - x.begin();\n    p += N - 1;\n    T ans = INF;\n    ans = min(ans,\
    \ ST[p].get(x2));\n    while (p > 0){\n      p = (p - 1) / 2;\n      ans = min(ans,\
    \ ST[p].get(x2));\n    }\n    return ans;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/other/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2022-09-17 03:51:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/line_add_get_min.test.cpp
  - test/library_checker/data_structure/segment_add_get_min.test.cpp
documentation_of: data_structure/other/li_chao_tree.hpp
layout: document
title: Li Chao Tree
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