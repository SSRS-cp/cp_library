#pragma once
struct affine_sum{
  int cnt;
  long long sum;
  affine_sum(): cnt(0), sum(0){
  }
};
affine_sum op(affine_sum A, affine_sum B){
  A.cnt += B.cnt;
  A.sum += B.sum;
  A.sum %= MOD;
  return A;
}
affine_sum mp(linear f, affine_sum A){
  A.sum = (A.sum * f.a + A.cnt * f.b) % MOD;
  return A;
}