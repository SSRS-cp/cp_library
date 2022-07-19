vector<long long> xor_fwt(vector<long long> A, bool inv){
	int N = A.size();
	for (int i = 1; i < N; i <<= 1){
		for (int j = 0; j < N; j++){
			if ((j & i) == 0){
				long long x = A[j];
				long long y = A[j | i];
				A[j] = (x + y) % MOD;
				A[j | i] = (x + MOD - y) % MOD;
				if (inv){
					A[j] *= (MOD + 1) / 2;
					A[j] %= MOD;
					A[j | i] *= (MOD + 1) / 2;
					A[j | i] %= MOD;
				}
			}
		}
	}
	return A;
}
vector<long long> xor_convolution(vector<long long> A, vector<long long> B){
	int N = A.size();
	A = xor_fwt(A, false);
	B = xor_fwt(B, false);
	vector<long long> C(N);
	for (int i = 0; i < N; i++){
		C[i] = A[i] * B[i] % MOD;
	}
	C = xor_fwt(C, true);
	return C;
}
