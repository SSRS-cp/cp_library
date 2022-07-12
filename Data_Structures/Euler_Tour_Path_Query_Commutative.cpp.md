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
  bundledCode: "#line 1 \"Data_Structures/Euler_Tour_Path_Query_Commutative.cpp\"\n\
    template <typename T>\nstruct euler_tour_path_query_commutative{\n\tlowest_common_ancestor\
    \ G;\n\tvector<T> A;\n\tvector<int> left;\n\tvector<int> right;\n\tT E;\n\tfunction<T(T,\
    \ T)> f;\n\tfunction<T(T)> inv;\n\tsegment_tree<T> ST;\n\tvoid dfs(int v, vector<vector<int>>\
    \ &c, vector<T> &a){\n\t\tleft[v] = A.size();\n\t\tA.push_back(a[v]);\n\t\tfor\
    \ (int w : c[v]){\n\t\t\tdfs(w, c, a);\n\t\t}\n\t\tright[v] = A.size();\n\t\t\
    A.push_back(inv(a[v]));\n\t}\n\teuler_tour_path_query_commutative(vector<int>\
    \ &p, vector<vector<int>> &c, vector<T> &a, function<T(T, T)> f, T E, function<T(T)>\
    \ inv): f(f), E(E), inv(inv){\n\t\tint N = p.size();\n\t\tG = lowest_common_ancestor(p,\
    \ c);\n\t\tleft = vector<int>(N);\n\t\tright = vector<int>(N);\n\t\tdfs(0, c,\
    \ a);\n\t\tST = segment_tree<T>(A, f, E);\n\t}\n\toperator [](int v){\n\t\treturn\
    \ A[left[v]];\n\t}\n\tvoid update(int v, T x){\n\t\tA[left[v]] = x;\n\t\tA[right[v]]\
    \ = inv(x);\n\t\tST.update(left[v], x);\n\t\tST.update(right[v], inv(x));\n\t\
    }\n\tT query(int v, int w){\n\t\tint u = G.lca(v, w);\n\t\treturn f(f(ST.query(left[u],\
    \ left[v] + 1), ST.query(left[u], left[w] + 1)), inv(A[left[u]]));\n\t}\n};\n"
  code: "template <typename T>\nstruct euler_tour_path_query_commutative{\n\tlowest_common_ancestor\
    \ G;\n\tvector<T> A;\n\tvector<int> left;\n\tvector<int> right;\n\tT E;\n\tfunction<T(T,\
    \ T)> f;\n\tfunction<T(T)> inv;\n\tsegment_tree<T> ST;\n\tvoid dfs(int v, vector<vector<int>>\
    \ &c, vector<T> &a){\n\t\tleft[v] = A.size();\n\t\tA.push_back(a[v]);\n\t\tfor\
    \ (int w : c[v]){\n\t\t\tdfs(w, c, a);\n\t\t}\n\t\tright[v] = A.size();\n\t\t\
    A.push_back(inv(a[v]));\n\t}\n\teuler_tour_path_query_commutative(vector<int>\
    \ &p, vector<vector<int>> &c, vector<T> &a, function<T(T, T)> f, T E, function<T(T)>\
    \ inv): f(f), E(E), inv(inv){\n\t\tint N = p.size();\n\t\tG = lowest_common_ancestor(p,\
    \ c);\n\t\tleft = vector<int>(N);\n\t\tright = vector<int>(N);\n\t\tdfs(0, c,\
    \ a);\n\t\tST = segment_tree<T>(A, f, E);\n\t}\n\toperator [](int v){\n\t\treturn\
    \ A[left[v]];\n\t}\n\tvoid update(int v, T x){\n\t\tA[left[v]] = x;\n\t\tA[right[v]]\
    \ = inv(x);\n\t\tST.update(left[v], x);\n\t\tST.update(right[v], inv(x));\n\t\
    }\n\tT query(int v, int w){\n\t\tint u = G.lca(v, w);\n\t\treturn f(f(ST.query(left[u],\
    \ left[v] + 1), ST.query(left[u], left[w] + 1)), inv(A[left[u]]));\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Euler_Tour_Path_Query_Commutative.cpp
  requiredBy: []
  timestamp: '2020-06-06 22:09:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Euler_Tour_Path_Query_Commutative.cpp
layout: document
redirect_from:
- /library/Data_Structures/Euler_Tour_Path_Query_Commutative.cpp
- /library/Data_Structures/Euler_Tour_Path_Query_Commutative.cpp.html
title: Data_Structures/Euler_Tour_Path_Query_Commutative.cpp
---