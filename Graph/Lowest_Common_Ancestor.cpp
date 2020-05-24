struct lowest_common_ancestor{
	vector<int> d;
	vector<vector<int>> p;
	lowest_common_ancestor(vector<int> &P, vector<vector<int>> &C){
		int N = P.size();
		d = vector<int>(N, 0);
		queue<int> Q;
		Q.push(0);
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			for (int w : C[v]){
				d[w] = d[v] + 1;
				Q.push(w);
			}
		}
		p = vector<vector<int>>(N, vector<int>(LOG, -1));
		for (int i = 0; i < N; i++){
			p[i][0] = P[i];
		}
		for (int i = 1; i < LOG; i++){
			for (int j = 0; j < N; j++){
				if (p[j][i - 1] != -1){
					p[j][i] = p[p[j][i - 1]][i - 1];
				}
			}
		}
	}
	int query(int u, int v){
		if (d[u] > d[v]){
			swap(u, v);
		}
		for (int k = 0; k < LOG; k++){
			if ((d[v] - d[u]) >> k & 1){
				v = p[v][k];
			}
		}
		if (u == v){
		    return u;
		}
		for (int k = LOG - 1; k >= 0; k--){
			if (p[u][k] != p[v][k]){
				u = p[u][k];
				v = p[v][k];
			}
		}
		return p[u][0];
	}
};
