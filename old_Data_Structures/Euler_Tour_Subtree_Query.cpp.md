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
  bundledCode: "#line 1 \"old_Data_Structures/Euler_Tour_Subtree_Query.cpp\"\ntemplate\
    \ <typename T>\nstruct euler_tour_subtree_query{\n\tvector<int> left;\n\tvector<int>\
    \ right;\n\tvector<T> A;\n\tT E;\n\tfunction<T(T, T)> f;\n\tsegment_tree<T> ST;\n\
    \tvoid dfs(int v, vector<vector<int>> &c, vector<T> &a){\n\t\tleft[v] = A.size();\n\
    \t\tA.push_back(a[v]);\n\t\tfor (int w : c[v]){\n\t\t\tdfs(w, c, a);\n\t\t}\n\t\
    \tright[v] = A.size();\n\t}\n\teuler_tour_subtree_query(vector<vector<int>> &c,\
    \ vector<T> &a, function<T(T, T)> f, T E): f(f), E(E){\n\t\tint N = c.size();\n\
    \t\tleft = vector<int>(N);\n\t\tright = vector<int>(N);\n\t\tdfs(0, c, a);\n\t\
    \tST = segment_tree<T>(A, f, E);\n\t}\n\tT operator [](int v){\n\t\treturn A[left[v]];\n\
    \t}\n\tvoid update(int v, T x){\n\t\tA[left[v]] = x;\n\t\tST.update(left[v], x);\n\
    \t}\n\tT query(int v){\n\t\treturn ST.query(left[v], right[v]);\n\t}\n};\n"
  code: "template <typename T>\nstruct euler_tour_subtree_query{\n\tvector<int> left;\n\
    \tvector<int> right;\n\tvector<T> A;\n\tT E;\n\tfunction<T(T, T)> f;\n\tsegment_tree<T>\
    \ ST;\n\tvoid dfs(int v, vector<vector<int>> &c, vector<T> &a){\n\t\tleft[v] =\
    \ A.size();\n\t\tA.push_back(a[v]);\n\t\tfor (int w : c[v]){\n\t\t\tdfs(w, c,\
    \ a);\n\t\t}\n\t\tright[v] = A.size();\n\t}\n\teuler_tour_subtree_query(vector<vector<int>>\
    \ &c, vector<T> &a, function<T(T, T)> f, T E): f(f), E(E){\n\t\tint N = c.size();\n\
    \t\tleft = vector<int>(N);\n\t\tright = vector<int>(N);\n\t\tdfs(0, c, a);\n\t\
    \tST = segment_tree<T>(A, f, E);\n\t}\n\tT operator [](int v){\n\t\treturn A[left[v]];\n\
    \t}\n\tvoid update(int v, T x){\n\t\tA[left[v]] = x;\n\t\tST.update(left[v], x);\n\
    \t}\n\tT query(int v){\n\t\treturn ST.query(left[v], right[v]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Data_Structures/Euler_Tour_Subtree_Query.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Data_Structures/Euler_Tour_Subtree_Query.cpp
layout: document
redirect_from:
- /library/old_Data_Structures/Euler_Tour_Subtree_Query.cpp
- /library/old_Data_Structures/Euler_Tour_Subtree_Query.cpp.html
title: old_Data_Structures/Euler_Tour_Subtree_Query.cpp
---
