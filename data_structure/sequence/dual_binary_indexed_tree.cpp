template <typename T>
struct dual_binary_indexed_tree{
  int N;
  vector<T> BIT;
  dual_binary_indexed_tree(){
  }
  dual_binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  dual_binary_indexed_tree(vector<T> &A): N(A.size()), BIT(N + 1){
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i < N; i++){
      BIT[i + (i & -i)] += BIT[i];
    }
  }
  void add(int i, T x){
    while (i > 0){
      BIT[i] += x;
      i -= i & -i;
    }
  }
  void add(int L, int R, T x){
    add(L, -x);
    add(R, x);
  }
  T operator [](int i){
    i++;
    T ans = 0;
    while (i <= N){
      ans += BIT[i];
      i += i & -i;
    }
    return ans;
  }
};
