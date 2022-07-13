template <typename T, typename F>
struct lazy_segment_tree{
  int N;
  vector<T> ST;
  vector<F> lazy;
  function<T(T, T)> op;
  function<T(F, T)> mp;
  function<F(F, F)> comp;
  T E;
  F id;
  lazy_segment_tree(int n, function<T(T, T)> op, function<T(F, T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E), id(id){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
    for (int i = N - 2; i >= 0; i--){
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
    lazy = vector<F>(N * 2 - 1, id);
  }
  lazy_segment_tree(vector<T> &A, function<T(T, T)> op, function<T(F, T)> mp, function<F(F, F)> comp, T E, F id): op(op), mp(mp), comp(comp), E(E), id(id){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
    lazy = vector<F>(N * 2 - 1, id);
  }
  void push(int i){
    if (i < N - 1){
      lazy[i * 2 + 1] = comp(lazy[i * 2 + 1], lazy[i]);
      lazy[i * 2 + 2] = comp(lazy[i * 2 + 2], lazy[i]);
    }
    ST[i] = mp(lazy[i], ST[i]);
    lazy[i] = id;
  }
  void range_apply(int L, int R, F f, int i, int l, int r){
    push(i);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = f;
      push(i);
    } else {
      int m = (l + r) / 2;
      range_apply(L, R, f, i * 2 + 1, l, m);
      range_apply(L, R, f, i * 2 + 2, m, r);
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void range_apply(int L, int R, F f){
    range_apply(L, R, f, 0, 0, N);
  }
  T range_fold(int L, int R, int i, int l, int r){
    push(i);
    if (r <= L || R <= l){
      return E;
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return op(range_fold(L, R, i * 2 + 1, l, m), range_fold(L, R, i * 2 + 2, m, r));
    }
  }
  T range_fold(int L, int R){
    return range_fold(L, R, 0, 0, N);
  }
  T all(){
    push(0);
    return ST[0];
  }
};
/**
 * @brief Lazy Segment Tree (遅延セグメント木)
*/
