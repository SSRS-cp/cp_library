#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/two_edge_connected_components.hpp"
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
  two_edge_connected_components G(E);
  vector<pair<int, int>> ans;
  for (int i = 0; i < N; i++){
    for (int j : E[i]){
      if (j > i && G[i] != G[j]){
        ans.push_back(make_pair(i, j));
      }
    }
  }
  sort(ans.begin(), ans.end());
  int cnt = ans.size();
  for (int i = 0; i < cnt; i++){
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
}