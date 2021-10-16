struct line{
  point A, B;
  line(){
  }
  line(point A, point B): A(A), B(B){
  }
};
point vec(line L){
  return L.B - L.A;
}
bool point_on_segment(point P, line L){
  return dot(P - L.A, vec(L)) > -eps && dot(P - L.B, vec(L)) < eps;
}
point projection(point P, line L){
  return L.A + vec(L) / abs(vec(L)) * dot(P - L.A, vec(L)) / abs(vec(L));
}
point reflection(point P, line L){
  return projection(P, L) * 2 - P;
}
double point_line_distance(point P, line L){
  return abs(cross(P - L.A, vec(L))) / abs(vec(L));
}
double point_segment_distance(point P, line L){
  if (dot(P - L.A, vec(L)) < 0){
    return dist(P, L.A);
  } else if (dot(P - L.B, vec(L)) > 0){
    return dist(P, L.B);
  } else {
    return point_line_distance(P, L);
  }
}
bool is_parallel(line L1, line L2){
  return abs(cross(vec(L1), vec(L2))) < eps;
}
point line_intersection(line L1, line L2){
  return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1), vec(L2));
}
bool segment_intersect(line L1, line L2){
  return cross(L1.A - L2.A, vec(L2)) * cross(L1.B - L2.A, vec(L2)) < eps && cross(L2.A - L1.A, vec(L1)) * cross(L2.B - L1.A, vec(L1)) < eps;
}
double segment_distance(line L1, line L2){
  if (segment_intersect(L1, L2)){
    return 0;
  } else {
    double ans = INF;
    ans = min(ans, point_segment_distance(L1.A, L2));
    ans = min(ans, point_segment_distance(L1.B, L2));
    ans = min(ans, point_segment_distance(L2.A, L1));
    ans = min(ans, point_segment_distance(L2.B, L1));
    return ans;
  }
}
