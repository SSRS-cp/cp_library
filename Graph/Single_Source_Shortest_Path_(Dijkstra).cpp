vector<long long> dijkstra(vector<vector<pair<int, int>>> &E, int s){
	int V = E.size();
	vector<long long> d(V, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
	Q.push(make_pair(0, s));
	while (!Q.empty()){
		long long c = Q.top().first;
		int v = Q.top().second;
		Q.pop();
		if (d[v] == INF){
			d[v] = c;
			for (auto P : E[v]){
				Q.push(make_pair(P.first + c, P.second));
			}
		}
	}
	return d;
}
