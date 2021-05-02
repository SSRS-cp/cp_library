template <typename T>
struct treap{
  int N;
  T E;
  function<T(T, T)> f;
  vector<T> node;
  vector<T> prod;
  vector<int> priority;
  vector<int> parent;
  vector<int> left, right;
  vector<int> size;
  int root;
  treap(T E, function<T(T, T)> f): E(E), f(f){
    N = 0;
    root = 0;
  }
  void eval(int v){
    size[v] = 1;
    if (left[v] != -1){
      size[v] += size[left[v]];
    }
    if (right[v] != -1){
      size[v] += size[right[v]];
    }
    prod[v] = node[v];
    if (left[v] != -1){
      prod[v] = f(prod[left[v]], prod[v]);
    }
    if (right[v] != -1){
      prod[v] = f(prod[v], prod[right[v]]);
    }
  }
  int right_rotate(int v){
    int w = left[v];
    left[v] = right[w];
    parent[w] = parent[v];
    if (right[w] != -1){
      parent[right[w]] = v;
    }
    right[w] = v;
    if (parent[w] != -1){
      if (left[parent[w]] == v){
        left[parent[w]] = w;
      } else {
        right[parent[w]] = w;
      }
    }
    parent[v] = w;
    if (root == v){
      root = w;
    }
    eval(v);
    return w;
  }
  int left_rotate(int v){
    int w = right[v];
    right[v] = left[w];
    parent[w] = parent[v];
    if (left[w] != -1){
      parent[left[w]] = v;
    }
    left[w] = v;
    if (parent[w] != -1){
      if (left[parent[w]] == v){
        left[parent[w]] = w;
      } else {
        right[parent[w]] = w;
      }
    }
    parent[v] = w;
    if (root == v){
      root = w;
    }
    eval(v);
    return w;
  }
  int get_id(int k){
    int v = root;
    while (true){
      int lsz = 0;
      if (left[v] != -1){
        lsz = size[left[v]];
      }
      if (k < lsz){
        v = left[v];
      } else if (k == lsz){
        return v;
      } else {
        k -= lsz + 1;
        v = right[v];
      }
    }
  }
  T operator [](int k){
    return node[get_id(k)];
  }
  void insert(int pos, T x, int pri){
    int v = -1;
    if (N > 0){
      v = root;
      while (true){
        int lsz = 0;
        if (left[v] != -1){
          lsz = size[left[v]];
        }
        if (pos <= lsz){
          if (left[v] == -1){
            left[v] = N;
            break;
          } else {
            v = left[v];
          }
        } else {
          pos -= lsz + 1;
          if (right[v] == -1){
            right[v] = N;
            break;
          } else {
            v = right[v];
          }
        }
      }
    }
    node.push_back(x);
    prod.push_back(x);
    priority.push_back(pri);
    parent.push_back(v);
    left.push_back(-1);
    right.push_back(-1);
    size.push_back(1);
    N++;
    if (N == 1){
      root = 0;
    }
    v = N - 1;
    while (parent[v] != -1){
      if (priority[parent[v]] < priority[v]){
        if (left[parent[v]] == v){
          v = right_rotate(parent[v]);
        } else {
          v = left_rotate(parent[v]);
        }
      } else {
        break;
      }
    }
    while (parent[v] != -1){
      eval(v);
      v = parent[v];
    }
    eval(v);
  }
  void erase(int k){
    int v = get_id(k);
    while (left[v] != -1 || right[v] != -1){
      if (left[v] != -1 && right[v] != -1){
        if (priority[left[v]] > priority[right[v]]){
          v = right[right_rotate(v)];
        } else {
          v = left[left_rotate(v)];
        }
      } else if (left[v] != -1){
        v = right[right_rotate(v)];
      } else {
        v = left[left_rotate(v)];
      }
    }
    int w = v;
    size[w] = 0;
    prod[w] = INF;
    while (parent[w] != -1){
      w = parent[w];
      eval(w);
    }
    if (parent[v] != -1){
      if (left[parent[v]] == v){
        left[parent[v]] = -1;
      } else {
        right[parent[v]] = -1;
      }
    }
    if (v != N - 1){
      if (parent[N - 1] != -1){
        if (left[parent[N - 1]] == N - 1){
          left[parent[N - 1]] = v;
        } else {
          right[parent[N - 1]] = v;
        }
      }
      if (left[N - 1] != -1){
        parent[left[N - 1]] = v;
      }
      if (right[N - 1] != -1){
        parent[right[N - 1]] = v;
      }
      node[v] = node[N - 1];
      prod[v] = prod[N - 1];
      priority[v] = priority[N - 1];
      parent[v] = parent[N - 1];
      left[v] = left[N - 1];
      right[v] = right[N - 1];
      size[v] = size[N - 1];
      if (root == N - 1){
        root = v;
      }
    }
    node.pop_back();
    prod.pop_back();
    priority.pop_back();
    parent.pop_back();
    left.pop_back();
    right.pop_back();
    size.pop_back();
    N--;
  }
  void update(int k, T x){
    int v = get_id(k);
    node[v] = x;
    while (parent[v] != -1){
      eval(v);
      v = parent[v];
    }
    eval(v);
  }
  T range_fold(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return E;
    } else if (L <= l && r <= R){
      return prod[i];
    } else {
      int lsz = 0;
      if (left[i] != -1){
        lsz = size[left[i]];
      }
      T ans = E;
      if (L <= l + lsz && l + lsz < R){
        ans = node[i];
      }
      if (left[i] != -1){
        ans = f(range_fold(L, R, left[i], l, l + lsz), ans);
      }
      if (right[i] != -1){
        ans = f(ans, range_fold(L, R, right[i], l + lsz + 1, r));
      }
      return ans;
    }
  }
  T range_fold(int L, int R){
    return range_fold(L, R, root, 0, N);
  }
};
