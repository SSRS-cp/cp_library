#pragma once
/**
 * @brief 最長回文 (Manacher's Algorithm)
*/
vector<int> manacher(string &S){
  int N = S.size();
  vector<int> ans(N, 0);
  int i = 0, j = 0;
  while (i < N){
    while (i >= j && i + j < N && S[i - j] == S[i + j]){
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