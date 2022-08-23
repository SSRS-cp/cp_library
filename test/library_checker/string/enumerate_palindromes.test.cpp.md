---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manacher.hpp
    title: "\u6700\u9577\u56DE\u6587 (Manacher's Algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"string/manacher.hpp\"\
    \nvector<int> manacher(const string &S){\n  int N = S.size();\n  vector<int> ans(N,\
    \ 0);\n  int i = 0, j = 0;\n  while (i < N){\n    while (i >= j && i + j < N &&\
    \ S[i - j] == S[i + j]){\n      j++;\n    }\n    ans[i] = j;\n    int k = 1;\n\
    \    while (i >= k && i + k < N && k + ans[i - k] < j){\n      ans[i + k] = ans[i\
    \ - k];\n      k++;\n    }\n    i += k;\n    j -= k;\n  }\n  return ans;\n}\n\
    #line 5 \"test/library_checker/string/enumerate_palindromes.test.cpp\"\nint main(){\n\
    \  string S;\n  cin >> S;\n  int N = S.size();\n  string T = \"$\";\n  for (int\
    \ i = 0; i < N; i++){\n    T += S[i];\n    T += '$';\n  }\n  vector<int> ans =\
    \ manacher(T);\n  for (int i = 1; i < N * 2; i++){\n    cout << ans[i] - 1;\n\
    \    if (i < N * 2 - 1){\n      cout << ' ';\n    }\n  }\n  cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../string/manacher.hpp\"\
    \nint main(){\n  string S;\n  cin >> S;\n  int N = S.size();\n  string T = \"\
    $\";\n  for (int i = 0; i < N; i++){\n    T += S[i];\n    T += '$';\n  }\n  vector<int>\
    \ ans = manacher(T);\n  for (int i = 1; i < N * 2; i++){\n    cout << ans[i] -\
    \ 1;\n    if (i < N * 2 - 1){\n      cout << ' ';\n    }\n  }\n  cout << endl;\n\
    }"
  dependsOn:
  - string/manacher.hpp
  isVerificationFile: true
  path: test/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2022-08-24 05:13:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/enumerate_palindromes.test.cpp
- /verify/test/library_checker/string/enumerate_palindromes.test.cpp.html
title: test/library_checker/string/enumerate_palindromes.test.cpp
---
