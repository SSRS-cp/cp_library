struct two_edge_connected_components{
  vector<int> tcc;
  int cnt;
  two_edge_connected_components(vector<vector<int>> &E){
    int N = E.size();
    vector<int> p(N, -1);
    vector<int> d(N, -1);
    d[0] = 0;
    vector<int> imos(N, 0);
    dfs1(E, p, d, imos);
    tcc = vector<int>(N, -1);
    tcc[0] = 0;
    cnt = 1;
    dfs2(E, p, imos);
  }
  void dfs1(vector<vector<int>> &E, vector<int> &p, vector<int> &d, vector<int> &imos, int v = 0){
    for (int w : E[v]){
      if (w != p[v]){
      	if (d[w] == -1){
          p[w] = v;
          d[w] = d[v] + 1;
          dfs1(E, p, d, imos, w);
          imos[v] += imos[w];
        } else if (d[w] < d[v]){
          imos[v]++;
          imos[w]--;
        }
      }
    }
  }
  void dfs2(vector<vector<int>> &E, vector<int> &p, vector<int> &imos, int v = 0){
    for (int w : E[v]){
      if (tcc[w] == -1){
        if (imos[w] > 0){
          tcc[w] = tcc[v];
        } else {
          tcc[w] = cnt;
          cnt++;
        }
        dfs2(E, p, imos, w);
      }
    }
  }
  int operator [](int v){
    return tcc[v];
  }
  int count(){
    return cnt;
  }
};
