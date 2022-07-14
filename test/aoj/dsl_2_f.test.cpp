#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
#include "../../data_structure/sequence/lazy_segment_tree.cpp"
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n, 0);
  function<int(int, int)> op = [](int a, int b){
    return min(a, b);
  };
  function<int(int, int)> mp = [](int a, int b){
    if (a == -1){
      return b;
    } else {
      return a;
    }
  };
  function<int(int, int)> comp = [](int a, int b){
    if (b == -1){
      return a;
    } else {
      return b;
    }
  };
  lazy_segment_tree<int, int> ST(a, op, mp, comp, INF, -1);
  for (int i = 0; i < q; i++){
    int c;
    cin >> c;
    if (c == 0){
      int s, t, x;
      cin >> s >> t >> x;
      t++;
      ST.range_apply(s, t, x);
    }
    if (c == 1){
      int s, t;
      cin >> s >> t;
      t++;
      cout << ST.range_fold(s, t) << endl;
    }
  }
}
