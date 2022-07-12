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
  bundledCode: "#line 1 \"Math/Polynomial_Division.cpp\"\nvector<long long> polynomial_quotient(vector<long\
    \ long> f, vector<long long> g){\n  int N = f.size(), M = g.size();\n  if (N <\
    \ M){\n    return {0};\n  }\n  reverse(g.begin(), g.end());\n  g.resize(N - M\
    \ + 1);\n  vector<long long> t = polynomial_inverse(g);\n  reverse(f.begin(),\
    \ f.end());\n  vector<long long> q = convolution(f, t, N - M + 1);\n  reverse(q.begin(),\
    \ q.end());\n  return q;\n}\nvector<long long> polynomial_remainder(vector<long\
    \ long> f, vector<long long> g){\n  int N = f.size();\n  int M = g.size();\n \
    \ if (M <= 1200){\n    for (int i = N - M; i >= 0; i--){\n      long long q =\
    \ f[i + M - 1] * modinv(g[M - 1]) % MOD;\n      for (int j = 0; j < M; j++){\n\
    \        f[i + j] += MOD - q * g[j] % MOD;\n        f[i + j] %= MOD;\n      }\n\
    \      f.pop_back();\n    }\n    return f;\n  } else {\n    vector<long long>\
    \ q = polynomial_quotient(f, g);\n    vector<long long> b = convolution(g, q);\n\
    \    for (int i = 0; i < N; i++){\n      f[i] += MOD - b[i];\n      f[i] %= MOD;\n\
    \    }\n    f.resize(M - 1);\n    return f;\n  }\n}\n"
  code: "vector<long long> polynomial_quotient(vector<long long> f, vector<long long>\
    \ g){\n  int N = f.size(), M = g.size();\n  if (N < M){\n    return {0};\n  }\n\
    \  reverse(g.begin(), g.end());\n  g.resize(N - M + 1);\n  vector<long long> t\
    \ = polynomial_inverse(g);\n  reverse(f.begin(), f.end());\n  vector<long long>\
    \ q = convolution(f, t, N - M + 1);\n  reverse(q.begin(), q.end());\n  return\
    \ q;\n}\nvector<long long> polynomial_remainder(vector<long long> f, vector<long\
    \ long> g){\n  int N = f.size();\n  int M = g.size();\n  if (M <= 1200){\n   \
    \ for (int i = N - M; i >= 0; i--){\n      long long q = f[i + M - 1] * modinv(g[M\
    \ - 1]) % MOD;\n      for (int j = 0; j < M; j++){\n        f[i + j] += MOD -\
    \ q * g[j] % MOD;\n        f[i + j] %= MOD;\n      }\n      f.pop_back();\n  \
    \  }\n    return f;\n  } else {\n    vector<long long> q = polynomial_quotient(f,\
    \ g);\n    vector<long long> b = convolution(g, q);\n    for (int i = 0; i < N;\
    \ i++){\n      f[i] += MOD - b[i];\n      f[i] %= MOD;\n    }\n    f.resize(M\
    \ - 1);\n    return f;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Polynomial_Division.cpp
  requiredBy: []
  timestamp: '2021-08-29 18:39:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Polynomial_Division.cpp
layout: document
redirect_from:
- /library/Math/Polynomial_Division.cpp
- /library/Math/Polynomial_Division.cpp.html
title: Math/Polynomial_Division.cpp
---
