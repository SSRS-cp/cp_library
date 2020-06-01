vector<complex<double>> fft(vector<complex<double>> A, bool inv){
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
		for (int j = 0; j < i; j++){
			complex<double> z = polar((double) 1, (2 * PI) / (i * 2) * j * (inv ? -1 : 1));
			for (int k = 0; k < N; k += i * 2){
				complex<double> s = A[j + k];
				complex<double> t = A[j + k + i] * z;
				A[j + k] = s + t;
				A[j + k + i] = s - t;
			}
		}
	}
	if (inv){
		for (int i = 0; i < N; i++){
			A[i] /= N;
		}
	}
	return A;
}
vector<double> convolution(vector<double> A, vector<double> B){
	int deg = A.size() + B.size() - 1;
	int N = 1;
	while (N < deg){
		N *= 2;
	}
	vector<complex<double>> A2(N);
	for (int i = 0; i < A.size(); i++){
		A2[i] = A[i];
	}
	while (A2.size() < N){
		A2.push_back(0);
	}
	vector<complex<double>> B2(N);
	for (int i = 0; i < B.size(); i++){
		B2[i] = B[i];
	}
	while (B2.size() < N){
		B2.push_back(0);
	}
	
	vector<complex<double>> a = fft(A2, false);
	vector<complex<double>> b = fft(B2, false);
	vector<complex<double>> c(N);
	for (int i = 0; i < N; i++){
		c[i] = a[i] * b[i];
	}
	c = fft(c, true);
	vector<double> ans(deg);
	for (int i = 0; i < deg; i++){
		ans[i] = c[i].real();
	}
	return ans;
}
