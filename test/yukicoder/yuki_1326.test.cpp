#define PROBLEM "https://yukicoder.me/problems/no/1326"
#include <bits/stdc++.h>
using namespace std;
#include "../../graph/block_cut_tree.hpp"
#include "../../data_structure/tree/heavy_light_decomposition.hpp"
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  block_cut_tree G(E);
  vector<int> id(N, -1);
  for (int i = 0; i < G.V; i++){
    for (int j : G.node[i]){
      if (id[j] == -1){
        id[j] = i;
      }
    }
  }
  vector<int> p(G.V, -1);
  vector<vector<int>> c(G.V);
  vector<int> d(G.V, 0);
  if (G.cut[0]){
    d[0]++;
  }
  queue<int> q;
  q.push(0);
  while (!q.empty()){
    int v = q.front();
    q.pop();
    for (int w : G.G[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        d[w] = d[v];
        if (G.cut[w]){
          d[w]++;
        }
        q.push(w);
      }
    }
  }
  heavy_light_decomposition T(p, c);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    x = id[x];
    y = id[y];
    if (x == y){
      cout << 0 << endl;
    } else {
      int z = T.lca(x, y);
      int ans = d[x] + d[y] - d[z] * 2;
      if (G.cut[z]){
        ans++;
      }
      if (G.cut[x]){
        ans--;
      }
      if (G.cut[y]){
        ans--;
      }
      cout << ans << endl;
    }
  }
}