struct strongly_connected_components{
	vector<vector<int>> E1;
	vector<vector<int>> E2;
	vector<int> t;
	vector<bool> used;
	vector<bool> used2;
	vector<vector<int>> ans;
	void dfs1(int v){
		for (int w : E1[v]){
			if (!used[w]){
				used[w] = true;
				dfs1(w);
			}
		}
		t.push_back(v);
	}
	void dfs2(int v){
		ans.back().push_back(v);
		for (int w : E2[v]){
			if (!used2[w]){
				used2[w] = true;
				dfs2(w);
			}
		}
	}
	strongly_connected_components(vector<vector<int>> &G){
		int V = G.size();
		E1 = vector<vector<int>>(V);
		E2 = vector<vector<int>>(V);
		used = vector<bool>(V, false);
		used2 = vector<bool>(V, false);
		for (int i = 0; i < V; i++){
			for (int j : G[i]){
				E1[i].push_back(j);
				E2[j].push_back(i);
			}
		}
		for (int i = 0; i < V; i++){
			if (!used[i]){
				used[i] = true;
				dfs1(i);
			}
		}
		reverse(t.begin(), t.end());
		for (int i = 0; i < V; i++){
			if (!used2[t[i]]){
				used2[t[i]] = true;
				ans.push_back(vector<int>());
				dfs2(t[i]);
			}
		}
	}
};
