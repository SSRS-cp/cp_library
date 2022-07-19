template <typename T>
struct naive{
	int N;
	vector<T> A;
	naive(int N): N(N){
		A = vector<T>(N);
	}
	naive(int N, T x): N(N){
		A = vector<T>(N, x);
	}
	naive(vector<T> A): A(A){
		N = A.size();
	}
	void update(int i, T x){
		A[i] = x;
	}
	void add(int i, T x){
		A[i] += x;
	}
	void chmin(int i, T x){
		A[i] = min(A[i], x);
	}
	void chmax(int i, T x){
		A[i] = max(A[i], x);
	}
	void range_update(int L, int R, T x){
		for (int i = L; i < R; i++){
			A[i] = x;
		}
	}
	void range_add(int L, int R, T x){
		for (int i = L; i < R; i++){
			A[i] += x;
		}
	}
	void range_chmin(int L, int R, T x){
		for (int i = L; i < R; i++){
			A[i] = min(A[i], x);
		}
	}
	void range_chmax(int L, int R, T x){
		for (int i = L; i < R; i++){
			A[i] = max(A[i], x);
		}
	}
	T operator [](int i){
		return A[i];
	}
	T range_sum(int L, int R){
		T ans = 0;
		for (int i = L; i < R; i++){
			ans += A[i];
		}
		return ans;
	}
	T range_min(int L, int R){
		T ans = INF;
		for (int i = L; i < R; i++){
			ans = min(ans, A[i]);
		}
		return ans;
	}
	T range_max(int L, int R){
		T ans = -INF;
		for (int i = L; i < R; i++){
			ans = max(ans, A[i]);
		}
		return ans;
	}
	void debug(){
		cout << "[";
		for (int i = 0; i < N; i++){
			cout << A[i];
			if (i < N - 1){
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
};
