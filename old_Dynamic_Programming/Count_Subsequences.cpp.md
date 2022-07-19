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
  bundledCode: "#line 1 \"old_Dynamic_Programming/Count_Subsequences.cpp\"\nlong long\
    \ count_subsequences(string &S){\n\tint N = S.size();\n\tvector<vector<int>> next(N\
    \ + 1, vector<int>(26, N));\n\tfor (int i = N - 1; i >= 0; i--){\n\t\tfor (int\
    \ j = 0; j < 26; j++){\n\t\tnext[i][j] = next[i + 1][j];\n\t\t}\n\t\tnext[i][S[i]\
    \ - 'a'] = i;\n\t}\n\tvector<long long> dp(N + 1, 0);\n\tdp[0] = 1;\n\tfor (int\
    \ i = 0; i < N; i++){\n\t\tfor (int j = 0; j < 26; j++){\n\t\t\tif (next[i][j]\
    \ < N){\n\t\t\t\tdp[next[i][j] + 1] = (dp[next[i][j] + 1] + dp[i]) % MOD;\n\t\t\
    \t}\n\t\t}\n\t}\n\tlong long ans = 0;\n\tfor (int i = 0; i <= N; i++){\n\t\tans\
    \ = (ans + dp[i]) % MOD;\n\t}\n\treturn ans;\n}\n"
  code: "long long count_subsequences(string &S){\n\tint N = S.size();\n\tvector<vector<int>>\
    \ next(N + 1, vector<int>(26, N));\n\tfor (int i = N - 1; i >= 0; i--){\n\t\t\
    for (int j = 0; j < 26; j++){\n\t\tnext[i][j] = next[i + 1][j];\n\t\t}\n\t\tnext[i][S[i]\
    \ - 'a'] = i;\n\t}\n\tvector<long long> dp(N + 1, 0);\n\tdp[0] = 1;\n\tfor (int\
    \ i = 0; i < N; i++){\n\t\tfor (int j = 0; j < 26; j++){\n\t\t\tif (next[i][j]\
    \ < N){\n\t\t\t\tdp[next[i][j] + 1] = (dp[next[i][j] + 1] + dp[i]) % MOD;\n\t\t\
    \t}\n\t\t}\n\t}\n\tlong long ans = 0;\n\tfor (int i = 0; i <= N; i++){\n\t\tans\
    \ = (ans + dp[i]) % MOD;\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Dynamic_Programming/Count_Subsequences.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Dynamic_Programming/Count_Subsequences.cpp
layout: document
redirect_from:
- /library/old_Dynamic_Programming/Count_Subsequences.cpp
- /library/old_Dynamic_Programming/Count_Subsequences.cpp.html
title: old_Dynamic_Programming/Count_Subsequences.cpp
---
