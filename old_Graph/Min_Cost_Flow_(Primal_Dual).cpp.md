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
  bundledCode: "#line 1 \"old_Graph/Min_Cost_Flow_(Primal_Dual).cpp\"\ntemplate <typename\
    \ Cap, typename Cost>\nstruct primal_dual{\n\tstruct edge{\n\t\tint to, rev;\n\
    \t\tCap cap;\n\t\tCost cost;\n\t\tedge(int to, int rev, Cap cap, Cost cost): to(to),\
    \ rev(rev), cap(cap), cost(cost){\n\t\t}\n\t};\n\tint N;\n\tvector<vector<edge>>\
    \ G;\n\tprimal_dual(){\n\t}\n\tprimal_dual(int N): N(N), G(N){\n\t}\n\tvoid add_edge(int\
    \ from, int to, Cap cap, Cost cost){\n\t\tint id1 = G[from].size();\n\t\tint id2\
    \ = G[to].size();\n\t\tG[from].push_back(edge(to, id2, cap, cost));\n\t\tG[to].push_back(edge(from,\
    \ id1, 0, - cost));\n\t}\n\tpair<Cap, Cost> min_cost_flow(int s, int t, Cap F){\n\
    \t\tCap flow = 0;\n\t\tCost cost = 0;\n\t\tvector<Cost> h(N, 0);\n\t\twhile (flow\
    \ < F){\n\t\t\tvector<Cap> m(N, INF);\n\t\t\tvector<Cost> d(N, INF);\n\t\t\tvector<int>\
    \ pv(N, -1);\n\t\t\tvector<int> pe(N, -1);\n\t\t\tvector<bool> used(N, false);\n\
    \t\t\tpriority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost,\
    \ int>>> pq;\n\t\t\tpq.push(make_pair(0, s));\n\t\t\td[s] = 0;\n\t\t\twhile (!pq.empty()){\n\
    \t\t\t\tint v = pq.top().second;\n\t\t\t\tpq.pop();\n\t\t\t\tif (!used[v]){\n\t\
    \t\t\t\tused[v] = true;\n\t\t\t\t\tif (v == t){\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t\
    }\n\t\t\t\t\tint cnt = G[v].size();\n\t\t\t\t\tfor (int i = 0; i < cnt; i++){\n\
    \t\t\t\t\t\tint w = G[v][i].to;\n\t\t\t\t\t\tif (!used[w] && G[v][i].cap > 0){\n\
    \t\t\t\t\t\t\tCost tmp = G[v][i].cost - h[w] + h[v];\n\t\t\t\t\t\t\tif (d[w] >\
    \ d[v] + tmp){\n\t\t\t\t\t\t\t\td[w] = d[v] + tmp;\n\t\t\t\t\t\t\t\tm[w] = min(m[v],\
    \ G[v][i].cap);\n\t\t\t\t\t\t\t\tpv[w] = v;\n\t\t\t\t\t\t\t\tpe[w] = i;\n\t\t\t\
    \t\t\t\t\tpq.push(make_pair(d[w], w));\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\
    \t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (!used[t]){\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\
    \tfor (int i = 0; i < N; i++){\n\t\t\t\tif (used[i]){\n\t\t\t\t\th[i] -= d[t]\
    \ - d[i];\n\t\t\t\t}\n\t\t\t}\n\t\t\tCap c = min(m[t], F - flow);\n\t\t\tfor (int\
    \ i = t; i != s; i = pv[i]){\n\t\t\t\tG[pv[i]][pe[i]].cap -= c;\n\t\t\t\tG[i][G[pv[i]][pe[i]].rev].cap\
    \ += c;\n\t\t\t}\n\t\t\tflow += c;\n\t\t\tcost += c * (- h[s]);\n\t\t}\n\t\treturn\
    \ make_pair(flow, cost);\n\t}\n};\n"
  code: "template <typename Cap, typename Cost>\nstruct primal_dual{\n\tstruct edge{\n\
    \t\tint to, rev;\n\t\tCap cap;\n\t\tCost cost;\n\t\tedge(int to, int rev, Cap\
    \ cap, Cost cost): to(to), rev(rev), cap(cap), cost(cost){\n\t\t}\n\t};\n\tint\
    \ N;\n\tvector<vector<edge>> G;\n\tprimal_dual(){\n\t}\n\tprimal_dual(int N):\
    \ N(N), G(N){\n\t}\n\tvoid add_edge(int from, int to, Cap cap, Cost cost){\n\t\
    \tint id1 = G[from].size();\n\t\tint id2 = G[to].size();\n\t\tG[from].push_back(edge(to,\
    \ id2, cap, cost));\n\t\tG[to].push_back(edge(from, id1, 0, - cost));\n\t}\n\t\
    pair<Cap, Cost> min_cost_flow(int s, int t, Cap F){\n\t\tCap flow = 0;\n\t\tCost\
    \ cost = 0;\n\t\tvector<Cost> h(N, 0);\n\t\twhile (flow < F){\n\t\t\tvector<Cap>\
    \ m(N, INF);\n\t\t\tvector<Cost> d(N, INF);\n\t\t\tvector<int> pv(N, -1);\n\t\t\
    \tvector<int> pe(N, -1);\n\t\t\tvector<bool> used(N, false);\n\t\t\tpriority_queue<pair<Cost,\
    \ int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> pq;\n\t\t\tpq.push(make_pair(0,\
    \ s));\n\t\t\td[s] = 0;\n\t\t\twhile (!pq.empty()){\n\t\t\t\tint v = pq.top().second;\n\
    \t\t\t\tpq.pop();\n\t\t\t\tif (!used[v]){\n\t\t\t\t\tused[v] = true;\n\t\t\t\t\
    \tif (v == t){\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t\tint cnt = G[v].size();\n\
    \t\t\t\t\tfor (int i = 0; i < cnt; i++){\n\t\t\t\t\t\tint w = G[v][i].to;\n\t\t\
    \t\t\t\tif (!used[w] && G[v][i].cap > 0){\n\t\t\t\t\t\t\tCost tmp = G[v][i].cost\
    \ - h[w] + h[v];\n\t\t\t\t\t\t\tif (d[w] > d[v] + tmp){\n\t\t\t\t\t\t\t\td[w]\
    \ = d[v] + tmp;\n\t\t\t\t\t\t\t\tm[w] = min(m[v], G[v][i].cap);\n\t\t\t\t\t\t\t\
    \tpv[w] = v;\n\t\t\t\t\t\t\t\tpe[w] = i;\n\t\t\t\t\t\t\t\tpq.push(make_pair(d[w],\
    \ w));\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    if (!used[t]){\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tfor (int i = 0; i < N; i++){\n\t\
    \t\t\tif (used[i]){\n\t\t\t\t\th[i] -= d[t] - d[i];\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    Cap c = min(m[t], F - flow);\n\t\t\tfor (int i = t; i != s; i = pv[i]){\n\t\t\t\
    \tG[pv[i]][pe[i]].cap -= c;\n\t\t\t\tG[i][G[pv[i]][pe[i]].rev].cap += c;\n\t\t\
    \t}\n\t\t\tflow += c;\n\t\t\tcost += c * (- h[s]);\n\t\t}\n\t\treturn make_pair(flow,\
    \ cost);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Graph/Min_Cost_Flow_(Primal_Dual).cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Graph/Min_Cost_Flow_(Primal_Dual).cpp
layout: document
redirect_from:
- /library/old_Graph/Min_Cost_Flow_(Primal_Dual).cpp
- /library/old_Graph/Min_Cost_Flow_(Primal_Dual).cpp.html
title: old_Graph/Min_Cost_Flow_(Primal_Dual).cpp
---
