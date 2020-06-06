template <typename T>
struct rerooting{
	vector<T> dp1;
	vector<T> dp2;
	T E;
	function<T(T, T)> add;
	function<T(T)> root;
	void dfs1(vector<vector<int>> &c, int v){
		dp1[v] = E;
		for (auto w : c[v]){
			dfs1(c, w);
			dp1[v] = add(dp1[v], root(dp1[w]));
		}
	}
	void dfs2(vector<vector<int>> &c, int v){
		int deg = c[v].size();
		vector<T> L(deg + 1, E);
		for (int i = 0; i < deg; i++){
			L[i + 1] = add(L[i], root(dp1[c[v][i]]));
		}
		vector<T> R(deg + 1, E);
		for (int i = deg - 1; i >= 0; i--){
			R[i] = add(R[i + 1], root(dp1[c[v][i]]));
		}
		for (int i = 0; i < deg; i++){
			dp2[c[v][i]] = root(add(dp2[v], add(L[i], R[i + 1])));
			dfs2(c, c[v][i]);
		}
	}
	rerooting(vector<vector<int>> &c, function<T(T, T)> add, function<T(T)> root, T E): add(add), root(root), E(E){
		int N = c.size();
		dp1 = vector<T>(N, E);
		dfs1(c, 0);
		dp2 = vector<T>(N, E);
		dfs2(c, 0);
	}
	T operator [](int k){
		return add(dp1[k], dp2[k]);
	}
};
struct rerooting{
	vector<T> dp1;
	vector<T> dp2;
	T E;
	function<T(T, T)> add;
	function<T(T, T)> root;
	void dfs1(vector<vector<pair<int, int>>> &c, int v){
		dp1[v] = E;
		for (auto P : c[v]){
			int w = P.second;
			dfs1(c, w);
			dp1[v] = add(dp1[v], root(dp1[w], P.first));
		}
	}
	void dfs2(vector<vector<pair<int, int>>> &c, int v){
		int deg = c[v].size();
		vector<T> L(deg + 1, E);
		for (int i = 0; i < deg; i++){
			L[i + 1] = add(L[i], root(dp1[c[v][i].second], c[v][i].first));
		}
		vector<T> R(deg + 1, E);
		for (int i = deg - 1; i >= 0; i--){
			R[i] = add(R[i + 1], root(dp1[c[v][i].second], c[v][i].first));
		}
		for (int i = 0; i < deg; i++){
			dp2[c[v][i].second] = root(add(dp2[v], add(L[i], R[i + 1])), c[v][i].first);
			dfs2(c, c[v][i].second);
		}
	}
	rerooting(vector<vector<pair<int, int>>> &c, function<T(T, T)> add, function<T(T, T)> root, T E): add(add), root(root), E(E){
		int N = c.size();
		dp1 = vector<T>(N);
		dfs1(c, 0);
		dp2 = vector<T>(N);
		dfs2(c, 0);
	}
	T operator [](int k){
		return add(dp1[k], dp2[k]);
	}
};
