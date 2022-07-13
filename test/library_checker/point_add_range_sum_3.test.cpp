#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/segment_tree.cpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<long long> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  segment_tree<long long> ST(a, plus<long long>(), 0);
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int p, x;
      cin >> p >> x;
      a[p] += x;
      ST.update(p, a[p]);
    }
    if (t == 1){
      int l, r;
      cin >> l >> r;
      cout << ST.query(l, r) << endl;
    }
  }
}
