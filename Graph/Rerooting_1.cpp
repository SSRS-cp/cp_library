int dfs1(vector<int> &dp, vector<vector<int>> &c, int v){
	for (int w : c[v]) {
		vp[v] = add(dp[v], root(dfs1(dp, c, w)));
	}
	return dp[v];
}
void dfs2(vector<int> &dp, vector<vector<int>> &c, int v){
	for (int w : c[v]){
		dp[w] = add(dp[w], root(sub(dp[v], root(dp[w]))));
		dfs2(dp, c, w);
	}
}
