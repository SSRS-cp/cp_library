long long kruskal(vector<vector<pair<int, int>>> &E){
	int V = E.size();
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < V; i++){
		for (auto P : E[i]){
			edges.push_back(make_tuple(P.first, i, P.second));
		}
	}
	sort(edges.begin(), edges.end());
	unionfind UF(V);
	long long ans = 0;
	for (auto e : edges){
		int c = get<0>(e);
		int v = get<1>(e);
		int w = get<2>(e);
		if (!UF.same(v, w)){
			UF.unite(v, w);
			ans += c;
		}
	}
	return ans;
}
