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
  bundledCode: "#line 1 \"old_Data_Structures/Euler_Tour_Path_Query.cpp\"\ntemplate\
    \ <typename T>\nstruct euler_tour_path_query{\n\tlowest_common_ancestor G;\n\t\
    vector<T> A;\n\tvector<int> left;\n\tvector<int> right;\n\tT E;\n\tfunction<T(T,\
    \ T)> f;\n\tfunction<T(T)> inv;\n\tbidirectional_segment_tree<T> ST;\n\tvoid dfs(int\
    \ v, vector<vector<int>> &c, vector<T> &a){\n\t\tleft[v] = A.size();\n\t\tA.push_back(a[v]);\n\
    \t\tfor (int w : c[v]){\n\t\t\tdfs(w, c, a);\n\t\t}\n\t\tright[v] = A.size();\n\
    \t\tA.push_back(inv(a[v]));\n\t}\n\teuler_tour_path_query(vector<int> &p, vector<vector<int>>\
    \ &c, vector<T> &a, function<T(T, T)> f, T E, function<T(T)> inv): f(f), E(E),\
    \ inv(inv){\n\t\tint N = p.size();\n\t\tG = lowest_common_ancestor(p, c);\n\t\t\
    left = vector<int>(N);\n\t\tright = vector<int>(N);\n\t\tdfs(0, c, a);\n\t\tST\
    \ = bidirectional_segment_tree<T>(A, f, E);\n\t}\n\toperator [](int v){\n\t\t\
    return A[left[v]];\n\t}\n\tvoid update(int v, T x){\n\t\tST.update(left[v], x);\n\
    \t\tST.update(right[v], inv(x));\n\t}\n\tT query(int v, int w){\n\t\tint u = G.lca(v,\
    \ w);\n\t\treturn f(ST.query(left[u] + 1, left[v] + 1, 1), ST.query(left[u], left[w]\
    \ + 1, 0));\n\t}\n};\n"
  code: "template <typename T>\nstruct euler_tour_path_query{\n\tlowest_common_ancestor\
    \ G;\n\tvector<T> A;\n\tvector<int> left;\n\tvector<int> right;\n\tT E;\n\tfunction<T(T,\
    \ T)> f;\n\tfunction<T(T)> inv;\n\tbidirectional_segment_tree<T> ST;\n\tvoid dfs(int\
    \ v, vector<vector<int>> &c, vector<T> &a){\n\t\tleft[v] = A.size();\n\t\tA.push_back(a[v]);\n\
    \t\tfor (int w : c[v]){\n\t\t\tdfs(w, c, a);\n\t\t}\n\t\tright[v] = A.size();\n\
    \t\tA.push_back(inv(a[v]));\n\t}\n\teuler_tour_path_query(vector<int> &p, vector<vector<int>>\
    \ &c, vector<T> &a, function<T(T, T)> f, T E, function<T(T)> inv): f(f), E(E),\
    \ inv(inv){\n\t\tint N = p.size();\n\t\tG = lowest_common_ancestor(p, c);\n\t\t\
    left = vector<int>(N);\n\t\tright = vector<int>(N);\n\t\tdfs(0, c, a);\n\t\tST\
    \ = bidirectional_segment_tree<T>(A, f, E);\n\t}\n\toperator [](int v){\n\t\t\
    return A[left[v]];\n\t}\n\tvoid update(int v, T x){\n\t\tST.update(left[v], x);\n\
    \t\tST.update(right[v], inv(x));\n\t}\n\tT query(int v, int w){\n\t\tint u = G.lca(v,\
    \ w);\n\t\treturn f(ST.query(left[u] + 1, left[v] + 1, 1), ST.query(left[u], left[w]\
    \ + 1, 0));\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Data_Structures/Euler_Tour_Path_Query.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Data_Structures/Euler_Tour_Path_Query.cpp
layout: document
redirect_from:
- /library/old_Data_Structures/Euler_Tour_Path_Query.cpp
- /library/old_Data_Structures/Euler_Tour_Path_Query.cpp.html
title: old_Data_Structures/Euler_Tour_Path_Query.cpp
---
