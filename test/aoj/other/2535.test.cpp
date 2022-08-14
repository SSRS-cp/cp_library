#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2535"
#define ERROR 0.0000001
#include <bits/stdc++.h>
using namespace std;
#include "other/poker_hands.hpp"
vector<int> hand2(vector<card> C){
  vector<int> ans;
  vector<int> p = {0, 0, 1, 1, 1, 1, 1};
  while (true){
    array<card, 5> C2;
    int cnt = 0;
    for (int i = 0; i < 7; i++){
      if (p[i] == 1){
        C2[cnt] = C[i];
        cnt++;
      }
    }
    ans = max(ans, hand(C2));
    if (!next_permutation(p.begin(), p.end())){
      break;
    }
  }
  return ans;
}
int main(){
  cout << fixed << setprecision(20);
  while (true){
    vector<card> C(9);
    for (int i = 0; i < 7; i++){
      cin >> C[i];
    }
    if (!cin){
      break;
    }
    string suits = "SHDC";
    int cnt1 = 0, cnt2 = 0;
    for (int s1 = 0; s1 < 4; s1++){
      for (int r1 = 2; r1 <= 14; r1++){
        for (int s2 = 0; s2 < 4; s2++){
          for (int r2 = 2; r2 <= 14; r2++){
            C[7].suit = suits[s1];
            C[7].rank = r1;
            C[8].suit = suits[s2];
            C[8].rank = r2;
            bool ok = true;
            for (int i = 0; i < 9; i++){
              for (int j = i + 1; j < 9; j++){
                if (C[i].suit == C[j].suit && C[i].rank == C[j].rank){
                  ok = false;
                }
              }
            }
            if (ok){
              vector<card> A = {C[0], C[1], C[4], C[5], C[6], C[7], C[8]};
              vector<card> B = {C[2], C[3], C[4], C[5], C[6], C[7], C[8]};
              if (hand2(A) > hand2(B)){
                cnt1++;
              }
              cnt2++;
            }
          }
        }
      }
    }
    cout << (double) cnt1 / cnt2 << endl;
  }
}