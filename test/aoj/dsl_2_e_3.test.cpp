#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/commutative_dual_segment_tree.cpp"
int main(){
  int n, q;
  cin >> n >> q;
  commutative_dual_segment_tree<int> ST(n, plus<int>(), 0);
  for (int i = 0; i < q; i++){
    int c;
    cin >> c;
    if (c == 0){
      int s, t, x;
      cin >> s >> t >> x;
      s--;
      ST.range_apply(s, t, x);
    }
    if (c == 1){
      int t;
      cin >> t;
      t--;
      cout << ST[t] << endl;
    }
  }
}
