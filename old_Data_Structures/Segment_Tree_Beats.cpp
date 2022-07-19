template <typename T>
struct segment_tree_beats{
	int N;
	vector<T> max1, max2, min1, min2;
	vector<T> add, sum;
	vector<int> maxc, minc, len;
	void update_max(int i, T x){
		sum[i] += (x - max1[i]) * maxc[i];
		if (max1[i] == min1[i]){
			min1[i] = x;
		} else if (max1[i] == min2[i]){
			min2[i] = x;
		}
		max1[i] = x;
	}
	void update_min(int i, T x){
		sum[i] += (x - min1[i]) * minc[i];
		if (min1[i] == max1[i]){
			max1[i] = x;
		} else if (min1[i] == max2[i]){
			max2[i] = x;
		}
		min1[i] = x;
	}
	void update_add(int i, T x){
		max1[i] += x;
		if (max2[i] != -INF){
			max2[i] += x;
		}
		min1[i] += x;
		if (min2[i] != INF){
			min2[i] += x;
		}
		sum[i] += x * len[i];
		add[i] += x;
	}
	void push(int i){
		if (i >= N - 1){
			return;
		}
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		if (add[i] != 0){
			update_add(l, add[i]);
			update_add(r, add[i]);
			add[i] = 0;
		}
		if (max1[i] < max1[l]){
			update_max(l, max1[i]);
		}
		if (min1[i] > min1[l]){
			update_min(l, min1[i]);
		}
		if (max1[i] < max1[r]){
			update_max(r, max1[i]);
		}
		if (min1[i] > min1[r]){
			update_min(r, min1[i]);
		}
	}
	void update(int i){
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		sum[i] = sum[l] + sum[r];
		if (max1[l] > max1[r]){
			max1[i] = max1[l];
			max2[i] = max(max2[l], max1[r]);
			maxc[i] = maxc[l];
		} else if (max1[l] < max1[r]){
			max1[i] = max1[r];
			max2[i] = max(max1[l], max2[r]);
			maxc[i] = maxc[r];
		} else {
			max1[i] = max1[l];
			max2[i] = max(max2[l], max2[r]);
			maxc[i] = maxc[l] + maxc[r];
		}
		if (min1[l] < min1[r]){
			min1[i] = min1[l];
			min2[i] = min(min2[l], min1[r]);
			minc[i] = minc[l];
		} else if (min1[l] > min1[r]){
			min1[i] = min1[r];
			min2[i] = min(min1[l], min2[r]);
			minc[i] = minc[r];
		} else {
			min1[i] = min1[l];
			min2[i] = min(min2[l], min2[r]);
			minc[i] = minc[l] + minc[r];
		}
	}
	segment_tree_beats(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		max1 = vector<T>(N * 2 - 1, -INF);
		max2 = vector<T>(N * 2 - 1, -INF);
		min1 = vector<T>(N * 2 - 1, INF);
		min2 = vector<T>(N * 2 - 1, INF);
		add = vector<T>(N * 2 - 1, 0);
		sum = vector<T>(N * 2 - 1, 0);
		maxc = vector<int>(N * 2 - 1, 0);
		minc = vector<int>(N * 2 - 1, 0);
		len = vector<int>(N * 2 - 1, 1);
		for (int i = 0; i < n; i++){
			max1[N - 1 + i] = A[i];
			min1[N - 1 + i] = A[i];
			sum[N - 1 + i] = A[i];
			maxc[N - 1 + i] = 1;
			minc[N - 1 + i] = 1;
		}
		for (int i = N - 2; i >= 0; i--){
			len[i] = len[i * 2 + 1] + len[i * 2 + 2];
			update(i);
		}
	}
	void range_chmin(int L, int R, T x, int i, int l, int r){
		if (r <= L || R <= l || x >= max1[i]){
			return;
		} else if (L <= l && r <= R && x > max2[i]){
			update_max(i, x);
			return;
		}
		push(i);
		int m = (l + r) / 2;
		range_chmin(L, R, x, i * 2 + 1, l, m);
		range_chmin(L, R, x, i * 2 + 2, m, r);
		update(i);
	}
	void range_chmin(int L, int R, T x){
		range_chmin(L, R, x, 0, 0, N);
	}
	void range_chmax(int L, int R, T x, int i, int l, int r){
		if (r <= L || R <= l || x <= min1[i]){
			return;
		} else if (L <= l && r <= R && x < min2[i]){
			update_min(i, x);
			return;
		}
		push(i);
		int m = (l + r) / 2;
		range_chmax(L, R, x, i * 2 + 1, l, m);
		range_chmax(L, R, x, i * 2 + 2, m, r);
		update(i);
	}
	void range_chmax(int L, int R, T x){
		range_chmax(L, R, x, 0, 0, N);
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (r <= L || R <= l){	
			return;
		} else if (L <= l && r <= R){
			update_add(i, x);
			return;
		}
		push(i);
		int m = (l + r) / 2;
		range_add(L, R, x, i * 2 + 1, l, m);
		range_add(L, R, x, i * 2 + 2, m, r);
		update(i);
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	T range_sum(int L, int R, int i, int l, int r){
		if (r <= L || R <= l){
			return 0;
		} else if (L <= l && r <= R){
			return sum[i];
		}
		push(i);
		int m = (l + r) / 2;
		return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
	}
	T range_sum(int L, int R){
		return range_sum(L, R, 0, 0, N);
	}
};
