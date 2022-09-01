#pragma once
template <typename T>
vector<int> manacher(const T &A){
  int N = A.size();
  vector<int> ans(N, 0);
  int i = 0, j = 0;
  while (i < N){
    while (i >= j && i + j < N && A[i - j] == A[i + j]){
      j++;
    }
    ans[i] = j;
    int k = 1;
    while (i >= k && i + k < N && k + ans[i - k] < j){
      ans[i + k] = ans[i - k];
      k++;
    }
    i += k;
    j -= k;
  }
  return ans;
}