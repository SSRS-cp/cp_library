#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include <bits/stdc++.h>
using namespace std;
#include "../../../data_structure/sequence/lazy_segment_tree.hpp"
struct monoid{
  int cnt;
  long long sum;
  monoid(): cnt(0), sum(0){
  }
};
int main(){
  int n, q;
  cin >> n >> q;
  vector<monoid> A(n);
  for (int i = 0; i < n; i++){
    A[i].cnt = 1;
  }
  function<monoid(monoid, monoid)> op = [](monoid a, monoid b){
    a.cnt += b.cnt;
    a.sum += b.sum;
    return a;
  };
  function<monoid(int, monoid)> mp = [](int a, monoid b){
    b.sum += (long long) a * b.cnt;
    return b;
  };
  lazy_segment_tree<monoid, int> ST(A, op, mp, plus<int>(), monoid(), 0);
  for (int i = 0; i < q; i++){
    int c;
    cin >> c;
    if (c == 0){
      int s, t, x;
      cin >> s >> t >> x;
      s--;
      ST.range_apply(s, t, x);
    }
    if (c == 1){
      int s, t;
      cin >> s >> t;
      s--;
      cout << ST.range_fold(s, t).sum << endl;
    }
  }
}