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
  bundledCode: "#line 1 \"String/Rolling_Hash.cpp\"\nstruct rolling_hash{\n  vector<long\
    \ long> S;\n  rolling_hash(string s){\n    int N = s.size();\n    S = vector<long\
    \ long>(N + 1, 0);\n    for (int i = N - 1; i >= 0; i--){\n      S[i] = (S[i +\
    \ 1] * BASE + s[i]) % MOD;\n    }\n  }\n  long long get(int L, int R){\n    return\
    \ (S[L] - S[R] * POW[R - L] % MOD + MOD) % MOD;\n  }\n};\n"
  code: "struct rolling_hash{\n  vector<long long> S;\n  rolling_hash(string s){\n\
    \    int N = s.size();\n    S = vector<long long>(N + 1, 0);\n    for (int i =\
    \ N - 1; i >= 0; i--){\n      S[i] = (S[i + 1] * BASE + s[i]) % MOD;\n    }\n\
    \  }\n  long long get(int L, int R){\n    return (S[L] - S[R] * POW[R - L] % MOD\
    \ + MOD) % MOD;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/Rolling_Hash.cpp
  requiredBy: []
  timestamp: '2021-12-01 17:45:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Rolling_Hash.cpp
layout: document
redirect_from:
- /library/String/Rolling_Hash.cpp
- /library/String/Rolling_Hash.cpp.html
title: String/Rolling_Hash.cpp
---
