---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/segment_tree_beats.cpp
    title: data_structure/sequence/segment_tree_beats.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"data_structure/sequence/segment_tree_beats.cpp\"\
    \n\ntemplate <typename T, typename F>\nstruct segment_tree_beats{\n  int N;\n\
    \  vector<T> ST;\n  vector<F> lazy;\n  function<T(T, T)> op;\n  function<T(F,\
    \ T)> mp;\n  function<F(F, F)> comp;\n  T E;\n  F id;\n  segment_tree_beats(vector<T>\
    \ &A, function<T(T, T)> op, function<T(F, T)> mp, function<F(F, F)> comp, T E,\
    \ F id): op(op), mp(mp), comp(comp), E(E), id(id){\n    int n = A.size();\n  \
    \  N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2\
    \ - 1, E);\n    for (int i = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n  \
    \  }\n    for (int i = N - 2; i >= 0; i--){\n      update(i);\n    }\n    lazy\
    \ = vector<F>(N * 2 - 1, id);\n  }\n  void update(int i){\n    ST[i] = op(ST[i\
    \ * 2 + 1], ST[i * 2 + 2]);\n  }\n  void push(int i){\n    ST[i] = mp(lazy[i],\
    \ ST[i]);\n    if (i < N - 1){\n      lazy[i * 2 + 1] = comp(lazy[i], lazy[i *\
    \ 2 + 1]);\n      lazy[i * 2 + 2] = comp(lazy[i], lazy[i * 2 + 2]);\n      if\
    \ (ST[i].fail){\n        push(i * 2 + 1);\n        push(i * 2 + 2);\n        update(i);\n\
    \      }\n    }\n    lazy[i] = id;\n  }\n  void range_apply(int L, int R, F f,\
    \ int i, int l, int r){\n    push(i);\n    if (r <= L || R <= l){\n      return;\n\
    \    } else if (L <= l && r <= R){\n      lazy[i] = f;\n      push(i);\n    }\
    \ else {\n      int m = (l + r) / 2;\n      range_apply(L, R, f, i * 2 + 1, l,\
    \ m);\n      range_apply(L, R, f, i * 2 + 2, m, r);\n      update(i);\n    }\n\
    \  }\n  void range_apply(int L, int R, F f){\n    range_apply(L, R, f, 0, 0, N);\n\
    \  }\n  T range_fold(int L, int R, int i, int l, int r){\n    push(i);\n    if\
    \ (r <= L || R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n  \
    \    return ST[i];\n    } else {\n      int m = (l + r) / 2;\n      return op(range_fold(L,\
    \ R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));\n    }\n  }\n  T range_fold(int\
    \ L, int R){\n    return range_fold(L, R, 0, 0, N);\n  }\n};\n#line 5 \"test/library_checker/range_chmin_chmax_add_range_sum.test.cpp\"\
    \nconst long long INF = 1000000000000000000;\nstruct monoid{\n  int sz, minc,\
    \ maxc;\n  long long min1, min2, max1, max2, sum;\n  bool fail;\n  monoid(): sz(0),\
    \ minc(0), maxc(0), min1(INF), min2(INF), max1(-INF), max2(-INF), sum(0), fail(false){\n\
    \  }\n  monoid(long long x, int sz = 1): sz(sz), minc(sz), maxc(sz), min1(x),\
    \ min2(INF), max1(x), max2(-INF), sum(x * sz), fail(false){\n  }\n};\nmonoid op(monoid\
    \ L, monoid R){\n  monoid ans;\n  ans.sz = L.sz + R.sz;\n  ans.sum = L.sum + R.sum;\n\
    \  ans.min1 = min(L.min1, R.min1);\n  if (L.min1 < R.min1){\n    ans.min2 = min(L.min2,\
    \ R.min1);\n    ans.minc = L.minc;\n  } else if (L.min1 > R.min1){\n    ans.min2\
    \ = min(L.min1, R.min2);\n    ans.minc = R.minc;\n  } else {\n    ans.min2 = min(L.min2,\
    \ R.min2);\n    ans.minc = L.minc + R.minc;\n  }\n  ans.max1 = max(L.max1, R.max1);\n\
    \  if (L.max1 > R.max1){\n    ans.max2 = max(L.max2, R.max1);\n    ans.maxc =\
    \ L.maxc;\n  } else if (L.max1 < R.max1){\n    ans.max2 = max(L.max1, R.max2);\n\
    \    ans.maxc = R.maxc;\n  } else {\n    ans.max2 = max(L.max2, R.max2);\n   \
    \ ans.maxc = L.maxc + R.maxc;\n  }\n  return ans;\n}\nstruct func{\n  long long\
    \ mn, mx, add;\n  func(): mn(-INF), mx(INF), add(0){\n  }\n  func(long long mn,\
    \ long long mx, long long add): mn(mn), mx(mx), add(add){\n  }\n};\nfunc comp(func\
    \ g, func f){\n  func ans;\n  ans.mn = max(min(f.mn + g.add, g.mx), g.mn);\n \
    \ ans.mx = min(max(f.mx + g.add, g.mn), g.mx);\n  ans.add = f.add + g.add;\n \
    \ return ans;\n}\nmonoid mp(func f, monoid x){\n  if (x.sz == 0){\n    return\
    \ x;\n  }\n  x.min1 += f.add;\n  if (x.min2 != INF){\n    x.min2 += f.add;\n \
    \ }\n  x.max1 += f.add;\n  if (x.max2 != -INF){\n    x.max2 += f.add;\n  }\n \
    \ x.sum += x.sz * f.add;\n  if (x.max1 <= f.mn){\n    return monoid(f.mn, x.sz);\n\
    \  }\n  if (x.min1 >= f.mx){\n    return monoid(f.mx, x.sz);\n  }\n  if (f.mn\
    \ < x.min2){\n    if (x.min1 < f.mn){\n      x.sum += (f.mn - x.min1) * x.minc;\n\
    \      if (x.min1 == x.max1){\n        x.max1 = f.mn;\n      } else if (x.min1\
    \ == x.max2){\n        x.max2 = f.mn;\n      }\n      x.min1 = f.mn;\n    }\n\
    \  } else {\n    x.fail = true;\n    return x;\n  }\n  if (f.mx > x.max2){\n \
    \   if (x.max1 > f.mx){\n      x.sum -= (x.max1 - f.mx) * x.maxc;\n      if (x.max1\
    \ == x.min1){\n        x.min1 = f.mx;\n      } else if (x.max1 == x.min2){\n \
    \       x.min2 = f.mx;\n      }\n      x.max1 = f.mx;\n    }\n  } else {\n   \
    \ x.fail = true;\n    return x;\n  }\n  return x;\n}\nint main(){\n  int N, Q;\n\
    \  cin >> N >> Q;\n  vector<monoid> A(N);\n  for (int i = 0; i < N; i++){\n  \
    \  long long a;\n    cin >> a;\n    A[i] = monoid(a);\n  }\n  segment_tree_beats<monoid,\
    \ func> ST(A, op, mp, comp, monoid(), func());\n  for (int i = 0; i < Q; i++){\n\
    \    int t;\n    cin >> t;\n    if (t == 0){\n      int l, r;\n      long long\
    \ b;\n      cin >> l >> r >> b;\n      ST.range_apply(l, r, func(-INF, b, 0));\n\
    \    }\n    if (t == 1){\n      int l, r;\n      long long b;\n      cin >> l\
    \ >> r >> b;\n      ST.range_apply(l, r, func(b, INF, 0));\n    }\n    if (t ==\
    \ 2){\n      int l, r;\n      long long b;\n      cin >> l >> r >> b;\n      ST.range_apply(l,\
    \ r, func(-INF, INF, b));\n    }\n    if (t == 3){\n      int l, r;\n      cin\
    \ >> l >> r;\n      cout << ST.range_fold(l, r).sum << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/segment_tree_beats.cpp\"\
    \nconst long long INF = 1000000000000000000;\nstruct monoid{\n  int sz, minc,\
    \ maxc;\n  long long min1, min2, max1, max2, sum;\n  bool fail;\n  monoid(): sz(0),\
    \ minc(0), maxc(0), min1(INF), min2(INF), max1(-INF), max2(-INF), sum(0), fail(false){\n\
    \  }\n  monoid(long long x, int sz = 1): sz(sz), minc(sz), maxc(sz), min1(x),\
    \ min2(INF), max1(x), max2(-INF), sum(x * sz), fail(false){\n  }\n};\nmonoid op(monoid\
    \ L, monoid R){\n  monoid ans;\n  ans.sz = L.sz + R.sz;\n  ans.sum = L.sum + R.sum;\n\
    \  ans.min1 = min(L.min1, R.min1);\n  if (L.min1 < R.min1){\n    ans.min2 = min(L.min2,\
    \ R.min1);\n    ans.minc = L.minc;\n  } else if (L.min1 > R.min1){\n    ans.min2\
    \ = min(L.min1, R.min2);\n    ans.minc = R.minc;\n  } else {\n    ans.min2 = min(L.min2,\
    \ R.min2);\n    ans.minc = L.minc + R.minc;\n  }\n  ans.max1 = max(L.max1, R.max1);\n\
    \  if (L.max1 > R.max1){\n    ans.max2 = max(L.max2, R.max1);\n    ans.maxc =\
    \ L.maxc;\n  } else if (L.max1 < R.max1){\n    ans.max2 = max(L.max1, R.max2);\n\
    \    ans.maxc = R.maxc;\n  } else {\n    ans.max2 = max(L.max2, R.max2);\n   \
    \ ans.maxc = L.maxc + R.maxc;\n  }\n  return ans;\n}\nstruct func{\n  long long\
    \ mn, mx, add;\n  func(): mn(-INF), mx(INF), add(0){\n  }\n  func(long long mn,\
    \ long long mx, long long add): mn(mn), mx(mx), add(add){\n  }\n};\nfunc comp(func\
    \ g, func f){\n  func ans;\n  ans.mn = max(min(f.mn + g.add, g.mx), g.mn);\n \
    \ ans.mx = min(max(f.mx + g.add, g.mn), g.mx);\n  ans.add = f.add + g.add;\n \
    \ return ans;\n}\nmonoid mp(func f, monoid x){\n  if (x.sz == 0){\n    return\
    \ x;\n  }\n  x.min1 += f.add;\n  if (x.min2 != INF){\n    x.min2 += f.add;\n \
    \ }\n  x.max1 += f.add;\n  if (x.max2 != -INF){\n    x.max2 += f.add;\n  }\n \
    \ x.sum += x.sz * f.add;\n  if (x.max1 <= f.mn){\n    return monoid(f.mn, x.sz);\n\
    \  }\n  if (x.min1 >= f.mx){\n    return monoid(f.mx, x.sz);\n  }\n  if (f.mn\
    \ < x.min2){\n    if (x.min1 < f.mn){\n      x.sum += (f.mn - x.min1) * x.minc;\n\
    \      if (x.min1 == x.max1){\n        x.max1 = f.mn;\n      } else if (x.min1\
    \ == x.max2){\n        x.max2 = f.mn;\n      }\n      x.min1 = f.mn;\n    }\n\
    \  } else {\n    x.fail = true;\n    return x;\n  }\n  if (f.mx > x.max2){\n \
    \   if (x.max1 > f.mx){\n      x.sum -= (x.max1 - f.mx) * x.maxc;\n      if (x.max1\
    \ == x.min1){\n        x.min1 = f.mx;\n      } else if (x.max1 == x.min2){\n \
    \       x.min2 = f.mx;\n      }\n      x.max1 = f.mx;\n    }\n  } else {\n   \
    \ x.fail = true;\n    return x;\n  }\n  return x;\n}\nint main(){\n  int N, Q;\n\
    \  cin >> N >> Q;\n  vector<monoid> A(N);\n  for (int i = 0; i < N; i++){\n  \
    \  long long a;\n    cin >> a;\n    A[i] = monoid(a);\n  }\n  segment_tree_beats<monoid,\
    \ func> ST(A, op, mp, comp, monoid(), func());\n  for (int i = 0; i < Q; i++){\n\
    \    int t;\n    cin >> t;\n    if (t == 0){\n      int l, r;\n      long long\
    \ b;\n      cin >> l >> r >> b;\n      ST.range_apply(l, r, func(-INF, b, 0));\n\
    \    }\n    if (t == 1){\n      int l, r;\n      long long b;\n      cin >> l\
    \ >> r >> b;\n      ST.range_apply(l, r, func(b, INF, 0));\n    }\n    if (t ==\
    \ 2){\n      int l, r;\n      long long b;\n      cin >> l >> r >> b;\n      ST.range_apply(l,\
    \ r, func(-INF, INF, b));\n    }\n    if (t == 3){\n      int l, r;\n      cin\
    \ >> l >> r;\n      cout << ST.range_fold(l, r).sum << endl;\n    }\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/segment_tree_beats.cpp
  isVerificationFile: true
  path: test/library_checker/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-15 07:37:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/library_checker/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/library_checker/range_chmin_chmax_add_range_sum.test.cpp
---
