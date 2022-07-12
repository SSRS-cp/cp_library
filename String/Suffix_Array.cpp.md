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
  bundledCode: "#line 1 \"String/Suffix_Array.cpp\"\nvector<int> suffix_array(string\
    \ S){\n  S.push_back(0);\n  int N = S.size();\n  vector<int> cnt(128, 0);\n  for\
    \ (int i = 0; i < N; i++){\n    cnt[S[i]]++;\n  }\n  for (int i = 0; i < 127;\
    \ i++){\n    cnt[i + 1] += cnt[i];\n  }\n  vector<int> SA(N), rank(N);\n  for\
    \ (int i = 0; i < N; i++){\n    cnt[S[i]]--;\n    SA[cnt[S[i]]] = i;\n  }\n  rank[SA[0]]\
    \ = 0;\n  for (int i = 0; i < N - 1; i++){\n    rank[SA[i + 1]] = rank[SA[i]];\n\
    \    if (S[SA[i]] != S[SA[i + 1]]){\n      rank[SA[i + 1]]++;\n    }\n  }\n  int\
    \ L = 1;\n  while (L < N){\n    vector<int> SA2(N), rank2(N);\n    for (int i\
    \ = 0; i < N; i++){\n      SA2[i] = SA[i] - L;\n      if (SA2[i] < 0){\n     \
    \   SA2[i] += N;\n      }\n    }\n    cnt = vector<int>(N, 0);\n    for (int i\
    \ = 0; i < N; i++){\n      cnt[rank[SA2[i]]]++;\n    }\n    for (int i = 0; i\
    \ < N - 1; i++){\n      cnt[i + 1] += cnt[i];\n    }\n    for (int i = N - 1;\
    \ i >= 0; i--){\n      cnt[rank[SA2[i]]]--;\n      SA[cnt[rank[SA2[i]]]] = SA2[i];\n\
    \    }\n    rank2[SA[0]] = 0;\n    for (int i = 0; i < N - 1; i++){\n      rank2[SA[i\
    \ + 1]] = rank2[SA[i]];\n      if (rank[SA[i]] != rank[SA[i + 1]] || rank[(SA[i]\
    \ + L) % N] != rank[(SA[i + 1] + L) % N]){\n        rank2[SA[i + 1]]++;\n    \
    \  }\n    }\n    rank = rank2;\n    L *= 2;\n  }\n  SA.erase(SA.begin());\n  return\
    \ SA;\n};\n"
  code: "vector<int> suffix_array(string S){\n  S.push_back(0);\n  int N = S.size();\n\
    \  vector<int> cnt(128, 0);\n  for (int i = 0; i < N; i++){\n    cnt[S[i]]++;\n\
    \  }\n  for (int i = 0; i < 127; i++){\n    cnt[i + 1] += cnt[i];\n  }\n  vector<int>\
    \ SA(N), rank(N);\n  for (int i = 0; i < N; i++){\n    cnt[S[i]]--;\n    SA[cnt[S[i]]]\
    \ = i;\n  }\n  rank[SA[0]] = 0;\n  for (int i = 0; i < N - 1; i++){\n    rank[SA[i\
    \ + 1]] = rank[SA[i]];\n    if (S[SA[i]] != S[SA[i + 1]]){\n      rank[SA[i +\
    \ 1]]++;\n    }\n  }\n  int L = 1;\n  while (L < N){\n    vector<int> SA2(N),\
    \ rank2(N);\n    for (int i = 0; i < N; i++){\n      SA2[i] = SA[i] - L;\n   \
    \   if (SA2[i] < 0){\n        SA2[i] += N;\n      }\n    }\n    cnt = vector<int>(N,\
    \ 0);\n    for (int i = 0; i < N; i++){\n      cnt[rank[SA2[i]]]++;\n    }\n \
    \   for (int i = 0; i < N - 1; i++){\n      cnt[i + 1] += cnt[i];\n    }\n   \
    \ for (int i = N - 1; i >= 0; i--){\n      cnt[rank[SA2[i]]]--;\n      SA[cnt[rank[SA2[i]]]]\
    \ = SA2[i];\n    }\n    rank2[SA[0]] = 0;\n    for (int i = 0; i < N - 1; i++){\n\
    \      rank2[SA[i + 1]] = rank2[SA[i]];\n      if (rank[SA[i]] != rank[SA[i +\
    \ 1]] || rank[(SA[i] + L) % N] != rank[(SA[i + 1] + L) % N]){\n        rank2[SA[i\
    \ + 1]]++;\n      }\n    }\n    rank = rank2;\n    L *= 2;\n  }\n  SA.erase(SA.begin());\n\
    \  return SA;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/Suffix_Array.cpp
  requiredBy: []
  timestamp: '2021-12-01 17:44:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Suffix_Array.cpp
layout: document
redirect_from:
- /library/String/Suffix_Array.cpp
- /library/String/Suffix_Array.cpp.html
title: String/Suffix_Array.cpp
---
