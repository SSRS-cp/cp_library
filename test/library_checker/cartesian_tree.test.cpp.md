---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/other/cartesian_tree_min.hpp
    title: "\u30C7\u30AB\u30EB\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/library_checker/cartesian_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"data_structure/other/cartesian_tree_min.hpp\"\n\
    /**\n * @brief \u30C7\u30AB\u30EB\u30C8\u6728\n*/\nvector<int> cartesian_tree_min(vector<int>\
    \ &A){\n  int N = A.size();\n  vector<int> pr(N, -1);\n  stack<int> st;\n  st.push(0);\n\
    \  for (int i = 1; i < N; i++){\n    int prev = -1;\n    while (!st.empty()){\n\
    \      int j = st.top();\n      if (A[i] < A[j]){\n        st.pop();\n       \
    \ if (prev != -1){\n          pr[prev] = j;\n        }\n        prev = j;\n  \
    \    } else {\n        break;\n      }\n    }\n    if (prev != -1){\n      pr[prev]\
    \ = i;\n    }\n    st.push(i);\n  }\n  while (st.size() >= 2){\n    int x = st.top();\n\
    \    st.pop();\n    pr[x] = st.top();\n  }\n  return pr;\n}\n#line 5 \"test/library_checker/cartesian_tree.test.cpp\"\
    \nint main(){\n  int N;\n  cin >> N;\n  vector<int> a(N);\n  for (int i = 0; i\
    \ < N; i++){\n    cin >> a[i];\n  }\n  vector<int> p = cartesian_tree_min(a);\n\
    \  for (int i = 0; i < N; i++){\n    if (p[i] == -1){\n      cout << i;\n    }\
    \ else {\n      cout << p[i];\n    }\n    if (i < N - 1){\n      cout << ' ';\n\
    \    }\n  }\n  cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../data_structure/other/cartesian_tree_min.hpp\"\
    \nint main(){\n  int N;\n  cin >> N;\n  vector<int> a(N);\n  for (int i = 0; i\
    \ < N; i++){\n    cin >> a[i];\n  }\n  vector<int> p = cartesian_tree_min(a);\n\
    \  for (int i = 0; i < N; i++){\n    if (p[i] == -1){\n      cout << i;\n    }\
    \ else {\n      cout << p[i];\n    }\n    if (i < N - 1){\n      cout << ' ';\n\
    \    }\n  }\n  cout << endl;\n}"
  dependsOn:
  - data_structure/other/cartesian_tree_min.hpp
  isVerificationFile: true
  path: test/library_checker/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/cartesian_tree.test.cpp
- /verify/test/library_checker/cartesian_tree.test.cpp.html
title: test/library_checker/cartesian_tree.test.cpp
---
