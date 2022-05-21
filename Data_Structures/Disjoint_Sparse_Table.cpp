template <typename T>
struct disjoint_sparse_table{
  function<T(T, T)> f;
  vector<T> A;
  vector<vector<T>> D;
  disjoint_sparse_table(){
  }
  disjoint_sparse_table(vector<T> &A, function<T(T, T)> f): A(A), f(f){
    int N = A.size();
    int LOG = 32 - __builtin_clz(N - 1);
    D = vector<vector<T>>(LOG, vector<T>(N));
    for (int i = 0; i < LOG; i++){
      for (int j = 0; j + (1 << i) < N; j += 1 << (i + 1)){
        int d = 1 << i;
        int x = min(j + d - 1, N - 1);
        D[i][x] = A[x];
        for (int k = x - 1; k >= j; k--){
          D[i][k] = f(A[k], D[i][k + 1]);
        }
        D[i][j + d] = A[j + d];
        for (int k = j + d + 1; k < min(j + d * 2, N); k++){
          D[i][k] = f(D[i][k - 1], A[k]);
        }
      }
    }
  }
  T query(int L, int R){
    if (R - L == 1){
      return A[L];
    } else {
      R--;
      int b = 31 - __builtin_clz(R ^ L);
      return f(D[b][L], D[b][R]);
    }
  }
};
