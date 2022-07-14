---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/queue_operate_all_composite.test.cpp
    title: test/library_checker/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Sliding Window Aggregation
    links: []
  bundledCode: "#line 1 \"data_structure/other/sliding_window_aggregation.cpp\"\n\
    template <typename T>\nstruct sliding_window_aggregation{\n  function<T(T, T)>\
    \ f;\n  T E;\n  stack<pair<T, T>> fr, bk;\n  sliding_window_aggregation(function<T(T,\
    \ T)> f, T E): f(f), E(E){\n  }\n  void push(T x){\n    if (fr.empty()){\n   \
    \   fr.push(make_pair(x, x));\n    } else {\n      fr.push(make_pair(x, f(fr.top().second,\
    \ x)));\n    }\n  }\n  void pop(){\n    if (bk.empty()){\n      while (!fr.empty()){\n\
    \        T x = fr.top().first;\n        fr.pop();\n        if (bk.empty()){\n\
    \          bk.push(make_pair(x, x));\n        } else {\n          bk.push(make_pair(x,\
    \ f(x, bk.top().second)));\n        }\n      }\n    }\n    bk.pop();\n  }\n  T\
    \ get(){\n    T ans1 = E;\n    if (!fr.empty()){\n      ans1 = fr.top().second;\n\
    \    }\n    T ans2 = E;\n    if (!bk.empty()){\n      ans2 = bk.top().second;\n\
    \    }\n    return f(ans2, ans1);\n  }\n};\n/**\n * @brief Sliding Window Aggregation\n\
    */\n"
  code: "template <typename T>\nstruct sliding_window_aggregation{\n  function<T(T,\
    \ T)> f;\n  T E;\n  stack<pair<T, T>> fr, bk;\n  sliding_window_aggregation(function<T(T,\
    \ T)> f, T E): f(f), E(E){\n  }\n  void push(T x){\n    if (fr.empty()){\n   \
    \   fr.push(make_pair(x, x));\n    } else {\n      fr.push(make_pair(x, f(fr.top().second,\
    \ x)));\n    }\n  }\n  void pop(){\n    if (bk.empty()){\n      while (!fr.empty()){\n\
    \        T x = fr.top().first;\n        fr.pop();\n        if (bk.empty()){\n\
    \          bk.push(make_pair(x, x));\n        } else {\n          bk.push(make_pair(x,\
    \ f(x, bk.top().second)));\n        }\n      }\n    }\n    bk.pop();\n  }\n  T\
    \ get(){\n    T ans1 = E;\n    if (!fr.empty()){\n      ans1 = fr.top().second;\n\
    \    }\n    T ans2 = E;\n    if (!bk.empty()){\n      ans2 = bk.top().second;\n\
    \    }\n    return f(ans2, ans1);\n  }\n};\n/**\n * @brief Sliding Window Aggregation\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/other/sliding_window_aggregation.cpp
  requiredBy: []
  timestamp: '2022-07-15 08:42:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/queue_operate_all_composite.test.cpp
documentation_of: data_structure/other/sliding_window_aggregation.cpp
layout: document
redirect_from:
- /library/data_structure/other/sliding_window_aggregation.cpp
- /library/data_structure/other/sliding_window_aggregation.cpp.html
title: Sliding Window Aggregation
---
