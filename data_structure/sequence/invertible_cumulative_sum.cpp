template <typename T>
struct invertible_cumulative_sum{
  vector<T> S;
  function<T(T, T)> f;
  function<T(T)> inv;
  T E;
  invertible_cumulative_sum(){
  }
  invertible_cumulative_sum(vector<T> A, function<T(T, T)> f, function<T(T)> inv, T E): f(f), inv(inv), E(E){
    int N = A.size();
    S = vector<T>(N + 1);
    S[0] = E;
    for (int i = 0; i < N; i++){
      S[i + 1] = f(S[i], A[i]);
    }
  }
  T get(int i){
    return S[i];
  }
  T get(int l, int r){
    return f(S[r], inv(S[l]));
  }
};
