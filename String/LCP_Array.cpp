vector<int> lcp_array(string &S, vector<int> &SA){
  int N = S.size();
  vector<int> rank(N);
  for (int i = 0; i < N; i++){
    rank[SA[i]] = i;
  }
  vector<int> lcp(N - 1, 0);
  int h = 0;
  for (int i = 0; i < N; i++){
    if (rank[i] > 0){
      int prev = SA[rank[i] - 1];
      if (h > 0){
        h--;
      }
      while (i + h < N && prev + h < N){
        if (S[i + h] != S[prev + h]){
          break;
        }
        h++;
      }
      lcp[rank[i] - 1] = h;
    }
  }
  return lcp;
}
