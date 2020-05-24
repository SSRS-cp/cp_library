template <typename T>
struct euler_tour_subtree_query{
	vector<T> A;
	vector<int> left;
	vector<int> right;
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
	euler_tour_subtree_query(vector<vector<int>> &c, vector<T> &a, T e, function<T(T, T)> F){
		E = e;
		f = F;
		int N = c.size();
		left = vector<int>(N);
		right = vector<int>(N);
		dfs(0, c, a);
		ST = segment_tree<T>(A, E, f);
	}
	void update(int v, T x){
		ST.update(left[v], x);
	}
	T query(int v){
		return ST.query(left[v], right[v]);
	}
};
