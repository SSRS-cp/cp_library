#pragma once
/**
 * @brief UnionFind
*/
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