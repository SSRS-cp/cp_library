#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/segment_tree_beats.hpp"
const long long INF = 1000000000000000000;
struct monoid{
  int sz, minc, maxc;
  long long min1, min2, max1, max2, sum;
  bool fail;
  monoid(): sz(0), minc(0), maxc(0), min1(INF), min2(INF), max1(-INF), max2(-INF), sum(0), fail(false){
  }
  monoid(long long x, int sz = 1): sz(sz), minc(sz), maxc(sz), min1(x), min2(INF), max1(x), max2(-INF), sum(x * sz), fail(false){
  }
};
monoid op(monoid L, monoid R){
  monoid ans;
  ans.sz = L.sz + R.sz;
  ans.sum = L.sum + R.sum;
  ans.min1 = min(L.min1, R.min1);
  if (L.min1 < R.min1){
    ans.min2 = min(L.min2, R.min1);
    ans.minc = L.minc;
  } else if (L.min1 > R.min1){
    ans.min2 = min(L.min1, R.min2);
    ans.minc = R.minc;
  } else {
    ans.min2 = min(L.min2, R.min2);
    ans.minc = L.minc + R.minc;
  }
  ans.max1 = max(L.max1, R.max1);
  if (L.max1 > R.max1){
    ans.max2 = max(L.max2, R.max1);
    ans.maxc = L.maxc;
  } else if (L.max1 < R.max1){
    ans.max2 = max(L.max1, R.max2);
    ans.maxc = R.maxc;
  } else {
    ans.max2 = max(L.max2, R.max2);
    ans.maxc = L.maxc + R.maxc;
  }
  return ans;
}
struct func{
  long long mn, mx, add;
  func(): mn(-INF), mx(INF), add(0){
  }
  func(long long mn, long long mx, long long add): mn(mn), mx(mx), add(add){
  }
};
func comp(func g, func f){
  func ans;
  ans.mn = max(min(f.mn + g.add, g.mx), g.mn);
  ans.mx = min(max(f.mx + g.add, g.mn), g.mx);
  ans.add = f.add + g.add;
  return ans;
}
monoid mp(func f, monoid x){
  if (x.sz == 0){
    return x;
  }
  x.min1 += f.add;
  if (x.min2 != INF){
    x.min2 += f.add;
  }
  x.max1 += f.add;
  if (x.max2 != -INF){
    x.max2 += f.add;
  }
  x.sum += x.sz * f.add;
  if (x.max1 <= f.mn){
    return monoid(f.mn, x.sz);
  }
  if (x.min1 >= f.mx){
    return monoid(f.mx, x.sz);
  }
  if (f.mn < x.min2){
    if (x.min1 < f.mn){
      x.sum += (f.mn - x.min1) * x.minc;
      if (x.min1 == x.max1){
        x.max1 = f.mn;
      } else if (x.min1 == x.max2){
        x.max2 = f.mn;
      }
      x.min1 = f.mn;
    }
  } else {
    x.fail = true;
    return x;
  }
  if (f.mx > x.max2){
    if (x.max1 > f.mx){
      x.sum -= (x.max1 - f.mx) * x.maxc;
      if (x.max1 == x.min1){
        x.min1 = f.mx;
      } else if (x.max1 == x.min2){
        x.min2 = f.mx;
      }
      x.max1 = f.mx;
    }
  } else {
    x.fail = true;
    return x;
  }
  return x;
}
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<monoid> A(N);
  for (int i = 0; i < N; i++){
    long long a;
    cin >> a;
    A[i] = monoid(a);
  }
  segment_tree_beats<monoid, func> ST(A, op, mp, comp, monoid(), func());
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int l, r;
      long long b;
      cin >> l >> r >> b;
      ST.range_apply(l, r, func(-INF, b, 0));
    }
    if (t == 1){
      int l, r;
      long long b;
      cin >> l >> r >> b;
      ST.range_apply(l, r, func(b, INF, 0));
    }
    if (t == 2){
      int l, r;
      long long b;
      cin >> l >> r >> b;
      ST.range_apply(l, r, func(-INF, INF, b));
    }
    if (t == 3){
      int l, r;
      cin >> l >> r;
      cout << ST.range_fold(l, r).sum << endl;
    }
  }
}