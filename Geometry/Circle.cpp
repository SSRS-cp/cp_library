struct circle{
  point C;
  double r;
  circle(){
  }
  circle(point C, double r): C(C), r(r){
  }
};
pair<point, point> line_circle_intersection(line L, circle C){
  point P = projection(C.C, L);
  double d = point_line_distance(C.C, L);
  double h = sqrt(C.r * C.r - d * d);
  point A = P + vec(L) / abs(vec(L)) * h;
  point B = P - vec(L) / abs(vec(L)) * h;
  return make_pair(A, B);
}
pair<point, point> circle_intersection(circle C1, circle C2){
  double d = dist(C1.C, C2.C);
  double m = (C1.r * C1.r - C2.r * C2.r + d * d) / (d * 2);
  point M = C1.C + (C2.C - C1.C) / d * m;
  double h = sqrt(C1.r * C1.r - m * m);
  point H = rotate90(C2.C - C1.C) / d * h;
  return make_pair(M - H, M + H);
}
pair<point, point> circle_tangent(point P, circle C){
  double d = dist(P, C.C);
  double r = sqrt(d * d - C.r * C.r);
  return circle_intersection(C, circle(P, r));
}
vector<line> common_tangent(circle C1, circle C2){
  if (C1.r < C2.r){
    swap(C1, C2);
  }
  double d = dist(C1.C, C2.C);
  vector<line> L;
  if (C1.r - C2.r <= d + eps){
    if (C1.r - C2.r <= eps){
      point D = rotate90(C2.C - C1.C) / d * C1.r;
      L.push_back(line(C1.C + D, C2.C + D));
      L.push_back(line(C1.C - D, C2.C - D));
    } else {
      double m = (C1.r - C2.r) * (C1.r - C2.r) / d;
      point M = C1.C + (C2.C - C1.C) / d * m;
      double h = sqrt((C1.r - C2.r) * (C1.r - C2.r) - m * m);
      point H1 = M + rotate90(C2.C - C1.C) / d * h;
      point D1 = (H1 - C1.C) / dist(H1, C1.C) * C2.r;
      L.push_back(line(H1 + D1, C2.C + D1));
      point H2 = M - rotate90(C2.C - C1.C) / d * h;
      point D2 = (H2 - C1.C) / dist(H2, C1.C) * C2.r;
      L.push_back(line(H2 + D2, C2.C + D2));
    }
  }
  if (C1.r + C2.r <= d + eps){
    double m = (C1.r + C2.r) * (C1.r + C2.r) / d;
    point M = C1.C + (C2.C - C1.C) / d * m;
    double h = sqrt((C1.r + C2.r) * (C1.r + C2.r) - m * m);
    point H1 = M + rotate90(C2.C - C1.C) / d * h;
    point D1 = (H1 - C1.C) / dist(H1, C1.C) * C2.r;
    L.push_back(line(H1 - D1, C2.C - D1));
    point H2 = M - rotate90(C2.C - C1.C) / d * h;
    point D2 = (H2 - C1.C) / dist(H2, C1.C) * C2.r;
    L.push_back(line(H2 - D2, C2.C - D2));
  }
  return L;
}
