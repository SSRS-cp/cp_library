#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"
#include <bits/stdc++.h>
using namespace std;
#include "../../../data_structure/sequence/dual_binary_indexed_tree.hpp"
int main(){
  int N, T;
  cin >> N >> T;
  dual_binary_indexed_tree<int> BIT(T, plus<int>(), 0);
  for (int i = 0; i < N; i++){
    int l, r;
    cin >> l >> r;
    BIT.add(l, -1);
    BIT.add(r, 1);
  }
  vector<int> S = BIT.get();
  int ans = 0;
  for (int i = 0; i < T; i++){
    ans = max(ans, S[i]);
  }
  cout << ans << endl;
}