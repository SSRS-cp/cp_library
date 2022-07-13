template <typename T>
struct commutative_dual_segment_tree{
  int N;
  vector<T> ST;
  function<T(T, T)> f;
  T E;
  commutative_dual_segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
  }
  commutative_dual_segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
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
  T operator [](int k){
    k += N - 1;
    T ans = ST[k];
    while (k > 0){
      k = (k - 1) / 2;
      ans = f(ans, ST[k]);
    }
    return ans;
  }
  void range_apply(int L, int R, T x, int i, int l, int r){
    if (r <= L || R <= l){
    } else if (L <= l && r <= R){
      ST[i] = f(ST[i], x);
    } else {
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
 * @brief Commutative Dual Segment Tree (可換双対セグメント木、らて木)
*/
