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
		if (a == 0){
			A = point(1, -c/b);
		} else {
			A = point(-c/a, 0);
		}
		if (b == 0){
			B = point(-c/a, 1);
		} else {
			B = point(0, -c/b);
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
