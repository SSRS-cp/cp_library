#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/extended_block_cut_tree.hpp"
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
  extended_block_cut_tree T(E);
  for (int i = 0; i < N; i++){
    if (T[i].size() >= 2){
      cout << i << endl;
    }
  }
}