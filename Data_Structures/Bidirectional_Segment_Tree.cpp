template <typename T>
struct bidirectional_segment_tree{
	int N;
	vector<array<T, 2>> ST;
	function<T(T, T)> f;
	T E;
	bidirectional_segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<array<T, 2>>(N * 2 - 1, array<T, 2>{E, E});
		for (int i = 0; i < n; i++){
			ST[N - 1 + i][0] = A[i];
			ST[N - 1 + i][1] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i][0] = f(ST[i * 2 + 1][0], ST[i * 2 + 2][0]);
			ST[i][1] = f(ST[i * 2 + 2][1], ST[i * 2 + 1][1]);
		}
	}
	void update(int i, T x){
		i += N - 1;
		ST[i][0] = x;
		ST[i][1] = x;
		while (i > 0){
			i = (i - 1) / 2;
			ST[i][0] = f(ST[i * 2 + 1][0], ST[i * 2 + 2][0]);
			ST[i][1] = f(ST[i * 2 + 2][1], ST[i * 2 + 1][1]);
		}
	}
	T query(int L, int R, int i, int l, int r, int d){
		if (R <= l || r <= L){
			return E;
		} else if (L <= l && r <= R){
			return ST[i][d];
		} else {
			int m = (l + r) / 2;
			if (d == 0){
				return f(query(L, R, i * 2 + 1, l, m, d), query(L, R, i * 2 + 2, m, r, d));
			} else {
				return f(query(L, R, i * 2 + 2, m, r, d), query(L, R, i * 2 + 1, l, m, d));
			}
		}
	}
	T query(int L, int R, int d){
		return query(L, R, 0, 0, N, d);
	}
};
