vector<vector<long long>> warshall_floyd(vector<vector<pair<int, int>>> &E){
	int V = E.size();
	vector<vector<long long>> d(V, vector<long long>(V, INF));
	for (int i = 0; i < V; i++){
		d[i][i] = 0;
	}
	for (int i = 0; i < V; i++){
		for (int j = 0; j < E[i].size(); j++){
			d[i][E[i][j].second] = E[i][j].first;
		}
	}
	for (int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){
			for (int j = 0; j < V; j++){
				if (d[i][k] != INF && d[k][j] != INF){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	return d;
}
