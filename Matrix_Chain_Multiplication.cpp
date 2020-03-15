long long matrix_chain_multiplication(vector<long long> &A){
	int n = A.size() - 1;
	vector<vector<long long>> dp(n, vector<long long>(n, INF));
	for (int i = 0; i < n; i++){
		dp[i][i] = 0;
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < n - i; j++){
			for (int k = j; k < j + i; k++){
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + A[j] * A[k + 1] * A[j + i + 1]);
			}
		}
	}
	return dp[0][n - 1];
}
