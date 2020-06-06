bool detect_cycle(vector<vector<int>> &E){
	int V = E.size();
	vector<int> deg(V, 0);
	for (int i = 0; i < V; i++){
		for (int j : E[i]){
			deg[j]++;
		}
	}
	queue<int> Q;
	for (int i = 0; i < V; i++){
		if (deg[i] == 0){
			Q.push(i);
		}
	}
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int w : E[v]){
			deg[w]--;
			if (deg[w] == 0){
				Q.push(w);
			}
		}
	}
	for (int i = 0; i < V; i++){
		if (deg[i] != 0){
			return true;
		}
	}
	return false;
}
