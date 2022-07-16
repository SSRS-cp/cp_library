#pragma once
/**
 * @brief 双対スパーステーブル
*/
template <typename T>
struct dual_sparse_table{
  vector<vector<T>> ST;
  function<T(T, T)> f;
  T E;
  dual_sparse_table(){
  }
  dual_sparse_table(int N, function<T(T, T)> f, T E): f(f), E(E){
    int LOG = 32 - __builtin_clz(N);
    ST = vector<vector<T>>(LOG, vector<T>(N, E));
  }
  dual_sparse_table(vector<T> &A, function<T(T, T)> f, T E): f(f), E(E){
    int N = A.size();
    int LOG = 32 - __builtin_clz(N);
    ST = vector<vector<T>>(LOG, vector<T>(N, E));
    ST[0] = A;
  }
  void apply(int L, int R, T x){
    if (L == R){
      return;
    }
    int d = 31 - __builtin_clz(R - L);
    ST[d][L] = f(ST[d][L], x);
    ST[d][R - (1 << d)] = f(ST[d][R - (1 << d)], x);
  }
  vector<T> get(){
    int LOG = ST.size();
    int N = ST[0].size();
    for (int i = LOG - 2; i >= 0; i--){
      for (int j = 0; j < N - (1 << i); j++){
        ST[i][j] = f(ST[i][j], ST[i + 1][j]);
        ST[i][j + (1 << i)] = f(ST[i][j + (1 << i)], ST[i + 1][j]);
      }
    }
    return ST[0];
  }
};