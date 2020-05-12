template <typename T>
struct range_update_point_value{
	int N;
	vector<pair<T, int>> ST;
	int t;
	range_update_point_value(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<pair<T, int>>(N * 2 - 1, make_pair(0, 0));
		t = 1;
	}
	range_update_point_value(int n, T x){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<pair<T, int>>(N * 2 - 1, make_pair(0, 0));
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = make_pair(x, 1);
		}
		t = 2;
	}
	range_update_point_value(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<pair<T, int>>(N * 2 - 1, make_pair(0, 0));
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = make_pair(A[i], 1);
		}
		t = 2;
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k].first;
		T time = ST[k].second;
		while (k > 0){
			k = (k - 1) / 2;
			if (ST[k].second > time){
				ans = ST[k].first;
				time = ST[k].second;
			}
		}
		return ans;
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = make_pair(x, t);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
		}
	}
	void range_update(int L, int R, T x){
		range_update(L, R, x, 0, 0, N);
		t++;
	}
};
