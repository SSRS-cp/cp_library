#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/strongly_connected_components.hpp"
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    E[a].push_back(b);
  }
  strongly_connected_components G(E);
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