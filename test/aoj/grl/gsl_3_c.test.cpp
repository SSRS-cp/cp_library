#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/strongly_connected_components.hpp"
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int s, t;
    cin >> s >> t;
    E[s].push_back(t);
  }
  strongly_connected_components G(E);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int u, v;
    cin >> u >> v;
    if (G[u] == G[v]){
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}