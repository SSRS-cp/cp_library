---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sequence/dual_segment_tree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u3073\u30FC\u3068\u6728\
      )"
  - icon: ':heavy_check_mark:'
    path: other/monoids/linear.hpp
    title: other/monoids/linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/library_checker/range_affine_point_get.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n#line\
    \ 2 \"data_structure/sequence/dual_segment_tree.hpp\"\n/**\n * @brief \u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u3073\u30FC\u3068\u6728)\n*/\ntemplate\
    \ <typename T>\nstruct dual_segment_tree{\n  int N;\n  vector<T> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  dual_segment_tree(int n, function<T(T, T)> f, T E): f(f),\
    \ E(E){\n    N = 1;\n    while (N < n){\n      N *= 2;\n    }\n    ST = vector<T>(N\
    \ * 2 - 1, E);\n  }\n  dual_segment_tree(vector<T> A, function<T(T, T)> f, T E):\
    \ f(f), E(E){\n    int n = A.size();\n    N = 1;\n    while (N < n){\n      N\
    \ *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i = 0; i < n;\
    \ i++){\n      ST[N - 1 + i] = A[i];\n    }\n  }\n  void push(int i){\n    if\
    \ (i < N - 1){\n      ST[i * 2 + 1] = f(ST[i * 2 + 1], ST[i]);\n      ST[i * 2\
    \ + 2] = f(ST[i * 2 + 2], ST[i]);\n      ST[i] = E;\n    }\n  }\n  T operator\
    \ [](int k){\n    int v = 0;\n    for (int i = N / 2; i >= 1; i >>= 1){\n    \
    \  push(v);\n      if ((k & i) == 0){\n        v = v * 2 + 1;\n      } else {\n\
    \        v = v * 2 + 2;\n      }\n    }\n    return ST[v];\n  }\n  void range_apply(int\
    \ L, int R, T x, int i, int l, int r){\n    if (r <= L || R <= l){\n    } else\
    \ if (L <= l && r <= R){\n      ST[i] = f(ST[i], x);\n    } else {\n      push(i);\n\
    \      int m = (l + r) / 2;\n      range_apply(L, R, x, i * 2 + 1, l, m);\n  \
    \    range_apply(L, R, x, i * 2 + 2, m, r);\n    }\n  }\n  void range_apply(int\
    \ L, int R, T x){\n    range_apply(L, R, x, 0, 0, N);\n  }\n};\n#line 2 \"other/monoids/linear.hpp\"\
    \nstruct linear{\n  long long a, b;\n  linear(){\n    a = 1;\n    b = 0;\n  }\n\
    \  linear(int a, int b): a(a), b(b){\n  }\n};\nlinear composite(linear A, linear\
    \ B){\n  return linear(A.a * B.a % MOD, (A.b * B.a + B.b) % MOD);\n}\nint value(linear\
    \ A, int x){\n  return (A.a * x + A.b) % MOD;\n}\n#line 7 \"test/library_checker/range_affine_point_get.test.cpp\"\
    \nint main(){\n  int N, Q;\n  cin >> N >> Q;\n  vector<linear> a(N);\n  for (int\
    \ i = 0; i < N; i++){\n    a[i].a = 0;\n    cin >> a[i].b;\n  }\n  dual_segment_tree<linear>\
    \ ST(a, composite, linear());\n  for (int i = 0; i < Q; i++){\n    int t;\n  \
    \  cin >> t;\n    if (t == 0){\n      int l, r, b, c;\n      cin >> l >> r >>\
    \ b >> c;\n      ST.range_apply(l, r, linear(b, c));\n    }\n    if (t == 1){\n\
    \      int p;\n      cin >> p;\n      cout << ST[p].b << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #include \"../../data_structure/sequence/dual_segment_tree.hpp\"\n#include \"\
    ../../other/monoids/linear.hpp\"\nint main(){\n  int N, Q;\n  cin >> N >> Q;\n\
    \  vector<linear> a(N);\n  for (int i = 0; i < N; i++){\n    a[i].a = 0;\n   \
    \ cin >> a[i].b;\n  }\n  dual_segment_tree<linear> ST(a, composite, linear());\n\
    \  for (int i = 0; i < Q; i++){\n    int t;\n    cin >> t;\n    if (t == 0){\n\
    \      int l, r, b, c;\n      cin >> l >> r >> b >> c;\n      ST.range_apply(l,\
    \ r, linear(b, c));\n    }\n    if (t == 1){\n      int p;\n      cin >> p;\n\
    \      cout << ST[p].b << endl;\n    }\n  }\n}"
  dependsOn:
  - data_structure/sequence/dual_segment_tree.hpp
  - other/monoids/linear.hpp
  isVerificationFile: true
  path: test/library_checker/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 07:03:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/range_affine_point_get.test.cpp
- /verify/test/library_checker/range_affine_point_get.test.cpp.html
title: test/library_checker/range_affine_point_get.test.cpp
---
