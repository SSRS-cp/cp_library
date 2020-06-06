long long tree_diameter(vector<vector<pair<int, int>>> &E){
	int N = E.size();
	vector<long long> d1(N, INF);
	d1[0] = 0;
	queue<int> Q1;
	Q1.push(0);
	while (!Q1.empty()){
		int v = Q1.front();
		Q1.pop();
		for (auto P : E[v]){
			int c = P.first;
			int w = P.second;
			if (d1[w] == INF){
				d1[w] = d1[v] + c;
				Q1.push(w);
			}
		}
	}
	int s = max_element(d1.begin(), d1.end()) - d1.begin();
	vector<long long> d2(N, INF);
	d2[s] = 0;
	queue<int> Q2;
	Q2.push(s);
	while (!Q2.empty()){
		int v = Q2.front();
		Q2.pop();
		for (auto P : E[v]){
			int c = P.first;
			int w = P.second;
			if (d2[w] == INF){
				d2[w] = d2[v] + c;
				Q2.push(w);
			}
		}
	}
	return *max_element(d2.begin(), d2.end());
}
