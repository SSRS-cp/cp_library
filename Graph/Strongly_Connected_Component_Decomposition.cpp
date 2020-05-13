struct strongly_connected_components{
	int V;
	vector<vector<int>> E1;
	vector<vector<int>> E2;
	vector<int> t;
	vector<bool> used;
	vector<int> scc;
	int count;
	strongly_connected_components(vector<vector<int>> &G){
		V = G.size();
		E1 = vector<vector<int>>(V);
		E2 = vector<vector<int>>(V);
		used = vector<bool>(V, false);
		scc = vector<int>(V, -1);
		count = 0;
		for (int i = 0; i < V; i++){
			for (int j : G[i]){
				E1[i].push_back(j);
				E2[j].push_back(i);
			}
		}
	}
	void dfs1(int v){
		for (int w : E1[v]){
			if (!used[w]){
				used[w] = true;
				dfs1(w);
			}
		}
		t.push_back(v);
	}
	void dfs2(int v, int k){
		for (int w : E2[v]){
			if (scc[w] == -1){
				scc[w] = k;
				dfs2(w, k);
			}
		}
	}
	void decomp(){
		for (int i = 0; i < V; i++){
			if (!used[i]){
				used[i] = true;
				dfs1(i);
			}
		}
		reverse(t.begin(), t.end());
		for (int i = 0; i < V; i++){
			if (scc[t[i]] == -1){
				scc[t[i]] = count;
				dfs2(t[i], count);
				count++;
			}
		}
	}
	int operator [](int k){
		return scc[k];
	}
};
