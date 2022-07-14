---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/cartesian_tree.test.cpp
    title: test/library_checker/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/other/cartesian_tree_min.cpp\"\nvector<int>\
    \ cartesian_tree_min(vector<int> &A){\n  int N = A.size();\n  vector<int> pr(N,\
    \ -1);\n  stack<int> st;\n  st.push(0);\n  for (int i = 1; i < N; i++){\n    int\
    \ prev = -1;\n    while (!st.empty()){\n      int j = st.top();\n      if (A[i]\
    \ < A[j]){\n        st.pop();\n        if (prev != -1){\n          pr[prev] =\
    \ j;\n        }\n        prev = j;\n      } else {\n        break;\n      }\n\
    \    }\n    if (prev != -1){\n      pr[prev] = i;\n    }\n    st.push(i);\n  }\n\
    \  while (st.size() >= 2){\n    int x = st.top();\n    st.pop();\n    pr[x] =\
    \ st.top();\n  }\n  return pr;\n}\n"
  code: "vector<int> cartesian_tree_min(vector<int> &A){\n  int N = A.size();\n  vector<int>\
    \ pr(N, -1);\n  stack<int> st;\n  st.push(0);\n  for (int i = 1; i < N; i++){\n\
    \    int prev = -1;\n    while (!st.empty()){\n      int j = st.top();\n     \
    \ if (A[i] < A[j]){\n        st.pop();\n        if (prev != -1){\n          pr[prev]\
    \ = j;\n        }\n        prev = j;\n      } else {\n        break;\n      }\n\
    \    }\n    if (prev != -1){\n      pr[prev] = i;\n    }\n    st.push(i);\n  }\n\
    \  while (st.size() >= 2){\n    int x = st.top();\n    st.pop();\n    pr[x] =\
    \ st.top();\n  }\n  return pr;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/other/cartesian_tree_min.cpp
  requiredBy: []
  timestamp: '2022-07-15 08:34:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/cartesian_tree.test.cpp
documentation_of: data_structure/other/cartesian_tree_min.cpp
layout: document
redirect_from:
- /library/data_structure/other/cartesian_tree_min.cpp
- /library/data_structure/other/cartesian_tree_min.cpp.html
title: data_structure/other/cartesian_tree_min.cpp
---
