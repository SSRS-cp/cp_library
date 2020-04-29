struct line{
	point A;
	point B;
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
	point vec(){
		return B - A;
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
