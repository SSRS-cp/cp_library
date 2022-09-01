#pragma once
#include "suffix_array.hpp"
template <typename T>
vector<int> lcp_array(const T &A, vector<int> &SA){
  int N = A.size();
  vector<int> rank(N);
  for (int i = 0; i < N; i++){
    rank[SA[i]] = i;
  }
  vector<int> lcp(N - 1, 0);
  int h = 0;
  for (int i = 0; i < N; i++){
    if (rank[i] > 0){
      int prev = SA[rank[i] - 1];
      if (h > 0){
        h--;
      }
      while (i + h < N && prev + h < N){
        if (A[i + h] != A[prev + h]){
          break;
        }
        h++;
      }
      lcp[rank[i] - 1] = h;
    }
  }
  return lcp;
}