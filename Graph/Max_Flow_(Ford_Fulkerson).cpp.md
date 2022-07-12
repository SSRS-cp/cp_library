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
  bundledCode: "#line 1 \"Graph/Max_Flow_(Ford_Fulkerson).cpp\"\ntemplate <typename\
    \ Cap>\nstruct ford_fulkerson{\n\tstruct edge{\n\t\tint to, rev;\n\t\tCap cap;\n\
    \t\tedge(int to, int rev, Cap cap): to(to), rev(rev), cap(cap){\n\t\t}\n\t};\n\
    \tint N;\n\tvector<vector<edge>> G;\n\tford_fulkerson(){\n\t}\n\tford_fulkerson(int\
    \ N): N(N), G(N){\n\t}\n\tvoid add_edge(int from, int to, Cap cap){\n\t\tint id1\
    \ = G[from].size();\n\t\tint id2 = G[to].size();\n\t\tG[from].push_back(edge(to,\
    \ id2, cap));\n\t\tG[to].push_back(edge(from, id1, 0));\n\t}\n\tCap max_flow(int\
    \ s, int t){\n\t\tCap flow = 0;\n\t\twhile (1){\n\t\t\tvector<Cap> m(N, INF);\n\
    \t\t\tvector<int> pv(N, -1);\n\t\t\tvector<int> pe(N, -1);\n\t\t\tvector<bool>\
    \ used(N, false);\n\t\t\tqueue<int> Q;\n\t\t\tQ.push(s);\n\t\t\tused[s] = true;\n\
    \t\t\twhile (!Q.empty()){\n\t\t\t\tint v = Q.front();\n\t\t\t\tQ.pop();\n\t\t\t\
    \tint cnt = G[v].size();\n\t\t\t\tfor (int i = 0; i < cnt; i++){\n\t\t\t\t\tint\
    \ w = G[v][i].to;\n\t\t\t\t\tif (!used[w] && G[v][i].cap > 0){\n\t\t\t\t\t\tused[w]\
    \ = true;\n\t\t\t\t\t\tm[w] = min(m[v], G[v][i].cap);\n\t\t\t\t\t\tpv[w] = v;\n\
    \t\t\t\t\t\tpe[w] = i;\n\t\t\t\t\t\tQ.push(w);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\tif (!used[t]){\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tCap f = m[t];\n\t\t\t\
    for (int i = t; i != s; i = pv[i]){\n\t\t\t\tG[pv[i]][pe[i]].cap -= f;\n\t\t\t\
    \tG[i][G[pv[i]][pe[i]].rev].cap += f;\n\t\t\t}\n\t\t\tflow += f;\n\t\t}\n\t\t\
    return flow;\n\t}\n};\n"
  code: "template <typename Cap>\nstruct ford_fulkerson{\n\tstruct edge{\n\t\tint\
    \ to, rev;\n\t\tCap cap;\n\t\tedge(int to, int rev, Cap cap): to(to), rev(rev),\
    \ cap(cap){\n\t\t}\n\t};\n\tint N;\n\tvector<vector<edge>> G;\n\tford_fulkerson(){\n\
    \t}\n\tford_fulkerson(int N): N(N), G(N){\n\t}\n\tvoid add_edge(int from, int\
    \ to, Cap cap){\n\t\tint id1 = G[from].size();\n\t\tint id2 = G[to].size();\n\t\
    \tG[from].push_back(edge(to, id2, cap));\n\t\tG[to].push_back(edge(from, id1,\
    \ 0));\n\t}\n\tCap max_flow(int s, int t){\n\t\tCap flow = 0;\n\t\twhile (1){\n\
    \t\t\tvector<Cap> m(N, INF);\n\t\t\tvector<int> pv(N, -1);\n\t\t\tvector<int>\
    \ pe(N, -1);\n\t\t\tvector<bool> used(N, false);\n\t\t\tqueue<int> Q;\n\t\t\t\
    Q.push(s);\n\t\t\tused[s] = true;\n\t\t\twhile (!Q.empty()){\n\t\t\t\tint v =\
    \ Q.front();\n\t\t\t\tQ.pop();\n\t\t\t\tint cnt = G[v].size();\n\t\t\t\tfor (int\
    \ i = 0; i < cnt; i++){\n\t\t\t\t\tint w = G[v][i].to;\n\t\t\t\t\tif (!used[w]\
    \ && G[v][i].cap > 0){\n\t\t\t\t\t\tused[w] = true;\n\t\t\t\t\t\tm[w] = min(m[v],\
    \ G[v][i].cap);\n\t\t\t\t\t\tpv[w] = v;\n\t\t\t\t\t\tpe[w] = i;\n\t\t\t\t\t\t\
    Q.push(w);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (!used[t]){\n\t\t\t\tbreak;\n\
    \t\t\t}\n\t\t\tCap f = m[t];\n\t\t\tfor (int i = t; i != s; i = pv[i]){\n\t\t\t\
    \tG[pv[i]][pe[i]].cap -= f;\n\t\t\t\tG[i][G[pv[i]][pe[i]].rev].cap += f;\n\t\t\
    \t}\n\t\t\tflow += f;\n\t\t}\n\t\treturn flow;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Max_Flow_(Ford_Fulkerson).cpp
  requiredBy: []
  timestamp: '2020-09-29 19:31:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Max_Flow_(Ford_Fulkerson).cpp
layout: document
redirect_from:
- /library/Graph/Max_Flow_(Ford_Fulkerson).cpp
- /library/Graph/Max_Flow_(Ford_Fulkerson).cpp.html
title: Graph/Max_Flow_(Ford_Fulkerson).cpp
---
