#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/unionfind.cpp"
int main(){
  int n, q;
  cin >> n >> q;
  unionfind UF(n);
  for (int i = 0; i < q; i++){
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0){
      UF.unite(x, y);
    }
    if (com == 1){
      if (UF.same(x, y)){
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
}
