template <typename Cap>
struct dinic{
  struct edge{
    int to, rev;
    Cap cap;
    edge(int to, int rev, Cap cap): to(to), rev(rev), cap(cap){
    }
  };
  int N;
  vector<vector<edge>> G;
  dinic(){
  }
  dinic(int N): N(N), G(N){
  }
  void add_edge(int from, int to, Cap cap){
    G[from].push_back(edge(to, G[to].size(), cap));
    G[to].push_back(edge(from, G[from].size() - 1, 0));
  }
  Cap dfs(vector<int> &d, vector<int> &iter, int v, int t, Cap f){
    if (v == t){
      return f; 
    }
    while (iter[v] < G[v].size()){
      int w = G[v][iter[v]].to;
      if (G[v][iter[v]].cap > 0 && d[v] < d[w]){
        Cap f2 = dfs(d, iter, w, t, min(f, G[v][iter[v]].cap));
        if (f2 > 0){
          G[v][iter[v]].cap -= f2;
          G[w][G[v][iter[v]].rev].cap += f2;
          return f2;
        }
      }
      iter[v]++;
    }
    return 0;
  }
  Cap max_flow(int s, int t){
    Cap flow = 0;
    while (true){
      vector<int> d(N, -1);
      d[s] = 0;
      queue<int> Q;
      Q.push(s);
      while (!Q.empty()){
        if (d[t] != -1){
          break;
        }
        int v = Q.front();
        Q.pop();
        for (auto &e : G[v]){
          int w = e.to;
          if (e.cap > 0 && d[w] == -1){
            d[w] = d[v] + 1;
            Q.push(w);
          }
        }
      }
      if (d[t] == -1){
        break;
      }
      vector<int> iter(N, 0);
      while (true){
        Cap f = dfs(d, iter, s, t, INF);
        if (f == 0){
          break;
        }
        flow += f;
      }
    }
    return flow;
  }
};
