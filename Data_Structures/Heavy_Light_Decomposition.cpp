template <typename T>
struct heavy_light_decomposition{
	lowest_common_ancestor LCA;
	vector<int> p;
	vector<int> sz, in, out, next;
	int t;
	bidirectional_segment_tree<T> ST;
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
		ST = bidirectional_segment_tree(tmp, f, E);
	}
	void update(int v, T x){
		ST.update(in[v], x);
	}
	T query(int u, int v){
		int w = LCA.lca(u, v);
		T tmp1 = E;
		while (next[u] != next[w]){
			tmp1 = f(tmp1, ST.query(in[next[u]], in[u] + 1, 1));
			u = p[next[u]];
		}
		tmp1 = f(tmp1, ST.query(in[w], in[u] + 1, 1));
		T tmp2 = E;
		while (next[v] != next[w]){
			tmp2 = f(ST.query(in[next[v]], in[v] + 1, 0), tmp2);
			v = p[next[v]];
		}
		tmp2 = f(ST.query(in[w] + 1, in[v] + 1, 0), tmp2);
		return f(tmp1, tmp2);
	}
};
