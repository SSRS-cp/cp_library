vector<pair<long long, pair<long long, long long>>> quotient_ranges(long long N){
	vector<pair<long long, pair<long long, long long>>> ans;
	for (long long i = 1; i * i <= N; i++){
		ans.push_back(make_pair(N / i, make_pair(i, i)));
	}
	for (long long i = N / ((long long) sqrt(N) + 1); i >= 1; i--){
		ans.push_back(make_pair(i, make_pair(N / (i + 1) + 1, N / i)));
	}
	return ans;
}
