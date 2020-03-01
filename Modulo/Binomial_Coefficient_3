//Input: n, r, MOD
//Output: (nCr) mod MOD
//Time: O(r)
long long modpow(long long a, long long b){
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
long long modbinom(long long n, long long r){
	long long res = 1;
	for (int i = 0; i < r; i++){
		res = res * (n - i) % MOD;
		res = res * modinv(i + 1) % MOD;
	}
	return res;
}
