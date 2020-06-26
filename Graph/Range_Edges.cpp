0000000000;
template <typename T>
struct range_edges{
	int N;
	int V;
	vector<vector<pair<T, int>>> E;
	range_edges(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		V = N * 5 - 2;
		E = vector<vector<pair<T, int>>>(V);
		for (int i = 0; i < N - 1; i++){
			E[i].emplace_back(0, i * 2 + 1);
			E[i].emplace_back(0, i * 2 + 2);
			E[i * 2 + N * 2].emplace_back(0, i + N * 2 - 1);
			E[i * 2 + N * 2 + 1].emplace_back(0, i + N * 2 - 1);
		}
		for (int i = 0; i < N; i++){
			E[N - 1 + i].emplace_back(0, N * 4 - 2 + i);
			E[N * 4 - 2 + i].emplace_back(0, N * 3 - 2 + i);
		}
	}
	void add_edge_from(int L, int R, int v, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			E[i + N * 2 - 1].emplace_back(0, v);
		} else {
			int m = (l + r) / 2;
			add_edge_from(L, R, v, i * 2 + 1, l, m);
			add_edge_from(L, R, v, i * 2 + 2, m, r);
		}
	}
	void add_edge_from(int L, int R, int v){
		add_edge_from(L, R, v, 0, 0, N);
	}
	void add_edge_to(int L, int R, int v, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			E[v].emplace_back(0, i);
		} else {
			int m = (l + r) / 2;
			add_edge_to(L, R, v, i * 2 + 1, l, m);
			add_edge_to(L, R, v, i * 2 + 2, m, r);
		}
	}
	void add_edge_to(int L, int R, int v){
		add_edge_to(L, R, v, 0, 0, N);
	}
	void add_edge(int L1, int R1, int L2, int R2, T cost){
		E.emplace_back();
		E.emplace_back();
		V += 2;
		add_edge_from(L1, R1, V - 2);
		add_edge_to(L2, R2, V - 1);
		E[V - 2].emplace_back(cost, V - 1);
	}
	void debug(){
		for (int i = 0; i < V; i++){
			cout << i << ":";
			for (auto P : E[i]){
				cout << " (" << P.first << "," << P.second << ")";
			}
			cout << endl;
		}
	}
};
