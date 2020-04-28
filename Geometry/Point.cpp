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
	point& operator +=(point P){
		x += P.x;
		y += P.y;
		return *this;
	}
	point& operator -=(point P){
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
	point& operator *=(double k){
		x *= k;
		y *= k;
		return *this;
	}
	point& operator /=(double k){
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
		return sign(P.x - x) == 1 || (equals(x, P.x) && sign(P.y - y) == 1);
	}
	bool operator >(point P){
		return (P < *this);
	}
	double norm(){
	    return x * x + y * y;
	}
	double size(){
	    return sqrt((*this).norm());
	}
	point& rotate(double t){
	    double X = x * cos(t) - y * sin(t);
	    double Y = x * sin(t) + y * cos(t);
	    x = X;
	    y = Y;
	    return *this;
	}
	point& rotate(point P, double t){
	    *this -= P;
	    (*this).rotate(t);
	    *this += P;
	    return *this;
	}
	point& rotate90(){
	    swap(x, y);
	    x = -x;
	    return *this;
	}
};
istream& operator >>(istream &is, point &p){
	double x, y;
	is >> x >> y;
	p = point(x, y);
	return is;
}
ostream& operator <<(ostream &os, point p){
	os << p.x << ' ' << p.y;
	return os;
}
double norm(point P){
    return P.x * P.x + P.y * P.y;
}
double abs(point P){
    return sqrt(norm(P)); 
}
point rotate(point P, double t){
    return point(P.x * cos(t) - P.y * sin(t), P.x * sin(t) + P.y * cos(t));
}
point rotate(point P, point Q, double t){
    return rotate(P - Q, t) + Q;
}
point rotate90(point P){
    return point(-P.y, P.x);
}
double dot(point P, point Q){
    return P.x * Q.x + P.y * Q.y;
}
double cross(point P, point Q){
    return P.x * Q.y - P.y * Q.x;
}
double dist(point P, point Q){
    return abs(P - Q);
}
