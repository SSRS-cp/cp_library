template <typename T>
struct sparse_table{
  vector<vector<T>> ST;
  function<T(T, T)> f;
  T E;
  sparse_table(){
  }
  sparse_table(int N, function<T(T, T)> f, T E): f(f), E(E){
    int LOG = 32 - __builtin_clz(N);
    ST = vector<vector<T>>(LOG, vector<T>(N, E));
  }
  sparse_table(vector<T> &A, function<T(T, T)> f, T E): f(f), E(E){
    int N = A.size();
    int LOG = 32 - __builtin_clz(N);
    ST = vector<vector<T>>(LOG, vector<T>(N));
    for (int i = 0; i < N; i++){
      ST[0][i] = A[i];
    }
    for (int i = 0; i < LOG - 1; i++){
      for (int j = 0; j < N - (1 << i); j++){
        ST[i + 1][j] = f(ST[i][j], ST[i][j + (1 << i)]);
      }
    }
  }
  int query(int L, int R){
    if (L == R){
      return E;
    }
    int d = 31 - __builtin_clz(R - L);
    return f(ST[d][L], ST[d][R - (1 << d)]);
  }
};
/**
 * @brief Sparse Table (スパーステーブル)
*/
