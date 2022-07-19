---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: Z Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/library_checker/string/z_algorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"string/z_algorithm.hpp\"\n/**\n * @brief Z Algorithm\n\
    */\nvector<int> z_algorithm(string S){\n  int N = S.size();\n  vector<int> ans(N);\n\
    \  for (int i = 1, j = 0; i < N; i++){\n    if (i + ans[i - j] < j + ans[j]){\n\
    \      ans[i] = ans[i - j];\n    } else {\n      int k = max(0, j + ans[j] - i);\n\
    \      while (i + k < N && S[k] == S[i + k]){\n        k++;\n      }\n      ans[i]\
    \ = k;\n      j = i;\n    }\n  }\n  ans[0] = N;\n  return ans;\n}\n#line 5 \"\
    test/library_checker/string/z_algorithm.test.cpp\"\nint main(){\n  string S;\n\
    \  cin >> S;\n  int N = S.size();\n  vector<int> ans = z_algorithm(S);\n  for\
    \ (int i = 0; i < N; i++){\n    cout << ans[i];\n    if (i < N - 1){\n      cout\
    \ << ' ';\n    }\n  }\n  cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../../string/z_algorithm.hpp\"\
    \nint main(){\n  string S;\n  cin >> S;\n  int N = S.size();\n  vector<int> ans\
    \ = z_algorithm(S);\n  for (int i = 0; i < N; i++){\n    cout << ans[i];\n   \
    \ if (i < N - 1){\n      cout << ' ';\n    }\n  }\n  cout << endl;\n}"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: test/library_checker/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 02:21:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/z_algorithm.test.cpp
- /verify/test/library_checker/string/z_algorithm.test.cpp.html
title: test/library_checker/string/z_algorithm.test.cpp
---
