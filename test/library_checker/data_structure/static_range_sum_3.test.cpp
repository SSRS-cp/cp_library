#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>
using namespace std;
#include "../../../data_structure/sequence/disjoint_sparse_table.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<long long> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  disjoint_sparse_table<long long> DST(a, plus<long long>(), 0);
  for (int i = 0; i < Q; i++){
    int l, r;
    cin >> l >> r;
    cout << DST.query(l, r) << endl;
  }
}