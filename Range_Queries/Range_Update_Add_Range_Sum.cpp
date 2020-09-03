template <typename T>
struct lazy_segment_tree{
  int N;
  vector<T> ST;
  vector<pair<int, T>> lazy;
  lazy_segment_tree(){
  }
  lazy_segment_tree(int n){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, 0);
    lazy = vector<pair<int, T>>(N * 2 - 1, make_pair(1, 0));
  }
  void eval(int i, int l, int r){
    if (i < N - 1){
      if (lazy[i].first == 0){
        lazy[i * 2 + 1] = lazy[i];
        lazy[i * 2 + 2] = lazy[i];
      } else {
        lazy[i * 2 + 1].second += lazy[i].second;
        lazy[i * 2 + 2].second += lazy[i].second;
      }
    }
    ST[i] = ST[i] * lazy[i].first + lazy[i].second * (r - l);
    lazy[i] = make_pair(1, 0);
  }
  void update(int L, int R, T x, int t, int i, int l, int r){
    eval(i, l, r);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = make_pair(t, x);
      eval(i, l, r);
    } else {
      int m = (l + r) / 2;
      update(L, R, x, t, i * 2 + 1, l, m);
      update(L, R, x, t, i * 2 + 2, m, r);
      ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
    }
  }
  void range_update(int L, int R, T x){
    update(L, R, x, 0, 0, 0, N);
  }
  void range_add(int L, int R, T x){
    update(L, R, x, 1, 0, 0, N);
  }
  T range_sum(int L, int R, int i, int l, int r){
    eval(i, l, r);
    if (r <= L || R <= l){
      return 0;
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
    }
  }
  T range_sum(int L, int R){
    return range_sum(L, R, 0, 0, N);
  }
};
