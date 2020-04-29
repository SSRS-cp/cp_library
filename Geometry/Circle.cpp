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
