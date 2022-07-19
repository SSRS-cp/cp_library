#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/enumerate_triangles.hpp"
int main(){
  int N, M;
  cin >> N >> M;
  vector<long long> x(N);
  for (int i = 0; i < N; i++){
    cin >> x[i];
  }
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<tuple<int, int, int>> T = enumerate_triangles(E);
  int cnt = T.size();
  long long ans = 0;
  for (int i = 0; i < cnt; i++){
    int a = get<0>(T[i]);
    int b = get<1>(T[i]);
    int c = get<2>(T[i]);
    ans += x[a] * x[b] % MOD * x[c] % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}