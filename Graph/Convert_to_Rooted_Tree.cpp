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
vector<vector<int>> child(vector<int> &p){
	int N = p.size();
	vector<vector<int>> c(N);
	for (int i = 1; i < N; i++){
		c[p[i]].push_back(i);
	}
	return c;
}
