#pragma once
template <typename T>
vector<int> z_algorithm(const T &A){
  int N = A.size();
  vector<int> Z(N, 0);
  for (int i = 1, j = 0; i < N; i++){
    if (i + Z[i - j] < j + Z[j]){
      Z[i] = Z[i - j];
    } else {
      int k = max(0, j + Z[j] - i);
      while (i + k < N && A[k] == A[i + k]){
        k++;
      }
      Z[i] = k;
      j = i;
    }
  }
  Z[0] = N;
  return Z;
}