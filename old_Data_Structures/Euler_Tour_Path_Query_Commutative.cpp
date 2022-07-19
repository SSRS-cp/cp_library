template <typename T>
struct euler_tour_path_query_commutative{
	lowest_common_ancestor G;
	vector<T> A;
	vector<int> left;
	vector<int> right;
	T E;
	function<T(T, T)> f;
	function<T(T)> inv;
	segment_tree<T> ST;
	void dfs(int v, vector<vector<int>> &c, vector<T> &a){
		left[v] = A.size();
		A.push_back(a[v]);
		for (int w : c[v]){
			dfs(w, c, a);
		}
		right[v] = A.size();
		A.push_back(inv(a[v]));
	}
	euler_tour_path_query_commutative(vector<int> &p, vector<vector<int>> &c, vector<T> &a, function<T(T, T)> f, T E, function<T(T)> inv): f(f), E(E), inv(inv){
		int N = p.size();
		G = lowest_common_ancestor(p, c);
		left = vector<int>(N);
		right = vector<int>(N);
		dfs(0, c, a);
		ST = segment_tree<T>(A, f, E);
	}
	operator [](int v){
		return A[left[v]];
	}
	void update(int v, T x){
		A[left[v]] = x;
		A[right[v]] = inv(x);
		ST.update(left[v], x);
		ST.update(right[v], inv(x));
	}
	T query(int v, int w){
		int u = G.lca(v, w);
		return f(f(ST.query(left[u], left[v] + 1), ST.query(left[u], left[w] + 1)), inv(A[left[u]]));
	}
};
