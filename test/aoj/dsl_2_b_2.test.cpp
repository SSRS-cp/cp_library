#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/invertible_binary_indexed_tree.hpp"
int main(){
  int n, q;
  cin >> n >> q;
  invertible_binary_indexed_tree<int> BIT(n, plus<int>(), negate<int>(), 0);
  for (int i = 0; i < q; i++){
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0){
      x--;
      BIT.add(x, y);
    }
    if (com == 1){
      x--;
      cout << BIT.sum(x, y) << endl;
    }
  }
}