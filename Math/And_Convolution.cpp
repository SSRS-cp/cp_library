vector<long long> and_fwt(vector<long long> A, bool inv){
	int N = A.size();
	for (int i = 1; i < N; i <<= 1){
		for (int j = 0; j < N; j++){
			if ((j & i) == 0){
				if (!inv){
					A[j] += A[j | i];
					A[j] %= MOD;
				} else {
					A[j] -= A[j | i];
					A[j] += MOD;
					A[j] %= MOD;
				}
			}
		}
	}
	return A;
}
vector<long long> and_convolution(vector<long long> A, vector<long long> B){
	int N = A.size();
	A = and_fwt(A, false);
	B = and_fwt(B, false);
	vector<long long> C(N);
	for (int i = 0; i < N; i++){
		C[i] = A[i] * B[i] % MOD;
	}
	C = and_fwt(C, true);
	return C;
}
