vector<int> suffix_array(string S){
  int N = S.size();
  vector<int> sa(N + 1), rank(N + 1);
  for (int i = 0; i <= N; i++){
    sa[i] = i;
    if (i < N){
      rank[i] = S[i];
    } else {
      rank[i] = -1;
    }
  }
  for (int i = 1; i <= N; i *= 2){
    vector<pair<pair<int, int>, int>> P(N + 1);
    for (int j = 0; j <= N; j++){
      if (sa[j] + i <= N){
        P[j] = make_pair(make_pair(rank[sa[j]], rank[sa[j] + i]), sa[j]);
      } else {
        P[j] = make_pair(make_pair(rank[sa[j]], -1), sa[j]);
      }
    }
    sort(P.begin(), P.end());
    for (int j = 0; j <= N; j++){
      sa[j] = P[j].second;
    }
    vector<int> tmp(N + 1);
    tmp[sa[0]] = 0;
    for (int j = 1; j <= N; j++){
      tmp[sa[j]] = tmp[sa[j - 1]];
      pair<int, int> P1;
      if (sa[j - 1] + i <= N){
        P1 = make_pair(rank[sa[j - 1]], rank[sa[j - 1] + i]);
      } else {
        P1 = make_pair(rank[sa[j - 1]], -1);
      }
      pair<int, int> P2;
      if (sa[j] + i <= N){
        P2 = make_pair(rank[sa[j]], rank[sa[j] + i]);
      } else {
        P2 = make_pair(rank[sa[j]], -1);
      }
      if (P1 < P2){
        tmp[sa[j]]++;
      }
    }
    rank = tmp;
  }
  sa.erase(sa.begin());
  return sa;
}
