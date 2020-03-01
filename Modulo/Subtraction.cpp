//Input: a, b, MOD
//Output: (a - b) mod MOD
//Time: O(1)
long long modsub(long long a, long long b){
	if (a >= b){
		return (a - b) % MOD;
	} else {
		return p - (b - a) % MOD;
	}
}
