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
  bundledCode: "#line 1 \"old_String/Rolling_Hash.cpp\"\nstruct rolling_hash{\n  vector<long\
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
  path: old_String/Rolling_Hash.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_String/Rolling_Hash.cpp
layout: document
redirect_from:
- /library/old_String/Rolling_Hash.cpp
- /library/old_String/Rolling_Hash.cpp.html
title: old_String/Rolling_Hash.cpp
---
