template <typename T>
struct euler_tour_subtree_query{
	int N;
	vector<vector<int>> c;
	vector<int> left;
	vector<int> right;
	vector<T> value;
	vector<T> A;
	T E;
	function<T(T, T)> f;
	segment_tree<T> ST;
	euler_tour_subtree_query(vector<vector<int>> &C, vector<T> &a, T e, function<T(T, T)> F){
		c = C;
		E = e;
		f = F;
		value = a;
		N = c.size();
		left = vector<int>(N);
		right = vector<int>(N);
	}
	void dfs(int v){
		left[v] = A.size();
		A.push_back(value[v]);
		for (int w : c[v]){
			dfs(w);
		}
		right[v] = A.size();
	}
	void set(){
		dfs(0);
		ST = segment_tree<T>(A, E, f);
	}
	void update(int v, T x){
		ST.update(left[v], x);
	}
	T query(int v){
		return ST.query(left[v], right[v]);
	}
};
