vector<int> suffix_array(string S){
  S.push_back(0);
  int N = S.size();
  vector<int> cnt(128, 0);
  for (int i = 0; i < N; i++){
    cnt[S[i]]++;
  }
  for (int i = 0; i < 127; i++){
    cnt[i + 1] += cnt[i];
  }
  vector<int> SA(N), rank(N);
  for (int i = 0; i < N; i++){
    cnt[S[i]]--;
    SA[cnt[S[i]]] = i;
  }
  rank[SA[0]] = 0;
  for (int i = 0; i < N - 1; i++){
    rank[SA[i + 1]] = rank[SA[i]];
    if (S[SA[i]] != S[SA[i + 1]]){
      rank[SA[i + 1]]++;
    }
  }
  int L = 1;
  while (L < N){
    vector<int> SA2(N), rank2(N);
    for (int i = 0; i < N; i++){
      SA2[i] = SA[i] - L;
      if (SA2[i] < 0){
        SA2[i] += N;
      }
    }
    cnt = vector<int>(N, 0);
    for (int i = 0; i < N; i++){
      cnt[rank[SA2[i]]]++;
    }
    for (int i = 0; i < N - 1; i++){
      cnt[i + 1] += cnt[i];
    }
    for (int i = N - 1; i >= 0; i--){
      cnt[rank[SA2[i]]]--;
      SA[cnt[rank[SA2[i]]]] = SA2[i];
    }
    rank2[SA[0]] = 0;
    for (int i = 0; i < N - 1; i++){
      rank2[SA[i + 1]] = rank2[SA[i]];
      if (rank[SA[i]] != rank[SA[i + 1]] || rank[(SA[i] + L) % N] != rank[(SA[i + 1] + L) % N]){
        rank2[SA[i + 1]]++;
      }
    }
    rank = rank2;
    L *= 2;
  }
  SA.erase(SA.begin());
  return SA;
};
