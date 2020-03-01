//Input: a, MOD
//Output: inverse of a in mod MOD
//Time: O(log MOD)
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
