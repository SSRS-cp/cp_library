struct unionfind{
	vector<int> p;
	unionfind(int n){
		p = vector<int>(n, -1);
	}
	int root(int x){
		if (p[x] == -1){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same(int x, int y){
		x = root(x);
		y = root(y);
		return x == y;
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
			p[x] = y;
		}
		return;
	}
};
