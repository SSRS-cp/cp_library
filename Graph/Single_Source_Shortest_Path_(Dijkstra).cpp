vector<long long> dijkstra(vector<vector<pair<int, int>>> &E, int s){
	int N = E.size();
	vector<long long> d(N, INF);
	d[s] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
	Q.push(make_pair(0, s));
	while (!Q.empty()){
		long long c = Q.top().first;
		int v = Q.top().second;
		Q.pop();
		if (d[v] >= c){
			for (auto P : E[v]){
				int w = P.second;
				if (d[w] > d[v] + P.first){
					d[w] = d[v] + P.first;
					Q.push(make_pair(d[w], w));
				}
			}
		}
	}
	return d;
}
pair<long long, vector<int>> dijkstra_path(vector<vector<pair<int, int>>> &E, int s, int t){
	int N = E.size();
	vector<long long> d(N, INF);
	d[s] = 0;
	vector<int> prev(N);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
	Q.push(make_pair(0, s));
	while (!Q.empty()){
		long long c = Q.top().first;
		int v = Q.top().second;
		Q.pop();
		if (d[v] >= c){
			for (auto P : E[v]){
				int w = P.second;
				if (d[w] > d[v] + P.first){
					d[w] = d[v] + P.first;
					Q.push(make_pair(d[w], w));
					prev[w] = v;
				}
			}
		}
	}
	if (d[t] == INF){
		return make_pair(-1, vector<int>());
	} else {
		vector<int> path;
		path.push_back(t);
		while (1){
			int v = path.back();
			if (v == s){
				break;
			}
			path.push_back(prev[v]);
		}
		reverse(path.begin(), path.end());
		return make_pair(d[t], path);
	}
}
