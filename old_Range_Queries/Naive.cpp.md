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
  bundledCode: "#line 1 \"old_Range_Queries/Naive.cpp\"\ntemplate <typename T>\nstruct\
    \ naive{\n\tint N;\n\tvector<T> A;\n\tnaive(int N): N(N){\n\t\tA = vector<T>(N);\n\
    \t}\n\tnaive(int N, T x): N(N){\n\t\tA = vector<T>(N, x);\n\t}\n\tnaive(vector<T>\
    \ A): A(A){\n\t\tN = A.size();\n\t}\n\tvoid update(int i, T x){\n\t\tA[i] = x;\n\
    \t}\n\tvoid add(int i, T x){\n\t\tA[i] += x;\n\t}\n\tvoid chmin(int i, T x){\n\
    \t\tA[i] = min(A[i], x);\n\t}\n\tvoid chmax(int i, T x){\n\t\tA[i] = max(A[i],\
    \ x);\n\t}\n\tvoid range_update(int L, int R, T x){\n\t\tfor (int i = L; i < R;\
    \ i++){\n\t\t\tA[i] = x;\n\t\t}\n\t}\n\tvoid range_add(int L, int R, T x){\n\t\
    \tfor (int i = L; i < R; i++){\n\t\t\tA[i] += x;\n\t\t}\n\t}\n\tvoid range_chmin(int\
    \ L, int R, T x){\n\t\tfor (int i = L; i < R; i++){\n\t\t\tA[i] = min(A[i], x);\n\
    \t\t}\n\t}\n\tvoid range_chmax(int L, int R, T x){\n\t\tfor (int i = L; i < R;\
    \ i++){\n\t\t\tA[i] = max(A[i], x);\n\t\t}\n\t}\n\tT operator [](int i){\n\t\t\
    return A[i];\n\t}\n\tT range_sum(int L, int R){\n\t\tT ans = 0;\n\t\tfor (int\
    \ i = L; i < R; i++){\n\t\t\tans += A[i];\n\t\t}\n\t\treturn ans;\n\t}\n\tT range_min(int\
    \ L, int R){\n\t\tT ans = INF;\n\t\tfor (int i = L; i < R; i++){\n\t\t\tans =\
    \ min(ans, A[i]);\n\t\t}\n\t\treturn ans;\n\t}\n\tT range_max(int L, int R){\n\
    \t\tT ans = -INF;\n\t\tfor (int i = L; i < R; i++){\n\t\t\tans = max(ans, A[i]);\n\
    \t\t}\n\t\treturn ans;\n\t}\n\tvoid debug(){\n\t\tcout << \"[\";\n\t\tfor (int\
    \ i = 0; i < N; i++){\n\t\t\tcout << A[i];\n\t\t\tif (i < N - 1){\n\t\t\t\tcout\
    \ << \",\";\n\t\t\t}\n\t\t}\n\t\tcout << \"]\" << endl;\n\t}\n};\n"
  code: "template <typename T>\nstruct naive{\n\tint N;\n\tvector<T> A;\n\tnaive(int\
    \ N): N(N){\n\t\tA = vector<T>(N);\n\t}\n\tnaive(int N, T x): N(N){\n\t\tA = vector<T>(N,\
    \ x);\n\t}\n\tnaive(vector<T> A): A(A){\n\t\tN = A.size();\n\t}\n\tvoid update(int\
    \ i, T x){\n\t\tA[i] = x;\n\t}\n\tvoid add(int i, T x){\n\t\tA[i] += x;\n\t}\n\
    \tvoid chmin(int i, T x){\n\t\tA[i] = min(A[i], x);\n\t}\n\tvoid chmax(int i,\
    \ T x){\n\t\tA[i] = max(A[i], x);\n\t}\n\tvoid range_update(int L, int R, T x){\n\
    \t\tfor (int i = L; i < R; i++){\n\t\t\tA[i] = x;\n\t\t}\n\t}\n\tvoid range_add(int\
    \ L, int R, T x){\n\t\tfor (int i = L; i < R; i++){\n\t\t\tA[i] += x;\n\t\t}\n\
    \t}\n\tvoid range_chmin(int L, int R, T x){\n\t\tfor (int i = L; i < R; i++){\n\
    \t\t\tA[i] = min(A[i], x);\n\t\t}\n\t}\n\tvoid range_chmax(int L, int R, T x){\n\
    \t\tfor (int i = L; i < R; i++){\n\t\t\tA[i] = max(A[i], x);\n\t\t}\n\t}\n\tT\
    \ operator [](int i){\n\t\treturn A[i];\n\t}\n\tT range_sum(int L, int R){\n\t\
    \tT ans = 0;\n\t\tfor (int i = L; i < R; i++){\n\t\t\tans += A[i];\n\t\t}\n\t\t\
    return ans;\n\t}\n\tT range_min(int L, int R){\n\t\tT ans = INF;\n\t\tfor (int\
    \ i = L; i < R; i++){\n\t\t\tans = min(ans, A[i]);\n\t\t}\n\t\treturn ans;\n\t\
    }\n\tT range_max(int L, int R){\n\t\tT ans = -INF;\n\t\tfor (int i = L; i < R;\
    \ i++){\n\t\t\tans = max(ans, A[i]);\n\t\t}\n\t\treturn ans;\n\t}\n\tvoid debug(){\n\
    \t\tcout << \"[\";\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tcout << A[i];\n\t\t\
    \tif (i < N - 1){\n\t\t\t\tcout << \",\";\n\t\t\t}\n\t\t}\n\t\tcout << \"]\" <<\
    \ endl;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Range_Queries/Naive.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Range_Queries/Naive.cpp
layout: document
redirect_from:
- /library/old_Range_Queries/Naive.cpp
- /library/old_Range_Queries/Naive.cpp.html
title: old_Range_Queries/Naive.cpp
---
