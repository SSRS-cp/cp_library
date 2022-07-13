#define PROBLEM "https://yukicoder.me/problems/no/945"
#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
#include "../../data_structure/sequence/dual_sparse_table.cpp"
int main(){
  int N, M;
  cin >> N >> M;
  dual_sparse_table<pair<int, int>> ST(N, [](pair<int, int> a, pair<int, int> b){return min(a, b);}, make_pair(INF, 0));
  for (int i = 0; i < M; i++){
    int L, R;
    char T;
    cin >> L >> R >> T;
    L--;
    if (T == 'Y'){
      ST.apply(L, R, make_pair(i, 0));
    }
    if (T == 'K'){
      ST.apply(L, R, make_pair(i, 1));
    }
    if (T == 'C'){
      ST.apply(L, R, make_pair(i, 2));
    }
  }
  vector<pair<int, int>> A = ST.get();
  vector<int> ans(3, 0);
  for (int i = 0; i < N; i++){
    if (A[i].first != INF){
      ans[A[i].second]++;
    }
  }
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
}
