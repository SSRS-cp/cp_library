vector<long long> multipoint_evaluation(vector<long long> &f, vector<long long> x){
  int M = x.size();
  int M2 = 1;
  while (M2 < M){
    M2 *= 2;
  }
  vector<vector<long long>> g(M2 * 2 - 1, {1});
  for (int i = 0; i < M; i++){
    g[M2 - 1 + i] = vector<long long>{MOD - x[i], 1};
  }
  for (int i = M2 - 2; i >= 0; i--){
    g[i] = convolution(g[i * 2 + 1], g[i * 2 + 2]);
  }
  g[0] = polynomial_remainder(f, g[0]);
  for (int i = 1; i < M2 * 2 - 1; i++){
    g[i] = polynomial_remainder(g[(i - 1) / 2], g[i]);
  }
  vector<long long> ans(M);
  for (int i = 0; i < M; i++){
    ans[i] = g[M2 - 1 + i][0];
  }
  return ans;
}
