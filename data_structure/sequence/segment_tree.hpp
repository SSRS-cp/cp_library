#pragma once
/**
 * @brief セグメント木 (うし木)
*/
template <typename T>
struct segment_tree{
  int N;
  vector<T> ST;
  function<T(T, T)> f;
  T E;
  segment_tree(){
  }
  segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<T>(N * 2 - 1, E);
  }
  segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
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
      ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  T operator [](int k){
    return ST[N - 1 + k];
  }
  void update(int k, T x){
    k += N - 1;
    ST[k] = x;
    while (k > 0){
      k = (k - 1) / 2;
      ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);
    }
  }
  T query(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return E;
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
    }
  }
  T query(int L, int R){
    return query(L, R, 0, 0, N);
  }
  T all(){
    return ST[0];
  }
};