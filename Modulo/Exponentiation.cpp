//Input: a, b, MOD
//Output: (a^b) mod MOD
//Time: O(log b)
long long modpow(long long a, long long b){
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
