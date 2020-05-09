template <typename T>
struct range_sum{
	int N;
	vector<T> S;
	range_sum(vector<T> A){
		N = A.size();
		S = vector<T>(N + 1, 0);
		for (int i = 0; i < N; i++){
			S[i + 1] = S[i] + A[i];
		}
	}
	query(int p, int q){
		return S[q] - S[p];
	}
	all(){
		return S[N];
	}
};
