double PI = acos(-1);
vector<complex<double>> fft(vector<complex<double>> A, bool inv){
	int N = A.size();
	complex<double> r = polar((double) 1, (2 * PI) / (N));
	if (inv){
		r = pow(r, -1);
	}
	vector<complex<double>> B(N);
	for (int i = N / 2; i > 0; i /= 2){
		complex<double> z = pow(r, i);
		complex<double> z2 = 1;
		for (int j = 0; j < N; j += i * 2){
			for (int k = 0; k < i; k++){
				A[i + j + k] *= z2;
				B[j / 2 + k] = A[j + k] + A[i + j + k];
				B[N / 2 + j / 2 + k] = A[j + k] - A[i + j + k];
			}
			z2 *= z;
		}
		swap(A, B);
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
	vector<complex<double>> A2(N, 0);
	for (int i = 0; i < A.size(); i++){
		A2[i] = A[i];
	}
	vector<complex<double>> B2(N, 0);
	for (int i = 0; i < B.size(); i++){
		B2[i] = B[i];
	}
	A2 = fft(A2, false);
	B2 = fft(B2, false);
	vector<complex<double>> C2(N);
	for (int i = 0; i < N; i++){
		C2[i] = A2[i] * B2[i];
	}
	C2 = fft(C2, true);
	vector<double> C(deg);
	for (int i = 0; i < deg; i++){
	  C[i] = C2[i].real();
	}
	return C;
}
