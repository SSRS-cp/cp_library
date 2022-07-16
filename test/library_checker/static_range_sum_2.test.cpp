#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/invertible_cumulative_sum.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<long long> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  invertible_cumulative_sum<long long> S(a, plus<long long>(), negate<long long>(), 0);
  for (int i = 0; i < Q; i++){
    int l, r;
    cin >> l >> r;
    cout << S.get(l, r) << endl;
  }
}