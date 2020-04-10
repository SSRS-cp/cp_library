bool is_prime(long long N){
	for (long long i = 2; i * i <= N; i++){
		if (N % i == 0){
			return false;
		}
	}
	return true;
}
vector<long long> prime_factorization(long long N){
	vector<long long> ans;
	for (long long i = 2; i * i <= N; i++){
		if (N % i == 0){
			while (N % i == 0){
				N /= i;
				ans.push_back(i);
			}
		}
	}
	if (N != 1){
		ans.push_back(N);
	}
	return ans;
}
int factor_count(long long N){
	int ans = 1;
	for (long long i = 2; i * i <= N; i++){
		if (N % i == 0){
			int e = 0;
			while (N % i == 0){
				N /= i;
				e++;
			}
			ans *= e + 1;
		}
	}
	if (N != 1){
		ans *= 2;
	}
	return ans;
}
