template <typename T>
struct dual_invertible_binary_indexed_tree{
  int N;
  vector<T> BIT;
  function<T(T, T)> f;
  function<T(T)> inv;
  T E;
  dual_invertible_binary_indexed_tree(){
  }
  dual_invertible_binary_indexed_tree(int N, function<T(T, T)> f, function<T(T)> inv, T E): N(N), BIT(N + 1, E), f(f), inv(inv), E(E){
  }
  dual_invertible_binary_indexed_tree(vector<T> &A, function<T(T, T)> f, function<T(T)> inv, T E): N(A.size()), BIT(N + 1), f(f), inv(inv), E(E){
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
  void add(int l, int r, T x){
    add(l, inv(x));
    add(r, x);
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
      BIT[i + (i & -i)] = f(BIT[i + (i & -i)], inv(BIT[i]));
    }
    ans.erase(ans.begin());
    return ans;
  }
};
