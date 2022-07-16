#define PROBLEM "https://yukicoder.me/problems/no/1891"
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
#include "../../data_structure/sequence/xor_segment_tree.hpp"
#include "../../other/monoids/linear.hpp"
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<linear> f(N);
  for (int i = 0; i < N; i++){
    int a, b;
    cin >> a >> b;
    f[i] = linear(a, b);
  }
  xor_segment_tree<linear> F(f, composite, linear());
  for (int i = 0; i < Q; i++){
    int l, r, p, x;
    cin >> l >> r >> p >> x;
    cout << value(F.range_fold(l, r, p), x) << endl;
  }
}