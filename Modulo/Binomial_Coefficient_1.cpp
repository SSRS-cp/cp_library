//Input: n, r, MOD
//Output: (nCr) mod MOD
//Time: O(n)
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
long long modfact(long long n){
	long long res = 1;
	for (int i = 1; i <= n; i++){
		res = res * i % MOD;
	}
	return res;
}
long long modbinom(long long n, long long r){
	long long res;
	res = modfact(n);
	res = res * modinv(modfact(r)) % MOD;
	res = res * modinv(modfact(n - r)) % MOD;
	return res;
}
