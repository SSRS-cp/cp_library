#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/compact_bit_vector.cpp"
#include "../../data_structure/sequence/wavelet_matrix.cpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  wavelet_matrix WM(a);
  for (int i = 0; i < Q; i++){
    int l, r, x;
    cin >> l >> r >> x;
    cout << WM.rank(l, r, x) << endl;
  }
}
