#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
#include "../../data_structure/sequence/lazy_segment_tree.hpp"
#include "../../other/monoids/linear.hpp"
#include "../../other/monoids/affine_sum.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<affine_sum> a(N);
  for (int i = 0; i < N; i++){
    a[i].cnt = 1;
    cin >> a[i].sum;
  }
  lazy_segment_tree<affine_sum, linear> ST(a, op, mp, composite, affine_sum(), linear());
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int l, r, b, c;
      cin >> l >> r >> b >> c;
      ST.range_apply(l, r, linear(b, c));
    }
    if (t == 1){
      int l, r;
      cin >> l >> r;
      cout << ST.range_fold(l, r).sum << endl;
    }
  }
}