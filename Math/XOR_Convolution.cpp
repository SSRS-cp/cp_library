vector<long long> fwt(vector<long long> A, int N, bool inv){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < (1 << N); j++){
			if (!(j >> i & 1)){
				long long x = A[j];
				long long y = A[j | (1 << i)];
				A[j] = x + y;
				A[j | (1 << i)] = x - y;
				if (inv){
					A[j] /= 2;
					A[j | (1 << i)] /= 2;
				}
			}
		}
	}
	return A;
}
vector<long long> xor_convolution(vector<long long> A, vector<long long> B, int N){
	A = fwt(A, N, false);
	B = fwt(B, N, false);
	vector<long long> C(1 << N);
	for (int i = 0; i < (1 << N); i++){
	C[i] = A[i] * B[i];
	}
	C = fwt(C, N, true);
	return C;
}
