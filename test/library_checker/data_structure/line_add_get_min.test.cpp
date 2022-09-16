#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include <bits/stdc++.h>
using namespace std;
const long long INF = 3000000000000000000;
#include "../../../data_structure/other/li_chao_tree.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<long long> a(N), b(N);
  for (int i = 0; i < N; i++){
    cin >> a[i] >> b[i];
  }
  vector<int> t(Q);
  vector<long long> a2(Q), b2(Q);
  vector<long long> p(Q);
  for (int i = 0; i < Q; i++){
    cin >> t[i];
    if (t[i] == 0){
      cin >> a2[i] >> b2[i];
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
    T.line_add(a[i], b[i]);
  }
  for (int i = 0; i < Q; i++){
    if (t[i] == 0){
      T.line_add(a2[i], b2[i]);
    }
    if (t[i] == 1){
      cout << T.get(p[i]) << endl;
    }
  }
}