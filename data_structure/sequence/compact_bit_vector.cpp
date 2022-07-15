struct bit_vector{
  vector<unsigned long long> A;
  vector<int> S;
  bit_vector(){
  }
  bit_vector(vector<bool> &a){
    int N = a.size();
    int M = (N + 64 - 1) >> 6;
    A = vector<unsigned long long>(M, 0);
    for (int i = 0; i < M; i++){
      for (int j = i << 6; j < min((i + 1) << 6, N); j++){
        if (a[j]){
          A[i] |= (unsigned long long) 1 << (j - (i << 6));
        }
      }
    }
    S = vector<int>(M + 1, 0);
    for (int i = 0; i < M; i++){
      S[i + 1] = S[i] + __builtin_popcountll(A[i]);
    }
  }
  int rank(int k, int d){
    int ans;
    if ((k & 63) == 0){
      ans = S[k >> 6];
    } else {
      ans = S[k >> 6] + __builtin_popcountll(A[k >> 6] << (64 - k + (k >> 6 << 6)));
    }
    if (d == 0){
      return k - ans;
    } else {
      return ans;
    }
  }
};
