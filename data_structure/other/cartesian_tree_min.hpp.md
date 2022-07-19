---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/cartesian_tree.test.cpp
    title: test/library_checker/tree/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C7\u30AB\u30EB\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"data_structure/other/cartesian_tree_min.hpp\"\n/**\n * @brief\
    \ \u30C7\u30AB\u30EB\u30C8\u6728\n*/\nvector<int> cartesian_tree_min(vector<int>\
    \ &A){\n  int N = A.size();\n  vector<int> pr(N, -1);\n  stack<int> st;\n  st.push(0);\n\
    \  for (int i = 1; i < N; i++){\n    int prev = -1;\n    while (!st.empty()){\n\
    \      int j = st.top();\n      if (A[i] < A[j]){\n        st.pop();\n       \
    \ if (prev != -1){\n          pr[prev] = j;\n        }\n        prev = j;\n  \
    \    } else {\n        break;\n      }\n    }\n    if (prev != -1){\n      pr[prev]\
    \ = i;\n    }\n    st.push(i);\n  }\n  while (st.size() >= 2){\n    int x = st.top();\n\
    \    st.pop();\n    pr[x] = st.top();\n  }\n  return pr;\n}\n"
  code: "#pragma once\n/**\n * @brief \u30C7\u30AB\u30EB\u30C8\u6728\n*/\nvector<int>\
    \ cartesian_tree_min(vector<int> &A){\n  int N = A.size();\n  vector<int> pr(N,\
    \ -1);\n  stack<int> st;\n  st.push(0);\n  for (int i = 1; i < N; i++){\n    int\
    \ prev = -1;\n    while (!st.empty()){\n      int j = st.top();\n      if (A[i]\
    \ < A[j]){\n        st.pop();\n        if (prev != -1){\n          pr[prev] =\
    \ j;\n        }\n        prev = j;\n      } else {\n        break;\n      }\n\
    \    }\n    if (prev != -1){\n      pr[prev] = i;\n    }\n    st.push(i);\n  }\n\
    \  while (st.size() >= 2){\n    int x = st.top();\n    st.pop();\n    pr[x] =\
    \ st.top();\n  }\n  return pr;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/other/cartesian_tree_min.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/cartesian_tree.test.cpp
documentation_of: data_structure/other/cartesian_tree_min.hpp
layout: document
redirect_from:
- /library/data_structure/other/cartesian_tree_min.hpp
- /library/data_structure/other/cartesian_tree_min.hpp.html
title: "\u30C7\u30AB\u30EB\u30C8\u6728"
---
