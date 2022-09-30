#define _GLIBCXX_DEBUG
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <bits/stdc++.h>
using namespace std;
#include "../../../string/suffix_array.hpp"
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<int> A = suffix_array(S);
  for (int i = 0; i < N; i++){
    cout << A[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}