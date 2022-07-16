#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/dual_binary_indexed_tree.hpp"
int main(){
  int n, q;
  cin >> n >> q;
  dual_binary_indexed_tree<int> BIT(n, plus<int>(), 0);
  for (int i = 0; i < q; i++){
    int c;
    cin >> c;
    if (c == 0){
      int s, t, x;
      cin >> s >> t >> x;
      s--;
      BIT.add(s, -x);
      BIT.add(t, x);
    }
    if (c == 1){
      int t;
      cin >> t;
      t--;
      cout << BIT[t] << endl;
    }
  }
}