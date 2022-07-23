#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/extended_block_cut_tree.hpp"
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
  extended_block_cut_tree T(E);
  int V = T.size();
  int K = V - N;
  cout << K << endl;
  for (int i = 0; i < K; i++){
    cout << T[N + i].size();
    for (int j : T[N + i]){
      cout << ' ' << j;
    }
    cout << endl;
  }
}