#pragma once
/**
 * @brief 二重頂点連結成分分解
*/
struct biconnected_components{
  vector<int> bcc;
  int cnt = 0;
  biconnected_components(vector<vector<pair<int, int>>> &E){
    int N = E.size();
    vector<int> next(N, -1);
    vector<int> d(N, -1);
    vector<int> imos(N, 0);
    for (int i = 0; i < N; i++){
      if (d[i] == -1){
        d[i] = 0;
        dfs1(E, next, d, imos, i);
      }
    }
    int M = 0;
    for (int i = 0; i < N; i++){
      M += E[i].size();
    }
    M /= 2;
    bcc = vector<int>(M, -1);
    for (int i = 0; i < N; i++){
      if (d[i] == 0){
        dfs2(E, d, imos, cnt, i);
      }
    }
  }
  void dfs1(vector<vector<pair<int, int>>> &E, vector<int> &next, vector<int> &d, vector<int> &imos, int v){
    for (auto P : E[v]){
      int w = P.second;
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
  void dfs2(vector<vector<pair<int, int>>> &E, vector<int> &d, vector<int> &imos, int b, int v){
    for (auto P : E[v]){
      int x = P.first;
      int w = P.second;
      if (d[w] < d[v]){
        bcc[x] = b;
      } else if (d[w] == d[v] + 1 && bcc[x] == -1){
        if (imos[w] > 0){
          bcc[x] = b;
        } else {
          bcc[x] = cnt;
          cnt++;
        }
        dfs2(E, d, imos, bcc[x], w);
      }
    }
  }
  int operator [](int k){
    return bcc[k];
  }
};