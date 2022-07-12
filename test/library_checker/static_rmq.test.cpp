#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/sequence/disjoint_sparse_table.cpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  disjoint_sparse_table<int> DST(a, [](int a, int b){return min(a, b);});
  for (int i = 0; i < Q; i++){
    int l, r;
    cin >> l >> r;
    cout << DST.query(l, r) << endl;
  }
}
