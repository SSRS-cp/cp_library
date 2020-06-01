vector<long long> ntt(vector<long long> A, bool inv){
	int N = A.size();
	int M = 0;
	for (int i = 1; i < N; i *= 2){
		M++;
	}
	for (int i = 0; i < N; i++){
		int j = 0;
		for (int k = 0; k < M; k++){
			if ((i >> k) & 1){
				j |= 1 << (M - 1 - k);
			}
		}
		if (i < j){
			swap(A[i], A[j]);
		}
	}
	for (int i = 1; i < N; i *= 2){
		long long z = modpow(3, (MOD - 1) / (i * 2));
		if (inv){
			z = modinv(z);
		}
		long long z2 = 1;
		for (int j = 0; j < i; j++){
			for (int k = 0; k < N; k += i * 2){
				long long s = A[j + k];
				long long t = A[j + k + i] * z2 % MOD;
				A[j + k] = (s + t) % MOD;
				A[j + k + i] = (s - t + MOD) % MOD;;
			}
			z2 = z2 * z % MOD;
		}
	}
	if (inv){
		int Ninv = modinv(N);
		for (int i = 0; i < N; i++){
			A[i] = A[i] * Ninv % MOD;
		}
	}
	return A;
}
vector<long long> convolution(vector<long long> A, vector<long long> B){
	int deg = A.size() + B.size() - 1;
	int N = 1;
	while (N < deg){
		N *= 2;
	}
	while (A.size() < N){
		A.push_back(0);
	}
	while (B.size() < N){
		B.push_back(0);
	}
	vector<long long> a = ntt(A, false);
	vector<long long> b = ntt(B, false);
	vector<long long> c(N);
	for (int i = 0; i < N; i++){
		c[i] = a[i] * b[i] % MOD;
	}
	c = ntt(c, true);
	vector<long long> ans(deg);
	for (int i = 0; i < deg; i++){
		ans[i] = c[i];
	}
	return ans;
}
