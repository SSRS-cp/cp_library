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
  bundledCode: "#line 1 \"Data_Structures/Segment_Tree.cpp\"\ntemplate <typename T>\n\
    struct segment_tree{\n\tint N;\n\tvector<T> ST;\n\tfunction<T(T, T)> f;\n\tT E;\n\
    \tsegment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){\n\t\tN = 1;\n\t\t\
    while (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, E);\n\t}\n\
    \tsegment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){\n\t\tint n\
    \ = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST =\
    \ vector<T>(N * 2 - 1, E);\n\t\tfor (int i = 0; i < n; i++){\n\t\t\tST[N - 1 +\
    \ i] = A[i];\n\t\t}\n\t\tfor (int i = N - 2; i >= 0; i--){\n\t\t\tST[i] = f(ST[i\
    \ * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t}\n\tT operator [](int k){\n\t\treturn ST[N\
    \ - 1 + k];\n\t}\n\tvoid update(int k, T x){\n\t\tk += N - 1;\n\t\tST[k] = x;\n\
    \t\twhile (k > 0){\n\t\t\tk = (k - 1) / 2;\n\t\t\tST[k] = f(ST[k * 2 + 1], ST[k\
    \ * 2 + 2]);\n\t\t}\n\t}\n\tT query(int L, int R, int i, int l, int r){\n\t\t\
    if (R <= l || r <= L){\n\t\t\treturn E;\n\t\t} else if (L <= l && r <= R){\n\t\
    \t\treturn ST[i];\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\t\treturn f(query(L,\
    \ R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));\n\t\t}\n\t}\n\tT query(int\
    \ L, int R){\n\t\treturn query(L, R, 0, 0, N);\n\t}\n\tT all(){\n\t\treturn ST[0];\n\
    \t}\n};\n"
  code: "template <typename T>\nstruct segment_tree{\n\tint N;\n\tvector<T> ST;\n\t\
    function<T(T, T)> f;\n\tT E;\n\tsegment_tree(int n, function<T(T, T)> f, T E):\
    \ f(f), E(E){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST =\
    \ vector<T>(N * 2 - 1, E);\n\t}\n\tsegment_tree(vector<T> A, function<T(T, T)>\
    \ f, T E): f(f), E(E){\n\t\tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\
    \t\t\tN *= 2;\n\t\t}\n\t\tST = vector<T>(N * 2 - 1, E);\n\t\tfor (int i = 0; i\
    \ < n; i++){\n\t\t\tST[N - 1 + i] = A[i];\n\t\t}\n\t\tfor (int i = N - 2; i >=\
    \ 0; i--){\n\t\t\tST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);\n\t\t}\n\t}\n\tT operator\
    \ [](int k){\n\t\treturn ST[N - 1 + k];\n\t}\n\tvoid update(int k, T x){\n\t\t\
    k += N - 1;\n\t\tST[k] = x;\n\t\twhile (k > 0){\n\t\t\tk = (k - 1) / 2;\n\t\t\t\
    ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);\n\t\t}\n\t}\n\tT query(int L, int R,\
    \ int i, int l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn E;\n\t\t} else\
    \ if (L <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint m = (l\
    \ + r) / 2;\n\t\t\treturn f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 +\
    \ 2, m, r));\n\t\t}\n\t}\n\tT query(int L, int R){\n\t\treturn query(L, R, 0,\
    \ 0, N);\n\t}\n\tT all(){\n\t\treturn ST[0];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Segment_Tree.cpp
  requiredBy: []
  timestamp: '2020-05-24 14:23:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Segment_Tree.cpp
layout: document
redirect_from:
- /library/Data_Structures/Segment_Tree.cpp
- /library/Data_Structures/Segment_Tree.cpp.html
title: Data_Structures/Segment_Tree.cpp
---
