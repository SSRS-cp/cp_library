//Range Sum
template <typename T>
struct prefix_sum{
	int N;
	vector<T> S;
	prefix_sum(vector<T> A){
		N = A.size();
		S = vector<T>(N + 1, 0);
		for (int i = 0; i < N; i++){
			S[i + 1] = S[i] + A[i];
		}
	}
	T range_sum(int p, int q){
		return S[q] - S[p];
	}
	T all(){
		return S[N];
	}
};
