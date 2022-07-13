template <typename T>
struct xor_segment_tree{
  int N;
  vector<vector<T>> ST;
  function<T(T, T)> f;
  T E;
  xor_segment_tree(vector<T> &A, function<T(T, T)> f, T E): f(f), E(E){
    N = A.size();
    ST = vector<vector<T>>(N * 2 - 1);
    for (int i = 0; i < N; i++){
      ST[N - 1 + i].push_back(A[i]);
    }
    for (int i = N - 2; i >= 0; i--){
      int cnt = ST[i * 2 + 1].size();
      for (int j = 0; j < cnt; j++){
        ST[i].push_back(f(ST[i * 2 + 1][j], ST[i * 2 + 2][j]));
      }
      for (int j = 0; j < cnt; j++){
        ST[i].push_back(f(ST[i * 2 + 2][j], ST[i * 2 + 1][j]));
      }
    }
  }
  T range_fold(int L, int R, int x, int i, int l, int r){
    if (r <= L || R <= l){
      return E;
    } else if (L <= l && r <= R){
      return ST[i][x];
    } else {
      int p = (r - l) / 2;
      int m = (l + r) / 2;
      if ((x & p) == 0){
        T resL = range_fold(L, R, x, i * 2 + 1, l, m);
        T resR = range_fold(L, R, x, i * 2 + 2, m, r);
        return f(resL, resR);
      } else {
        T resL = E;
        if (R >= m){
          resL = range_fold(max(L, m) - p, R - p, x ^ p, i * 2 + 1, l, m);
        }
        T resR = E;
        if (L < m){
          resR = range_fold(L + p, min(R, m) + p, x ^ p, i * 2 + 2, m, r);
        }
        return f(resR, resL);
      }
    }
  }
  T range_fold(int L, int R, int x){
    return range_fold(L, R, x, 0, 0, N);
  }
};
/**
 * @brief XOR Segment Tree (XOR セグメント木)
*/
