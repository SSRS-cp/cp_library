#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
#include "../../../data_structure/bbst/splay_tree.hpp"
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  function<int(int, int)> op = [](int x, int y){
    return min(x, y);
  };
  splay_tree<int> ST(a, op, INF);
  for (int i = 0; i < q; i++){
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 0){
      z++;
      pair<splay_tree<int>::node*, splay_tree<int>::node*> A = ST.split(z - 1);
      pair<splay_tree<int>::node*, splay_tree<int>::node*> B = ST.split(A.first, y);
      pair<splay_tree<int>::node*, splay_tree<int>::node*> C = ST.split(A.second, 1);
      splay_tree<int>::node* l = ST.merge(B.first, C.first);
      splay_tree<int>::node* r = ST.merge(B.second, C.second);
      ST.merge(l, r);
    }
    if (x == 1){
      z++;
      pair<splay_tree<int>::node*, splay_tree<int>::node*> A = ST.split(z);
      pair<splay_tree<int>::node*, splay_tree<int>::node*> B = ST.split(A.first, y);
      cout << B.second->sum << endl;
      splay_tree<int>::node* l = ST.merge(B.first, B.second);
      ST.merge(l, A.second);
    }
    if (x == 2){
      ST.update(y, z);
    }
  }
}