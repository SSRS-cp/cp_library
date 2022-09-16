#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include <bits/stdc++.h>
using namespace std;
const long long INF = 3000000000000000000;
#include "../../../data_structure/other/li_chao_tree.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<long long> l(N), r(N), a(N), b(N);
  for (int i = 0; i < N; i++){
    cin >> l[i] >> r[i] >> a[i] >> b[i];
  }
  vector<int> t(Q);
  vector<long long> l2(Q), r2(Q), a2(Q), b2(Q);
  vector<long long> p(Q);
  for (int i = 0; i < Q; i++){
    cin >> t[i];
    if (t[i] == 0){
      cin >> l2[i] >> r2[i] >> a2[i] >> b2[i];
    }
    if (t[i] == 1){
      cin >> p[i];
    }
  }
  vector<long long> x;
  for (int i = 0; i < Q; i++){
    if (t[i] == 1){
      x.push_back(p[i]);
    }
  }
  li_chao_tree<long long> T(x);
  for (int i = 0; i < N; i++){
    T.segment_add(l[i], r[i], a[i], b[i]);
  }
  for (int i = 0; i < Q; i++){
    if (t[i] == 0){
      T.segment_add(l2[i], r2[i], a2[i], b2[i]);
    }
    if (t[i] == 1){
      long long ans = T.get(p[i]);
      if (ans == INF){
        cout << "INFINITY" << endl;
      } else {
        cout << ans << endl;
      }
    }
  }
}