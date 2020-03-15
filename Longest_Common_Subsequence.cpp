int longest_common_subsequence_length(string &S, string &T){
	vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));
	for (int i = 0; i < S.size(); i++){
		for (int j = 0; j < T.size(); j++){
			if (S[i] == T[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	return dp[S.size()][T.size()];
}
string longest_common_subsequence(string &S, string &T){
	vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));
	for (int i = 0; i < S.size(); i++){
		for (int j = 0; j < T.size(); j++){
			if (S[i] == T[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	string ans;
	int i = S.size();
	int j = T.size();
	while (dp[i][j] > 0){
		if (dp[i - 1][j] == dp[i][j]){
			i--;
		} else if (dp[i][j - 1] == dp[i][j]){
			j--;
		} else {
			i--;
			j--;
			ans += S[i];
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int longest_common_subsequence_length(vector<int> &A, vector<int> &B){
	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
	for (int i = 0; i < A.size(); i++){
		for (int j = 0; j < B.size(); j++){
			if (A[i] == B[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	return dp[A.size()][B.size()];
}
vector<int> longest_common_subsequence(vector<int> &A, vector<int> &B){
	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
	for (int i = 0; i < A.size(); i++){
		for (int j = 0; j < B.size(); j++){
			if (A[i] == B[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	vector<int> ans;
	int i = A.size();
	int j = B.size();
	while (dp[i][j] > 0){
		if (dp[i - 1][j] == dp[i][j]){
			i--;
		} else if (dp[i][j - 1] == dp[i][j]){
			j--;
		} else {
			i--;
			j--;
			ans += A[i];
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
