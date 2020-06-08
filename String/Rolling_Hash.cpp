int rh_cnt;
vector<long long> rh_base;
vector<long long> rh_mod;
vector<long long> rh_inv;
vector<vector<long long>> rh_pow;
struct rolling_hash{
	int sz;
	vector<long long> hash;
	rolling_hash(){
		sz = 0;
		for (int i = 0; i < rh_cnt; i++){
			hash.push_back(i);
		}
	}
	int size(){
		return sz;
	}
	void push_back(char c){
		sz++;
		for (int i = 0; i < rh_cnt; i++){
			hash[i] = (hash[i] * rh_base[i] + (int) c) % rh_mod[i];
		}
	}
	void push_front(char c){
		sz++;
		for (int i = 0; i < rh_cnt; i++){
			hash[i] = (hash[i] + (int) c * rh_pow[i][sz]) % rh_mod[i];
		}
	}
	void pop_back(char c){
		sz--;
		for (int i = 0; i < rh_cnt; i++){
			hash[i] = (hash[i] - (int) c + rh_mod[i]) * rh_inv[i] % rh_mod[i];
		}
	}
	void pop_front(char c){
		sz--;
		for (int i = 0; i < rh_cnt; i++){
			hash[i] = (hash[i] - (int) c * rh_pow[i][sz] % rh_mod[i] + rh_mod[i]) % rh_mod[i];
		}
	}
	bool operator ==(rolling_hash RH){
		if (sz != RH.sz){
			return false;
		}
		for (int i = 0; i < rh_cnt; i++){
			if (hash[i] != RH.hash[i]){
				return false;
			}
		}
		return true;
	}
};
rh_cnt = 1;
rh_base = {1000003};
rh_mod = {998244353};
rh_inv = {114156894};
for (int i = 0; i < rh_cnt; i++){
	rh_pow.push_back(vector<long long>(1, 1));
		for (int j = 1; j <= 1000000; j++){
			long long tmp = rh_pow[i].back() * rh_base[i] % rh_mod[i];
			rh_pow[i].push_back(tmp);
	}
}
