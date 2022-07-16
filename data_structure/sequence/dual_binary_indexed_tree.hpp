#pragma once
/**
 * @brief 双対 Binary Indexed Tree
*/
template <typename T>
struct dual_binary_indexed_tree{
  int N;
  vector<T> BIT;
  function<T(T, T)> f;
  T E;
  dual_binary_indexed_tree(){
  }
  dual_binary_indexed_tree(int N, function<T(T, T)> f, T E): N(N), BIT(N + 1, E), f(f), E(E){
  }
  dual_binary_indexed_tree(vector<T> &A, function<T(T, T)> f, T E): N(A.size()), BIT(N + 1), f(f), E(E){
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
  }
  void add(int i, T x){
    while (i > 0){
      BIT[i] = f(BIT[i], x);
      i -= i & -i;
    }
  }
  T operator [](int i){
    i++;
    T ans = E;
    while (i <= N){
      ans = f(ans, BIT[i]);
      i += i & -i;
    }
    return ans;
  }
  vector<T> get(){
    vector<T> ans = BIT;
    for (int i = N - 1; i >= 1; i--){
      if (i + (i & -i) <= N){
        ans[i] = f(ans[i + (i & -i)], ans[i]);
      }
    }
    ans.erase(ans.begin());
    return ans;
  }
};