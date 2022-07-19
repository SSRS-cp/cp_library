template <typename T>
struct euler_tour_subtree_query{
	vector<int> left;
	vector<int> right;
	vector<T> A;
	T E;
	function<T(T, T)> f;
	segment_tree<T> ST;
	void dfs(int v, vector<vector<int>> &c, vector<T> &a){
		left[v] = A.size();
		A.push_back(a[v]);
		for (int w : c[v]){
			dfs(w, c, a);
		}
		right[v] = A.size();
	}
	euler_tour_subtree_query(vector<vector<int>> &c, vector<T> &a, function<T(T, T)> f, T E): f(f), E(E){
		int N = c.size();
		left = vector<int>(N);
		right = vector<int>(N);
		dfs(0, c, a);
		ST = segment_tree<T>(A, f, E);
	}
	T operator [](int v){
		return A[left[v]];
	}
	void update(int v, T x){
		A[left[v]] = x;
		ST.update(left[v], x);
	}
	T query(int v){
		return ST.query(left[v], right[v]);
	}
};
