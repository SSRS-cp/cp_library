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
  bundledCode: "#line 1 \"Graph/Minimium_Cost_Arborescence.cpp\"\nint minimum_cost_arborescence(vector<vector<pair<int,\
    \ int>>> E, int r){\n\tint ans = 0;\n\twhile (true){\n\t\tint N = E.size();\n\t\
    \tvector<int> mn(N, INF), p(N, -1);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\t\
    for (auto P : E[i]){\n\t\t\t\tint c = P.first;\n\t\t\t\tint w = P.second;\n\t\t\
    \t\tif (w != r && mn[w] > c){\n\t\t\t\t\tmn[w] = c;\n\t\t\t\t\tp[w] = i;\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> d(N, 0);\n\t\tfor (int i = 0; i < N; i++){\n\
    \t\t\tif (i != r){\n\t\t\t\td[p[i]]++;\n\t\t\t}\n\t\t}\n\t\tqueue<int> Q;\n\t\t\
    for (int i = 0; i < N; i++){\n\t\t\tif (i != r && d[i] == 0){\n\t\t\t\tQ.push(i);\n\
    \t\t\t}\n\t\t}\n\t\twhile (!Q.empty()){\n\t\t\tint v = Q.front();\n\t\t\tQ.pop();\n\
    \t\t\tif (v != r){\n\t\t\t\td[p[v]]--;\n\t\t\t\tif (d[p[v]] == 0){\n\t\t\t\t\t\
    Q.push(p[v]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> cycle;\n\t\tvector<int>\
    \ id(N, -1);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tif (d[i] == 1){\n\t\t\t\t\
    cycle.push_back(i);\n\t\t\t\twhile (true){\n\t\t\t\t\tint v = cycle.back();\n\t\
    \t\t\t\tid[v] = 0;\n\t\t\t\t\tans += mn[v];\n\t\t\t\t\tif (p[v] == i){\n\t\t\t\
    \t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t\tcycle.push_back(p[v]);\n\t\t\t\t}\n\t\t\t\
    \tbreak;\n\t\t\t}\n\t\t}\n\t\tif (cycle.empty()){\n\t\t\tfor (int i = 0; i < N;\
    \ i++){\n\t\t\t\tif (i != r){\n\t\t\t\t\tans += mn[i];\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\tbreak;\n\t\t}\n\t\tint cnt = 1;\n\t\tfor (int i = 0; i < N; i++){\n\t\t\t\
    if (id[i] == -1){\n\t\t\t\tid[i] = cnt;\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\t\t\
    vector<vector<pair<int, int>>> E2(cnt);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\
    \tfor (auto P : E[i]){\n\t\t\t\tint c = P.first;\n\t\t\t\tint w = P.second;\n\t\
    \t\t\tif (id[w] == 0){\n\t\t\t\t\tc -= mn[w];\n\t\t\t\t}\n\t\t\t\tif (id[i] !=\
    \ id[w]){\n\t\t\t\t\tE2[id[i]].push_back(make_pair(c, id[w]));\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t\tswap(E, E2);\n\t\tswap(r, id[r]);\n\t}\n\treturn ans;\n}\n"
  code: "int minimum_cost_arborescence(vector<vector<pair<int, int>>> E, int r){\n\
    \tint ans = 0;\n\twhile (true){\n\t\tint N = E.size();\n\t\tvector<int> mn(N,\
    \ INF), p(N, -1);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tfor (auto P : E[i]){\n\
    \t\t\t\tint c = P.first;\n\t\t\t\tint w = P.second;\n\t\t\t\tif (w != r && mn[w]\
    \ > c){\n\t\t\t\t\tmn[w] = c;\n\t\t\t\t\tp[w] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\tvector<int> d(N, 0);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tif (i != r){\n\
    \t\t\t\td[p[i]]++;\n\t\t\t}\n\t\t}\n\t\tqueue<int> Q;\n\t\tfor (int i = 0; i <\
    \ N; i++){\n\t\t\tif (i != r && d[i] == 0){\n\t\t\t\tQ.push(i);\n\t\t\t}\n\t\t\
    }\n\t\twhile (!Q.empty()){\n\t\t\tint v = Q.front();\n\t\t\tQ.pop();\n\t\t\tif\
    \ (v != r){\n\t\t\t\td[p[v]]--;\n\t\t\t\tif (d[p[v]] == 0){\n\t\t\t\t\tQ.push(p[v]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> cycle;\n\t\tvector<int> id(N, -1);\n\
    \t\tfor (int i = 0; i < N; i++){\n\t\t\tif (d[i] == 1){\n\t\t\t\tcycle.push_back(i);\n\
    \t\t\t\twhile (true){\n\t\t\t\t\tint v = cycle.back();\n\t\t\t\t\tid[v] = 0;\n\
    \t\t\t\t\tans += mn[v];\n\t\t\t\t\tif (p[v] == i){\n\t\t\t\t\t\tbreak;\n\t\t\t\
    \t\t}\n\t\t\t\t\tcycle.push_back(p[v]);\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\t}\n\t\
    \t}\n\t\tif (cycle.empty()){\n\t\t\tfor (int i = 0; i < N; i++){\n\t\t\t\tif (i\
    \ != r){\n\t\t\t\t\tans += mn[i];\n\t\t\t\t}\n\t\t\t}\n\t\t\tbreak;\n\t\t}\n\t\
    \tint cnt = 1;\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tif (id[i] == -1){\n\t\t\
    \t\tid[i] = cnt;\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\t\tvector<vector<pair<int,\
    \ int>>> E2(cnt);\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tfor (auto P : E[i]){\n\
    \t\t\t\tint c = P.first;\n\t\t\t\tint w = P.second;\n\t\t\t\tif (id[w] == 0){\n\
    \t\t\t\t\tc -= mn[w];\n\t\t\t\t}\n\t\t\t\tif (id[i] != id[w]){\n\t\t\t\t\tE2[id[i]].push_back(make_pair(c,\
    \ id[w]));\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tswap(E, E2);\n\t\tswap(r, id[r]);\n\
    \t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Minimium_Cost_Arborescence.cpp
  requiredBy: []
  timestamp: '2021-04-13 08:12:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Minimium_Cost_Arborescence.cpp
layout: document
redirect_from:
- /library/Graph/Minimium_Cost_Arborescence.cpp
- /library/Graph/Minimium_Cost_Arborescence.cpp.html
title: Graph/Minimium_Cost_Arborescence.cpp
---
