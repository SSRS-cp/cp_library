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
  bundledCode: "#line 1 \"Geometry/Circle.cpp\"\nstruct circle{\n  point C;\n  double\
    \ r;\n  circle(){\n  }\n  circle(point C, double r): C(C), r(r){\n  }\n};\npair<point,\
    \ point> line_circle_intersection(line L, circle C){\n  point P = projection(C.C,\
    \ L);\n  double d = point_line_distance(C.C, L);\n  double h = sqrt(C.r * C.r\
    \ - d * d);\n  point A = P + vec(L) / abs(vec(L)) * h;\n  point B = P - vec(L)\
    \ / abs(vec(L)) * h;\n  return make_pair(A, B);\n}\npair<point, point> circle_intersection(circle\
    \ C1, circle C2){\n  double d = dist(C1.C, C2.C);\n  double m = (C1.r * C1.r -\
    \ C2.r * C2.r + d * d) / (d * 2);\n  point M = C1.C + (C2.C - C1.C) / d * m;\n\
    \  double h = sqrt(C1.r * C1.r - m * m);\n  point H = rotate90(C2.C - C1.C) /\
    \ d * h;\n  return make_pair(M - H, M + H);\n}\npair<point, point> circle_tangent(point\
    \ P, circle C){\n  double d = dist(P, C.C);\n  double r = sqrt(d * d - C.r * C.r);\n\
    \  return circle_intersection(C, circle(P, r));\n}\nvector<line> common_tangent(circle\
    \ C1, circle C2){\n  if (C1.r < C2.r){\n    swap(C1, C2);\n  }\n  double d = dist(C1.C,\
    \ C2.C);\n  vector<line> L;\n  if (C1.r - C2.r <= d + eps){\n    if (C1.r - C2.r\
    \ <= eps){\n      point D = rotate90(C2.C - C1.C) / d * C1.r;\n      L.push_back(line(C1.C\
    \ + D, C2.C + D));\n      L.push_back(line(C1.C - D, C2.C - D));\n    } else {\n\
    \      double m = (C1.r - C2.r) * (C1.r - C2.r) / d;\n      point M = C1.C + (C2.C\
    \ - C1.C) / d * m;\n      double h = sqrt((C1.r - C2.r) * (C1.r - C2.r) - m *\
    \ m);\n      point H1 = M + rotate90(C2.C - C1.C) / d * h;\n      point D1 = (H1\
    \ - C1.C) / dist(H1, C1.C) * C2.r;\n      L.push_back(line(H1 + D1, C2.C + D1));\n\
    \      point H2 = M - rotate90(C2.C - C1.C) / d * h;\n      point D2 = (H2 - C1.C)\
    \ / dist(H2, C1.C) * C2.r;\n      L.push_back(line(H2 + D2, C2.C + D2));\n   \
    \ }\n  }\n  if (C1.r + C2.r <= d + eps){\n    double m = (C1.r + C2.r) * (C1.r\
    \ + C2.r) / d;\n    point M = C1.C + (C2.C - C1.C) / d * m;\n    double h = sqrt((C1.r\
    \ + C2.r) * (C1.r + C2.r) - m * m);\n    point H1 = M + rotate90(C2.C - C1.C)\
    \ / d * h;\n    point D1 = (H1 - C1.C) / dist(H1, C1.C) * C2.r;\n    L.push_back(line(H1\
    \ - D1, C2.C - D1));\n    point H2 = M - rotate90(C2.C - C1.C) / d * h;\n    point\
    \ D2 = (H2 - C1.C) / dist(H2, C1.C) * C2.r;\n    L.push_back(line(H2 - D2, C2.C\
    \ - D2));\n  }\n  return L;\n}\n"
  code: "struct circle{\n  point C;\n  double r;\n  circle(){\n  }\n  circle(point\
    \ C, double r): C(C), r(r){\n  }\n};\npair<point, point> line_circle_intersection(line\
    \ L, circle C){\n  point P = projection(C.C, L);\n  double d = point_line_distance(C.C,\
    \ L);\n  double h = sqrt(C.r * C.r - d * d);\n  point A = P + vec(L) / abs(vec(L))\
    \ * h;\n  point B = P - vec(L) / abs(vec(L)) * h;\n  return make_pair(A, B);\n\
    }\npair<point, point> circle_intersection(circle C1, circle C2){\n  double d =\
    \ dist(C1.C, C2.C);\n  double m = (C1.r * C1.r - C2.r * C2.r + d * d) / (d * 2);\n\
    \  point M = C1.C + (C2.C - C1.C) / d * m;\n  double h = sqrt(C1.r * C1.r - m\
    \ * m);\n  point H = rotate90(C2.C - C1.C) / d * h;\n  return make_pair(M - H,\
    \ M + H);\n}\npair<point, point> circle_tangent(point P, circle C){\n  double\
    \ d = dist(P, C.C);\n  double r = sqrt(d * d - C.r * C.r);\n  return circle_intersection(C,\
    \ circle(P, r));\n}\nvector<line> common_tangent(circle C1, circle C2){\n  if\
    \ (C1.r < C2.r){\n    swap(C1, C2);\n  }\n  double d = dist(C1.C, C2.C);\n  vector<line>\
    \ L;\n  if (C1.r - C2.r <= d + eps){\n    if (C1.r - C2.r <= eps){\n      point\
    \ D = rotate90(C2.C - C1.C) / d * C1.r;\n      L.push_back(line(C1.C + D, C2.C\
    \ + D));\n      L.push_back(line(C1.C - D, C2.C - D));\n    } else {\n      double\
    \ m = (C1.r - C2.r) * (C1.r - C2.r) / d;\n      point M = C1.C + (C2.C - C1.C)\
    \ / d * m;\n      double h = sqrt((C1.r - C2.r) * (C1.r - C2.r) - m * m);\n  \
    \    point H1 = M + rotate90(C2.C - C1.C) / d * h;\n      point D1 = (H1 - C1.C)\
    \ / dist(H1, C1.C) * C2.r;\n      L.push_back(line(H1 + D1, C2.C + D1));\n   \
    \   point H2 = M - rotate90(C2.C - C1.C) / d * h;\n      point D2 = (H2 - C1.C)\
    \ / dist(H2, C1.C) * C2.r;\n      L.push_back(line(H2 + D2, C2.C + D2));\n   \
    \ }\n  }\n  if (C1.r + C2.r <= d + eps){\n    double m = (C1.r + C2.r) * (C1.r\
    \ + C2.r) / d;\n    point M = C1.C + (C2.C - C1.C) / d * m;\n    double h = sqrt((C1.r\
    \ + C2.r) * (C1.r + C2.r) - m * m);\n    point H1 = M + rotate90(C2.C - C1.C)\
    \ / d * h;\n    point D1 = (H1 - C1.C) / dist(H1, C1.C) * C2.r;\n    L.push_back(line(H1\
    \ - D1, C2.C - D1));\n    point H2 = M - rotate90(C2.C - C1.C) / d * h;\n    point\
    \ D2 = (H2 - C1.C) / dist(H2, C1.C) * C2.r;\n    L.push_back(line(H2 - D2, C2.C\
    \ - D2));\n  }\n  return L;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Circle.cpp
  requiredBy: []
  timestamp: '2021-10-17 05:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Circle.cpp
layout: document
redirect_from:
- /library/Geometry/Circle.cpp
- /library/Geometry/Circle.cpp.html
title: Geometry/Circle.cpp
---
