#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
using namespace std;
struct unionfind{
	vector<int> p;
	unionfind(int N){
		p = vector<int>(N, -1);
	}
	int root(int x){
		if (p[x] < 0){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
			if (p[x] < p[y]){
				swap(x, y);
			}
			p[y] += p[x];
			p[x] = y;
		}
	}
};
int main(){
  int N, Q;
  cin >> N >> Q;
  unionfind UF(N);
  for (int i = 0; i < Q; i++){
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0){
      UF.unite(u, v);
    }
    if (t == 1){
      if (UF.same(u, v)){
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
}
