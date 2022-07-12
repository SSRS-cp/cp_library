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
  bundledCode: "#line 1 \"Range_Queries/Range_Update_Point_Value.cpp\"\n//Range Update\
    \ Point Value\ntemplate <typename T>\nstruct dual_segment_tree{\n\tint N;\n\t\
    vector<pair<T, int>> ST;\n\tint t;\n\tdual_segment_tree(int n){\n\t\tN = 1;\n\t\
    \twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<pair<T, int>>(N * 2 -\
    \ 1, make_pair(0, 0));\n\t\tt = 1;\n\t}\n\tdual_segment_tree(vector<T> A){\n\t\
    \tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\t\
    ST = vector<pair<T, int>>(N * 2 - 1, make_pair(0, 0));\n\t\tfor (int i = 0; i\
    \ < n; i++){\n\t\t\tST[N - 1 + i] = make_pair(A[i], 1);\n\t\t}\n\t\tt = 2;\n\t\
    }\n\tT operator [](int k){\n\t\tk += N - 1;\n\t\tT ans = ST[k].first;\n\t\tT time\
    \ = ST[k].second;\n\t\twhile (k > 0){\n\t\t\tk = (k - 1) / 2;\n\t\t\tif (ST[k].second\
    \ > time){\n\t\t\t\tans = ST[k].first;\n\t\t\t\ttime = ST[k].second;\n\t\t\t}\n\
    \t\t}\n\t\treturn ans;\n\t}\n\tvoid range_update(int L, int R, T x, int i, int\
    \ l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn;\n\t\t} else if (L <= l\
    \ && r <= R){\n\t\t\tST[i] = make_pair(x, t);\n\t\t} else {\n\t\t\tint m = (l\
    \ + r) / 2;\n\t\t\trange_update(L, R, x, i * 2 + 1, l, m);\n\t\t\trange_update(L,\
    \ R, x, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tvoid range_update(int L, int R, T x){\n\
    \t\trange_update(L, R, x, 0, 0, N);\n\t\tt++;\n\t}\n};\n"
  code: "//Range Update Point Value\ntemplate <typename T>\nstruct dual_segment_tree{\n\
    \tint N;\n\tvector<pair<T, int>> ST;\n\tint t;\n\tdual_segment_tree(int n){\n\t\
    \tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tST = vector<pair<T, int>>(N\
    \ * 2 - 1, make_pair(0, 0));\n\t\tt = 1;\n\t}\n\tdual_segment_tree(vector<T> A){\n\
    \t\tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\
    \tST = vector<pair<T, int>>(N * 2 - 1, make_pair(0, 0));\n\t\tfor (int i = 0;\
    \ i < n; i++){\n\t\t\tST[N - 1 + i] = make_pair(A[i], 1);\n\t\t}\n\t\tt = 2;\n\
    \t}\n\tT operator [](int k){\n\t\tk += N - 1;\n\t\tT ans = ST[k].first;\n\t\t\
    T time = ST[k].second;\n\t\twhile (k > 0){\n\t\t\tk = (k - 1) / 2;\n\t\t\tif (ST[k].second\
    \ > time){\n\t\t\t\tans = ST[k].first;\n\t\t\t\ttime = ST[k].second;\n\t\t\t}\n\
    \t\t}\n\t\treturn ans;\n\t}\n\tvoid range_update(int L, int R, T x, int i, int\
    \ l, int r){\n\t\tif (R <= l || r <= L){\n\t\t\treturn;\n\t\t} else if (L <= l\
    \ && r <= R){\n\t\t\tST[i] = make_pair(x, t);\n\t\t} else {\n\t\t\tint m = (l\
    \ + r) / 2;\n\t\t\trange_update(L, R, x, i * 2 + 1, l, m);\n\t\t\trange_update(L,\
    \ R, x, i * 2 + 2, m, r);\n\t\t}\n\t}\n\tvoid range_update(int L, int R, T x){\n\
    \t\trange_update(L, R, x, 0, 0, N);\n\t\tt++;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Range_Queries/Range_Update_Point_Value.cpp
  requiredBy: []
  timestamp: '2020-10-08 22:39:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Range_Queries/Range_Update_Point_Value.cpp
layout: document
redirect_from:
- /library/Range_Queries/Range_Update_Point_Value.cpp
- /library/Range_Queries/Range_Update_Point_Value.cpp.html
title: Range_Queries/Range_Update_Point_Value.cpp
---
