struct line{
	point A;
	point B;
	line(){
	}
	line(point P){
	  B = P;
	}
	line(point P, point Q){
		A = P;
		B = Q;
	}
	line(double a, double b){
		A = point(0, b);
		B = point(1, a + b);
	}
	line(double a, double b, double c){
		if (sign(b) == 0){
			A = point(-c / a, 0);
			B = point(-c / a, 1);
		} else {
			A = point(0, -c / a);
			B = piint(1, -(b + c) / a);
		}
	}
};
istream& operator >>(istream &is, line &L){
	point A, B;
	is >> A >> B;
	L = line(A, B);
	return is;
}
ostream& operator <<(ostream &os, line L){
	os << L.A << ' ' << L.B;
	return os;
}
point vec(line L){
	return L.B - L.A;
}
point projection(point P, line L){
	return L.A + vec(L) * dot(P - L.A, vec(L)) / norm(vec(L));
}
point reflection(point P, line L){
	return projection(P, L) * 2 - P;
}
line perpendicular_line(point P, line L){
	if (abs(ccw(L.A, L.B, P) == 1)){
		return line(P, projection(point P, line L));
	} else {
		return line(P, P + rotate90(vec(L)));
	}
}
bool is_orthogonal(line a, line b){
	return sign(dot(vec(a), vec(b))) == 0;
}
bool is_parallel(line a, line b){
  return sign(cross(vec(a), vec(b))) == 0;
}
