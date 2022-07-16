#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
#include "../../data_structure/sequence/segment_tree.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  segment_tree<int> ST(a, [](int x, int y){return min(x, y);}, INF);
  for (int i = 0; i < Q; i++){
    int L, R;
    cin >> L >> R;
    cout << ST.query(L, R) << endl;
  }
}