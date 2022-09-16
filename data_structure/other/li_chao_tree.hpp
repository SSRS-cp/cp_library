#pragma once
template <typename T>
struct li_chao_tree{
  struct line{
    T a, b;
    line(): a(0), b(INF){
    }
    line(T a, T b): a(a), b(b){
    }
    T get(T x){
      return a * x + b;
    }
  };
  int N;
  vector<T> x;
  vector<line> ST;
  li_chao_tree(){
  }
  li_chao_tree(const vector<T> &x2){
    x = x2;
    sort(x.begin(), x.end());
    int N2 = x.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    x.resize(N);
    for (int i = N2; i < N; i++){
      x[i] = x[N2 - 1];
    }
    ST = vector<line>(N * 2 - 1);
  }
  void line_add(line L, int i, int l, int r){
    T la = L.get(x[l]);
    T lb = ST[i].get(x[l]);
    T ra = L.get(x[r - 1]);
    T rb = ST[i].get(x[r - 1]);
    if (la >= lb && ra >= rb){
      return;
    } else if (la <= lb && ra <= rb){
      ST[i] = L;
    } else {
      int m = (l + r) / 2;
      T ma = L.get(x[m]);
      T mb = ST[i].get(x[m]);
      if (ma < mb){
        swap(L, ST[i]);
        swap(la, lb);
        swap(ra, rb);
      }
      if (la < lb){
        line_add(L, i * 2 + 1, l, m);
      }
      if (ra < rb){
        line_add(L, i * 2 + 2, m, r);
      }
    }
  }
  void line_add(T a, T b){
    line_add(line(a, b), 0, 0, N);
  }
  void segment_add(int L, int R, line S, int i, int l, int r){
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      line_add(S, i, l, r);
    } else {
      int m = (l + r) / 2;
      segment_add(L, R, S, i * 2 + 1, l, m);
      segment_add(L, R, S, i * 2 + 2, m, r);
    }
  }
  void segment_add(T l, T r, T a, T b){
    int pl = lower_bound(x.begin(), x.end(), l) - x.begin();
    int pr = lower_bound(x.begin(), x.end(), r) - x.begin();
    segment_add(pl, pr, line(a, b), 0, 0, N);
  }
  T get(T x2){
    int p = lower_bound(x.begin(), x.end(), x2) - x.begin();
    p += N - 1;
    T ans = INF;
    ans = min(ans, ST[p].get(x2));
    while (p > 0){
      p = (p - 1) / 2;
      ans = min(ans, ST[p].get(x2));
    }
    return ans;
  }
};