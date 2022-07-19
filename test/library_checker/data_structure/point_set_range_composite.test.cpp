#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
#include "../../../data_structure/sequence/segment_tree.hpp"
#include "../../../other/monoids/linear.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<linear> f(N);
  for (int i = 0; i < N; i++){
    cin >> f[i].a >> f[i].b;
  }
  segment_tree<linear> ST(f, composite, linear());
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int p, c, d;
      cin >> p >> c >> d;
      ST.update(p, linear(c, d));
    }
    if (t == 1){
      int l, r, x;
      cin >> l >> r >> x;
      cout << value(ST.query(l, r), x) << endl;
    }
  }
}