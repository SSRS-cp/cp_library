---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/other/sliding_window_aggregation.cpp
    title: data_structure/other/sliding_window_aggregation.cpp
  - icon: ':question:'
    path: other/monoids/linear.cpp
    title: other/monoids/linear.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/library_checker/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #line 1 \"data_structure/other/sliding_window_aggregation.cpp\"\ntemplate <typename\
    \ T>\nstruct sliding_window_aggregation{\n  function<T(T, T)> f;\n  T E;\n  stack<pair<T,\
    \ T>> fr, bk;\n  swag(function<T(T, T)> f, T E): f(f), E(E){\n  }\n  void push(T\
    \ x){\n    if (fr.empty()){\n      fr.push(make_pair(x, x));\n    } else {\n \
    \     fr.push(make_pair(x, f(fr.top().second, x)));\n    }\n  }\n  void pop(){\n\
    \    if (bk.empty()){\n      while (!fr.empty()){\n        T x = fr.top().first;\n\
    \        fr.pop();\n        if (bk.empty()){\n          bk.push(make_pair(x, x));\n\
    \        } else {\n          bk.push(make_pair(x, f(x, bk.top().second)));\n \
    \       }\n      }\n    }\n    bk.pop();\n  }\n  T get(){\n    T ans1 = E;\n \
    \   if (!fr.empty()){\n      ans1 = fr.top().second;\n    }\n    T ans2 = E;\n\
    \    if (!bk.empty()){\n      ans2 = bk.top().second;\n    }\n    return f(ans2,\
    \ ans1);\n  }\n};\n#line 1 \"other/monoids/linear.cpp\"\nstruct linear{\n  long\
    \ long a, b;\n  linear(){\n    a = 1;\n    b = 0;\n  }\n  linear(int a, int b):\
    \ a(a), b(b){\n  }\n};\nlinear composite(linear A, linear B){\n  return linear(A.a\
    \ * B.a % MOD, (A.b * B.a + B.b) % MOD);\n}\nint value(linear A, int x){\n  return\
    \ (A.a * x + A.b) % MOD;\n}\n#line 7 \"test/library_checker/queue_operate_all_composite.test.cpp\"\
    \nint main(){\n  int Q;\n  cin >> Q;\n  swag<linear> S(composite, linear());\n\
    \  for (int i = 0; i < Q; i++){\n    int t;\n    cin >> t;\n    if (t == 0){\n\
    \      int a, b;\n      cin >> a >> b;\n      S.push(linear(a, b));\n    }\n \
    \   if (t == 1){\n      S.pop();\n    }\n    if (t == 2){\n      int x;\n    \
    \  cin >> x;\n      cout << value(S.get(),x) << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 998244353;\n\
    #include \"../../data_structure/other/sliding_window_aggregation.cpp\"\n#include\
    \ \"../../other/monoids/linear.cpp\"\nint main(){\n  int Q;\n  cin >> Q;\n  swag<linear>\
    \ S(composite, linear());\n  for (int i = 0; i < Q; i++){\n    int t;\n    cin\
    \ >> t;\n    if (t == 0){\n      int a, b;\n      cin >> a >> b;\n      S.push(linear(a,\
    \ b));\n    }\n    if (t == 1){\n      S.pop();\n    }\n    if (t == 2){\n   \
    \   int x;\n      cin >> x;\n      cout << value(S.get(),x) << endl;\n    }\n\
    \  }\n}\n"
  dependsOn:
  - data_structure/other/sliding_window_aggregation.cpp
  - other/monoids/linear.cpp
  isVerificationFile: true
  path: test/library_checker/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2022-07-15 08:40:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/queue_operate_all_composite.test.cpp
- /verify/test/library_checker/queue_operate_all_composite.test.cpp.html
title: test/library_checker/queue_operate_all_composite.test.cpp
---
