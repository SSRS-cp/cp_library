vector<int> segtree(vector<int> &A){
  int N = 1;
  while (N < A.size()){
    N = N * 2;
  }
  vector<int> ST(N * 2 - 1);
  for (int i = 0; i < A.size(); i++){
    ST[i + N - 1] = A[i];
  }
  for (int i = A.size() + N - 1; i < N * 2 - 1; i++){
    ST[i] = INF;
  }
  for (int i = N - 2; i >= 0; i--){
    ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
  }
  return ST;
}
void segtree_update(vector<int> &ST, int i, int x){
  int N = (ST.size() + 1) / 2;
  i = i + N - 1;
  ST[i] = ST[i] + x;
  while (i > 0){
    i = (i - 1) / 2;
    ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
  }
  return;
}
int segtree_query(vector<int> &ST, int x, int y, int i, int L, int R){
  if (y <= L || R <= x){
    return INF;
  } else if (x <= L && R <= y){
    return ST[i];
  } else {
    int M = (L + R) / 2;
    int A = segtree_query(ST, x, y, i * 2 + 1, L, M);
    int B = segtree_query(ST, x, y, i * 2 + 2, M, R);
    return min(A, B);
  }
}
