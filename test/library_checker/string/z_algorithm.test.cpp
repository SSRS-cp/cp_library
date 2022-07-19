#include <bits/stdc++.h>
using namespace std;
#include "../../../string/z_algorithm.hpp"
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<int> ans = z_algorithm(S);
  for (int i = 0; i < N; i++){
    cout << ans[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}