---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: Z Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/library_checker/string/zalgorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"string/z_algorithm.hpp\"\ntemplate <typename T>\n\
    vector<int> z_algorithm(const vector<T> &A){\n  int N = A.size();\n  vector<int>\
    \ Z(N, 0);\n  for (int i = 1, j = 0; i < N; i++){\n    if (i + Z[i - j] < j +\
    \ Z[j]){\n      Z[i] = Z[i - j];\n    } else {\n      int k = max(0, j + Z[j]\
    \ - i);\n      while (i + k < N && A[k] == A[i + k]){\n        k++;\n      }\n\
    \      Z[i] = k;\n      j = i;\n    }\n  }\n  Z[0] = N;\n  return Z;\n}\nvector<int>\
    \ z_algorithm(const string &S){\n  int N = S.size();\n  vector<int> A(N);\n  for\
    \ (int i = 0; i < N; i++){\n    A[i] = S[i];\n  }\n  return z_algorithm(A);\n\
    }\n#line 5 \"test/library_checker/string/zalgorithm.test.cpp\"\nint main(){\n\
    \  string S;\n  cin >> S;\n  int N = S.size();\n  vector<int> ans = z_algorithm(S);\n\
    \  for (int i = 0; i < N; i++){\n    cout << ans[i];\n    if (i < N - 1){\n  \
    \    cout << ' ';\n    }\n  }\n  cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../../string/z_algorithm.hpp\"\
    \nint main(){\n  string S;\n  cin >> S;\n  int N = S.size();\n  vector<int> ans\
    \ = z_algorithm(S);\n  for (int i = 0; i < N; i++){\n    cout << ans[i];\n   \
    \ if (i < N - 1){\n      cout << ' ';\n    }\n  }\n  cout << endl;\n}"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: test/library_checker/string/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2022-08-29 05:52:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/zalgorithm.test.cpp
- /verify/test/library_checker/string/zalgorithm.test.cpp.html
title: test/library_checker/string/zalgorithm.test.cpp
---
