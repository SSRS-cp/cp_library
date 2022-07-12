template <typename T>
struct dual_binary_indexed_tree{
  int N;
  vector<T> BIT;
  function<T(T, T)> f;
  T E;
  dual_binary_indexed_tree(){
  }
  dual_binary_indexed_tree(int N, function<T(T, T)>, T E): N(N), BIT(N + 1, E), f(f), E(E){
  }
  dual_binary_indexed_tree(vector<T> &A, function<T(T, T)>, T E): N(A.size()), BIT(N + 1), f(f), E(E){
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i < N; i++){
      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);
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
};
