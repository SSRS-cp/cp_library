#pragma once
/**
 * @brief 拡張 Block Cut Tree
*/
struct extended_block_cut_tree{
  int N, cnt;
  vector<vector<int>> G;
  extended_block_cut_tree(vector<vector<int>> &E){
    N = E.size();
    vector<int> next(N, -1);
    vector<int> d(N, -1);
    vector<int> imos(N, 0);
    for (int i = 0; i < N; i++){
      if (d[i] == -1){
        d[i] = 0;
        dfs1(E, next, d, imos, i);
      }
    }
    cnt = 0;
    G.resize(N + 1);
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++){
      if (d[i] == 0){
        dfs2(E, d, imos, used, cnt, i);
      }
      if (E[i].empty()){
        G[i].push_back(N + cnt);
        G[N + cnt].push_back(i);
        cnt++;
        G.push_back({});
      }
    }
    G.pop_back();
  }
  void dfs1(vector<vector<int>> &E, vector<int> &next, vector<int> &d, vector<int> &imos, int v){
    for (int w : E[v]){
      if (d[w] == -1){
        d[w] = d[v] + 1;
        next[v] = w;
        dfs1(E, next, d, imos, w);
        imos[v] += imos[w];
      } else if (d[w] < d[v] - 1){
        imos[v]++;
        imos[next[w]]--;
      }
    }
  }
  void dfs2(vector<vector<int>> &E, vector<int> &d, vector<int> &imos, vector<bool> &used, int b, int v){
    used[v] = true;
    bool ok = false;
    for (int w : E[v]){
      if (d[w] == d[v] + 1 && !used[w]){
        if (imos[w] > 0){
          if (!ok){
            ok = true;
            G[v].push_back(N + b);
            G[N + b].push_back(v);
          }
          dfs2(E, d, imos, used, b, w);
        } else {
          G[v].push_back(N + cnt);
          G[N + cnt].push_back(v);
          cnt++;
          G.push_back({});
          dfs2(E, d, imos, used, cnt - 1, w);
        }
      }
    }
    if (!ok && d[v] > 0){
      G[v].push_back(N + b);
      G[N + b].push_back(v);
    }
  }
  int size(){
    return G.size();
  }
  vector<int> &operator [](int v){
    return G[v];
  }
};