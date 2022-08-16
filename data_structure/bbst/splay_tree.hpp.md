---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/other/1508.test.cpp
    title: test/aoj/other/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/other/1508_2.test.cpp
    title: test/aoj/other/1508_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B9\u30D7\u30EC\u30FC\u6728 (\u4E00\u70B9\u66F4\u65B0\u30FB\
      \u533A\u9593\u53D6\u5F97)"
    links: []
  bundledCode: "#line 2 \"data_structure/bbst/splay_tree.hpp\"\n/**\n * @brief \u30B9\
    \u30D7\u30EC\u30FC\u6728 (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u53D6\u5F97\
    )\n*/\ntemplate <typename T>\nstruct splay_tree{\n  struct node{\n    node* p;\n\
    \    array<node*, 2> ch;\n    int sz;\n    T val, sum;\n    node(): p(nullptr),\
    \ ch({nullptr, nullptr}){\n    }\n    node(T x): p(nullptr), ch({nullptr, nullptr}),\
    \ sz(1), val(x), sum(x){\n    }\n  };\n  function<T(T, T)> f;\n  T E;\n  node*\
    \ root = nullptr;\n  splay_tree(){\n  }\n  splay_tree(vector<T> A, function<T(T,\
    \ T)> f, T E): f(f), E(E){\n    root = build(A, 0, A.size());\n  }\n  node* build(vector<T>\
    \ &A, int L, int R){\n    if (L == R){\n      return nullptr;\n    }\n    int\
    \ m = (L + R) / 2;\n    node* v = new node(A[m]);\n    node* l = build(A, L, m);\n\
    \    v->ch[0] = l;\n    if (l != nullptr){\n      l->p = v;\n    }\n    node*\
    \ r = build(A, m + 1, R);\n    v->ch[1] = r;\n    if (r != nullptr){\n      r->p\
    \ = v;\n    }\n    update(v);\n    return v;\n  }\n  bool empty(){\n    return\
    \ root == nullptr;\n  }\n  int size(){\n    return size(root);\n  }\n  int size(node*\
    \ v){\n    if (v == nullptr){\n      return 0;\n    }\n    return v->sz;\n  }\n\
    \  T sum(node* v){\n    if (v == nullptr){\n      return E;\n    }\n    return\
    \ v->sum;\n  }\n  void update(node* v){\n    v->sz = size(v->ch[0]) + 1 + size(v->ch[1]);\n\
    \    v->sum = f(f(sum(v->ch[0]), v->val), sum(v->ch[1]));\n  }\n  int child_id(node\
    \ *v){\n    if (v->p == nullptr){\n      return -1;\n    } else if (v->p->ch[0]\
    \ == v){\n      return 0;\n    } else {\n      return 1;\n    }\n  }\n  void update_child(node*\
    \ v, node *w){\n    w->p = v->p;\n    if (v->p == nullptr){\n      return;\n \
    \   }\n     if (v->p->ch[0] == v){\n      v->p->ch[0] = w;\n    } else {\n   \
    \   v->p->ch[1] = w;\n    }\n  }\n  void rotate(node* v, int c){\n    node* w\
    \ = v->ch[c ^ 1];\n    update_child(v, w);\n    v->ch[c ^ 1] = w->ch[c];\n   \
    \ if (w->ch[c] != nullptr){\n      w->ch[c]->p = v;\n    }\n    v->p = w;\n  \
    \  w->ch[c] = v;\n    update(v);\n    update(w);\n  }\n  void splay(node* v){\n\
    \    while (v->p != nullptr){\n      node* p = v->p;\n      node* g = p->p;\n\
    \      int x = child_id(v);\n      int y = child_id(p);\n      if (y == -1){\n\
    \        rotate(p, x ^ 1);\n      } else if (x == y){\n        rotate(g, x ^ 1);\n\
    \        rotate(p, x ^ 1);\n      } else {\n        rotate(p, y);\n        rotate(g,\
    \ x);\n      }\n    }\n    root = v;\n  }\n  node* get(node *v, int k){\n    while\
    \ (true){\n      int s = size(v->ch[0]);\n      if (k < s){\n        v = v->ch[0];\n\
    \      } else if (k == s){\n        splay(v);\n        return v;\n      } else\
    \ {\n        k -= s + 1;\n        v = v->ch[1];\n      }\n    }\n  }\n  node*\
    \ get(int k){\n    return get(root, k);\n  }\n  T operator [](int k){\n    return\
    \ get(root, k)->val;\n  }\n  node* insert(node* r, int k, node* v){\n    if (k\
    \ == size(r)){\n      v->ch[0] = r;\n      if (r != nullptr){\n        r->p =\
    \ v;\n      }\n      r = v;\n      update(v);\n    } else {\n      node* u = get(r,\
    \ k);\n      v->ch[0] = u->ch[0];\n      v->ch[1] = u;\n      if (u->ch[0] !=\
    \ nullptr){\n        u->ch[0]->p = v;\n      }\n      u->ch[0] = nullptr;\n  \
    \    u->p = v;\n      update(u);\n      update(v);\n    }\n    root = v;\n   \
    \ return v;\n  }\n  node* insert(node *r, int k){\n    node* v = new node;\n \
    \   return insert(r, k, v);\n  }\n  node* insert(node *r, int k, T x){\n    node*\
    \ v = new node(x);\n    return insert(r, k, v);\n  }\n  node* insert(int k, T\
    \ x){\n    return insert(root, k, x);\n  }\n  void erase(node* v){\n    node*\
    \ l = v->ch[0];\n    node* r = v->ch[1];\n    delete v;\n    if (l == nullptr\
    \ && r == nullptr){\n      root = nullptr;\n    } else if (l == nullptr){\n  \
    \    root = r;\n      r->p = nullptr;    \n    } else if (r == nullptr){\n   \
    \   root = l;\n      l->p = nullptr;\n    } else {\n      r->p = nullptr;\n  \
    \    root = r;\n      r = get(0);\n      r->ch[0] = l;\n      l->p = r;\n    \
    \  update(r);\n    }\n  }\n  void erase(node *v, int k){\n    erase(get(v, k));\n\
    \  }\n  void erase(int k){\n    erase(get(k));\n  }\n  pair<node*, node*> split(node*\
    \ v, int k){\n    node* x = insert(v, k);\n    node* l = x->ch[0];\n    node*\
    \ r = x->ch[1];\n    if (l != nullptr){\n      l->p = nullptr;\n    }\n    if\
    \ (r != nullptr){\n      r->p = nullptr;\n    }\n    delete x;\n    return make_pair(l,\
    \ r);\n  }\n  pair<node*, node*> split(int k){\n    return split(root, k);\n \
    \ }\n  node* merge(node* l, node* r){\n    node* v = new node;\n    v->ch[0] =\
    \ l;\n    v->ch[1] = r;\n    if (l != nullptr){\n      l->p = v;\n    }\n    if\
    \ (r != nullptr){\n      r->p = v;\n    }\n    erase(v);\n    return root;\n \
    \ }\n  void set(node* v, T x){\n    v->val = x;\n    update(v);\n  }\n  void set(node*\
    \ v, int k, int x){\n    node* w = get(v, k);\n    set(w, x);\n  }\n  void set(int\
    \ k, int x){\n    node* v = get(k);\n    set(v, x);\n  }\n  T query(node* v, int\
    \ l, int r){\n    int sz = size(v->ch[0]);\n    T ans = E;\n    if (l == 0 &&\
    \ r >= sz){\n      ans = sum(v->ch[0]);\n    } else if (l < sz){\n      ans =\
    \ query(v->ch[0], l, min(r, sz));\n    }\n    if (l <= sz && r > sz){\n      ans\
    \ = f(ans, v->val);\n    }\n    if (l <= sz + 1 && r == v->sz){\n      ans = f(ans,\
    \ sum(v->ch[1]));\n    } else if (r > sz + 1){\n      ans = f(ans, query(v->ch[1],\
    \ max(l - sz - 1, 0), r - sz - 1));\n    }\n    return ans;\n  }\n  T query(int\
    \ l, int r){\n    return query(root, l, r);\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u30B9\u30D7\u30EC\u30FC\u6728 (\u4E00\u70B9\
    \u66F4\u65B0\u30FB\u533A\u9593\u53D6\u5F97)\n*/\ntemplate <typename T>\nstruct\
    \ splay_tree{\n  struct node{\n    node* p;\n    array<node*, 2> ch;\n    int\
    \ sz;\n    T val, sum;\n    node(): p(nullptr), ch({nullptr, nullptr}){\n    }\n\
    \    node(T x): p(nullptr), ch({nullptr, nullptr}), sz(1), val(x), sum(x){\n \
    \   }\n  };\n  function<T(T, T)> f;\n  T E;\n  node* root = nullptr;\n  splay_tree(){\n\
    \  }\n  splay_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){\n    root\
    \ = build(A, 0, A.size());\n  }\n  node* build(vector<T> &A, int L, int R){\n\
    \    if (L == R){\n      return nullptr;\n    }\n    int m = (L + R) / 2;\n  \
    \  node* v = new node(A[m]);\n    node* l = build(A, L, m);\n    v->ch[0] = l;\n\
    \    if (l != nullptr){\n      l->p = v;\n    }\n    node* r = build(A, m + 1,\
    \ R);\n    v->ch[1] = r;\n    if (r != nullptr){\n      r->p = v;\n    }\n   \
    \ update(v);\n    return v;\n  }\n  bool empty(){\n    return root == nullptr;\n\
    \  }\n  int size(){\n    return size(root);\n  }\n  int size(node* v){\n    if\
    \ (v == nullptr){\n      return 0;\n    }\n    return v->sz;\n  }\n  T sum(node*\
    \ v){\n    if (v == nullptr){\n      return E;\n    }\n    return v->sum;\n  }\n\
    \  void update(node* v){\n    v->sz = size(v->ch[0]) + 1 + size(v->ch[1]);\n \
    \   v->sum = f(f(sum(v->ch[0]), v->val), sum(v->ch[1]));\n  }\n  int child_id(node\
    \ *v){\n    if (v->p == nullptr){\n      return -1;\n    } else if (v->p->ch[0]\
    \ == v){\n      return 0;\n    } else {\n      return 1;\n    }\n  }\n  void update_child(node*\
    \ v, node *w){\n    w->p = v->p;\n    if (v->p == nullptr){\n      return;\n \
    \   }\n     if (v->p->ch[0] == v){\n      v->p->ch[0] = w;\n    } else {\n   \
    \   v->p->ch[1] = w;\n    }\n  }\n  void rotate(node* v, int c){\n    node* w\
    \ = v->ch[c ^ 1];\n    update_child(v, w);\n    v->ch[c ^ 1] = w->ch[c];\n   \
    \ if (w->ch[c] != nullptr){\n      w->ch[c]->p = v;\n    }\n    v->p = w;\n  \
    \  w->ch[c] = v;\n    update(v);\n    update(w);\n  }\n  void splay(node* v){\n\
    \    while (v->p != nullptr){\n      node* p = v->p;\n      node* g = p->p;\n\
    \      int x = child_id(v);\n      int y = child_id(p);\n      if (y == -1){\n\
    \        rotate(p, x ^ 1);\n      } else if (x == y){\n        rotate(g, x ^ 1);\n\
    \        rotate(p, x ^ 1);\n      } else {\n        rotate(p, y);\n        rotate(g,\
    \ x);\n      }\n    }\n    root = v;\n  }\n  node* get(node *v, int k){\n    while\
    \ (true){\n      int s = size(v->ch[0]);\n      if (k < s){\n        v = v->ch[0];\n\
    \      } else if (k == s){\n        splay(v);\n        return v;\n      } else\
    \ {\n        k -= s + 1;\n        v = v->ch[1];\n      }\n    }\n  }\n  node*\
    \ get(int k){\n    return get(root, k);\n  }\n  T operator [](int k){\n    return\
    \ get(root, k)->val;\n  }\n  node* insert(node* r, int k, node* v){\n    if (k\
    \ == size(r)){\n      v->ch[0] = r;\n      if (r != nullptr){\n        r->p =\
    \ v;\n      }\n      r = v;\n      update(v);\n    } else {\n      node* u = get(r,\
    \ k);\n      v->ch[0] = u->ch[0];\n      v->ch[1] = u;\n      if (u->ch[0] !=\
    \ nullptr){\n        u->ch[0]->p = v;\n      }\n      u->ch[0] = nullptr;\n  \
    \    u->p = v;\n      update(u);\n      update(v);\n    }\n    root = v;\n   \
    \ return v;\n  }\n  node* insert(node *r, int k){\n    node* v = new node;\n \
    \   return insert(r, k, v);\n  }\n  node* insert(node *r, int k, T x){\n    node*\
    \ v = new node(x);\n    return insert(r, k, v);\n  }\n  node* insert(int k, T\
    \ x){\n    return insert(root, k, x);\n  }\n  void erase(node* v){\n    node*\
    \ l = v->ch[0];\n    node* r = v->ch[1];\n    delete v;\n    if (l == nullptr\
    \ && r == nullptr){\n      root = nullptr;\n    } else if (l == nullptr){\n  \
    \    root = r;\n      r->p = nullptr;    \n    } else if (r == nullptr){\n   \
    \   root = l;\n      l->p = nullptr;\n    } else {\n      r->p = nullptr;\n  \
    \    root = r;\n      r = get(0);\n      r->ch[0] = l;\n      l->p = r;\n    \
    \  update(r);\n    }\n  }\n  void erase(node *v, int k){\n    erase(get(v, k));\n\
    \  }\n  void erase(int k){\n    erase(get(k));\n  }\n  pair<node*, node*> split(node*\
    \ v, int k){\n    node* x = insert(v, k);\n    node* l = x->ch[0];\n    node*\
    \ r = x->ch[1];\n    if (l != nullptr){\n      l->p = nullptr;\n    }\n    if\
    \ (r != nullptr){\n      r->p = nullptr;\n    }\n    delete x;\n    return make_pair(l,\
    \ r);\n  }\n  pair<node*, node*> split(int k){\n    return split(root, k);\n \
    \ }\n  node* merge(node* l, node* r){\n    node* v = new node;\n    v->ch[0] =\
    \ l;\n    v->ch[1] = r;\n    if (l != nullptr){\n      l->p = v;\n    }\n    if\
    \ (r != nullptr){\n      r->p = v;\n    }\n    erase(v);\n    return root;\n \
    \ }\n  void set(node* v, T x){\n    v->val = x;\n    update(v);\n  }\n  void set(node*\
    \ v, int k, int x){\n    node* w = get(v, k);\n    set(w, x);\n  }\n  void set(int\
    \ k, int x){\n    node* v = get(k);\n    set(v, x);\n  }\n  T query(node* v, int\
    \ l, int r){\n    int sz = size(v->ch[0]);\n    T ans = E;\n    if (l == 0 &&\
    \ r >= sz){\n      ans = sum(v->ch[0]);\n    } else if (l < sz){\n      ans =\
    \ query(v->ch[0], l, min(r, sz));\n    }\n    if (l <= sz && r > sz){\n      ans\
    \ = f(ans, v->val);\n    }\n    if (l <= sz + 1 && r == v->sz){\n      ans = f(ans,\
    \ sum(v->ch[1]));\n    } else if (r > sz + 1){\n      ans = f(ans, query(v->ch[1],\
    \ max(l - sz - 1, 0), r - sz - 1));\n    }\n    return ans;\n  }\n  T query(int\
    \ l, int r){\n    return query(root, l, r);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/bbst/splay_tree.hpp
  requiredBy: []
  timestamp: '2022-08-05 04:50:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/other/1508.test.cpp
  - test/aoj/other/1508_2.test.cpp
documentation_of: data_structure/bbst/splay_tree.hpp
layout: document
redirect_from:
- /library/data_structure/bbst/splay_tree.hpp
- /library/data_structure/bbst/splay_tree.hpp.html
title: "\u30B9\u30D7\u30EC\u30FC\u6728 (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\
  \u53D6\u5F97)"
---
