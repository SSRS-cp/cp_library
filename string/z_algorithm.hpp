#pragma once
/**
 * @brief Z Algorithm
*/
vector<int> z_algorithm(const string &S){
  int N = S.size();
  vector<int> ans(N);
  for (int i = 1, j = 0; i < N; i++){
    if (i + ans[i - j] < j + ans[j]){
      ans[i] = ans[i - j];
    } else {
      int k = max(0, j + ans[j] - i);
      while (i + k < N && S[k] == S[i + k]){
        k++;
      }
      ans[i] = k;
      j = i;
    }
  }
  ans[0] = N;
  return ans;
}