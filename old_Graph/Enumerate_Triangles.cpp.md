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
  bundledCode: "#line 1 \"old_Graph/Enumerate_Triangles.cpp\"\nvector<tuple<int, int,\
    \ int>> enumerate_triangles(vector<vector<int>> &E){\n\tint N = E.size();\n\t\
    vector<int> d(N);\n\tfor (int i = 0; i < N; i++){\n\t\td[i] = E[i].size();\n\t\
    }\n\tvector<vector<int>> E2(N);\n\tfor (int i = 0; i < N; i++){\n\t\tfor (int\
    \ j : E[i]){\n\t\t\tif (d[i] < d[j] || d[i] == d[j] && i < j){\n\t\t\t\tE2[i].push_back(j);\n\
    \t\t\t}\n\t\t}\n\t}\n\tvector<bool> flg(N, false);\n\tvector<tuple<int, int, int>>\
    \ ans;\n\tfor (int i = 0; i < N; i++){\n\t\tfor (int j : E2[i]){\n\t\t\tfor (int\
    \ k : E2[i]){\n\t\t\t\tflg[k] = true;\n\t\t\t}\n\t\t\tfor (int k : E2[j]){\n\t\
    \t\t\tif (flg[k]){\n\t\t\t\t\tans.push_back(make_tuple(i, j, k));\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tfor (int k : E2[i]){\n\t\t\t\tflg[k] = false;\n\t\t\t}\n\t\t}\n\
    \t}\n\treturn ans;\n}\n"
  code: "vector<tuple<int, int, int>> enumerate_triangles(vector<vector<int>> &E){\n\
    \tint N = E.size();\n\tvector<int> d(N);\n\tfor (int i = 0; i < N; i++){\n\t\t\
    d[i] = E[i].size();\n\t}\n\tvector<vector<int>> E2(N);\n\tfor (int i = 0; i <\
    \ N; i++){\n\t\tfor (int j : E[i]){\n\t\t\tif (d[i] < d[j] || d[i] == d[j] &&\
    \ i < j){\n\t\t\t\tE2[i].push_back(j);\n\t\t\t}\n\t\t}\n\t}\n\tvector<bool> flg(N,\
    \ false);\n\tvector<tuple<int, int, int>> ans;\n\tfor (int i = 0; i < N; i++){\n\
    \t\tfor (int j : E2[i]){\n\t\t\tfor (int k : E2[i]){\n\t\t\t\tflg[k] = true;\n\
    \t\t\t}\n\t\t\tfor (int k : E2[j]){\n\t\t\t\tif (flg[k]){\n\t\t\t\t\tans.push_back(make_tuple(i,\
    \ j, k));\n\t\t\t\t}\n\t\t\t}\n\t\t\tfor (int k : E2[i]){\n\t\t\t\tflg[k] = false;\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Enumerate_Triangles.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Enumerate_Triangles.cpp
layout: document
redirect_from:
- /library/old_Graph/Enumerate_Triangles.cpp
- /library/old_Graph/Enumerate_Triangles.cpp.html
title: old_Graph/Enumerate_Triangles.cpp
---
