#pragma once
/**
 * @brief デカルト木
*/
vector<int> cartesian_tree_min(vector<int> &A){
  int N = A.size();
  vector<int> pr(N, -1);
  stack<int> st;
  st.push(0);
  for (int i = 1; i < N; i++){
    int prev = -1;
    while (!st.empty()){
      int j = st.top();
      if (A[i] < A[j]){
        st.pop();
        if (prev != -1){
          pr[prev] = j;
        }
        prev = j;
      } else {
        break;
      }
    }
    if (prev != -1){
      pr[prev] = i;
    }
    st.push(i);
  }
  while (st.size() >= 2){
    int x = st.top();
    st.pop();
    pr[x] = st.top();
  }
  return pr;
}