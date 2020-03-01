//Input: n, MOD
//Output: (n!) mod MOD
//Order: O(1)
vector<long long> mf;
long long modfact(long long n){
	if (n < mf.size()){
		return mf[n];
	} else {
		if (mf.empty()) mf.push_back(1);
		long long res = mf.back();
		for (int i = mf.size(); i <= n; i++){
			res = res * i % MOD;
			mf.push_back(res);
		}
		return res;
	}
}
