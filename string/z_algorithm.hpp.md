---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm.test.cpp
    title: test/library_checker/string/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Z Algorithm
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n/**\n * @brief Z Algorithm\n*/\n\
    vector<int> z_algorithm(const string &S){\n  int N = S.size();\n  vector<int>\
    \ ans(N);\n  for (int i = 1, j = 0; i < N; i++){\n    if (i + ans[i - j] < j +\
    \ ans[j]){\n      ans[i] = ans[i - j];\n    } else {\n      int k = max(0, j +\
    \ ans[j] - i);\n      while (i + k < N && S[k] == S[i + k]){\n        k++;\n \
    \     }\n      ans[i] = k;\n      j = i;\n    }\n  }\n  ans[0] = N;\n  return\
    \ ans;\n}\n"
  code: "#pragma once\n/**\n * @brief Z Algorithm\n*/\nvector<int> z_algorithm(const\
    \ string &S){\n  int N = S.size();\n  vector<int> ans(N);\n  for (int i = 1, j\
    \ = 0; i < N; i++){\n    if (i + ans[i - j] < j + ans[j]){\n      ans[i] = ans[i\
    \ - j];\n    } else {\n      int k = max(0, j + ans[j] - i);\n      while (i +\
    \ k < N && S[k] == S[i + k]){\n        k++;\n      }\n      ans[i] = k;\n    \
    \  j = i;\n    }\n  }\n  ans[0] = N;\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2022-08-24 05:13:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/zalgorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: Z Algorithm
---
