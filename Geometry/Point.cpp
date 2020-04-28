double EPS = 0.0000000001;
int sign(double x){
	if (x > EPS){
		return 1;
	} else if (x < -EPS){
		return -1;
	} else {
		return 0;
	}
}
bool equals(double x, double y){
	return abs(x - y) < EPS;
}
struct point{
	double x;
	double y;
	point(){
		x = 0;
		y = 0;
	}
	point(double X, double Y){
		x = X;
		y = Y;
	}
	point operator +(){
		return point(x, y);
	}
	point operator -(){
		return point(-x, -y);
	}
	point operator +(point P){
		return point(x + P.x, y + P.y);
	}
	point operator -(point P){
		return point(x - P.x, y - P.y);
	}
	point operator +=(point P){
		x += P.x;
		y += P.y;
		return *this;
	}
	point operator -=(point P){
		x -= P.x;
		y -= P.y;
		return *this;
	}
	point operator *(double k){
		return point(x * k, y * k);
	}
	point operator /(double k){
		return point(x / k, y / k);
	}
	point operator *=(double k){
		x *= k;
		y *= k;
		return *this;
	}
	point operator /=(double k){
		x /= k;
		y /= k;
		return *this;
	}
	bool operator ==(point P){
		return equals(x, P.x) && equals(y, P.y);
	}
	bool operator !=(point P){
		return !(*this == P);
	}
	bool operator <(point P){
		return sign(P.x - x) == 1 || (equals(x == P.x) && sign(P.y - y) == 1);
	}
	bool operator >(point P){
		return (P < *this);
	}
};
istream &operator >>(istream &is, point &p){
	double x, y;
	is >> x >> y;
	p = point(x, y);
	return is;
}
ostream &operator <<(ostream &os, point p){
	os << p.x << ' ' << p.y;
	return os;
}
