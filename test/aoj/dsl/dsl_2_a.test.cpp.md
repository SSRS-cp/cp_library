---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sequence/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u3046\u3057\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/dsl/dsl_2_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"data_structure/sequence/segment_tree.hpp\"\
    \n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u3046\u3057\u6728)\n*/\n\
    template <typename T>\nstruct segment_tree{\n  int N;\n  vector<T> ST;\n  function<T(T,\
    \ T)> f;\n  T E;\n  segment_tree(){\n  }\n  segment_tree(int n, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    N = 1;\n    while (N < n){\n      N *= 2;\n  \
    \  }\n    ST = vector<T>(N * 2 - 1, E);\n  }\n  segment_tree(vector<T> A, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    int n = A.size();\n    N = 1;\n    while (N <\
    \ n){\n      N *= 2;\n    }\n    ST = vector<T>(N * 2 - 1, E);\n    for (int i\
    \ = 0; i < n; i++){\n      ST[N - 1 + i] = A[i];\n    }\n    for (int i = N -\
    \ 2; i >= 0; i--){\n      ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);\n    }\n  }\n\
    \  T operator [](int k){\n    return ST[N - 1 + k];\n  }\n  void update(int k,\
    \ T x){\n    k += N - 1;\n    ST[k] = x;\n    while (k > 0){\n      k = (k - 1)\
    \ / 2;\n      ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);\n    }\n  }\n  T query(int\
    \ L, int R, int i, int l, int r){\n    if (r <= L || R <= l){\n      return E;\n\
    \    } else if (L <= l && r <= R){\n      return ST[i];\n    } else {\n      int\
    \ m = (l + r) / 2;\n      return f(query(L, R, i * 2 + 1, l, m), query(L, R, i\
    \ * 2 + 2, m, r));\n    }\n  }\n  T query(int L, int R){\n    return query(L,\
    \ R, 0, 0, N);\n  }\n  T all(){\n    return ST[0];\n  }\n};\n#line 5 \"test/aoj/dsl/dsl_2_a.test.cpp\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  segment_tree<int> ST(n, [](int\
    \ a, int b){return min(a, b);}, 2147483647);\n  for (int i = 0; i < q; i++){\n\
    \    int com, x, y;\n    cin >> com >> x >> y;\n    if (com == 0){\n      ST.update(x,\
    \ y);\n    }\n    if (com == 1){\n      y++;\n      cout << ST.query(x, y) <<\
    \ endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../data_structure/sequence/segment_tree.hpp\"\
    \nint main(){\n  int n, q;\n  cin >> n >> q;\n  segment_tree<int> ST(n, [](int\
    \ a, int b){return min(a, b);}, 2147483647);\n  for (int i = 0; i < q; i++){\n\
    \    int com, x, y;\n    cin >> com >> x >> y;\n    if (com == 0){\n      ST.update(x,\
    \ y);\n    }\n    if (com == 1){\n      y++;\n      cout << ST.query(x, y) <<\
    \ endl;\n    }\n  }\n}"
  dependsOn:
  - data_structure/sequence/segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl_2_a.test.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:43:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl_2_a.test.cpp
- /verify/test/aoj/dsl/dsl_2_a.test.cpp.html
title: test/aoj/dsl/dsl_2_a.test.cpp
---
