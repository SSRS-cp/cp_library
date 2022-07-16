#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/tree/heavy_light_decomposition.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> p(N);
  for (int i = 1; i < N; i++){
    cin >> p[i];
  }
  vector<vector<int>> c(N);
  for (int i = 1; i < N; i++){
    c[p[i]].push_back(i);
  }
  heavy_light_decomposition T(p, c);
  for (int i = 0; i < Q; i++){
    int u, v;
    cin >> u >> v;
    cout << T.lca(u, v) << endl;
  }
}