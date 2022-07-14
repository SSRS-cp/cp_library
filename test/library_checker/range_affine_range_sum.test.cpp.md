---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sequence/lazy_segment_tree.cpp
    title: "Lazy Segment Tree (\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: other/monoids/affine_sum.cpp
    title: other/monoids/affine_sum.cpp
  - icon: ':heavy_check_mark:'
    path: other/monoids/linear.cpp
    title: other/monoids/linear.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/library_checker/range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n#line\
    \ 1 \"data_structure/sequence/lazy_segment_tree.cpp\"\ntemplate <typename T, typename\
    \ F>\nstruct lazy_segment_tree{\n  int N;\n  vector<T> ST;\n  vector<F> lazy;\n\
    \  function<T(T, T)> op;\n  function<T(F, T)> mp;\n  function<F(F, F)> comp;\n\
    \  T E;\n  F id;\n  lazy_segment_tree(int n, function<T(T, T)> op, function<T(F,\
    \ T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E),\
    \ id(id){\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N\
    \ * 2 - 1, E);\n    for (int i = N - 2; i >= 0; i--){\n      ST[i] = op(ST[i *\
    \ 2 + 1], ST[i * 2 + 2]);\n    }\n    lazy = vector<F>(N * 2 - 1, id);\n  }\n\
    \  lazy_segment_tree(vector<T> &A, function<T(T, T)> op, function<T(F, T)> mp,\
    \ function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E), id(id){\n\
    \    int n = A.size();\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n\
    \    ST = vector<T>(N * 2 - 1, E);\n    for (int i = 0; i < n; i++){\n      ST[N\
    \ - 1 + i] = A[i];\n    }\n    for (int i = N - 2; i >= 0; i--){\n      ST[i]\
    \ = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n    lazy = vector<F>(N * 2 - 1,\
    \ id);\n  }\n  void push(int i){\n    if (i < N - 1){\n      lazy[i * 2 + 1] =\
    \ comp(lazy[i * 2 + 1], lazy[i]);\n      lazy[i * 2 + 2] = comp(lazy[i * 2 + 2],\
    \ lazy[i]);\n    }\n    ST[i] = mp(lazy[i], ST[i]);\n    lazy[i] = id;\n  }\n\
    \  void range_apply(int L, int R, F f, int i, int l, int r){\n    push(i);\n \
    \   if (r <= L || R <= l){\n      return;\n    } else if (L <= l && r <= R){\n\
    \      lazy[i] = f;\n      push(i);\n    } else {\n      int m = (l + r) / 2;\n\
    \      range_apply(L, R, f, i * 2 + 1, l, m);\n      range_apply(L, R, f, i *\
    \ 2 + 2, m, r);\n      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n  }\n\
    \  void range_apply(int L, int R, F f){\n    range_apply(L, R, f, 0, 0, N);\n\
    \  }\n  T range_fold(int L, int R, int i, int l, int r){\n    push(i);\n    if\
    \ (r <= L || R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n  \
    \    return ST[i];\n    } else {\n      int m = (l + r) / 2;\n      return op(range_fold(L,\
    \ R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));\n    }\n  }\n  T range_fold(int\
    \ L, int R){\n    return range_fold(L, R, 0, 0, N);\n  }\n  T all(){\n    push(0);\n\
    \    return ST[0];\n  }\n};\n/**\n * @brief Lazy Segment Tree (\u9045\u5EF6\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n#line 1 \"other/monoids/linear.cpp\"\nstruct\
    \ linear{\n  long long a, b;\n  linear(){\n    a = 1;\n    b = 0;\n  }\n  linear(int\
    \ a, int b): a(a), b(b){\n  }\n};\nlinear composite(linear A, linear B){\n  return\
    \ linear(A.a * B.a % MOD, (A.b * B.a + B.b) % MOD);\n}\nint value(linear A, int\
    \ x){\n  return (A.a * x + A.b) % MOD;\n}\n#line 1 \"other/monoids/affine_sum.cpp\"\
    \nstruct affine_sum{\n  int cnt;\n  long long sum;\n  affine_sum(): cnt(0), sum(0){\n\
    \  }\n};\naffine_sum op(affine_sum A, affine_sum B){\n  A.cnt += B.cnt;\n  A.sum\
    \ += B.sum;\n  A.sum %= MOD;\n  return A;\n}\naffine_sum mp(linear f, affine_sum\
    \ A){\n  A.sum = (A.sum * f.a + A.cnt * f.b) % MOD;\n  return A;\n}\n#line 8 \"\
    test/library_checker/range_affine_range_sum.test.cpp\"\nint main(){\n  int N,\
    \ Q;\n  cin >> N >> Q;\n  vector<affine_sum> a(N);\n  for (int i = 0; i < N; i++){\n\
    \    a[i].cnt = 1;\n    cin >> a[i].sum;\n  }\n  lazy_segment_tree<affine_sum,\
    \ linear> ST(a, op, mp, composite, affine_sum(), linear());\n  for (int i = 0;\
    \ i < Q; i++){\n    int t;\n    cin >> t;\n    if (t == 0){\n      int l, r, b,\
    \ c;\n      cin >> l >> r >> b >> c;\n      ST.range_apply(l, r, linear(b, c));\n\
    \    }\n    if (t == 1){\n      int l, r;\n      cin >> l >> r;\n      cout <<\
    \ ST.range_fold(l, r).sum << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #include \"../../data_structure/sequence/lazy_segment_tree.cpp\"\n#include \"\
    ../../other/monoids/linear.cpp\"\n#include \"../../other/monoids/affine_sum.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<affine_sum> a(N);\n  for\
    \ (int i = 0; i < N; i++){\n    a[i].cnt = 1;\n    cin >> a[i].sum;\n  }\n  lazy_segment_tree<affine_sum,\
    \ linear> ST(a, op, mp, composite, affine_sum(), linear());\n  for (int i = 0;\
    \ i < Q; i++){\n    int t;\n    cin >> t;\n    if (t == 0){\n      int l, r, b,\
    \ c;\n      cin >> l >> r >> b >> c;\n      ST.range_apply(l, r, linear(b, c));\n\
    \    }\n    if (t == 1){\n      int l, r;\n      cin >> l >> r;\n      cout <<\
    \ ST.range_fold(l, r).sum << endl;\n    }\n  }\n}\n"
  dependsOn:
  - data_structure/sequence/lazy_segment_tree.cpp
  - other/monoids/linear.cpp
  - other/monoids/affine_sum.cpp
  isVerificationFile: true
  path: test/library_checker/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-14 02:37:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/range_affine_range_sum.test.cpp
- /verify/test/library_checker/range_affine_range_sum.test.cpp.html
title: test/library_checker/range_affine_range_sum.test.cpp
---
