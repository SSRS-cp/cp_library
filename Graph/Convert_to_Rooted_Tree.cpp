vector<int> parent(vector<vector<int>> &E, int r){
	int N = E.size();
	vector<int> p(N, -1);
	queue<int> Q;
	Q.push(r);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int w : E[v]){
			if (p[w] == -1){
				p[w] = v;
				Q.push(w);
			}
		}
	}
	return p;
}
vector<vector<int>> child(vector<vector<int>> E, int r){
	int N = E.size();
	vector<vector<int>> c(N);
	queue<int> Q;
	Q.push(r);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int w : E[v]){
			if (c[w].empty()){
				c[v].push_back(w);
				Q.push(w);
			}
		}
	}
	return c;
}
vector<vector<int>> child_2(vector<int> &p, int r){
	int N = p.size();
	vector<vector<int>> c(N);
	for (int i = 0; i < N; i++){
		if (i != r){
			c[p[i]].push_back(i);
		}
	}
	return c;
}
