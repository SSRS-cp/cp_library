//point update range min
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
	}
	segment_tree(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T operator [](int k){
		return ST[N - 1 + k];
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = min(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T range_min(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
		}
	}
	T range_min(int L, int R){
		return range_min(L, R, 0, 0, N);
	}
	T all(){
		return ST[0];
	}
};
