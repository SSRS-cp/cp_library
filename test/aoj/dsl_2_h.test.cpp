#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/lazy_segment_tree.cpp"
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n, 0);
  function<int(int, int)> op = [](int a, int b){return min(a, b)};
  lazy_segment_tree<int, int> ST(a, op, plus<int>(), plus<int>(), INF, 0);
  for (int i = 0; i < q; i++){
    int c;
    cin >> c;
    if (t == 0){
      int s, t, x;
      cin >> s >> t >> x;
      t++;
      ST.range_apply(s, t, x);
    }
    if (t == 1){
      int s, t;
      cin >> s >> t;
      t++;
      cout << ST.range_fold(s, t) << endl;
    }
  }
}
