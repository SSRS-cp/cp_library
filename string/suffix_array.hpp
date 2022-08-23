#pragma once
vector<int> suffix_array(const vector<int> &A, int mx){
  int N = A.size();
  vector<int> sum(mx + 1, 0);
  for (int i = 0; i < N; i++){
    sum[A[i] + 1]++;
  }
  for (int i = 0; i < mx; i++){
    sum[i + 1] += sum[i];
  }
  vector<bool> is_s(N);
  is_s[N - 1] = false;
  for (int i = N - 2; i >= 0; i--){
    is_s[i] = A[i] < A[i + 1] || A[i] == A[i + 1] && is_s[i + 1];
  }
  vector<int> id(N, -1);
  vector<int> pos;
  int M = 0;
  for (int i = 1; i < N; i++){
    if (is_s[i] && !is_s[i - 1]){
      id[i] = M;
      pos.push_back(i);
      M++;
    }
  }
  vector<int> sa(N);
  auto induce = [&](vector<int>& lms){
    sa = vector<int>(N, -1);
    vector<bool> used(N, false);
    vector<int> p(mx);
    vector<int> p2(mx);
    for (int i = 0; i < mx; i++){
      p[i] = sum[i + 1] - 1;
      p2[i] = sum[i];
    }
    for (int i = M - 1; i >= 0; i--){
      sa[p[A[lms[i]]]] = lms[i];
      p[A[lms[i]]]--;
      used[lms[i]] = true;
    }
    sa[p2[A[N - 1]]] = N - 1;
    p2[A[N - 1]]++;
    used[N - 1] = true;
    for (int i = 0; i < N; i++){
      if (sa[i] > 0){
        if (!is_s[sa[i] - 1] && !used[sa[i] - 1]){
          sa[p2[A[sa[i] - 1]]] = sa[i] - 1;
          p2[A[sa[i] - 1]]++;
          used[sa[i] - 1] = true;
        }
      }
    }
    for (int i = 0; i < N; i++){
      if (sa[i] != -1){
        if (id[sa[i]] != -1){
          used[sa[i]] = false;
          sa[i] = -1;
        }
      }
    }
    for (int i = 0; i < mx; i++){
      p[i] = sum[i + 1] - 1;
    }
    for (int i = N - 1; i >= 0; i--){
      if (sa[i] > 0){
        if (is_s[sa[i] - 1] && !used[sa[i] - 1]){
          sa[p[A[sa[i] - 1]]] = sa[i] - 1;
          p[A[sa[i] - 1]]--;
          used[sa[i] - 1] = true;
        }
      }
    }
  };
  induce(pos);
  if (M == 0){
    return sa;
  }
  vector<int> lms;
  for (int i = 0; i < N; i++){
    if (id[sa[i]] != -1){
      lms.push_back(sa[i]);
    }
  }
  vector<int> c(M);
  c[0] = 0;
  for (int i = 0; i < M - 1; i++){
    c[i + 1] = c[i];
    int x = lms[i];
    int y = lms[i + 1];
    bool ok = true;
    while (x < N && y < N){
      if (A[x] != A[y]){
        ok = false;
        break;
      }
      x++;
      y++;
      if (id[x] != -1){
        if (id[y] == -1){
          ok = false;
        }
        break;
      }
    }
    if (x == N || y == N){
      ok = false;
    }
    if (!ok){
      c[i + 1]++;
    }
  }
  vector<int> rec(M);
  for (int i = 0; i < M; i++){
    rec[id[lms[i]]] = c[i];
  }
  vector<int> sa2 = suffix_array(rec, c[M - 1] + 1);
  vector<int> pos2(M);
  for (int i = 0; i < M; i++){
    pos2[i] = pos[sa2[i]];
  }
  induce(pos2);
  return sa;
}
vector<int> suffix_array(const string &S){
  int N = S.size();
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    A[i] = S[i];
  }
  return suffix_array(A, 256);
}