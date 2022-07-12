template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  function<T(T, T)> f;
  T E;
  binary_indexed_tree(){
  }
  binary_indexed_tree(int N, function<T(T, T)> f, T E): N(N), BIT(N + 1, E), f(f), E(E){
  }
  binary_indexed_tree(vector<T> &A, function<T(T, T)> f, T E): N(A.size()), BIT(N + 1), f(f), E(E){
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i < N; i++){
      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], BIT[i]);
    }
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] = f(BIT[i], x);
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = E;
    while (i > 0){
      ans = f(ans, BIT[i]);
      i -= i & -i;
    }
    return ans;
  }
};
