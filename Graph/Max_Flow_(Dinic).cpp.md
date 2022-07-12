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
  bundledCode: "#line 1 \"Graph/Max_Flow_(Dinic).cpp\"\ntemplate <typename Cap>\n\
    struct dinic{\n  struct edge{\n    int to, rev;\n    Cap cap;\n    edge(int to,\
    \ int rev, Cap cap): to(to), rev(rev), cap(cap){\n    }\n  };\n  int N;\n  vector<vector<edge>>\
    \ G;\n  dinic(){\n  }\n  dinic(int N): N(N), G(N){\n  }\n  void add_edge(int from,\
    \ int to, Cap cap){\n    G[from].push_back(edge(to, G[to].size(), cap));\n   \
    \ G[to].push_back(edge(from, G[from].size() - 1, 0));\n  }\n  Cap dfs(vector<int>\
    \ &d, vector<int> &iter, int v, int t, Cap f){\n    if (v == t){\n      return\
    \ f; \n    }\n    while (iter[v] < G[v].size()){\n      int w = G[v][iter[v]].to;\n\
    \      if (G[v][iter[v]].cap > 0 && d[v] < d[w]){\n        Cap f2 = dfs(d, iter,\
    \ w, t, min(f, G[v][iter[v]].cap));\n        if (f2 > 0){\n          G[v][iter[v]].cap\
    \ -= f2;\n          G[w][G[v][iter[v]].rev].cap += f2;\n          return f2;\n\
    \        }\n      }\n      iter[v]++;\n    }\n    return 0;\n  }\n  Cap max_flow(int\
    \ s, int t){\n    Cap flow = 0;\n    while (true){\n      vector<int> d(N, -1);\n\
    \      d[s] = 0;\n      queue<int> Q;\n      Q.push(s);\n      while (!Q.empty()){\n\
    \        if (d[t] != -1){\n          break;\n        }\n        int v = Q.front();\n\
    \        Q.pop();\n        for (auto &e : G[v]){\n          int w = e.to;\n  \
    \        if (e.cap > 0 && d[w] == -1){\n            d[w] = d[v] + 1;\n       \
    \     Q.push(w);\n          }\n        }\n      }\n      if (d[t] == -1){\n  \
    \      break;\n      }\n      vector<int> iter(N, 0);\n      while (true){\n \
    \       Cap f = dfs(d, iter, s, t, INF);\n        if (f == 0){\n          break;\n\
    \        }\n        flow += f;\n      }\n    }\n    return flow;\n  }\n};\n"
  code: "template <typename Cap>\nstruct dinic{\n  struct edge{\n    int to, rev;\n\
    \    Cap cap;\n    edge(int to, int rev, Cap cap): to(to), rev(rev), cap(cap){\n\
    \    }\n  };\n  int N;\n  vector<vector<edge>> G;\n  dinic(){\n  }\n  dinic(int\
    \ N): N(N), G(N){\n  }\n  void add_edge(int from, int to, Cap cap){\n    G[from].push_back(edge(to,\
    \ G[to].size(), cap));\n    G[to].push_back(edge(from, G[from].size() - 1, 0));\n\
    \  }\n  Cap dfs(vector<int> &d, vector<int> &iter, int v, int t, Cap f){\n   \
    \ if (v == t){\n      return f; \n    }\n    while (iter[v] < G[v].size()){\n\
    \      int w = G[v][iter[v]].to;\n      if (G[v][iter[v]].cap > 0 && d[v] < d[w]){\n\
    \        Cap f2 = dfs(d, iter, w, t, min(f, G[v][iter[v]].cap));\n        if (f2\
    \ > 0){\n          G[v][iter[v]].cap -= f2;\n          G[w][G[v][iter[v]].rev].cap\
    \ += f2;\n          return f2;\n        }\n      }\n      iter[v]++;\n    }\n\
    \    return 0;\n  }\n  Cap max_flow(int s, int t){\n    Cap flow = 0;\n    while\
    \ (true){\n      vector<int> d(N, -1);\n      d[s] = 0;\n      queue<int> Q;\n\
    \      Q.push(s);\n      while (!Q.empty()){\n        if (d[t] != -1){\n     \
    \     break;\n        }\n        int v = Q.front();\n        Q.pop();\n      \
    \  for (auto &e : G[v]){\n          int w = e.to;\n          if (e.cap > 0 &&\
    \ d[w] == -1){\n            d[w] = d[v] + 1;\n            Q.push(w);\n       \
    \   }\n        }\n      }\n      if (d[t] == -1){\n        break;\n      }\n \
    \     vector<int> iter(N, 0);\n      while (true){\n        Cap f = dfs(d, iter,\
    \ s, t, INF);\n        if (f == 0){\n          break;\n        }\n        flow\
    \ += f;\n      }\n    }\n    return flow;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Max_Flow_(Dinic).cpp
  requiredBy: []
  timestamp: '2021-12-01 17:43:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Max_Flow_(Dinic).cpp
layout: document
redirect_from:
- /library/Graph/Max_Flow_(Dinic).cpp
- /library/Graph/Max_Flow_(Dinic).cpp.html
title: Graph/Max_Flow_(Dinic).cpp
---
