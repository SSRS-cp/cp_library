//range add point value
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	dual_segment_tree(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans += ST[k];
		}
		return ans;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] += x;
			return;
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	void all_add(T x){
		ST[0] += x;
	}
};
