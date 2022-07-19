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
long long inversion_number(vector<int> &A){
	int N = A.size();
	vector<int> B = A;
	sort(B.begin(), B.end());
	map<int, int> mp;
	for (int i = 0; i < N; i++){
		mp[B[i]] = i + 1;
	}
	for (int i = 0; i < N; i++){
		A[i] = mp[A[i]];
	}
	long long ans = 0;
	vector<int> BIT(N + 1, 0);
	for (int i = 0; i < N; i++){
		ans += i;
		int j = A[i];
		while (j > 0){
			ans -= BIT[j];
			j -= j & -j;
		}
		j = A[i];
		while (j <= N){
			BIT[j]++;
			j += j & -j;
		}
	}
	return ans;
}
