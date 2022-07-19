struct rolling_hash{
  vector<long long> S;
  rolling_hash(string s){
    int N = s.size();
    S = vector<long long>(N + 1, 0);
    for (int i = N - 1; i >= 0; i--){
      S[i] = (S[i + 1] * BASE + s[i]) % MOD;
    }
  }
  long long get(int L, int R){
    return (S[L] - S[R] * POW[R - L] % MOD + MOD) % MOD;
  }
};
