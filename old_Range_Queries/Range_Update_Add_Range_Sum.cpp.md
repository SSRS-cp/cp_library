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
  bundledCode: "#line 1 \"old_Range_Queries/Range_Update_Add_Range_Sum.cpp\"\n//Range\
    \ Update Add Range Sum\ntemplate <typename T>\nstruct lazy_segment_tree{\n\tint\
    \ N;\n\tvector<T> ST;\n\tvector<pair<int, T>> lazy;\n\tlazy_segment_tree(){\n\t\
    }\n\tlazy_segment_tree(int n){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\
    \t\t}\n\t\tST = vector<T>(N * 2 - 1, 0);\n\t\tlazy = vector<pair<int, T>>(N *\
    \ 2 - 1, make_pair(1, 0));\n\t}\n\tvoid eval(int i, int l, int r){\n\t\tif (i\
    \ < N - 1){\n\t\t\tif (lazy[i].first == 0){\n\t\t\t\tlazy[i * 2 + 1] = lazy[i];\n\
    \t\t\t\tlazy[i * 2 + 2] = lazy[i];\n\t\t\t} else {\n\t\t\t\tlazy[i * 2 + 1].second\
    \ += lazy[i].second;\n\t\t\t\tlazy[i * 2 + 2].second += lazy[i].second;\n\t\t\t\
    }\n\t\t}\n\t\tST[i] = ST[i] * lazy[i].first + lazy[i].second * (r - l);\n\t\t\
    lazy[i] = make_pair(1, 0);\n\t}\n\tvoid update(int L, int R, T x, int t, int i,\
    \ int l, int r){\n\t\teval(i, l, r);\n\t\tif (r <= L || R <= l){\n\t\t\treturn;\n\
    \t\t} else if (L <= l && r <= R){\n\t\t\tlazy[i] = make_pair(t, x);\n\t\t\teval(i,\
    \ l, r);\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\t\tupdate(L, R, x, t, i\
    \ * 2 + 1, l, m);\n\t\t\tupdate(L, R, x, t, i * 2 + 2, m, r);\n\t\t\tST[i] = ST[i\
    \ * 2 + 1] + ST[i * 2 + 2];\n\t\t}\n\t}\n\tvoid range_update(int L, int R, T x){\n\
    \t\tupdate(L, R, x, 0, 0, 0, N);\n\t}\n\tvoid range_add(int L, int R, T x){\n\t\
    \tupdate(L, R, x, 1, 0, 0, N);\n\t}\n\tT range_sum(int L, int R, int i, int l,\
    \ int r){\n\t\teval(i, l, r);\n\t\tif (r <= L || R <= l){\n\t\t\treturn 0;\n\t\
    \t} else if (L <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint\
    \ m = (l + r) / 2;\n\t\t\treturn range_sum(L, R, i * 2 + 1, l, m) + range_sum(L,\
    \ R, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tT range_sum(int L, int R){\n\t\treturn range_sum(L,\
    \ R, 0, 0, N);\n\t}\n};\n"
  code: "//Range Update Add Range Sum\ntemplate <typename T>\nstruct lazy_segment_tree{\n\
    \tint N;\n\tvector<T> ST;\n\tvector<pair<int, T>> lazy;\n\tlazy_segment_tree(){\n\
    \t}\n\tlazy_segment_tree(int n){\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\
    \t\t}\n\t\tST = vector<T>(N * 2 - 1, 0);\n\t\tlazy = vector<pair<int, T>>(N *\
    \ 2 - 1, make_pair(1, 0));\n\t}\n\tvoid eval(int i, int l, int r){\n\t\tif (i\
    \ < N - 1){\n\t\t\tif (lazy[i].first == 0){\n\t\t\t\tlazy[i * 2 + 1] = lazy[i];\n\
    \t\t\t\tlazy[i * 2 + 2] = lazy[i];\n\t\t\t} else {\n\t\t\t\tlazy[i * 2 + 1].second\
    \ += lazy[i].second;\n\t\t\t\tlazy[i * 2 + 2].second += lazy[i].second;\n\t\t\t\
    }\n\t\t}\n\t\tST[i] = ST[i] * lazy[i].first + lazy[i].second * (r - l);\n\t\t\
    lazy[i] = make_pair(1, 0);\n\t}\n\tvoid update(int L, int R, T x, int t, int i,\
    \ int l, int r){\n\t\teval(i, l, r);\n\t\tif (r <= L || R <= l){\n\t\t\treturn;\n\
    \t\t} else if (L <= l && r <= R){\n\t\t\tlazy[i] = make_pair(t, x);\n\t\t\teval(i,\
    \ l, r);\n\t\t} else {\n\t\t\tint m = (l + r) / 2;\n\t\t\tupdate(L, R, x, t, i\
    \ * 2 + 1, l, m);\n\t\t\tupdate(L, R, x, t, i * 2 + 2, m, r);\n\t\t\tST[i] = ST[i\
    \ * 2 + 1] + ST[i * 2 + 2];\n\t\t}\n\t}\n\tvoid range_update(int L, int R, T x){\n\
    \t\tupdate(L, R, x, 0, 0, 0, N);\n\t}\n\tvoid range_add(int L, int R, T x){\n\t\
    \tupdate(L, R, x, 1, 0, 0, N);\n\t}\n\tT range_sum(int L, int R, int i, int l,\
    \ int r){\n\t\teval(i, l, r);\n\t\tif (r <= L || R <= l){\n\t\t\treturn 0;\n\t\
    \t} else if (L <= l && r <= R){\n\t\t\treturn ST[i];\n\t\t} else {\n\t\t\tint\
    \ m = (l + r) / 2;\n\t\t\treturn range_sum(L, R, i * 2 + 1, l, m) + range_sum(L,\
    \ R, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tT range_sum(int L, int R){\n\t\treturn range_sum(L,\
    \ R, 0, 0, N);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Range_Queries/Range_Update_Add_Range_Sum.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Range_Queries/Range_Update_Add_Range_Sum.cpp
layout: document
redirect_from:
- /library/old_Range_Queries/Range_Update_Add_Range_Sum.cpp
- /library/old_Range_Queries/Range_Update_Add_Range_Sum.cpp.html
title: old_Range_Queries/Range_Update_Add_Range_Sum.cpp
---
