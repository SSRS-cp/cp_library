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
  bundledCode: "#line 1 \"Data_Structures/Sliding_Window_Aggregation.cpp\"\ntemplate\
    \ <typename T>\nstruct swag{\n  function<T(T, T)> f;\n  T E;\n  stack<pair<T,\
    \ T>> fr, bk;\n  swag(function<T(T, T)> f, T E): f(f), E(E){\n  }\n  void push(T\
    \ x){\n    if (fr.empty()){\n      fr.push(make_pair(x, x));\n    } else {\n \
    \     fr.push(make_pair(x, f(fr.top().second, x)));\n    }\n  }\n  void pop(){\n\
    \    if (bk.empty()){\n      while (!fr.empty()){\n        T x = fr.top().first;\n\
    \        fr.pop();\n        if (bk.empty()){\n          bk.push(make_pair(x, x));\n\
    \        } else {\n          bk.push(make_pair(x, f(x, bk.top().second)));\n \
    \       }\n      }\n    }\n    bk.pop();\n  }\n  T get(){\n    T ans1 = E;\n \
    \   if (!fr.empty()){\n      ans1 = fr.top().second;\n    }\n    T ans2 = E;\n\
    \    if (!bk.empty()){\n      ans2 = bk.top().second;\n    }\n    return f(ans2,\
    \ ans1);\n  }\n};\n"
  code: "template <typename T>\nstruct swag{\n  function<T(T, T)> f;\n  T E;\n  stack<pair<T,\
    \ T>> fr, bk;\n  swag(function<T(T, T)> f, T E): f(f), E(E){\n  }\n  void push(T\
    \ x){\n    if (fr.empty()){\n      fr.push(make_pair(x, x));\n    } else {\n \
    \     fr.push(make_pair(x, f(fr.top().second, x)));\n    }\n  }\n  void pop(){\n\
    \    if (bk.empty()){\n      while (!fr.empty()){\n        T x = fr.top().first;\n\
    \        fr.pop();\n        if (bk.empty()){\n          bk.push(make_pair(x, x));\n\
    \        } else {\n          bk.push(make_pair(x, f(x, bk.top().second)));\n \
    \       }\n      }\n    }\n    bk.pop();\n  }\n  T get(){\n    T ans1 = E;\n \
    \   if (!fr.empty()){\n      ans1 = fr.top().second;\n    }\n    T ans2 = E;\n\
    \    if (!bk.empty()){\n      ans2 = bk.top().second;\n    }\n    return f(ans2,\
    \ ans1);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Sliding_Window_Aggregation.cpp
  requiredBy: []
  timestamp: '2021-12-01 17:42:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Sliding_Window_Aggregation.cpp
layout: document
redirect_from:
- /library/Data_Structures/Sliding_Window_Aggregation.cpp
- /library/Data_Structures/Sliding_Window_Aggregation.cpp.html
title: Data_Structures/Sliding_Window_Aggregation.cpp
---
