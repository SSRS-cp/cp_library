int minimum_cost_arborescence(vector<vector<pair<int, int>>> E, int r){
	int ans = 0;
	while (true){
		int N = E.size();
		vector<int> mn(N, INF), p(N, -1);
		for (int i = 0; i < N; i++){
			for (auto P : E[i]){
				int c = P.first;
				int w = P.second;
				if (w != r && mn[w] > c){
					mn[w] = c;
					p[w] = i;
				}
			}
		}
		vector<int> d(N, 0);
		for (int i = 0; i < N; i++){
			if (i != r){
				d[p[i]]++;
			}
		}
		queue<int> Q;
		for (int i = 0; i < N; i++){
			if (i != r && d[i] == 0){
				Q.push(i);
			}
		}
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			if (v != r){
				d[p[v]]--;
				if (d[p[v]] == 0){
					Q.push(p[v]);
				}
			}
		}
		vector<int> cycle;
		vector<int> id(N, -1);
		for (int i = 0; i < N; i++){
			if (d[i] == 1){
				cycle.push_back(i);
				while (true){
					int v = cycle.back();
					id[v] = 0;
					ans += mn[v];
					if (p[v] == i){
						break;
					}
					cycle.push_back(p[v]);
				}
				break;
			}
		}
		if (cycle.empty()){
			for (int i = 0; i < N; i++){
				if (i != r){
					ans += mn[i];
				}
			}
			break;
		}
		int cnt = 1;
		for (int i = 0; i < N; i++){
			if (id[i] == -1){
				id[i] = cnt;
				cnt++;
			}
		}
		vector<vector<pair<int, int>>> E2(cnt);
		for (int i = 0; i < N; i++){
			for (auto P : E[i]){
				int c = P.first;
				int w = P.second;
				if (id[w] == 0){
					c -= mn[w];
				}
				if (id[i] != id[w]){
					E2[id[i]].push_back(make_pair(c, id[w]));
				}
			}
		}
		swap(E, E2);
		swap(r, id[r]);
	}
	return ans;
}
