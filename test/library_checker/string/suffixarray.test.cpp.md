---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/suffix_array.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (SA-IS)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/library_checker/string/suffixarray.test.cpp\"\n#define\
    \ _GLIBCXX_DEBUG\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"string/suffix_array.hpp\"\
    \nvector<int> suffix_array(const vector<int> &A, int mx){\n  int N = A.size();\n\
    \  vector<int> sum(mx + 1, 0);\n  for (int i = 0; i < N; i++){\n    sum[A[i] +\
    \ 1]++;\n  }\n  for (int i = 0; i < mx; i++){\n    sum[i + 1] += sum[i];\n  }\n\
    \  vector<bool> is_s(N);\n  is_s[N - 1] = false;\n  for (int i = N - 2; i >= 0;\
    \ i--){\n    is_s[i] = A[i] < A[i + 1] || A[i] == A[i + 1] && is_s[i + 1];\n \
    \ }\n  vector<int> id(N, -1);\n  vector<int> pos;\n  int M = 0;\n  for (int i\
    \ = 1; i < N; i++){\n    if (is_s[i] && !is_s[i - 1]){\n      id[i] = M;\n   \
    \   pos.push_back(i);\n      M++;\n    }\n  }\n  vector<int> sa(N);\n  auto induce\
    \ = [&](vector<int>& lms){\n    sa = vector<int>(N, -1);\n    vector<bool> used(N,\
    \ false);\n    vector<int> p(mx);\n    vector<int> p2(mx);\n    for (int i = 0;\
    \ i < mx; i++){\n      p[i] = sum[i + 1] - 1;\n      p2[i] = sum[i];\n    }\n\
    \    for (int i = M - 1; i >= 0; i--){\n      sa[p[A[lms[i]]]] = lms[i];\n   \
    \   p[A[lms[i]]]--;\n      used[lms[i]] = true;\n    }\n    sa[p2[A[N - 1]]] =\
    \ N - 1;\n    p2[A[N - 1]]++;\n    used[N - 1] = true;\n    for (int i = 0; i\
    \ < N; i++){\n      if (sa[i] > 0){\n        if (!is_s[sa[i] - 1] && !used[sa[i]\
    \ - 1]){\n          sa[p2[A[sa[i] - 1]]] = sa[i] - 1;\n          p2[A[sa[i] -\
    \ 1]]++;\n          used[sa[i] - 1] = true;\n        }\n      }\n    }\n    for\
    \ (int i = 0; i < N; i++){\n      if (sa[i] != -1){\n        if (id[sa[i]] !=\
    \ -1){\n          used[sa[i]] = false;\n          sa[i] = -1;\n        }\n   \
    \   }\n    }\n    for (int i = 0; i < mx; i++){\n      p[i] = sum[i + 1] - 1;\n\
    \    }\n    for (int i = N - 1; i >= 0; i--){\n      if (sa[i] > 0){\n       \
    \ if (is_s[sa[i] - 1] && !used[sa[i] - 1]){\n          sa[p[A[sa[i] - 1]]] = sa[i]\
    \ - 1;\n          p[A[sa[i] - 1]]--;\n          used[sa[i] - 1] = true;\n    \
    \    }\n      }\n    }\n  };\n  induce(pos);\n  if (M == 0){\n    return sa;\n\
    \  }\n  vector<int> lms;\n  for (int i = 0; i < N; i++){\n    if (id[sa[i]] !=\
    \ -1){\n      lms.push_back(sa[i]);\n    }\n  }\n  vector<int> c(M);\n  c[0] =\
    \ 0;\n  for (int i = 0; i < M - 1; i++){\n    c[i + 1] = c[i];\n    int x = lms[i];\n\
    \    int y = lms[i + 1];\n    bool ok = true;\n    while (x < N && y < N){\n \
    \     if (A[x] != A[y]){\n        ok = false;\n        break;\n      }\n     \
    \ x++;\n      y++;\n      if (id[x] != -1){\n        if (id[y] == -1){\n     \
    \     ok = false;\n        }\n        break;\n      }\n    }\n    if (x == N ||\
    \ y == N){\n      ok = false;\n    }\n    if (!ok){\n      c[i + 1]++;\n    }\n\
    \  }\n  vector<int> rec(M);\n  for (int i = 0; i < M; i++){\n    rec[id[lms[i]]]\
    \ = c[i];\n  }\n  vector<int> sa2 = suffix_array(rec, c[M - 1] + 1);\n  vector<int>\
    \ pos2(M);\n  for (int i = 0; i < M; i++){\n    pos2[i] = pos[sa2[i]];\n  }\n\
    \  induce(pos2);\n  return sa;\n}\nvector<int> suffix_array(const string &S){\n\
    \  int N = S.size();\n  vector<int> A(N);\n  for (int i = 0; i < N; i++){\n  \
    \  A[i] = S[i];\n  }\n  return suffix_array(A, 256);\n}\n#line 6 \"test/library_checker/string/suffixarray.test.cpp\"\
    \nint main(){\n  string S;\n  cin >> S;\n  int N = S.size();\n  vector<int> A\
    \ = suffix_array(S);\n  for (int i = 0; i < N; i++){\n    cout << A[i];\n    if\
    \ (i < N - 1){\n      cout << ' ';\n    }\n  }\n  cout << endl;\n}\n"
  code: "#define _GLIBCXX_DEBUG\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../string/suffix_array.hpp\"\
    \nint main(){\n  string S;\n  cin >> S;\n  int N = S.size();\n  vector<int> A\
    \ = suffix_array(S);\n  for (int i = 0; i < N; i++){\n    cout << A[i];\n    if\
    \ (i < N - 1){\n      cout << ' ';\n    }\n  }\n  cout << endl;\n}"
  dependsOn:
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test/library_checker/string/suffixarray.test.cpp
  requiredBy: []
  timestamp: '2022-10-01 03:56:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/string/suffixarray.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/suffixarray.test.cpp
- /verify/test/library_checker/string/suffixarray.test.cpp.html
title: test/library_checker/string/suffixarray.test.cpp
---
