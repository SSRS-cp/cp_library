#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A"
#include <bits/stdc++.h>
using namespace std;
#include "../../../data_structure/sequence/wavelet_matrix.hpp"
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  wavelet_matrix WM(a);
  for (int i = n - 1; i >= 0; i--){
    cout << WM[i];
    if (i > 0){
      cout << ' ';
    }
  }
  cout << endl;
}