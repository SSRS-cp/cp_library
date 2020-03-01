//Input: n, MOD
//Output: (n!) mod MOD
//Time: O(n)
long long modfact(long long n){
	long long res = 1;
	for (int i = 1; i <= n; i++){
		res = res * i % MOD;
	}
	return res;
}
