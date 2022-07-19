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
  bundledCode: "#line 1 \"old_Data_Structures/Inversion_Number.cpp\"\nlong long inversion_number(vector<int>\
    \ &p){\n\tint N = p.size();\n\tlong long ans = 0;\n\tvector<int> bit(N + 1, 0);\n\
    \tfor (int i = 0; i < N; i++){\n\t\tans += i;\n\t\tint j = p[i];\n\t\twhile (j\
    \ > 0){\n\t\t\tans -= bit[j];\n\t\t\tj -= j & -j;\n\t\t}\n\t\tj = p[i];\n\t\t\
    while (j <= N){\n\t\t\tbit[j]++;\n\t\t\tj += j & -j;\n\t\t}\n\t}\n\treturn ans;\n\
    }\nlong long inversion_number(vector<int> &A){\n\tint N = A.size();\n\tvector<int>\
    \ B = A;\n\tsort(B.begin(), B.end());\n\tmap<int, int> mp;\n\tfor (int i = 0;\
    \ i < N; i++){\n\t\tmp[B[i]] = i + 1;\n\t}\n\tfor (int i = 0; i < N; i++){\n\t\
    \tA[i] = mp[A[i]];\n\t}\n\tlong long ans = 0;\n\tvector<int> BIT(N + 1, 0);\n\t\
    for (int i = 0; i < N; i++){\n\t\tans += i;\n\t\tint j = A[i];\n\t\twhile (j >\
    \ 0){\n\t\t\tans -= BIT[j];\n\t\t\tj -= j & -j;\n\t\t}\n\t\tj = A[i];\n\t\twhile\
    \ (j <= N){\n\t\t\tBIT[j]++;\n\t\t\tj += j & -j;\n\t\t}\n\t}\n\treturn ans;\n\
    }\n"
  code: "long long inversion_number(vector<int> &p){\n\tint N = p.size();\n\tlong\
    \ long ans = 0;\n\tvector<int> bit(N + 1, 0);\n\tfor (int i = 0; i < N; i++){\n\
    \t\tans += i;\n\t\tint j = p[i];\n\t\twhile (j > 0){\n\t\t\tans -= bit[j];\n\t\
    \t\tj -= j & -j;\n\t\t}\n\t\tj = p[i];\n\t\twhile (j <= N){\n\t\t\tbit[j]++;\n\
    \t\t\tj += j & -j;\n\t\t}\n\t}\n\treturn ans;\n}\nlong long inversion_number(vector<int>\
    \ &A){\n\tint N = A.size();\n\tvector<int> B = A;\n\tsort(B.begin(), B.end());\n\
    \tmap<int, int> mp;\n\tfor (int i = 0; i < N; i++){\n\t\tmp[B[i]] = i + 1;\n\t\
    }\n\tfor (int i = 0; i < N; i++){\n\t\tA[i] = mp[A[i]];\n\t}\n\tlong long ans\
    \ = 0;\n\tvector<int> BIT(N + 1, 0);\n\tfor (int i = 0; i < N; i++){\n\t\tans\
    \ += i;\n\t\tint j = A[i];\n\t\twhile (j > 0){\n\t\t\tans -= BIT[j];\n\t\t\tj\
    \ -= j & -j;\n\t\t}\n\t\tj = A[i];\n\t\twhile (j <= N){\n\t\t\tBIT[j]++;\n\t\t\
    \tj += j & -j;\n\t\t}\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Data_Structures/Inversion_Number.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Data_Structures/Inversion_Number.cpp
layout: document
redirect_from:
- /library/old_Data_Structures/Inversion_Number.cpp
- /library/old_Data_Structures/Inversion_Number.cpp.html
title: old_Data_Structures/Inversion_Number.cpp
---
