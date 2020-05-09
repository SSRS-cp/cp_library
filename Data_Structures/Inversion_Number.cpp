long long inversion_number(vector<int> &p){
	int N = p.size();
	long long ans = 0;
	vector<int> bit(N + 1, 0);
	for (int i = 0; i < N; i++){
		ans += i;
		int j = p[i];
		while (j > 0){
			ans -= bit[j];
			j -= j & -j;
		}
		j = p[i];
		while (j <= N){
			bit[j]++;
			j += j & -j;
		}
	}
	return ans;
}
