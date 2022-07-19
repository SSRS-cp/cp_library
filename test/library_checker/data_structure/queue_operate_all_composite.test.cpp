#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
#include "../../../data_structure/other/sliding_window_aggregation.hpp"
#include "../../../other/monoids/linear.hpp"
int main(){
  int Q;
  cin >> Q;
  sliding_window_aggregation<linear> S(composite, linear());
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 0){
      int a, b;
      cin >> a >> b;
      S.push(linear(a, b));
    }
    if (t == 1){
      S.pop();
    }
    if (t == 2){
      int x;
      cin >> x;
      cout << value(S.get(),x) << endl;
    }
  }
}