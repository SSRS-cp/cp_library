#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include <bits/stdc++.h>
using namespace std;
#include "../../../data_structure/sequence/wavelet_matrix.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  wavelet_matrix WM(a);
  for (int i = 0; i < Q; i++){
    int l, r, k;
    cin >> l >> r >> k;
    cout << WM.quantile(l, r, k) << endl;
  }
}