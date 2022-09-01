#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include <bits/stdc++.h>
using namespace std;
#include "../../../string/lcp_array.hpp"
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<int> SA = suffix_array(S);
  vector<int> LCP = lcp_array(S, SA);
  long long ans = 1;
  for (int i = 0; i < N - 1; i++){
    ans += i + 2 - LCP[i];
  }
  cout << ans << endl;
}