---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/aoj/dsl_2_g.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"data_structure/sequence/lazy_segment_tree.hpp\"\
    \n/**\n * @brief \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n*/\ntemplate\
    \ <typename T, typename F>\nstruct lazy_segment_tree{\n  int N;\n  vector<T> ST;\n\
    \  vector<F> lazy;\n  function<T(T, T)> op;\n  function<T(F, T)> mp;\n  function<F(F,\
    \ F)> comp;\n  T E;\n  F id;\n  lazy_segment_tree(int n, function<T(T, T)> op,\
    \ function<T(F, T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp),\
    \ E(E), id(id){\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST\
    \ = vector<T>(N * 2 - 1, E);\n    for (int i = N - 2; i >= 0; i--){\n      ST[i]\
    \ = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n    lazy = vector<F>(N * 2 - 1,\
    \ id);\n  }\n  lazy_segment_tree(vector<T> &A, function<T(T, T)> op, function<T(F,\
    \ T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E),\
    \ id(id){\n    int n = A.size();\n    N = 1;\n    while (N < n){\n      N *= 2;\n\
    \    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i = 0; i < n; i++){\n\
    \      ST[N - 1 + i] = A[i];\n    }\n    for (int i = N - 2; i >= 0; i--){\n \
    \     ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n    lazy = vector<F>(N\
    \ * 2 - 1, id);\n  }\n  void push(int i){\n    if (i < N - 1){\n      lazy[i *\
    \ 2 + 1] = comp(lazy[i * 2 + 1], lazy[i]);\n      lazy[i * 2 + 2] = comp(lazy[i\
    \ * 2 + 2], lazy[i]);\n    }\n    ST[i] = mp(lazy[i], ST[i]);\n    lazy[i] = id;\n\
    \  }\n  void range_apply(int L, int R, F f, int i, int l, int r){\n    push(i);\n\
    \    if (r <= L || R <= l){\n      return;\n    } else if (L <= l && r <= R){\n\
    \      lazy[i] = f;\n      push(i);\n    } else {\n      int m = (l + r) / 2;\n\
    \      range_apply(L, R, f, i * 2 + 1, l, m);\n      range_apply(L, R, f, i *\
    \ 2 + 2, m, r);\n      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n  }\n\
    \  void range_apply(int L, int R, F f){\n    range_apply(L, R, f, 0, 0, N);\n\
    \  }\n  T range_fold(int L, int R, int i, int l, int r){\n    push(i);\n    if\
    \ (r <= L || R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n  \
    \    return ST[i];\n    } else {\n      int m = (l + r) / 2;\n      return op(range_fold(L,\
    \ R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));\n    }\n  }\n  T range_fold(int\
    \ L, int R){\n    return range_fold(L, R, 0, 0, N);\n  }\n  T all(){\n    push(0);\n\
    \    return ST[0];\n  }\n};\n#line 5 \"test/aoj/dsl_2_g.test.cpp\"\nstruct monoid{\n\
    \  int cnt;\n  long long sum;\n  monoid(): cnt(0), sum(0){\n  }\n};\nint main(){\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<monoid> A(n);\n  for (int i = 0; i <\
    \ n; i++){\n    A[i].cnt = 1;\n  }\n  function<monoid(monoid, monoid)> op = [](monoid\
    \ a, monoid b){\n    a.cnt += b.cnt;\n    a.sum += b.sum;\n    return a;\n  };\n\
    \  function<monoid(int, monoid)> mp = [](int a, monoid b){\n    b.sum += (long\
    \ long) a * b.cnt;\n    return b;\n  };\n  lazy_segment_tree<monoid, int> ST(A,\
    \ op, mp, plus<int>(), monoid(), 0);\n  for (int i = 0; i < q; i++){\n    int\
    \ c;\n    cin >> c;\n    if (c == 0){\n      int s, t, x;\n      cin >> s >> t\
    \ >> x;\n      s--;\n      ST.range_apply(s, t, x);\n    }\n    if (c == 1){\n\
    \      int s, t;\n      cin >> s >> t;\n      s--;\n      cout << ST.range_fold(s,\
    \ t).sum << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/sequence/lazy_segment_tree.hpp\"\
    \nstruct monoid{\n  int cnt;\n  long long sum;\n  monoid(): cnt(0), sum(0){\n\
    \  }\n};\nint main(){\n  int n, q;\n  cin >> n >> q;\n  vector<monoid> A(n);\n\
    \  for (int i = 0; i < n; i++){\n    A[i].cnt = 1;\n  }\n  function<monoid(monoid,\
    \ monoid)> op = [](monoid a, monoid b){\n    a.cnt += b.cnt;\n    a.sum += b.sum;\n\
    \    return a;\n  };\n  function<monoid(int, monoid)> mp = [](int a, monoid b){\n\
    \    b.sum += (long long) a * b.cnt;\n    return b;\n  };\n  lazy_segment_tree<monoid,\
    \ int> ST(A, op, mp, plus<int>(), monoid(), 0);\n  for (int i = 0; i < q; i++){\n\
    \    int c;\n    cin >> c;\n    if (c == 0){\n      int s, t, x;\n      cin >>\
    \ s >> t >> x;\n      s--;\n      ST.range_apply(s, t, x);\n    }\n    if (c ==\
    \ 1){\n      int s, t;\n      cin >> s >> t;\n      s--;\n      cout << ST.range_fold(s,\
    \ t).sum << endl;\n    }\n  }\n}"
  dependsOn:
  - data_structure/sequence/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/dsl_2_g.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_2_g.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_g.test.cpp
- /verify/test/aoj/dsl_2_g.test.cpp.html
title: test/aoj/dsl_2_g.test.cpp
---
