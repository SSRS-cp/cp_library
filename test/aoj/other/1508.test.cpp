#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
#include "../../../data_structure/bbst/splay_tree.hpp"
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  function<int(int, int)> op = [](int x, int y){
    return min(x, y);
  };
  splay_tree<int> ST(a, op, INF);
  for (int i = 0; i < q; i++){
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 0){
      splay_tree<int>::node* v = ST.get(z);
      int s = v->val;
      ST.erase(v);
      ST.insert(y, s);
    }
    if (x == 1){
      z++;
      cout << ST.query(y, z) << endl;
    }
    if (x == 2){
      ST.update(y, z);
    }
  }
}