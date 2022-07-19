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
  bundledCode: "#line 1 \"old_Data_Structures/Trie.cpp\"\nstruct trie{\n\tint N;\n\
    \tvector<tuple<vector<int>, char, bool>> T;\n\ttrie(){\n\t\tT = vector<tuple<vector<int>,\
    \ char, bool>>(1);\n\t\tT[0] = make_tuple(vector<int>(), ' ', false);\n\t}\n\t\
    void insert(string s){\n\t\tint v = 0;\n\t\tfor (char c : s){\n\t\t\tbool flg\
    \ = false;\n\t\t\tfor (int i : get<0>(T[v])){\n\t\t\t\tif (get<1>(T[i]) == c){\n\
    \t\t\t\t\tv = i;\n\t\t\t\t\tflg = true;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tif (!flg){\n\t\t\t\tget<0>(T[v]).push_back(T.size());\n\t\t\t\tv = T.size();\n\
    \t\t\t\tT.push_back(make_tuple(vector<int>(), c, false));\n\t\t\t}\n\t\t}\n\t\t\
    get<2>(T[v]) = true;\n\t}\n\tvector<bool> query(string s){\n\t\tint M = s.size();\n\
    \t\tint v = 0;\n\t\tvector<bool> ans(M, false);\n\t\tfor (int i = 0; i < M; i++){\n\
    \t\t\tbool flg = falsr;\n\t\t\tfor (int j : get<0>(T[v])){\n\t\t\t\tif (get<1>(T[j])\
    \ == s[i]){\n\t\t\t\t\tv = j;\n\t\t\t\t\tflg = true;\n\t\t\t\t\tbreak;\n\t\t\t\
    \t}\n\t\t\t}\n\t\t\tif (flg){\n\t\t\t\tans[i] = get<2>(T[v]);\n\t\t\t} else {\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t}\n};\n"
  code: "struct trie{\n\tint N;\n\tvector<tuple<vector<int>, char, bool>> T;\n\ttrie(){\n\
    \t\tT = vector<tuple<vector<int>, char, bool>>(1);\n\t\tT[0] = make_tuple(vector<int>(),\
    \ ' ', false);\n\t}\n\tvoid insert(string s){\n\t\tint v = 0;\n\t\tfor (char c\
    \ : s){\n\t\t\tbool flg = false;\n\t\t\tfor (int i : get<0>(T[v])){\n\t\t\t\t\
    if (get<1>(T[i]) == c){\n\t\t\t\t\tv = i;\n\t\t\t\t\tflg = true;\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif (!flg){\n\t\t\t\tget<0>(T[v]).push_back(T.size());\n\
    \t\t\t\tv = T.size();\n\t\t\t\tT.push_back(make_tuple(vector<int>(), c, false));\n\
    \t\t\t}\n\t\t}\n\t\tget<2>(T[v]) = true;\n\t}\n\tvector<bool> query(string s){\n\
    \t\tint M = s.size();\n\t\tint v = 0;\n\t\tvector<bool> ans(M, false);\n\t\tfor\
    \ (int i = 0; i < M; i++){\n\t\t\tbool flg = falsr;\n\t\t\tfor (int j : get<0>(T[v])){\n\
    \t\t\t\tif (get<1>(T[j]) == s[i]){\n\t\t\t\t\tv = j;\n\t\t\t\t\tflg = true;\n\t\
    \t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (flg){\n\t\t\t\tans[i] = get<2>(T[v]);\n\
    \t\t\t} else {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Data_Structures/Trie.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Data_Structures/Trie.cpp
layout: document
redirect_from:
- /library/old_Data_Structures/Trie.cpp
- /library/old_Data_Structures/Trie.cpp.html
title: old_Data_Structures/Trie.cpp
---
