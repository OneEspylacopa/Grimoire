int dcmp(const double &x) {
	return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1);
}

struct TPoint{
	double x, y, z;
	TPoint() {}
	TPoint(double x, double y, double z) : x(x), y(y), z(z) {}
	TPoint operator +(const TPoint &p)const {
		return TPoint(x + p.x, y + p.y, z + p.z);
	}
	TPoint operator -(const TPoint &p)const {
		return TPoint(x - p.x, y - p.y, z - p.z);
	}
	TPoint operator *(const double &p)const {
		return TPoint(x * p, y * p, z * p);
	}
	TPoint operator /(const double &p)const {
		return TPoint(x / p, y / p, z / p);
	}
	bool operator <(const TPoint &p)const {
		int dX = dcmp(x - p.x), dY = dcmp(y - p.y), dZ = dcmp(z - p.z);
		return dX < 0 || (dX == 0 && (dY < 0 || (dY == 0 && dZ < 0)));
	}
	bool read() {
		return scanf("%lf%lf%lf", &x, &y, &z) == 3;
	}
};

double sqrdist(const TPoint &a) {
	double ret = 0;
	ret += a.x * a.x;
	ret += a.y * a.y;
	ret += a.z * a.z;
	return ret;
}
double sqrdist(const TPoint &a, const TPoint &b) {
	double ret = 0;
	ret += (a.x - b.x) * (a.x - b.x);
	ret += (a.y - b.y) * (a.y - b.y);
	ret += (a.z - b.z) * (a.z - b.z);
	return ret;
}
double dist(const TPoint &a) {
	return sqrt(sqrdist(a));
}
double dist(const TPoint &a, const TPoint &b) {
	return sqrt(sqrdist(a, b));
}
TPoint det(const TPoint &a, const TPoint &b) {
	TPoint ret;
	ret.x = a.y * b.z - b.y * a.z;
	ret.y = a.z * b.x - b.z * a.x;
	ret.z = a.x * b.y - b.x * a.y;
	return ret;
}
double dot(const TPoint &a, const TPoint &b) {
	double ret = 0;
	ret += a.x * b.x;
	ret += a.y * b.y;
	ret += a.z * b.z;
	return ret;
}
double detdot(const TPoint &a, const TPoint &b, const TPoint &c, const TPoint &d) {
	return dot(det(b - a, c - a), d - a);
}
