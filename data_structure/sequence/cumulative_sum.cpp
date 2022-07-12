template <typename T>
struct cumulative_sum{
  vector<T> S;
  function<T(T, T)> f;
  T E;
  cumulative_sum(){
  }
  cumulative_sum(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
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
};
