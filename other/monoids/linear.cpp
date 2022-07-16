#pragma once
struct linear{
  long long a, b;
  linear(){
    a = 1;
    b = 0;
  }
  linear(int a, int b): a(a), b(b){
  }
};
linear composite(linear A, linear B){
  return linear(A.a * B.a % MOD, (A.b * B.a + B.b) % MOD);
}
int value(linear A, int x){
  return (A.a * x + A.b) % MOD;
}