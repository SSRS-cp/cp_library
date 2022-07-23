#define PROBLEM "https://yukicoder.me/problems/no/1326"
#include <bits/stdc++.h>
using namespace std;
#include "../../graph/extended_block_cut_tree.hpp"
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
  extended_block_cut_tree T(E);
  int V = T.size();
  vector<int> p(V, -1);
  vector<vector<int>> c(V);
  vector<int> d(V, 0);
  queue<int> q;
  q.push(0);
  while (!q.empty()){
    int v = q.front();
    q.pop();
    for (int w : T[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        d[w] = d[v] + 1;
        q.push(w);
      }
    }
  }
  heavy_light_decomposition HLD(p, c);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << max(HLD.dist(x, y) / 2 - 1, 0) << endl;
  }
}