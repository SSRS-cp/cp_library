---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30B3\u30F3\u30D1\u30AF\u30C8 Bit Vector"
    links: []
  bundledCode: "#line 2 \"data_structure/sequence/compact_bit_vector.hpp\"\n/**\n\
    \ * @brief \u30B3\u30F3\u30D1\u30AF\u30C8 Bit Vector\n*/\nstruct bit_vector{\n\
    \  vector<unsigned long long> A;\n  vector<int> S;\n  bit_vector(){\n  }\n  bit_vector(vector<bool>\
    \ &a){\n    int N = a.size();\n    int M = (N + 64 - 1) >> 6;\n    A = vector<unsigned\
    \ long long>(M, 0);\n    for (int i = 0; i < M; i++){\n      for (int j = i <<\
    \ 6; j < min((i + 1) << 6, N); j++){\n        if (a[j]){\n          A[i] |= (unsigned\
    \ long long) 1 << (j - (i << 6));\n        }\n      }\n    }\n    S = vector<int>(M\
    \ + 1, 0);\n    for (int i = 0; i < M; i++){\n      S[i + 1] = S[i] + __builtin_popcountll(A[i]);\n\
    \    }\n  }\n  int operator [](int k){\n    return A[k >> 6] >> (k & 63) & 1;\n\
    \  }\n  int rank0(int k){\n    return k - rank1(k);\n  }\n  int rank1(int k){\n\
    \    if ((k & 63) == 0){\n      return S[k >> 6];\n    } else {\n      return\
    \ S[k >> 6] + __builtin_popcountll(A[k >> 6] << (64 - k + (k >> 6 << 6)));\n \
    \   }\n  }\n};\n"
  code: "#pragma once\n/**\n * @brief \u30B3\u30F3\u30D1\u30AF\u30C8 Bit Vector\n\
    */\nstruct bit_vector{\n  vector<unsigned long long> A;\n  vector<int> S;\n  bit_vector(){\n\
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
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sequence/compact_bit_vector.hpp
  requiredBy: []
  timestamp: '2022-07-17 06:33:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sequence/compact_bit_vector.hpp
layout: document
redirect_from:
- /library/data_structure/sequence/compact_bit_vector.hpp
- /library/data_structure/sequence/compact_bit_vector.hpp.html
title: "\u30B3\u30F3\u30D1\u30AF\u30C8 Bit Vector"
---
