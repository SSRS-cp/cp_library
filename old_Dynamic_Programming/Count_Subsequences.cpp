long long count_subsequences(string &S){
	int N = S.size();
	vector<vector<int>> next(N + 1, vector<int>(26, N));
	for (int i = N - 1; i >= 0; i--){
		for (int j = 0; j < 26; j++){
		next[i][j] = next[i + 1][j];
		}
		next[i][S[i] - 'a'] = i;
	}
	vector<long long> dp(N + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 26; j++){
			if (next[i][j] < N){
				dp[next[i][j] + 1] = (dp[next[i][j] + 1] + dp[i]) % MOD;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= N; i++){
		ans = (ans + dp[i]) % MOD;
	}
	return ans;
}
