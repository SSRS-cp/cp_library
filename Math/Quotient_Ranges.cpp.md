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
  bundledCode: "#line 1 \"Math/Quotient_Ranges.cpp\"\nvector<pair<long long, pair<long\
    \ long, long long>>> quotient_ranges(long long N){\n\tvector<pair<long long, pair<long\
    \ long, long long>>> ans;\n\tfor (long long i = 1; i * i <= N; i++){\n\t\tans.push_back(make_pair(N\
    \ / i, make_pair(i, i)));\n\t}\n\tfor (long long i = N / ((long long) sqrt(N)\
    \ + 1); i >= 1; i--){\n\t\tans.push_back(make_pair(i, make_pair(N / (i + 1) +\
    \ 1, N / i)));\n\t}\n\treturn ans;\n}\n"
  code: "vector<pair<long long, pair<long long, long long>>> quotient_ranges(long\
    \ long N){\n\tvector<pair<long long, pair<long long, long long>>> ans;\n\tfor\
    \ (long long i = 1; i * i <= N; i++){\n\t\tans.push_back(make_pair(N / i, make_pair(i,\
    \ i)));\n\t}\n\tfor (long long i = N / ((long long) sqrt(N) + 1); i >= 1; i--){\n\
    \t\tans.push_back(make_pair(i, make_pair(N / (i + 1) + 1, N / i)));\n\t}\n\treturn\
    \ ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Quotient_Ranges.cpp
  requiredBy: []
  timestamp: '2020-07-20 21:52:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Quotient_Ranges.cpp
layout: document
redirect_from:
- /library/Math/Quotient_Ranges.cpp
- /library/Math/Quotient_Ranges.cpp.html
title: Math/Quotient_Ranges.cpp
---
