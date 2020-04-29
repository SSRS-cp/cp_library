struct circle{
	point c;
	double r;
	circle(){
	}
	circle(point C, double R){
		c = C;
		r = R;
	}
	circle(double x, double y, double R){
		c = point(x, y);
		r = R;
	}
	circle operator +(point P){
		return circle(c + P, r);
	}
	circle operator -(point P){
		return circle(c - P, r);
	}
	circle& operator +=(point P){
		c += P;
		return *this;
	}
	circle& operator -=(point P){
		c -= P;
		return *this;
	}
	circle operator *(double k){
		return circle(c, r * k);
	}
	circle operator /(double k){
		return circle(c, r / k);
	}
	circle& operator *=(double k){
		r *= k;
		return *this;
	}
	circle& operator /=(double k){
		r /= k;
		return *this;
	}
	bool operator ==(circle C2){
		return c == C2.c && equals(r, C2.r);
	}
	bool operator !=(circle C2){
		return !(*this == C2);
	}
};
istream& operator >>(istream &is, circle &C){
	point P;
	double r;
	cin >> P >> r;
	C = circle(P, r);
	return is;
}
ostream& operator <<(ostream &os, circle C){
	cout << C.c << ' ' << C.r << endl;
	return os;
}
double perimeter(circle C){
	return 2 * M_PI * C.r;
}
double area(circle C){
	return M_PI * pow(C.r, 2);
}
bool point_on_circle(point P, circle C){
	return equals(r, dist(C.c, P));
}
bool point_in_circle(point P, circle C){
	return sign(r - dist(C.c, P)) >= 0;
}
int circle_pos(circle C1, circle C2){
	double d = dist(C1.c, C2.c);
	if (sign(d - (C1.r + C2.r)) == 1){
		return 4;
	} else if (sign(d - (C1.r + C2.r)) == 0){
		return 3;
	} else if (sign(d - abs(C1.r - C2.r)) == 1){
		return 2;
	} else if (sign(d - abs(C1.r - C2.r)) == 0){
		return 1;
	} else {
		return 0;
	}
}
int line_circle_intersection_count(line L, circle C){
	return sign(C.r - point_line_distance(C.c, L)) + 1;
}
int segment_circle_intersection_count(segment S, circle C){
	int ans = line_circle_intersection_count(S, C);
	if (ans == 0){
		return 0;
	} else if (ans == 1){
		if (equals(point_segment_distance(C.c, S), r)){
			return 1;
		} else {
			return 0;
		}
	} else {
		if (!point_in_circle(S.A, C) && !point_in_circle(S.B, C)){
			if (equals(r - point_segment_distance(C.c, S))){
				return 2;
			} else {
				return 0;
			}
		} else if (point_in_circle(S.A, C) && point_in_circle(S.B, C)){
			return 0;
		} else {
			return 1;
		}
	}
}
vector<point> line_circle_intersection(line L, circle C){
	int count = line_circle_intersection_count(L, C);
	vector<point> ans;
	if (count == 0){
		return ans;
	} else if (count == 1) {
		ans.push_back(projection(C.c, L));
		return ans;
	} else {
		point P = projection(C.c, L);
		double d = sqrt(pow(C.r, 2) - pow(point_line_distance(C.c, L), 2));
		ans.push_back(P + unit(L) * d);
		ans.push_back(P - unit(L) * d);
		return ans;
	}
}
