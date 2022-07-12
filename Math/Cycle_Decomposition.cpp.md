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
  bundledCode: "#line 1 \"Math/Cycle_Decomposition.cpp\"\nvector<vector<int>> cycle_decomposition(vector<int>\
    \ &P){\n\tint N = P.size();\n\tvector<bool> used(N, false);\n\tvector<vector<int>>\
    \ ans;\n\tfor (int i = N - 1; i >= 0; i--){\n\t\tif (used[i]) continue;\n\t\t\
    vector<int> C;\n\t\tC.push_back(i);\n\t\twhile (C.front() != P[C.back()]){\n\t\
    \t\tC.push_back(P[C.back()]);\n\t\t\tused[C.back()] = true;\n\t\t}\n\tans.push_back(C);\n\
    \t}\n\treturn ans;\n}\n"
  code: "vector<vector<int>> cycle_decomposition(vector<int> &P){\n\tint N = P.size();\n\
    \tvector<bool> used(N, false);\n\tvector<vector<int>> ans;\n\tfor (int i = N -\
    \ 1; i >= 0; i--){\n\t\tif (used[i]) continue;\n\t\tvector<int> C;\n\t\tC.push_back(i);\n\
    \t\twhile (C.front() != P[C.back()]){\n\t\t\tC.push_back(P[C.back()]);\n\t\t\t\
    used[C.back()] = true;\n\t\t}\n\tans.push_back(C);\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Cycle_Decomposition.cpp
  requiredBy: []
  timestamp: '2020-03-26 16:28:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Cycle_Decomposition.cpp
layout: document
redirect_from:
- /library/Math/Cycle_Decomposition.cpp
- /library/Math/Cycle_Decomposition.cpp.html
title: Math/Cycle_Decomposition.cpp
---
