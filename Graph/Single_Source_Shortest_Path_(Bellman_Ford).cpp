vector<long long> bellman_ford(vector<vector<pair<int, int>>> &E, int s){
	int V = E.size();
	vector<long long> d(V, INF);
	d[s] = 0;
	while (1){
		bool update = false;
		for (int i = 0; i < V; i++){
			for (int j = 0; j < E[i].size(); j++){
				int c = E[i][j].first;
				int v = E[i][j].second;
				if (d[v] > d[i] + c && d[i] != INF){
					d[v] = d[i] + c;
					update = true;
				}
			}
		}
		if (!update){
			break;
		}
	}
	return d;
}
bool detect_negative_cycles(vector<vector<pair<int, int>>> &E, int s){
	int V = E.size();
	vector<long long> d(V, INF);
	d[s] = 0;
	for (int i = 0; i < V; i++){
		bool update = false;
		for (int j = 0; j < V; j++){
			for (int k = 0; k < E[j].size(); k++){
				int c = E[j][k].first;
				int v = E[j][k].second;
				if (d[v] > d[j] + c && d[j] != INF){
					d[v] = d[j] + c;
					update = true;
					if (i == V - 1){
						return true;
					}
				}
			}
		}
		if (!update){
			break;
		}
	}
	return false;
}
vector<bool> find_negative_cycles(vector<vector<pair<int, int>>> &E){
	int V = E.size();
	vector<long long> d(V, 0);
	for (int i = 0; i < V; i++){
		bool update = false;
		for (int j = 0; j < V; j++){
			for (int k = 0; k < E[j].size(); k++){
				int c = E[j][k].first;
				int v = E[j][k].second;
				if (d[v] > d[j] + c){
					d[v] = d[j] + c;
					update = true;
				}
			}
		}
		if (!update){
			break;
		}
	}
	vector<bool> res(V, false);
	for (int i = 0; i < V; i++){
		if (d[i] < 0){
			res[i] = true;
		}
	}
	return res;
}
	
