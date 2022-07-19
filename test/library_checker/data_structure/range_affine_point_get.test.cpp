#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
#include "../../../data_structure/sequence/dual_segment_tree.hpp"
#include "../../../other/monoids/linear.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<linear> a(N);
  for (int i = 0; i < N; i++){
    a[i].a = 0;
    cin >> a[i].b;
  }
  dual_segment_tree<linear> ST(a, composite, linear());
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int l, r, b, c;
      cin >> l >> r >> b >> c;
      ST.range_apply(l, r, linear(b, c));
    }
    if (t == 1){
      int p;
      cin >> p;
      cout << ST[p].b << endl;
    }
  }
}