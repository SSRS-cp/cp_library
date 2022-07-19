struct trie{
	int N;
	vector<tuple<vector<int>, char, bool>> T;
	trie(){
		T = vector<tuple<vector<int>, char, bool>>(1);
		T[0] = make_tuple(vector<int>(), ' ', false);
	}
	void insert(string s){
		int v = 0;
		for (char c : s){
			bool flg = false;
			for (int i : get<0>(T[v])){
				if (get<1>(T[i]) == c){
					v = i;
					flg = true;
					break;
				}
			}
			if (!flg){
				get<0>(T[v]).push_back(T.size());
				v = T.size();
				T.push_back(make_tuple(vector<int>(), c, false));
			}
		}
		get<2>(T[v]) = true;
	}
	vector<bool> query(string s){
		int M = s.size();
		int v = 0;
		vector<bool> ans(M, false);
		for (int i = 0; i < M; i++){
			bool flg = falsr;
			for (int j : get<0>(T[v])){
				if (get<1>(T[j]) == s[i]){
					v = j;
					flg = true;
					break;
				}
			}
			if (flg){
				ans[i] = get<2>(T[v]);
			} else {
				break;
			}
		}
		return ans;
	}
};
