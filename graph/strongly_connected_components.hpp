#pragma once
/**
 * @brief 強連結成分分解
*/
struct strongly_connected_components{
  vector<int> scc;
  int cnt = 0;
  void dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v){
    for (int w : E[v]){
      if (!used[w]){
        used[w] = true;
        dfs1(E, t, used, w);
      }
    }
    t.push_back(v);
  }
  void dfs2(vector<vector<int>> &E2, vector<bool> &used2, int v){
    scc[v] = cnt;
    for (int w : E2[v]){
      if (!used2[w]){
        used2[w] = true;
        dfs2(E2, used2, w);
      }
    }
  }
  strongly_connected_components(vector<vector<int>> &E){
    int N = E.size();
    vector<vector<int>> E2(N);
    for (int i = 0; i < N; i++){
      for (int j : E[i]){
        E2[j].push_back(i);
      }
    }
    vector<int> t;
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++){
      if (!used[i]){
        used[i] = true;
        dfs1(E, t, used, i);
      }
    }
    reverse(t.begin(), t.end());
    vector<bool> used2(N, false);
    scc = vector<int>(N);
    for (int i = 0; i < N; i++){
      if (!used2[t[i]]){
        used2[t[i]] = true;
        dfs2(E2, used2, t[i]);
        cnt++;
      }
    }
  }
  int operator [](int k){
    return scc[k];
  }
};
