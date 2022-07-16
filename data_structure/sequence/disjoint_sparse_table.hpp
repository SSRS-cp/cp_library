#pragma once
/**
 * @brief Disjoint Sparse Table
*/
template <typename T>
struct disjoint_sparse_table{
  vector<T> A;
  vector<vector<T>> D;
  function<T(T, T)> f;
  T E;
  disjoint_sparse_table(){
  }
  disjoint_sparse_table(int N, function<T(T, T)> f, T E): A(N, E), f(f), E(E){
    if (N > 1){
      int LOG = 32 - __builtin_clz(N - 1);
      D = vector<vector<T>>(LOG, vector<T>(N));
    }
  }
  disjoint_sparse_table(vector<T> &A, function<T(T, T)> f, T E): A(A), f(f), E(E){
    int N = A.size();
    if (N > 1){
      int LOG = 32 - __builtin_clz(N - 1);
      D = vector<vector<T>>(LOG, vector<T>(N));
      for (int i = 0; i < LOG; i++){
        int d = 1 << i;
        for (int j = 0; j + d < N; j += d * 2){
          D[i][j + d - 1] = A[j + d - 1];
          for (int k = j + d - 2; k >= j; k--){
            D[i][k] = f(A[k], D[i][k + 1]);
          }
          D[i][j + d] = A[j + d];
          for (int k = j + d + 1; k < min(j + d * 2, N); k++){
            D[i][k] = f(D[i][k - 1], A[k]);
          }
        }
      }
    }
  }
  T query(int L, int R){
    if (R == L){
      return E;
    } else if (R - L == 1){
      return A[L];
    } else {
      R--;
      int b = 31 - __builtin_clz(R ^ L);
      return f(D[b][L], D[b][R]);
    }
  }
};