template <typename T>
struct dual_disjoint_sparse_table{
  vector<T> A;
  vector<vector<T>> D;
  function<T(T, T)> f;
  T E;
  dual_disjoint_sparse_table(){
  }
  dual_disjoint_sparse_table(int N, function<T(T, T)> f, T E): A(N, E), f(f), E(E){
    if (N > 1){
      int LOG = 32 - __builtin_clz(N - 1);
      D = vector<vector<T>>(LOG, vector<T>(N, E));
    }
  }
  dual_disjoint_sparse_table(vector<T> &A, function<T(T, T)> f, T E): A(A), f(f), E(E){
    int N = A.size();
    if (N > 1){
      int LOG = 32 - __builtin_clz(N - 1);
      D = vector<vector<T>>(LOG, vector<T>(N, E));
    }
  }
  void apply(int L, int R, T x){
    if (L == R){
      return;
    } else if (R - L == 1){
      A[L] = f(A[L], x);
    } else {
      R--;
      int b = 31 - __builtin_clz(R ^ L);
      D[b][L] = f(D[b][L], x);
      D[b][R] = f(D[b][R], x);
    }
  }
  vector<T> get(){
    int LOG = D.size();
    int N = A.size();
    for (int i = 0; i < LOG; i++){
      int d = 1 << i;
      for (int j = 0; j + d < N; j += d * 2){
        T L = E;
        for (int k = j; k < j + d; k++){
          L = f(L, D[i][k]);
          A[k] = f(A[k], L);
        }
        T R = E;
        for (int k = min(j + d * 2, N) - 1; k >= j + d; k--){
          R = f(R, D[i][k]);
          A[k] = f(A[k], R);
        }
      }
    }
    return A;
  }
};
/**
 * @brief Dual Disjoint Sparse Table (双対 Disjoint Sparse Table)
*/
