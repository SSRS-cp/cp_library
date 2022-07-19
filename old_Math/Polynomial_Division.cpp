vector<long long> polynomial_quotient(vector<long long> f, vector<long long> g){
  int N = f.size(), M = g.size();
  if (N < M){
    return {0};
  }
  reverse(g.begin(), g.end());
  g.resize(N - M + 1);
  vector<long long> t = polynomial_inverse(g);
  reverse(f.begin(), f.end());
  vector<long long> q = convolution(f, t, N - M + 1);
  reverse(q.begin(), q.end());
  return q;
}
vector<long long> polynomial_remainder(vector<long long> f, vector<long long> g){
  int N = f.size();
  int M = g.size();
  if (M <= 1200){
    for (int i = N - M; i >= 0; i--){
      long long q = f[i + M - 1] * modinv(g[M - 1]) % MOD;
      for (int j = 0; j < M; j++){
        f[i + j] += MOD - q * g[j] % MOD;
        f[i + j] %= MOD;
      }
      f.pop_back();
    }
    return f;
  } else {
    vector<long long> q = polynomial_quotient(f, g);
    vector<long long> b = convolution(g, q);
    for (int i = 0; i < N; i++){
      f[i] += MOD - b[i];
      f[i] %= MOD;
    }
    f.resize(M - 1);
    return f;
  }
}
