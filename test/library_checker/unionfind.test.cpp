#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
#include "../../data_structure/unionfind.cpp"
using namespace std;
int main(){
  int N, Q;
  cin >> N >> Q;
  unionfind UF(N);
  for (int i = 0; i < Q; i++){
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0){
      UF.unite(u, v);
    }
    if (t == 1){
      if (UF.same(u, v)){
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
}
