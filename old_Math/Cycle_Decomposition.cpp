vector<vector<int>> cycle_decomposition(vector<int> &P){
	int N = P.size();
	vector<bool> used(N, false);
	vector<vector<int>> ans;
	for (int i = N - 1; i >= 0; i--){
		if (used[i]) continue;
		vector<int> C;
		C.push_back(i);
		while (C.front() != P[C.back()]){
			C.push_back(P[C.back()]);
			used[C.back()] = true;
		}
	ans.push_back(C);
	}
	return ans;
}
