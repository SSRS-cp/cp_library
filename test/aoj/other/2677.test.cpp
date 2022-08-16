#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2677"
#include <bits/stdc++.h>
using namespace std;
#include "../../../data_structure/tree/heavy_light_decomposition.hpp"
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  vector<int> bfs;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (int w : c[v]){
      Q.push(w);
    }
  }
  heavy_light_decomposition T(p, c);
  long long ans = 0;
  for (int i = 0; i < n - 1; i++){
    ans += T.dist(bfs[i], bfs[i + 1]);
  }
  cout << ans << endl;
}