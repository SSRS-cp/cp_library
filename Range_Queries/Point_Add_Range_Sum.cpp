template <typename T>
struct point_add_range_sum{
	int N;
	vector<T> BIT;
	point_add_range_sum(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		BIT = vector<T>(N + 1, 0);
	}
	void point_add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans;
	}
	T range_sum(int L, int R){
		return sum(R) - sum(L);
	}
	T all_sum(){
		return BIT[N];
	}
};
