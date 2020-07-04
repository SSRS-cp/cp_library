const long long MOD = 1000000007;
long long modsub(long long a, long long b){
	return (a % MOD - b % MOD + MOD) % MOD;
}
long long modpow(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a){
  return modpow(a, MOD - 2);
}
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n){
  if (mf.size() > n){
    return mf[n];
  } else {
    for (int i = mf.size(); i <= n; i++){
      long long next = mf.back() * i % MOD;
      mf.push_back(next);
      mfi.push_back(modinv(next));
    }
    return mf[n];
  }
}
long long modfactinv(int n){
  if (mfi.size() > n){
    return mfi[n];
  } else {
    return modinv(modfact(n));
  }
}
long long modbinom(int n, int k){
  if (n < 0 || k < 0 || k > n){
    return 0;
  } else {
    return modfact(n) * modfactinv(k) % MOD * modfactinv(n - k) % MOD;
  }
}
long long modbinom2(long long n, int r){
	long long ans = 1;
	for (int i = 0; i < r; i++){
		ans = ans * ((n - i) % MOD) % MOD;
		ans = ans * modinv(i + 1) % MOD;
	}
	return ans;
}
