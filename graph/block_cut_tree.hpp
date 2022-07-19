#pragma once
/**
 * @brief Block Cut Tree
*/
#include "biconnected_components.hpp"
struct block_cut_tree{
  int V;
  vector<bool> art;
  vector<bool> cut;
  vector<vector<int>> G;
  vector<vector<int>> node;
  block_cut_tree(vector<vector<int>> &E){
    int N = E.size();
    int M = 0;
    vector<vector<pair<int, int>>> E2(N);
    for (int i = 0; i < N; i++){
      for (int j : E[i]){
        if (j > i){
          E2[i].push_back(make_pair(M, j));
          E2[j].push_back(make_pair(M, i));
          M++;
        }
      }
    }
    biconnected_components B(E2);
    art = vector<bool>(N, false);
    int cnt = 0;
    for (int i = 0; i < N; i++){
      for (auto P : E2[i]){
        if (B[P.first] != B[E2[i][0].first]){
          art[i] = true;
        }
      }
      if (art[i]){
        cnt++;
      }
      if (E[i].empty()){
        cnt++;
      }
    }
    V = cnt + B.cnt;
    cut = vector<bool>(V, false);
    G.resize(V);
    node.resize(V);
    int cnt2 = 0;
    vector<bool> used(B.cnt, false);
    for (int i = 0; i < N; i++){
      if (art[i]){
        cut[cnt2] = true;
        node[cnt2].push_back(i);
        for (auto P : E2[i]){
          int b = B[P.first];
          if (!used[b]){
            used[b] = true;
            G[cnt + b].push_back(cnt2);
            G[cnt2].push_back(cnt + b);
            node[cnt + b].push_back(i);
          }
        }
        for (auto P : E2[i]){
          int b = B[P.first];
          used[b] = false;
        }
        cnt2++;
      } else if (!E2[i].empty()){
        int b = B[E2[i][0].first];
        node[cnt + b].push_back(i);
      } else {
        node[cnt2].push_back(i);
        cnt2++;
      }
    }
  }
};