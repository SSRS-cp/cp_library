long long euler_phi(long long x){
	long long ans = x;
	for (long long i = 2; i * i <= x; i++){
		if (x % i == 0){
			ans /= i;
			ans *= i - 1;
			while (x % i == 0){
				x /= i;
			}
		}
	}
	if (x > 1){
		ans /= x;
		ans *= x - 1;
	}
	return ans;
}
