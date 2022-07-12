---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structures/Treap.cpp\"\ntemplate <typename T>\nstruct\
    \ treap{\n  int N;\n  T E;\n  function<T(T, T)> f;\n  vector<T> node;\n  vector<T>\
    \ prod;\n  vector<int> priority;\n  vector<int> parent;\n  vector<int> left, right;\n\
    \  vector<int> size;\n  int root;\n  treap(T E, function<T(T, T)> f): E(E), f(f){\n\
    \    N = 0;\n    root = 0;\n  }\n  void eval(int v){\n    size[v] = 1;\n    if\
    \ (left[v] != -1){\n      size[v] += size[left[v]];\n    }\n    if (right[v] !=\
    \ -1){\n      size[v] += size[right[v]];\n    }\n    prod[v] = node[v];\n    if\
    \ (left[v] != -1){\n      prod[v] = f(prod[left[v]], prod[v]);\n    }\n    if\
    \ (right[v] != -1){\n      prod[v] = f(prod[v], prod[right[v]]);\n    }\n  }\n\
    \  int right_rotate(int v){\n    int w = left[v];\n    left[v] = right[w];\n \
    \   parent[w] = parent[v];\n    if (right[w] != -1){\n      parent[right[w]] =\
    \ v;\n    }\n    right[w] = v;\n    if (parent[w] != -1){\n      if (left[parent[w]]\
    \ == v){\n        left[parent[w]] = w;\n      } else {\n        right[parent[w]]\
    \ = w;\n      }\n    }\n    parent[v] = w;\n    if (root == v){\n      root =\
    \ w;\n    }\n    eval(v);\n    return w;\n  }\n  int left_rotate(int v){\n   \
    \ int w = right[v];\n    right[v] = left[w];\n    parent[w] = parent[v];\n   \
    \ if (left[w] != -1){\n      parent[left[w]] = v;\n    }\n    left[w] = v;\n \
    \   if (parent[w] != -1){\n      if (left[parent[w]] == v){\n        left[parent[w]]\
    \ = w;\n      } else {\n        right[parent[w]] = w;\n      }\n    }\n    parent[v]\
    \ = w;\n    if (root == v){\n      root = w;\n    }\n    eval(v);\n    return\
    \ w;\n  }\n  int get_id(int k){\n    int v = root;\n    while (true){\n      int\
    \ lsz = 0;\n      if (left[v] != -1){\n        lsz = size[left[v]];\n      }\n\
    \      if (k < lsz){\n        v = left[v];\n      } else if (k == lsz){\n    \
    \    return v;\n      } else {\n        k -= lsz + 1;\n        v = right[v];\n\
    \      }\n    }\n  }\n  T operator [](int k){\n    return node[get_id(k)];\n \
    \ }\n  void insert(int pos, T x, int pri){\n    int v = -1;\n    if (N > 0){\n\
    \      v = root;\n      while (true){\n        int lsz = 0;\n        if (left[v]\
    \ != -1){\n          lsz = size[left[v]];\n        }\n        if (pos <= lsz){\n\
    \          if (left[v] == -1){\n            left[v] = N;\n            break;\n\
    \          } else {\n            v = left[v];\n          }\n        } else {\n\
    \          pos -= lsz + 1;\n          if (right[v] == -1){\n            right[v]\
    \ = N;\n            break;\n          } else {\n            v = right[v];\n  \
    \        }\n        }\n      }\n    }\n    node.push_back(x);\n    prod.push_back(x);\n\
    \    priority.push_back(pri);\n    parent.push_back(v);\n    left.push_back(-1);\n\
    \    right.push_back(-1);\n    size.push_back(1);\n    N++;\n    if (N == 1){\n\
    \      root = 0;\n    }\n    v = N - 1;\n    while (parent[v] != -1){\n      if\
    \ (priority[parent[v]] < priority[v]){\n        if (left[parent[v]] == v){\n \
    \         v = right_rotate(parent[v]);\n        } else {\n          v = left_rotate(parent[v]);\n\
    \        }\n      } else {\n        break;\n      }\n    }\n    while (parent[v]\
    \ != -1){\n      eval(v);\n      v = parent[v];\n    }\n    eval(v);\n  }\n  void\
    \ erase(int k){\n    int v = get_id(k);\n    while (left[v] != -1 || right[v]\
    \ != -1){\n      if (left[v] != -1 && right[v] != -1){\n        if (priority[left[v]]\
    \ > priority[right[v]]){\n          v = right[right_rotate(v)];\n        } else\
    \ {\n          v = left[left_rotate(v)];\n        }\n      } else if (left[v]\
    \ != -1){\n        v = right[right_rotate(v)];\n      } else {\n        v = left[left_rotate(v)];\n\
    \      }\n    }\n    int w = v;\n    size[w] = 0;\n    prod[w] = E;\n    while\
    \ (parent[w] != -1){\n      w = parent[w];\n      eval(w);\n    }\n    if (parent[v]\
    \ != -1){\n      if (left[parent[v]] == v){\n        left[parent[v]] = -1;\n \
    \     } else {\n        right[parent[v]] = -1;\n      }\n    }\n    if (v != N\
    \ - 1){\n      if (parent[N - 1] != -1){\n        if (left[parent[N - 1]] == N\
    \ - 1){\n          left[parent[N - 1]] = v;\n        } else {\n          right[parent[N\
    \ - 1]] = v;\n        }\n      }\n      if (left[N - 1] != -1){\n        parent[left[N\
    \ - 1]] = v;\n      }\n      if (right[N - 1] != -1){\n        parent[right[N\
    \ - 1]] = v;\n      }\n      node[v] = node[N - 1];\n      prod[v] = prod[N -\
    \ 1];\n      priority[v] = priority[N - 1];\n      parent[v] = parent[N - 1];\n\
    \      left[v] = left[N - 1];\n      right[v] = right[N - 1];\n      size[v] =\
    \ size[N - 1];\n      if (root == N - 1){\n        root = v;\n      }\n    }\n\
    \    node.pop_back();\n    prod.pop_back();\n    priority.pop_back();\n    parent.pop_back();\n\
    \    left.pop_back();\n    right.pop_back();\n    size.pop_back();\n    N--;\n\
    \  }\n  void update(int k, T x){\n    int v = get_id(k);\n    node[v] = x;\n \
    \   while (parent[v] != -1){\n      eval(v);\n      v = parent[v];\n    }\n  \
    \  eval(v);\n  }\n  T range_fold(int L, int R, int i, int l, int r){\n    if (r\
    \ <= L || R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n     \
    \ return prod[i];\n    } else {\n      int lsz = 0;\n      if (left[i] != -1){\n\
    \        lsz = size[left[i]];\n      }\n      T ans = E;\n      if (L <= l + lsz\
    \ && l + lsz < R){\n        ans = node[i];\n      }\n      if (left[i] != -1){\n\
    \        ans = f(range_fold(L, R, left[i], l, l + lsz), ans);\n      }\n     \
    \ if (right[i] != -1){\n        ans = f(ans, range_fold(L, R, right[i], l + lsz\
    \ + 1, r));\n      }\n      return ans;\n    }\n  }\n  T range_fold(int L, int\
    \ R){\n    return range_fold(L, R, root, 0, N);\n  }\n};\n"
  code: "template <typename T>\nstruct treap{\n  int N;\n  T E;\n  function<T(T, T)>\
    \ f;\n  vector<T> node;\n  vector<T> prod;\n  vector<int> priority;\n  vector<int>\
    \ parent;\n  vector<int> left, right;\n  vector<int> size;\n  int root;\n  treap(T\
    \ E, function<T(T, T)> f): E(E), f(f){\n    N = 0;\n    root = 0;\n  }\n  void\
    \ eval(int v){\n    size[v] = 1;\n    if (left[v] != -1){\n      size[v] += size[left[v]];\n\
    \    }\n    if (right[v] != -1){\n      size[v] += size[right[v]];\n    }\n  \
    \  prod[v] = node[v];\n    if (left[v] != -1){\n      prod[v] = f(prod[left[v]],\
    \ prod[v]);\n    }\n    if (right[v] != -1){\n      prod[v] = f(prod[v], prod[right[v]]);\n\
    \    }\n  }\n  int right_rotate(int v){\n    int w = left[v];\n    left[v] = right[w];\n\
    \    parent[w] = parent[v];\n    if (right[w] != -1){\n      parent[right[w]]\
    \ = v;\n    }\n    right[w] = v;\n    if (parent[w] != -1){\n      if (left[parent[w]]\
    \ == v){\n        left[parent[w]] = w;\n      } else {\n        right[parent[w]]\
    \ = w;\n      }\n    }\n    parent[v] = w;\n    if (root == v){\n      root =\
    \ w;\n    }\n    eval(v);\n    return w;\n  }\n  int left_rotate(int v){\n   \
    \ int w = right[v];\n    right[v] = left[w];\n    parent[w] = parent[v];\n   \
    \ if (left[w] != -1){\n      parent[left[w]] = v;\n    }\n    left[w] = v;\n \
    \   if (parent[w] != -1){\n      if (left[parent[w]] == v){\n        left[parent[w]]\
    \ = w;\n      } else {\n        right[parent[w]] = w;\n      }\n    }\n    parent[v]\
    \ = w;\n    if (root == v){\n      root = w;\n    }\n    eval(v);\n    return\
    \ w;\n  }\n  int get_id(int k){\n    int v = root;\n    while (true){\n      int\
    \ lsz = 0;\n      if (left[v] != -1){\n        lsz = size[left[v]];\n      }\n\
    \      if (k < lsz){\n        v = left[v];\n      } else if (k == lsz){\n    \
    \    return v;\n      } else {\n        k -= lsz + 1;\n        v = right[v];\n\
    \      }\n    }\n  }\n  T operator [](int k){\n    return node[get_id(k)];\n \
    \ }\n  void insert(int pos, T x, int pri){\n    int v = -1;\n    if (N > 0){\n\
    \      v = root;\n      while (true){\n        int lsz = 0;\n        if (left[v]\
    \ != -1){\n          lsz = size[left[v]];\n        }\n        if (pos <= lsz){\n\
    \          if (left[v] == -1){\n            left[v] = N;\n            break;\n\
    \          } else {\n            v = left[v];\n          }\n        } else {\n\
    \          pos -= lsz + 1;\n          if (right[v] == -1){\n            right[v]\
    \ = N;\n            break;\n          } else {\n            v = right[v];\n  \
    \        }\n        }\n      }\n    }\n    node.push_back(x);\n    prod.push_back(x);\n\
    \    priority.push_back(pri);\n    parent.push_back(v);\n    left.push_back(-1);\n\
    \    right.push_back(-1);\n    size.push_back(1);\n    N++;\n    if (N == 1){\n\
    \      root = 0;\n    }\n    v = N - 1;\n    while (parent[v] != -1){\n      if\
    \ (priority[parent[v]] < priority[v]){\n        if (left[parent[v]] == v){\n \
    \         v = right_rotate(parent[v]);\n        } else {\n          v = left_rotate(parent[v]);\n\
    \        }\n      } else {\n        break;\n      }\n    }\n    while (parent[v]\
    \ != -1){\n      eval(v);\n      v = parent[v];\n    }\n    eval(v);\n  }\n  void\
    \ erase(int k){\n    int v = get_id(k);\n    while (left[v] != -1 || right[v]\
    \ != -1){\n      if (left[v] != -1 && right[v] != -1){\n        if (priority[left[v]]\
    \ > priority[right[v]]){\n          v = right[right_rotate(v)];\n        } else\
    \ {\n          v = left[left_rotate(v)];\n        }\n      } else if (left[v]\
    \ != -1){\n        v = right[right_rotate(v)];\n      } else {\n        v = left[left_rotate(v)];\n\
    \      }\n    }\n    int w = v;\n    size[w] = 0;\n    prod[w] = E;\n    while\
    \ (parent[w] != -1){\n      w = parent[w];\n      eval(w);\n    }\n    if (parent[v]\
    \ != -1){\n      if (left[parent[v]] == v){\n        left[parent[v]] = -1;\n \
    \     } else {\n        right[parent[v]] = -1;\n      }\n    }\n    if (v != N\
    \ - 1){\n      if (parent[N - 1] != -1){\n        if (left[parent[N - 1]] == N\
    \ - 1){\n          left[parent[N - 1]] = v;\n        } else {\n          right[parent[N\
    \ - 1]] = v;\n        }\n      }\n      if (left[N - 1] != -1){\n        parent[left[N\
    \ - 1]] = v;\n      }\n      if (right[N - 1] != -1){\n        parent[right[N\
    \ - 1]] = v;\n      }\n      node[v] = node[N - 1];\n      prod[v] = prod[N -\
    \ 1];\n      priority[v] = priority[N - 1];\n      parent[v] = parent[N - 1];\n\
    \      left[v] = left[N - 1];\n      right[v] = right[N - 1];\n      size[v] =\
    \ size[N - 1];\n      if (root == N - 1){\n        root = v;\n      }\n    }\n\
    \    node.pop_back();\n    prod.pop_back();\n    priority.pop_back();\n    parent.pop_back();\n\
    \    left.pop_back();\n    right.pop_back();\n    size.pop_back();\n    N--;\n\
    \  }\n  void update(int k, T x){\n    int v = get_id(k);\n    node[v] = x;\n \
    \   while (parent[v] != -1){\n      eval(v);\n      v = parent[v];\n    }\n  \
    \  eval(v);\n  }\n  T range_fold(int L, int R, int i, int l, int r){\n    if (r\
    \ <= L || R <= l){\n      return E;\n    } else if (L <= l && r <= R){\n     \
    \ return prod[i];\n    } else {\n      int lsz = 0;\n      if (left[i] != -1){\n\
    \        lsz = size[left[i]];\n      }\n      T ans = E;\n      if (L <= l + lsz\
    \ && l + lsz < R){\n        ans = node[i];\n      }\n      if (left[i] != -1){\n\
    \        ans = f(range_fold(L, R, left[i], l, l + lsz), ans);\n      }\n     \
    \ if (right[i] != -1){\n        ans = f(ans, range_fold(L, R, right[i], l + lsz\
    \ + 1, r));\n      }\n      return ans;\n    }\n  }\n  T range_fold(int L, int\
    \ R){\n    return range_fold(L, R, root, 0, N);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structures/Treap.cpp
  requiredBy: []
  timestamp: '2021-05-02 22:13:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structures/Treap.cpp
layout: document
redirect_from:
- /library/Data_Structures/Treap.cpp
- /library/Data_Structures/Treap.cpp.html
title: Data_Structures/Treap.cpp
---
