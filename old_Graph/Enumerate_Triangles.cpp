vector<tuple<int, int, int>> enumerate_triangles(vector<vector<int>> &E){
	int N = E.size();
	vector<int> d(N);
	for (int i = 0; i < N; i++){
		d[i] = E[i].size();
	}
	vector<vector<int>> E2(N);
	for (int i = 0; i < N; i++){
		for (int j : E[i]){
			if (d[i] < d[j] || d[i] == d[j] && i < j){
				E2[i].push_back(j);
			}
		}
	}
	vector<bool> flg(N, false);
	vector<tuple<int, int, int>> ans;
	for (int i = 0; i < N; i++){
		for (int j : E2[i]){
			for (int k : E2[i]){
				flg[k] = true;
			}
			for (int k : E2[j]){
				if (flg[k]){
					ans.push_back(make_tuple(i, j, k));
				}
			}
			for (int k : E2[i]){
				flg[k] = false;
			}
		}
	}
	return ans;
}
