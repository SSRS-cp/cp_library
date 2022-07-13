template <typename T>
struct dual_segment_tree{
  int N;
  vector<T> ST;
  function<T(T, T)> f;
  T E;
  dual_segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
  }
  dual_segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
  }
  void push(int i){
    if (i < N - 1){
      ST[i * 2 + 1] = f(ST[i * 2 + 1], ST[i]);
      ST[i * 2 + 2] = f(ST[i * 2 + 2], ST[i]);
      ST[i] = E;
    }
  }
  T operator [](int k){
    int v = 0;
    for (int i = N / 2; i >= 1; i >>= 1){
      push(v);
      if ((k & i) == 0){
        v = v * 2 + 1;
      } else {
        v = v * 2 + 2;
      }
    }
    return ST[v];
  }
  void range_apply(int L, int R, T x, int i, int l, int r){
    if (r <= L || R <= l){
    } else if (L <= l && r <= R){
      ST[i] = f(ST[i], x);
    } else {
      push(i);
      int m = (l + r) / 2;
      range_apply(L, R, x, i * 2 + 1, l, m);
      range_apply(L, R, x, i * 2 + 2, m, r);
    }
  }
  void range_apply(int L, int R, T x){
    range_apply(L, R, x, 0, 0, N);
  }
};
/**
 * @brief Dual Segment Tree (双対セグメント木、びーと木)
*/
