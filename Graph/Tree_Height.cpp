vector<int> tree_height(vector<vector<int>> &E){
	int N = E.size();
	vector<int> d(N, -1);
	d[0] = 0;
	queue<int> Q;
	Q.push(0);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int w : E[v]){
			if (d[w] == -1){
				d[w] = d[v] + 1;
				Q.push(w);
			}
		}
	}
	int s = max_element(d.begin(), d.end()) - d.begin();
	vector<int> d2(N, -1);
	d2[s] = 0;
	queue<int> Q2;
	Q2.push(s);
	while (!Q2.empty()){
		int v = Q2.front();
		Q2.pop();
		for (int w : E[v]){
			if (d2[w] == -1){
				d2[w] = d2[v] + 1;
				Q2.push(w);
			}
		}
	}
	int t = max_element(d2.begin(), d2.end()) - d2.begin();
	vector<int> d3(N, -1);
	d3[t] = 0;
	queue<int> Q3;
	Q3.push(t);
	while (!Q3.empty()){
		int v = Q3.front();
		Q3.pop();
		for (int w : E[v]){
			if (d3[w] == -1){
				d3[w] = d3[v] + 1;
				Q3.push(w);
			}
		}
	}
	vector<int> ans(N);
	for (int i = 0; i < N; i++){
		ans[i] = max(d2[i], d3[i]);
	}
	return ans;
}
