int unionfind_root(vector<int> &parent, int x){
	if (parent[x] == x){
		return x;
	} else {
		int y = unionfind_root(parent, parent[x]);
		parent[x] = y;
		return y;
	}
}
void unionfind_union(vector<int> &parent, int x, int y){
	x = unionfind_root(parent, x);
	y = unionfind_root(parent, y);
	if (x != y){
		parent[x] = y;
	}
	return;
}
