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
  bundledCode: "#line 1 \"data_structure/sequence/compact_bit_vector.cpp\"\nstruct\
    \ bit_vector{\n  vector<unsigned long long> A;\n  vector<int> S;\n  bit_vector(){\n\
    \  }\n  bit_vector(vector<bool> &a){\n    int N = a.size();\n    int M = (N +\
    \ 64 - 1) >> 6;\n    A = vector<unsigned long long>(M, 0);\n    for (int i = 0;\
    \ i < M; i++){\n      for (int j = i << 6; j < min((i + 1) << 6, N); j++){\n \
    \       if (a[j]){\n          A[i] |= (unsigned long long) 1 << (j - (i << 6));\n\
    \        }\n      }\n    }\n    S = vector<int>(M + 1, 0);\n    for (int i = 0;\
    \ i < M; i++){\n      S[i + 1] = S[i] + __builtin_popcountll(A[i]);\n    }\n \
    \ }\n  int operator [](int k){\n    return A[k >> 6] >> (k & 63) & 1;\n  }\n \
    \ int rank0(int k){\n    return k - rank1(k);\n  }\n  int rank1(int k){\n    if\
    \ ((k & 63) == 0){\n      return S[k >> 6];\n    } else {\n      return S[k >>\
    \ 6] + __builtin_popcountll(A[k >> 6] << (64 - k + (k >> 6 << 6)));\n    }\n \
    \ }\n};\n"
  code: "struct bit_vector{\n  vector<unsigned long long> A;\n  vector<int> S;\n \
    \ bit_vector(){\n  }\n  bit_vector(vector<bool> &a){\n    int N = a.size();\n\
    \    int M = (N + 64 - 1) >> 6;\n    A = vector<unsigned long long>(M, 0);\n \
    \   for (int i = 0; i < M; i++){\n      for (int j = i << 6; j < min((i + 1) <<\
    \ 6, N); j++){\n        if (a[j]){\n          A[i] |= (unsigned long long) 1 <<\
    \ (j - (i << 6));\n        }\n      }\n    }\n    S = vector<int>(M + 1, 0);\n\
    \    for (int i = 0; i < M; i++){\n      S[i + 1] = S[i] + __builtin_popcountll(A[i]);\n\
    \    }\n  }\n  int operator [](int k){\n    return A[k >> 6] >> (k & 63) & 1;\n\
    \  }\n  int rank0(int k){\n    return k - rank1(k);\n  }\n  int rank1(int k){\n\
    \    if ((k & 63) == 0){\n      return S[k >> 6];\n    } else {\n      return\
    \ S[k >> 6] + __builtin_popcountll(A[k >> 6] << (64 - k + (k >> 6 << 6)));\n \
    \   }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/compact_bit_vector.cpp
  requiredBy: []
  timestamp: '2022-07-16 18:37:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sequence/compact_bit_vector.cpp
layout: document
redirect_from:
- /library/data_structure/sequence/compact_bit_vector.cpp
- /library/data_structure/sequence/compact_bit_vector.cpp.html
title: data_structure/sequence/compact_bit_vector.cpp
---
