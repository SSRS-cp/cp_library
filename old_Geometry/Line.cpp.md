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
  bundledCode: "#line 1 \"old_Geometry/Line.cpp\"\nstruct line{\n  point A, B;\n \
    \ line(){\n  }\n  line(point A, point B): A(A), B(B){\n  }\n};\npoint vec(line\
    \ L){\n  return L.B - L.A;\n}\nbool point_on_segment(point P, line L){\n  return\
    \ dot(P - L.A, vec(L)) > -eps && dot(P - L.B, vec(L)) < eps;\n}\npoint projection(point\
    \ P, line L){\n  return L.A + vec(L) / abs(vec(L)) * dot(P - L.A, vec(L)) / abs(vec(L));\n\
    }\npoint reflection(point P, line L){\n  return projection(P, L) * 2 - P;\n}\n\
    double point_line_distance(point P, line L){\n  return abs(cross(P - L.A, vec(L)))\
    \ / abs(vec(L));\n}\ndouble point_segment_distance(point P, line L){\n  if (dot(P\
    \ - L.A, vec(L)) < 0){\n    return dist(P, L.A);\n  } else if (dot(P - L.B, vec(L))\
    \ > 0){\n    return dist(P, L.B);\n  } else {\n    return point_line_distance(P,\
    \ L);\n  }\n}\nbool is_parallel(line L1, line L2){\n  return abs(cross(vec(L1),\
    \ vec(L2))) < eps;\n}\npoint line_intersection(line L1, line L2){\n  return L1.A\
    \ + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1), vec(L2));\n}\nbool\
    \ segment_intersect(line L1, line L2){\n  return cross(L1.A - L2.A, vec(L2)) *\
    \ cross(L1.B - L2.A, vec(L2)) < eps && cross(L2.A - L1.A, vec(L1)) * cross(L2.B\
    \ - L1.A, vec(L1)) < eps;\n}\ndouble segment_distance(line L1, line L2){\n  if\
    \ (segment_intersect(L1, L2)){\n    return 0;\n  } else {\n    double ans = INF;\n\
    \    ans = min(ans, point_segment_distance(L1.A, L2));\n    ans = min(ans, point_segment_distance(L1.B,\
    \ L2));\n    ans = min(ans, point_segment_distance(L2.A, L1));\n    ans = min(ans,\
    \ point_segment_distance(L2.B, L1));\n    return ans;\n  }\n}\n"
  code: "struct line{\n  point A, B;\n  line(){\n  }\n  line(point A, point B): A(A),\
    \ B(B){\n  }\n};\npoint vec(line L){\n  return L.B - L.A;\n}\nbool point_on_segment(point\
    \ P, line L){\n  return dot(P - L.A, vec(L)) > -eps && dot(P - L.B, vec(L)) <\
    \ eps;\n}\npoint projection(point P, line L){\n  return L.A + vec(L) / abs(vec(L))\
    \ * dot(P - L.A, vec(L)) / abs(vec(L));\n}\npoint reflection(point P, line L){\n\
    \  return projection(P, L) * 2 - P;\n}\ndouble point_line_distance(point P, line\
    \ L){\n  return abs(cross(P - L.A, vec(L))) / abs(vec(L));\n}\ndouble point_segment_distance(point\
    \ P, line L){\n  if (dot(P - L.A, vec(L)) < 0){\n    return dist(P, L.A);\n  }\
    \ else if (dot(P - L.B, vec(L)) > 0){\n    return dist(P, L.B);\n  } else {\n\
    \    return point_line_distance(P, L);\n  }\n}\nbool is_parallel(line L1, line\
    \ L2){\n  return abs(cross(vec(L1), vec(L2))) < eps;\n}\npoint line_intersection(line\
    \ L1, line L2){\n  return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1),\
    \ vec(L2));\n}\nbool segment_intersect(line L1, line L2){\n  return cross(L1.A\
    \ - L2.A, vec(L2)) * cross(L1.B - L2.A, vec(L2)) < eps && cross(L2.A - L1.A, vec(L1))\
    \ * cross(L2.B - L1.A, vec(L1)) < eps;\n}\ndouble segment_distance(line L1, line\
    \ L2){\n  if (segment_intersect(L1, L2)){\n    return 0;\n  } else {\n    double\
    \ ans = INF;\n    ans = min(ans, point_segment_distance(L1.A, L2));\n    ans =\
    \ min(ans, point_segment_distance(L1.B, L2));\n    ans = min(ans, point_segment_distance(L2.A,\
    \ L1));\n    ans = min(ans, point_segment_distance(L2.B, L1));\n    return ans;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old_Geometry/Line.cpp
  requiredBy: []
  timestamp: '2022-07-19 22:14:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old_Geometry/Line.cpp
layout: document
redirect_from:
- /library/old_Geometry/Line.cpp
- /library/old_Geometry/Line.cpp.html
title: old_Geometry/Line.cpp
---
