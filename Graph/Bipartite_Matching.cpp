int bipartite_matching(vector<pair<int, int>> &E, int X, int Y){
	int V = X + Y + 2;
	vector<set<int>> E2(V);
	for (int i = 0; i < X; i++){
		E2[0].insert(i + 1);
	}
	for (int i = 0; i < E.size(); i++){
		int v = E[i].first;
		int w = E[i].second;
		E2[v + 1].insert(X + 1 + w);
	}
	for (int i = X + 1; i < V - 1; i++){
		E2[i].insert(V - 1);
	}
	int F = 0;
	while (1){
		vector<bool> used(V, false);
		vector<int> prev(V, -1);
		used[0] = true;
		queue<int> Q;
		Q.push(0);
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			for (int w : E2[v]){
				if (!used[w]){
					used[w] = true;
					prev[w] = v;
					Q.push(w);
				}
			}
		}
		if (!used[V - 1]){
			break;
		}
		int c = V - 1;
		while (c != 0){
			E2[prev[c]].erase(c);
			E2[c].insert(prev[c]);
			c = prev[c];
		}
		F++;
	}
	return F;
}
