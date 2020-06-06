int ford_fulkerson(vector<unordered_map<int, int>> &E, int s, int t){
	int V = E.size();
	int F = 0;
	while (1){
		vector<int> d(V, INF);
		vector<int> m(V, INF);
		vector<int> prev(V, -1);
		d[s] = 0;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			for (auto P : E[v]){
				int w = P.first;
				if (d[w] == INF){
					prev[w] = v;
					d[w] = d[v] + 1;
					m[w] = min(m[v], P.second);
					Q.push(w);
				}
			}
		}
		if (d[t] == INF){
			break;
		}
		int f = m[t];
		int c = t;
		while (c != 0){
			if (E[prev[c]][c] == f){
				E[prev[c]].erase(c);
			} else {
				E[prev[c]][c] -= f;
			}
			E[c][prev[c]] += f;
			c = prev[c];
		}
		F += f;
	}
	return F;
}
struct ford_fulkerson{
	vector<unordered_map<int, int>> E;
	int V;
	int F;
	ford_fulkerson(vector<unordered_map<int, int>> &E): E(E), V(E.size()), F(0){
	}
	int max_flow(){
		while (1){
			vector<int> d(V, INF);
			vector<int> m(V, INF);
			vector<int> prev(V, -1);
			d[0] = 0;
			queue<int> Q;
			Q.push(0);
			while (!Q.empty()){
				int v = Q.front();
				Q.pop();
				for (auto P : E[v]){
					int w = P.first;
					if (d[w] == INF){
						prev[w] = v;
						d[w] = d[v] + 1;
						m[w] = min(m[v], P.second);
						Q.push(w);
					}
				}
			}
			if (d[V - 1] == INF){
				break;
			}
			int f = m[V - 1];
			int c = V - 1;
			while (1){
				if (E[prev[c]][c] == f){
					E[prev[c]].erase(c);
				} else {
					E[prev[c]][c] -= f;
				}
				E[c][prev[c]] += f;
				c = prev[c];
				if (c == 0){
					break;
				}
			}
			F += f;
		}
		return F;
	}
	void add_edge(int v, int w, int cap){
		E[v][w] = cap;
	}
};
