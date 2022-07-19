#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include <bits/stdc++.h>
using namespace std;
#include "../../../string/manacher.hpp"
int main(){
  string S;
  cin >> S;
  int N = S.size();
  string T = "$";
  for (int i = 0; i < N; i++){
    T += S[i];
    T += '$';
  }
  vector<int> ans = manacher(T);
  for (int i = 1; i < N * 2; i++){
    cout << ans[i] - 1;
    if (i < N * 2 - 1){
      cout << ' ';
    }
  }
  cout << endl;
}