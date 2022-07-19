int longest_increasing_subsequence_length(vector<int> &A){
	int N = A.size();
	vector<int> dp(N, INF);
	for (int i = 0; i < N; i++){
		*lower_bound(dp.begin(), dp.end(), A[i]) = A[i];
	}
	return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
