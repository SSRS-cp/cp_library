int dfs1(vector<int> &dp, vector<vector<int>> &c, int v){
	dp[v] = 1;
	for (int w : c[v]) dp[v] = add(dp[v], root(dfs1(dp, c, w)));
	return dp[v];
}
void dfs2(vector<int> &dp1, vector<int> &dp2, vector<vector<int>> &c, int v){
	int deg = c[v].size();
	vector<int> L(deg + 1, 1), R(deg + 1, 1);
	for (int i = 0; i < deg; i++) L[i + 1] = add(L[i], root(dp1[c[v][i]]));
	for (int i = deg - 1; i >= 0; i--) R[i] = add(R[i + 1], root(dp1[c[v][i]]));
	for (int i = 0; i < deg; i++){
		dp2[c[v][i]] = root(add(dp2[v], add(L[i], R[i + 1])));
		dfs2(dp1, dp2, c, c[v][i]);
	}
}
