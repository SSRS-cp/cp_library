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
  bundledCode: "#line 1 \"Geometry/Point.cpp\"\nstruct point{\n  double x, y;\n  point(){\n\
    \  }\n  point(double x, double y): x(x), y(y){\n  }\n  point operator +(point\
    \ P){\n    return point(x + P.x, y + P.y);\n  }\n  point operator -(point P){\n\
    \    return point(x - P.x, y - P.y);\n  }\n  point operator *(double k){\n   \
    \ return point(x * k, y * k);\n  }\n  point operator /(double k){\n    return\
    \ point(x / k, y / k);\n  }\n};\npoint rotate90(point P){\n  return point(-P.y,\
    \ P.x);\n}\npoint rotate(point P, double t){\n  return point(P.x * cos(t) - P.y\
    \ * sin(t), P.x * sin(t) + P.y * cos(t));\n}\ndouble abs(point P){\n  return sqrt(P.x\
    \ * P.x + P.y * P.y);\n}\ndouble dist(point P, point Q){\n  return abs(Q - P);\n\
    }\ndouble dot(point P, point Q){\n  return P.x * Q.x + P.y * Q.y;\n}\ndouble cross(point\
    \ P, point Q){\n  return P.x * Q.y - P.y * Q.x;\n}\n"
  code: "struct point{\n  double x, y;\n  point(){\n  }\n  point(double x, double\
    \ y): x(x), y(y){\n  }\n  point operator +(point P){\n    return point(x + P.x,\
    \ y + P.y);\n  }\n  point operator -(point P){\n    return point(x - P.x, y -\
    \ P.y);\n  }\n  point operator *(double k){\n    return point(x * k, y * k);\n\
    \  }\n  point operator /(double k){\n    return point(x / k, y / k);\n  }\n};\n\
    point rotate90(point P){\n  return point(-P.y, P.x);\n}\npoint rotate(point P,\
    \ double t){\n  return point(P.x * cos(t) - P.y * sin(t), P.x * sin(t) + P.y *\
    \ cos(t));\n}\ndouble abs(point P){\n  return sqrt(P.x * P.x + P.y * P.y);\n}\n\
    double dist(point P, point Q){\n  return abs(Q - P);\n}\ndouble dot(point P, point\
    \ Q){\n  return P.x * Q.x + P.y * Q.y;\n}\ndouble cross(point P, point Q){\n \
    \ return P.x * Q.y - P.y * Q.x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Point.cpp
  requiredBy: []
  timestamp: '2021-10-17 05:40:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Point.cpp
layout: document
redirect_from:
- /library/Geometry/Point.cpp
- /library/Geometry/Point.cpp.html
title: Geometry/Point.cpp
---
