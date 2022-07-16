#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
#include "../../data_structure/sequence/sparse_table.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  sparse_table<int> ST(a, [](int a, int b){return min(a, b);}, INF);
  for (int i = 0; i < Q; i++){
    int l, r;
    cin >> l >> r;
    cout << ST.query(l, r) << endl;
  }
}