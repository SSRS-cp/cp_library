#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/two_edge_connected_components.hpp"
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  two_edge_connected_components G(E);
  int K = G.cnt;
  vector<vector<int>> v(K);
  for (int i = 0; i < N; i++){
    v[G[i]].push_back(i);
  }
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