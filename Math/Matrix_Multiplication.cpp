vector<vector<long long>> matmul(vector<vector<long long>> A, vector<vector<long long>> B){
  int N = A.size();
  vector<vector<long long>> ans(N, vector<long long>(N, 0));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        ans[i][k] += A[i][j] * B[j][k];
        ans[i][k] %= MOD;
      }
    }
  }
  return ans;
}
vector<vector<long long>> matexp(vector<vector<long long>> A, long long b){
  int N = A.size();
  vector<vector<long long>> ans(N, vector<long long>(N, 0));
  for (int i = 0; i < N; i++){
    ans[i][i] = 1;
  }
  while (b > 0){
    if (b % 2 == 1){
      ans = matmul(ans, A);
    }
    A = matmul(A, A);
    b /= 2;
  }
  return ans;
}
