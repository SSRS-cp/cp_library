long long primal_dual(vector<map<int, pair<long long, int>>> &E, int s, int t, long long F){
	int V = E.size();
	for (int i = 0; i < V; i++){
		for (auto edge : E[i]){
			if (!E[edge.first].count(i)){
				E[edge.first][i] = make_pair(0, -edge.second.second);
			}
		}
	}
	long long ans = 0;
	vector<long long> h(V, 0);
	while (F > 0){
		vector<long long> d(V, INF);
		vector<long long> m(V, INF);
		vector<int> prev(V, -1);
		d[s] = 0;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
		Q.push(make_pair(0, s));
		while (!Q.empty()){
			long long c = Q.top().first;
			int v = Q.top().second;
			Q.pop();
			if(d[v] >= c){
				for (auto P : E[v]){
					int w = P.first;
					long long cap = P.second.first;
					int cost = P.second.second;
					if (cap > 0 && d[w] > d[v] + cost + h[v] - h[w]){
						d[w] = d[v] + cost + h[v] - h[w];
						prev[w] = v;
						m[w] = min(m[v], cap);
						Q.push(make_pair(d[w], w));
					}
				}
			}
		}
		if (d[t] == INF){
			return -1;
		}
		for (int i = 0; i < V; i++){
			h[i] += d[i];
		}
		int f = min(m[t], F);
		int c = t;
		while (c != s){
			E[prev[c]][c].first -= f;
			E[c][prev[c]].first += f;
			c = prev[c];
		}
		F -= f;
		ans += f * h[t];
	}
	return ans;
}
