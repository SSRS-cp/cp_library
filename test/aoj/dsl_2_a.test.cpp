#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/segment_tree.cpp"
int main(){
  int n, q;
  cin >> n >> q;
  segment_tree<int> ST(n, [](int a, int b){return min(a, b);}, 2147483647);
  for (int i = 0; i < q; i++){
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0){
      ST.update(x, y);
    }
    if (com == 1){
      y++;
      cout << ST.query(x, y) << endl;
    }
  }
}
