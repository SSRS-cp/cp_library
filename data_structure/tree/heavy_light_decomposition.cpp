struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  void dfs1(vector<vector<int>> &c, int v){
    sz[v] = 1;
    for (int &w : c[v]){
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v){
    in[v] = t;
    t++;
    for (int w : c[v]){
      if (w == c[v][0]){
        next[w] = next[v];
      } else {
        next[w] = w;
      }
      dfs2(c, t, w);
    }
  }
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, int r = 0): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c, r);
    in = vector<int>(N);
    next = vector<int>(N, r);
    int t = 0;
    dfs2(c, t, r);
  }
  int lca(int u, int v){
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        return u;
      }
      v = p[next[v]];
    }
  }
  int dist(int u, int v){
    int ans = 0;
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        ans += in[v] - in[u];
        return ans;
      }
      ans += in[v] - in[next[v]] + 1;
      v = p[next[v]];
    }
  }
};
/**
 * @brief 重軽分解
*/
