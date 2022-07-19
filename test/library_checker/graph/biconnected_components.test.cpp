#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/block_cut_tree.hpp"
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int s, t;
    cin >> s >> t;
    E[s].push_back(t);
    E[t].push_back(s);
  }
  block_cut_tree G(E);
  int V = G.V;
  vector<vector<int>> v;
  for (int i = 0; i < V; i++){
    if (!G.cut[i]){
      v.push_back(G.node[i]);
    }
  }
  int K = v.size();
  cout << K << endl;
  for (int i = 0; i < K; i++){
    int l = v[i].size();
    cout << l;
    for (int j = 0; j < l; j++){
      cout << ' ' << v[i][j];
    }
    cout << endl;
  }
}