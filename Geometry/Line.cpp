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
			B = point(1, -(b + c) / a);
		}
	}
	line operator +(point P){
		return line(A + P, B + P);
	}
	line operator -(point P){
		return line(A - P, B - P);
	}
	line& operator +=(point P){
		A += P;
		B += P;
		return *this;
	}
	line& operator -=(point P){
		A -= P;
		B -= P;
		return *this;
	}
	bool operator ==(line L){
		return abs(ccw(A, B, L.A)) != 1 && abs(ccw(A, B, L.B)) != 1;
	}
	bool operator !=(line L){
		return !(*this == L);
	}
	bool operator <(line L){
		return A < L.A || A == L.A && B < L.B;
	}
	bool operator >(line L){
		return (L < *this);
	}
};
using ray = line;
using segment = line;
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
point unit(line L){
	return vec(L) / abs(vec(L));
}
point norm(line L){
	return rotate90(unit(L));
}
point projection(point P, line L){
	return L.A + vec(L) * dot(P - L.A, vec(L)) / norm(L);
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
bool is_on_line(point P, line L){
	return abs(ccw(L.A, L.B, P)) != 1;
}
bool is_on_segment(point P, segment L){
	return ccw(L.A, L.B, P) == 0;
}
bool is_intersecting_line(line a, line b){
	return !is_parallel(a, b);
}
pair<bool, point> line_intersection(line L1, line L2){
	if (L1 == L2){
		return make_pair(true, L2.A);
	} else if (is_parallel(L1, L2)){
		return make_pair(false, point());
	} else {
		point P = L1.A + vec(L1) * cross(vec(L2), L2.A - L1.A) / cross(vec(L2), vec(L1));
		return make_pair(true, P);
	}
}
pair<bool, point> line_segment_intersection(line L, segment S){
	auto P = line_intersection(L, S);
	if (P.first && is_on_segment(P.second, S)){
		return make_pair(true, P.second);
	} else {
		return make_pair(false, point());
	}
}
pair<bool, point> segment_intersection(segment S1, segment S2){
	if (S1 == S2){
		if (is_on_segment(S2.A, S1)){
			return make_pair(true, S2.A);
		} else if (is_on_segment(S2.B, S1)){
			return make_pair(true, S2.B);
		} else if (is_on_segment(S1.A, S2)){
			return make_pair(true, S1.A);
		} else {
			return make_pair(false, point());
		}
	}
	pair<bool, point> P = line_intersection(S1, S2);
	if (!P.first){
		return P;
	} else if (is_on_segment(P.second, S1) && is_on_segment(P.second, S2)){
		return P;
	} else {
		return make_pair(false, point());
	}
}
double point_line_distance(point P, line L){
	return abs(cross(P - L.A, vec(L))) / abs(vec(L));
}
double point_segment_distance(point P, segment S){
	if (angle_type(P, S.A, S.B) == -1){
		return dist(P, S.A);
	} else if (angle_type(P, S.B, S.A) == -1){
		return dist(P, S.B);
	} else {
		return point_line_distance(P, S);
	}
}
double line_segment_distance(line L, segment S){
	if (line_segment_intersection(L, S).first){
		return 0;
	} else {
		return min(point_line_distance(S.A, L), point_line_distance(S.B, L));
	}
}
double segment_distance(segment S1, segment S2){
	if (segment_intersection(S1, S2).first){
		return 0;
	} else {
		double ans1 = min(point_segment_distance(S1.A, S2), point_segment_distance(S1.B, S2));
		double ans2 = min(point_segment_distance(S2.A, S1), point_segment_distance(S2.B, S1));
		return min(ans1, ans2);
	}
}
line perpendicular_bisector(segment S){
	return line(midpoint(S.A, S.B), midpoint(S.A, S.B) + rotate90(vec(S)));
}
line angle_bisector(point A, point B, point C){
	return line(B, midpoint(B + (A - B) / abs(A - B), B + (C - B) / abs(C - B)));
}
