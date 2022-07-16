#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/commutative_dual_segment_tree.hpp"
int main(){
  int n, q;
  cin >> n >> q;
  commutative_dual_segment_tree<pair<int, int>> ST(n, [](pair<int, int> a, pair<int, int> b){return  max(a, b);}, make_pair(-1, 2147483647));
  for (int i = 0; i < q; i++){
    int c;
    cin >> c;
    if (c == 0){
      int s, t, x;
      cin >> s >> t >> x;
      t++;
      ST.range_apply(s, t, make_pair(i, x));
    }
    if (c == 1){
      int t;
      cin >> t;
      cout << ST[t].second << endl;
    }
  }
}