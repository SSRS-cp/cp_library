template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(){
  }
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  binary_indexed_tree(vector<T> &A): N(A.size()), BIT(N + 1):{
    for (int i = 0; i < N; i++){
      BIT[i + 1] = A[i];
    }
    for (int i = 1; i < N; i++){
      BIT[i + (i & -i)] += BIT[i];
    }
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
