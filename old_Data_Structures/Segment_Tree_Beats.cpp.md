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
  bundledCode: "#line 1 \"old_Data_Structures/Segment_Tree_Beats.cpp\"\ntemplate <typename\
    \ T>\nstruct segment_tree_beats{\n\tint N;\n\tvector<T> max1, max2, min1, min2;\n\
    \tvector<T> add, sum;\n\tvector<int> maxc, minc, len;\n\tvoid update_max(int i,\
    \ T x){\n\t\tsum[i] += (x - max1[i]) * maxc[i];\n\t\tif (max1[i] == min1[i]){\n\
    \t\t\tmin1[i] = x;\n\t\t} else if (max1[i] == min2[i]){\n\t\t\tmin2[i] = x;\n\t\
    \t}\n\t\tmax1[i] = x;\n\t}\n\tvoid update_min(int i, T x){\n\t\tsum[i] += (x -\
    \ min1[i]) * minc[i];\n\t\tif (min1[i] == max1[i]){\n\t\t\tmax1[i] = x;\n\t\t\
    } else if (min1[i] == max2[i]){\n\t\t\tmax2[i] = x;\n\t\t}\n\t\tmin1[i] = x;\n\
    \t}\n\tvoid update_add(int i, T x){\n\t\tmax1[i] += x;\n\t\tif (max2[i] != -INF){\n\
    \t\t\tmax2[i] += x;\n\t\t}\n\t\tmin1[i] += x;\n\t\tif (min2[i] != INF){\n\t\t\t\
    min2[i] += x;\n\t\t}\n\t\tsum[i] += x * len[i];\n\t\tadd[i] += x;\n\t}\n\tvoid\
    \ push(int i){\n\t\tif (i >= N - 1){\n\t\t\treturn;\n\t\t}\n\t\tint l = i * 2\
    \ + 1;\n\t\tint r = i * 2 + 2;\n\t\tif (add[i] != 0){\n\t\t\tupdate_add(l, add[i]);\n\
    \t\t\tupdate_add(r, add[i]);\n\t\t\tadd[i] = 0;\n\t\t}\n\t\tif (max1[i] < max1[l]){\n\
    \t\t\tupdate_max(l, max1[i]);\n\t\t}\n\t\tif (min1[i] > min1[l]){\n\t\t\tupdate_min(l,\
    \ min1[i]);\n\t\t}\n\t\tif (max1[i] < max1[r]){\n\t\t\tupdate_max(r, max1[i]);\n\
    \t\t}\n\t\tif (min1[i] > min1[r]){\n\t\t\tupdate_min(r, min1[i]);\n\t\t}\n\t}\n\
    \tvoid update(int i){\n\t\tint l = i * 2 + 1;\n\t\tint r = i * 2 + 2;\n\t\tsum[i]\
    \ = sum[l] + sum[r];\n\t\tif (max1[l] > max1[r]){\n\t\t\tmax1[i] = max1[l];\n\t\
    \t\tmax2[i] = max(max2[l], max1[r]);\n\t\t\tmaxc[i] = maxc[l];\n\t\t} else if\
    \ (max1[l] < max1[r]){\n\t\t\tmax1[i] = max1[r];\n\t\t\tmax2[i] = max(max1[l],\
    \ max2[r]);\n\t\t\tmaxc[i] = maxc[r];\n\t\t} else {\n\t\t\tmax1[i] = max1[l];\n\
    \t\t\tmax2[i] = max(max2[l], max2[r]);\n\t\t\tmaxc[i] = maxc[l] + maxc[r];\n\t\
    \t}\n\t\tif (min1[l] < min1[r]){\n\t\t\tmin1[i] = min1[l];\n\t\t\tmin2[i] = min(min2[l],\
    \ min1[r]);\n\t\t\tminc[i] = minc[l];\n\t\t} else if (min1[l] > min1[r]){\n\t\t\
    \tmin1[i] = min1[r];\n\t\t\tmin2[i] = min(min1[l], min2[r]);\n\t\t\tminc[i] =\
    \ minc[r];\n\t\t} else {\n\t\t\tmin1[i] = min1[l];\n\t\t\tmin2[i] = min(min2[l],\
    \ min2[r]);\n\t\t\tminc[i] = minc[l] + minc[r];\n\t\t}\n\t}\n\tsegment_tree_beats(vector<T>\
    \ A){\n\t\tint n = A.size();\n\t\tN = 1;\n\t\twhile (N < n){\n\t\t\tN *= 2;\n\t\
    \t}\n\t\tmax1 = vector<T>(N * 2 - 1, -INF);\n\t\tmax2 = vector<T>(N * 2 - 1, -INF);\n\
    \t\tmin1 = vector<T>(N * 2 - 1, INF);\n\t\tmin2 = vector<T>(N * 2 - 1, INF);\n\
    \t\tadd = vector<T>(N * 2 - 1, 0);\n\t\tsum = vector<T>(N * 2 - 1, 0);\n\t\tmaxc\
    \ = vector<int>(N * 2 - 1, 0);\n\t\tminc = vector<int>(N * 2 - 1, 0);\n\t\tlen\
    \ = vector<int>(N * 2 - 1, 1);\n\t\tfor (int i = 0; i < n; i++){\n\t\t\tmax1[N\
    \ - 1 + i] = A[i];\n\t\t\tmin1[N - 1 + i] = A[i];\n\t\t\tsum[N - 1 + i] = A[i];\n\
    \t\t\tmaxc[N - 1 + i] = 1;\n\t\t\tminc[N - 1 + i] = 1;\n\t\t}\n\t\tfor (int i\
    \ = N - 2; i >= 0; i--){\n\t\t\tlen[i] = len[i * 2 + 1] + len[i * 2 + 2];\n\t\t\
    \tupdate(i);\n\t\t}\n\t}\n\tvoid range_chmin(int L, int R, T x, int i, int l,\
    \ int r){\n\t\tif (r <= L || R <= l || x >= max1[i]){\n\t\t\treturn;\n\t\t} else\
    \ if (L <= l && r <= R && x > max2[i]){\n\t\t\tupdate_max(i, x);\n\t\t\treturn;\n\
    \t\t}\n\t\tpush(i);\n\t\tint m = (l + r) / 2;\n\t\trange_chmin(L, R, x, i * 2\
    \ + 1, l, m);\n\t\trange_chmin(L, R, x, i * 2 + 2, m, r);\n\t\tupdate(i);\n\t\
    }\n\tvoid range_chmin(int L, int R, T x){\n\t\trange_chmin(L, R, x, 0, 0, N);\n\
    \t}\n\tvoid range_chmax(int L, int R, T x, int i, int l, int r){\n\t\tif (r <=\
    \ L || R <= l || x <= min1[i]){\n\t\t\treturn;\n\t\t} else if (L <= l && r <=\
    \ R && x < min2[i]){\n\t\t\tupdate_min(i, x);\n\t\t\treturn;\n\t\t}\n\t\tpush(i);\n\
    \t\tint m = (l + r) / 2;\n\t\trange_chmax(L, R, x, i * 2 + 1, l, m);\n\t\trange_chmax(L,\
    \ R, x, i * 2 + 2, m, r);\n\t\tupdate(i);\n\t}\n\tvoid range_chmax(int L, int\
    \ R, T x){\n\t\trange_chmax(L, R, x, 0, 0, N);\n\t}\n\tvoid range_add(int L, int\
    \ R, T x, int i, int l, int r){\n\t\tif (r <= L || R <= l){\t\n\t\t\treturn;\n\
    \t\t} else if (L <= l && r <= R){\n\t\t\tupdate_add(i, x);\n\t\t\treturn;\n\t\t\
    }\n\t\tpush(i);\n\t\tint m = (l + r) / 2;\n\t\trange_add(L, R, x, i * 2 + 1, l,\
    \ m);\n\t\trange_add(L, R, x, i * 2 + 2, m, r);\n\t\tupdate(i);\n\t}\n\tvoid range_add(int\
    \ L, int R, T x){\n\t\trange_add(L, R, x, 0, 0, N);\n\t}\n\tT range_sum(int L,\
    \ int R, int i, int l, int r){\n\t\tif (r <= L || R <= l){\n\t\t\treturn 0;\n\t\
    \t} else if (L <= l && r <= R){\n\t\t\treturn sum[i];\n\t\t}\n\t\tpush(i);\n\t\
    \tint m = (l + r) / 2;\n\t\treturn range_sum(L, R, i * 2 + 1, l, m) + range_sum(L,\
    \ R, i * 2 + 2, m, r);\n\t}\n\tT range_sum(int L, int R){\n\t\treturn range_sum(L,\
    \ R, 0, 0, N);\n\t}\n};\n"
  code: "template <typename T>\nstruct segment_tree_beats{\n\tint N;\n\tvector<T>\
    \ max1, max2, min1, min2;\n\tvector<T> add, sum;\n\tvector<int> maxc, minc, len;\n\
    \tvoid update_max(int i, T x){\n\t\tsum[i] += (x - max1[i]) * maxc[i];\n\t\tif\
    \ (max1[i] == min1[i]){\n\t\t\tmin1[i] = x;\n\t\t} else if (max1[i] == min2[i]){\n\
    \t\t\tmin2[i] = x;\n\t\t}\n\t\tmax1[i] = x;\n\t}\n\tvoid update_min(int i, T x){\n\
    \t\tsum[i] += (x - min1[i]) * minc[i];\n\t\tif (min1[i] == max1[i]){\n\t\t\tmax1[i]\
    \ = x;\n\t\t} else if (min1[i] == max2[i]){\n\t\t\tmax2[i] = x;\n\t\t}\n\t\tmin1[i]\
    \ = x;\n\t}\n\tvoid update_add(int i, T x){\n\t\tmax1[i] += x;\n\t\tif (max2[i]\
    \ != -INF){\n\t\t\tmax2[i] += x;\n\t\t}\n\t\tmin1[i] += x;\n\t\tif (min2[i] !=\
    \ INF){\n\t\t\tmin2[i] += x;\n\t\t}\n\t\tsum[i] += x * len[i];\n\t\tadd[i] +=\
    \ x;\n\t}\n\tvoid push(int i){\n\t\tif (i >= N - 1){\n\t\t\treturn;\n\t\t}\n\t\
    \tint l = i * 2 + 1;\n\t\tint r = i * 2 + 2;\n\t\tif (add[i] != 0){\n\t\t\tupdate_add(l,\
    \ add[i]);\n\t\t\tupdate_add(r, add[i]);\n\t\t\tadd[i] = 0;\n\t\t}\n\t\tif (max1[i]\
    \ < max1[l]){\n\t\t\tupdate_max(l, max1[i]);\n\t\t}\n\t\tif (min1[i] > min1[l]){\n\
    \t\t\tupdate_min(l, min1[i]);\n\t\t}\n\t\tif (max1[i] < max1[r]){\n\t\t\tupdate_max(r,\
    \ max1[i]);\n\t\t}\n\t\tif (min1[i] > min1[r]){\n\t\t\tupdate_min(r, min1[i]);\n\
    \t\t}\n\t}\n\tvoid update(int i){\n\t\tint l = i * 2 + 1;\n\t\tint r = i * 2 +\
    \ 2;\n\t\tsum[i] = sum[l] + sum[r];\n\t\tif (max1[l] > max1[r]){\n\t\t\tmax1[i]\
    \ = max1[l];\n\t\t\tmax2[i] = max(max2[l], max1[r]);\n\t\t\tmaxc[i] = maxc[l];\n\
    \t\t} else if (max1[l] < max1[r]){\n\t\t\tmax1[i] = max1[r];\n\t\t\tmax2[i] =\
    \ max(max1[l], max2[r]);\n\t\t\tmaxc[i] = maxc[r];\n\t\t} else {\n\t\t\tmax1[i]\
    \ = max1[l];\n\t\t\tmax2[i] = max(max2[l], max2[r]);\n\t\t\tmaxc[i] = maxc[l]\
    \ + maxc[r];\n\t\t}\n\t\tif (min1[l] < min1[r]){\n\t\t\tmin1[i] = min1[l];\n\t\
    \t\tmin2[i] = min(min2[l], min1[r]);\n\t\t\tminc[i] = minc[l];\n\t\t} else if\
    \ (min1[l] > min1[r]){\n\t\t\tmin1[i] = min1[r];\n\t\t\tmin2[i] = min(min1[l],\
    \ min2[r]);\n\t\t\tminc[i] = minc[r];\n\t\t} else {\n\t\t\tmin1[i] = min1[l];\n\
    \t\t\tmin2[i] = min(min2[l], min2[r]);\n\t\t\tminc[i] = minc[l] + minc[r];\n\t\
    \t}\n\t}\n\tsegment_tree_beats(vector<T> A){\n\t\tint n = A.size();\n\t\tN = 1;\n\
    \t\twhile (N < n){\n\t\t\tN *= 2;\n\t\t}\n\t\tmax1 = vector<T>(N * 2 - 1, -INF);\n\
    \t\tmax2 = vector<T>(N * 2 - 1, -INF);\n\t\tmin1 = vector<T>(N * 2 - 1, INF);\n\
    \t\tmin2 = vector<T>(N * 2 - 1, INF);\n\t\tadd = vector<T>(N * 2 - 1, 0);\n\t\t\
    sum = vector<T>(N * 2 - 1, 0);\n\t\tmaxc = vector<int>(N * 2 - 1, 0);\n\t\tminc\
    \ = vector<int>(N * 2 - 1, 0);\n\t\tlen = vector<int>(N * 2 - 1, 1);\n\t\tfor\
    \ (int i = 0; i < n; i++){\n\t\t\tmax1[N - 1 + i] = A[i];\n\t\t\tmin1[N - 1 +\
    \ i] = A[i];\n\t\t\tsum[N - 1 + i] = A[i];\n\t\t\tmaxc[N - 1 + i] = 1;\n\t\t\t\
    minc[N - 1 + i] = 1;\n\t\t}\n\t\tfor (int i = N - 2; i >= 0; i--){\n\t\t\tlen[i]\
    \ = len[i * 2 + 1] + len[i * 2 + 2];\n\t\t\tupdate(i);\n\t\t}\n\t}\n\tvoid range_chmin(int\
    \ L, int R, T x, int i, int l, int r){\n\t\tif (r <= L || R <= l || x >= max1[i]){\n\
    \t\t\treturn;\n\t\t} else if (L <= l && r <= R && x > max2[i]){\n\t\t\tupdate_max(i,\
    \ x);\n\t\t\treturn;\n\t\t}\n\t\tpush(i);\n\t\tint m = (l + r) / 2;\n\t\trange_chmin(L,\
    \ R, x, i * 2 + 1, l, m);\n\t\trange_chmin(L, R, x, i * 2 + 2, m, r);\n\t\tupdate(i);\n\
    \t}\n\tvoid range_chmin(int L, int R, T x){\n\t\trange_chmin(L, R, x, 0, 0, N);\n\
    \t}\n\tvoid range_chmax(int L, int R, T x, int i, int l, int r){\n\t\tif (r <=\
    \ L || R <= l || x <= min1[i]){\n\t\t\treturn;\n\t\t} else if (L <= l && r <=\
    \ R && x < min2[i]){\n\t\t\tupdate_min(i, x);\n\t\t\treturn;\n\t\t}\n\t\tpush(i);\n\
    \t\tint m = (l + r) / 2;\n\t\trange_chmax(L, R, x, i * 2 + 1, l, m);\n\t\trange_chmax(L,\
    \ R, x, i * 2 + 2, m, r);\n\t\tupdate(i);\n\t}\n\tvoid range_chmax(int L, int\
    \ R, T x){\n\t\trange_chmax(L, R, x, 0, 0, N);\n\t}\n\tvoid range_add(int L, int\
    \ R, T x, int i, int l, int r){\n\t\tif (r <= L || R <= l){\t\n\t\t\treturn;\n\
    \t\t} else if (L <= l && r <= R){\n\t\t\tupdate_add(i, x);\n\t\t\treturn;\n\t\t\
    }\n\t\tpush(i);\n\t\tint m = (l + r) / 2;\n\t\trange_add(L, R, x, i * 2 + 1, l,\
    \ m);\n\t\trange_add(L, R, x, i * 2 + 2, m, r);\n\t\tupdate(i);\n\t}\n\tvoid range_add(int\
    \ L, int R, T x){\n\t\trange_add(L, R, x, 0, 0, N);\n\t}\n\tT range_sum(int L,\
    \ int R, int i, int l, int r){\n\t\tif (r <= L || R <= l){\n\t\t\treturn 0;\n\t\
    \t} else if (L <= l && r <= R){\n\t\t\treturn sum[i];\n\t\t}\n\t\tpush(i);\n\t\
    \tint m = (l + r) / 2;\n\t\treturn range_sum(L, R, i * 2 + 1, l, m) + range_sum(L,\
    \ R, i * 2 + 2, m, r);\n\t}\n\tT range_sum(int L, int R){\n\t\treturn range_sum(L,\
    \ R, 0, 0, N);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Data_Structures/Segment_Tree_Beats.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Data_Structures/Segment_Tree_Beats.cpp
layout: document
redirect_from:
- /library/old_Data_Structures/Segment_Tree_Beats.cpp
- /library/old_Data_Structures/Segment_Tree_Beats.cpp.html
title: old_Data_Structures/Segment_Tree_Beats.cpp
---
