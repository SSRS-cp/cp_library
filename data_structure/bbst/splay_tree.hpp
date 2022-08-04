#pragma once
/**
 * @brief スプレー木 (一点更新・区間取得)
*/
template <typename T>
struct splay_tree{
  struct node{
    node* p;
    array<node*, 2> ch;
    int sz;
    T val, sum;
    node(): p(nullptr), ch({nullptr, nullptr}){
    }
    node(T x): p(nullptr), ch({nullptr, nullptr}), sz(1), val(x), sum(x){
    }
  };
  function<T(T, T)> f;
  T E;
  node* root = nullptr;
  splay_tree(){
  }
  splay_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
    root = build(A, 0, A.size());
  }
  node* build(vector<T> &A, int L, int R){
    if (L == R){
      return nullptr;
    }
    int m = (L + R) / 2;
    node* v = new node(A[m]);
    node* l = build(A, L, m);
    v->ch[0] = l;
    if (l != nullptr){
      l->p = v;
    }
    node* r = build(A, m + 1, R);
    v->ch[1] = r;
    if (r != nullptr){
      r->p = v;
    }
    update(v);
    return v;
  }
  bool empty(){
    return root == nullptr;
  }
  int size(){
    return size(root);
  }
  int size(node* v){
    if (v == nullptr){
      return 0;
    }
    return v->sz;
  }
  T sum(node* v){
    if (v == nullptr){
      return E;
    }
    return v->sum;
  }
  void update(node* v){
    v->sz = size(v->ch[0]) + 1 + size(v->ch[1]);
    v->sum = f(f(sum(v->ch[0]), v->val), sum(v->ch[1]));
  }
  int child_id(node *v){
    if (v->p == nullptr){
      return -1;
    } else if (v->p->ch[0] == v){
      return 0;
    } else {
      return 1;
    }
  }
  void update_child(node* v, node *w){
    w->p = v->p;
    if (v->p == nullptr){
      return;
    }
     if (v->p->ch[0] == v){
      v->p->ch[0] = w;
    } else {
      v->p->ch[1] = w;
    }
  }
  void rotate(node* v, int c){
    node* w = v->ch[c ^ 1];
    update_child(v, w);
    v->ch[c ^ 1] = w->ch[c];
    if (w->ch[c] != nullptr){
      w->ch[c]->p = v;
    }
    v->p = w;
    w->ch[c] = v;
    update(v);
    update(w);
  }
  void splay(node* v){
    while (v->p != nullptr){
      node* p = v->p;
      node* g = p->p;
      int x = child_id(v);
      int y = child_id(p);
      if (y == -1){
        rotate(p, x ^ 1);
      } else if (x == y){
        rotate(g, x ^ 1);
        rotate(p, x ^ 1);
      } else {
        rotate(p, y);
        rotate(g, x);
      }
    }
    root = v;
  }
  node* get(node *v, int k){
    while (true){
      int s = size(v->ch[0]);
      if (k < s){
        v = v->ch[0];
      } else if (k == s){
        splay(v);
        return v;
      } else {
        k -= s + 1;
        v = v->ch[1];
      }
    }
  }
  node* get(int k){
    return get(root, k);
  }
  T operator [](int k){
    return get(root, k)->x;
  }
  node* insert(node* r, int k, node* v){
    if (k == size(r)){
      v->ch[0] = r;
      if (r != nullptr){
        r->p = v;
      }
      r = v;
      update(v);
    } else {
      node* u = get(r, k);
      v->ch[0] = u->ch[0];
      v->ch[1] = u;
      if (u->ch[0] != nullptr){
        u->ch[0]->p = v;
      }
      u->ch[0] = nullptr;
      u->p = v;
      update(u);
      update(v);
    }
    root = v;
    return v;
  }
  node* insert(node *r, int k, T x){
    node* v = new node(x);
    return insert(r, k, v);
  }
  node* insert(int k, T x){
    return insert(root, k, x);
  }
  void erase(node* v){
    node* l = v->ch[0];
    node* r = v->ch[1];
    delete v;
    if (l == nullptr && r == nullptr){
      root = nullptr;
    } else if (l == nullptr){
      root = r;
      r->p = nullptr;    
    } else if (r == nullptr){
      root = l;
      l->p = nullptr;
    } else {
      r->p = nullptr;
      root = r;
      r = get(0);
      r->ch[0] = l;
      l->p = r;
      update(r);
    }
  }
  void erase(node *v, int k){
    erase(get(v, k));
  }
  void erase(int k){
    erase(get(k));
  }
  pair<node*, node*> split(node* v, int k){
    node* x = insert(v, k);
    node* l = x->ch[0];
    node* r = x->ch[1];
    if (l != nullptr){
      l->p = nullptr;
    }
    if (r != nullptr){
      r->p = nullptr;
    }
    delete x;
    return make_pair(l, r);
  }
  pair<node*, node*> split(int k){
    return split(root, k);
  }
  node* merge(node* l, node* r){
    node* v = new node;
    v->ch[0] = l;
    v->ch[1] = r;
    if (l != nullptr){
      l->p = v;
    }
    if (r != nullptr){
      r->p = v;
    }
    erase(v);
    return root;
  }
  void update(node* v, T x){
    v->val = x;
    update(v);
  }
  void update(int k, int x){
    node* v = get(k);
    update(v, x);
  }
  T query(node* v, int l, int r){
    int sz = size(v->ch[0]);
    T ans = E;
    if (l == 0 && r >= sz){
      ans = sum(v->ch[0]);
    } else if (l < sz){
      ans = query(v->ch[0], l, min(r, sz));
    }
    if (l <= sz && r > sz){
      ans = f(ans, v->val);
    }
    if (l <= sz + 1 && r == v->sz){
      ans = f(ans, sum(v->ch[1]));
    } else if (r > sz + 1){
      ans = f(ans, query(v->ch[1], max(l - sz - 1, 0), r - sz - 1));
    }
    return ans;
  }
  T query(int l, int r){
    return query(root, l, r);
  }
};