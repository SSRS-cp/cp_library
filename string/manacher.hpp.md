---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/enumerate_palindromes.test.cpp
    title: test/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u9577\u56DE\u6587 (Manacher's Algorithm)"
    links: []
  bundledCode: "#line 2 \"string/manacher.hpp\"\n/**\n * @brief \u6700\u9577\u56DE\
    \u6587 (Manacher's Algorithm)\n*/\nvector<int> manacher(string &S){\n  int N =\
    \ S.size();\n  vector<int> ans(N, 0);\n  int i = 0, j = 0;\n  while (i < N){\n\
    \    while (i >= j && i + j < N && S[i - j] == S[i + j]){\n      j++;\n    }\n\
    \    ans[i] = j;\n    int k = 1;\n    while (i >= k && i + k < N && k + ans[i\
    \ - k] < j){\n      ans[i + k] = ans[i - k];\n      k++;\n    }\n    i += k;\n\
    \    j -= k;\n  }\n  return ans;\n}\n"
  code: "#pragma once\n/**\n * @brief \u6700\u9577\u56DE\u6587 (Manacher's Algorithm)\n\
    */\nvector<int> manacher(string &S){\n  int N = S.size();\n  vector<int> ans(N,\
    \ 0);\n  int i = 0, j = 0;\n  while (i < N){\n    while (i >= j && i + j < N &&\
    \ S[i - j] == S[i + j]){\n      j++;\n    }\n    ans[i] = j;\n    int k = 1;\n\
    \    while (i >= k && i + k < N && k + ans[i - k] < j){\n      ans[i + k] = ans[i\
    \ - k];\n      k++;\n    }\n    i += k;\n    j -= k;\n  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-07-20 02:28:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: "\u6700\u9577\u56DE\u6587 (Manacher's Algorithm)"
---
