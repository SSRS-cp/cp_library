vector<long long> polynomial_inverse(vector<long long> f){
  int N = f.size();
  vector<long long> ans(1);
  ans[0] = modinv(f[0]);
  for (int i = 1; i < N * 2; i *= 2){
    vector<long long> ans2 = ans;
    ans2.resize(i * 4);
    int N2 = min(N, i * 2);
    vector<long long> f2(i * 4, 0);
    for (int j = 0; j < N2; j++){
      f2[j] = f[j];
    }
    ans2 = convolution(ans2, ans2, i * 2);
    ans2 = convolution(ans2, f2, i * 2);
    for (int j = 0; j < i; j++){
      ans2[j] = MOD - ans2[j] + ans[j] * 2;
      ans2[j] %= MOD;
    }
    swap(ans, ans2);
  }
  ans.resize(N);
  return ans;
}
