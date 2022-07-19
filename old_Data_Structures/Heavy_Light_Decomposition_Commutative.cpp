template <typename T>
struct heavy_light_decomposition{
	lowest_common_ancestor LCA;
	vector<int> p;
	vector<int> sz, in, out, next;
	int t;
	segment_tree<T> ST;
	function<T(T, T)> f;
	T E;
	void dfs1(vector<vector<int>> &c, int v = 0){
		sz[v] = 1;
		for (int &w : c[v]){
			dfs1(c, w);
			sz[v] += sz[w];
			if (sz[w] > sz[c[v][0]]){
				swap(w, c[v][0]);
			}
		}
	}
	void dfs2(vector<vector<int>> &c, int v = 0){
		in[v] = t;
		t++;
		for (int w : c[v]){
			if (w == c[v][0]){
				next[w] = next[v];
			} else {
				next[w] = w;
			}
			dfs2(c, w);
		}
		out[v] = t;
	}
	heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, vector<T> &A, function<T(T, T)> f, T E): p(p), f(f), E(E){
		LCA = lowest_common_ancestor(p, c);
		int N = p.size();
		in = vector<int>(N, -1);
		out = vector<int>(N, -1);
		sz = vector<int>(N, -1);
		next = vector<int>(N, 0);
		t = 0;
		dfs1(c);
		dfs2(c);
		vector<T> tmp(N);
		for (int i = 0; i < N; i++){
			tmp[in[i]] = A[i];
		}
		ST = segment_tree<T>(tmp, f, E);
	}
	void update(int v, T x){
		ST.update(in[v], x);
	}
	T path_query(int u, int v){
		int w = LCA.lca(u, v);
		T ans = E;
		while (next[u] != next[w]){
			ans = f(ans, ST.query(in[next[u]], in[u] + 1));
			u = p[next[u]];
		}
		ans = f(ans, ST.query(in[w], in[u] + 1));
		while (next[v] != next[w]){
			ans = f(ans, ST.query(in[next[v]], in[v] + 1));
			v = p[next[v]];
		}
		ans = f(ans, ST.query(in[w] + 1, in[v] + 1));
		return ans;
	}
	T subtree_query(int v){
		return ST.query(in[v], out[v]);
	}
};
