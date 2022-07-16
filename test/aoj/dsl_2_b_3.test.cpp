#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/segment_tree.hpp"
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  segment_tree<int> ST(n, plus<int>(), 0);
  for (int i = 0; i < q; i++){
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0){
      x--;
      a[x] += y;
      ST.update(x, a[x]);
    }
    if (com == 1){
      x--;
      cout << ST.query(x, y) << endl;
    }
  }
}