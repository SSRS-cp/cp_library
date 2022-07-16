#include "compact_bit_vector.cpp"
struct wavelet_matrix{
  int N, LOG;
  vector<bit_vector> D;
  vector<int> cnt, T;
  wavelet_matrix(){
  }
  wavelet_matrix(vector<int> &A): N(A.size()){
    LOG = 1;
    for (int i = 0; i < N; i++){
      if (A[i] > 0){
        LOG = max(LOG, 32 - __builtin_clz(A[i]));
      }
    }
    D.resize(LOG);
    cnt.resize(LOG, 0);
    for (int i = LOG - 1; i >= 0; i--){
      vector<bool> B(N, false);
      for (int j = 0; j < N; j++){
        if ((A[j] >> i & 1) == 1){
          B[j] = true;
        }
      }
      D[LOG - 1 - i] = bit_vector(B);
      vector<int> A2;
      for (int j = 0; j < N; j++){
        if ((A[j] >> i & 1) == 0){
          A2.push_back(A[j]);
          cnt[LOG - 1 - i]++;
        }
      }
      for (int j = 0; j < N; j++){
        if ((A[j] >> i & 1) == 1){
          A2.push_back(A[j]);
        }
      }
      swap(A, A2);
    }
    T = A;
  }
  int operator [](int k){
    int ans = 0;
    for (int i = 0; i < LOG; i++){
      if (D[i][k] == 0){
        k = D[i].rank0(k);
      } else {
        ans += 1 << (LOG - 1 - i);
        k = cnt[i] + D[i].rank1(k);
      }
    }
    return ans;
  }
  int rank(int l, int r, int c){
    for (int i = 0; i < LOG; i++){
      if ((c >> (LOG - 1 - i) & 1) == 0){
        l = D[i].rank0(l);
        r = D[i].rank0(r);
      } else {
        l = cnt[i] + D[i].rank1(l);
        r = cnt[i] + D[i].rank1(r);
      }
    }
    return r - l;
  }
};
