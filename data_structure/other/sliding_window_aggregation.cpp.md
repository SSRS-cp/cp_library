---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/other/sliding_window_aggregation.cpp\"\n\
    template <typename T>\nstruct sliding_window_aggregation{\n  function<T(T, T)>\
    \ f;\n  T E;\n  stack<pair<T, T>> fr, bk;\n  swag(function<T(T, T)> f, T E): f(f),\
    \ E(E){\n  }\n  void push(T x){\n    if (fr.empty()){\n      fr.push(make_pair(x,\
    \ x));\n    } else {\n      fr.push(make_pair(x, f(fr.top().second, x)));\n  \
    \  }\n  }\n  void pop(){\n    if (bk.empty()){\n      while (!fr.empty()){\n \
    \       T x = fr.top().first;\n        fr.pop();\n        if (bk.empty()){\n \
    \         bk.push(make_pair(x, x));\n        } else {\n          bk.push(make_pair(x,\
    \ f(x, bk.top().second)));\n        }\n      }\n    }\n    bk.pop();\n  }\n  T\
    \ get(){\n    T ans1 = E;\n    if (!fr.empty()){\n      ans1 = fr.top().second;\n\
    \    }\n    T ans2 = E;\n    if (!bk.empty()){\n      ans2 = bk.top().second;\n\
    \    }\n    return f(ans2, ans1);\n  }\n};\n"
  code: "template <typename T>\nstruct sliding_window_aggregation{\n  function<T(T,\
    \ T)> f;\n  T E;\n  stack<pair<T, T>> fr, bk;\n  swag(function<T(T, T)> f, T E):\
    \ f(f), E(E){\n  }\n  void push(T x){\n    if (fr.empty()){\n      fr.push(make_pair(x,\
    \ x));\n    } else {\n      fr.push(make_pair(x, f(fr.top().second, x)));\n  \
    \  }\n  }\n  void pop(){\n    if (bk.empty()){\n      while (!fr.empty()){\n \
    \       T x = fr.top().first;\n        fr.pop();\n        if (bk.empty()){\n \
    \         bk.push(make_pair(x, x));\n        } else {\n          bk.push(make_pair(x,\
    \ f(x, bk.top().second)));\n        }\n      }\n    }\n    bk.pop();\n  }\n  T\
    \ get(){\n    T ans1 = E;\n    if (!fr.empty()){\n      ans1 = fr.top().second;\n\
    \    }\n    T ans2 = E;\n    if (!bk.empty()){\n      ans2 = bk.top().second;\n\
    \    }\n    return f(ans2, ans1);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/other/sliding_window_aggregation.cpp
  requiredBy: []
  timestamp: '2022-07-15 08:38:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/other/sliding_window_aggregation.cpp
layout: document
redirect_from:
- /library/data_structure/other/sliding_window_aggregation.cpp
- /library/data_structure/other/sliding_window_aggregation.cpp.html
title: data_structure/other/sliding_window_aggregation.cpp
---
