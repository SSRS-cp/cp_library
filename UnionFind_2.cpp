int unionfind_root(vector<int> &parent, int x){
	if (parent[x] == x){
		return x;
	} else {
		int y = unionfind_root(parent, parent[x]);
		parent[x] = y;
		return y;
	}
}
void unionfind_union(vector<int> &parent, vector<int> &rank, int x, int y){
	x = unionfind_root(parent, x);
	y = unionfind_root(parent, y);
	if (x != y){
		if (rank[x] < rank[y]){
			parent[x] = y;
		} else if (rank[y] < rank[x]){
			parent[y] = x;
		} else {
			parent[y] = x;
			rank[x]++;
		}
	}
	return;
}
