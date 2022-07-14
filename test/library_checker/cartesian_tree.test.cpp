#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include <bits/stdc++.h>
using namespace std;
#include "../../data_structure/other/cartesian_tree_min.cpp"
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<int> p = cartesian_tree(a);
  for (int i = 0; i < N; i++){
    if (p[i] == -1){
      cout << i;
    } else {
      cout << p[i];
    }
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
