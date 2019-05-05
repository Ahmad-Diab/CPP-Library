#include <bits/stdc++.h>

using namespace std ;

const double EPS  = 1e-9;
const double PI = acos(-1.0);

double degToRad(double d) { return d * PI / 180.0; }

double radToDeg(double r) { return r * 180.0 / PI; }

template <typename T> struct Vector;
template <typename T> struct point;
struct line;
struct lineSegment ;

template <typename T >
struct point
{
    T x , y ;
    point(){x = y = 0;}
    point(T x , T y) : x(x) , y(y) {}
    bool operator < (point p) const {
        if(fabs(x - p.x) > EPS)
            return x < p.x ;
        return y < p.y ;
    }
    bool operator == (point p) const {
        return (fabs(x - p.x) < EPS && (fabs(y - p.y) < EPS));
    }
    double dist (point<T> p1 , point<T> p2){
        return hypot(p1.x - p2.x , p1.y - p2.y) ;
    }
    double dist (point<T> p){
        return dist(point<double>(this->x , this->y) , p) ;
    }

    point<T> rotate(point<T>p , double theta){
        double rad = degToRad(theta);
        return point(p.x * cos(rad) - p.y * sin(rad),p.x * sin(rad) + p.y * cos(rad));
    }
    point<T> rotate(double theta){
        double angle = degToRad(theta);
        double c = cos(angle), s = sin(angle);
        return point<T>(x * c - y * s, x * s + y * c);
    }
    bool between(point p, point q){
        return x < max(p.x, q.x) + EPS && x + EPS > min(p.x, q.x)&& y < max(p.y, q.y) + EPS && y + EPS > min(p.y, q.y);
    }
    point translate(Vector<T> v) { return point(x + v.x , y + v.y); }

    bool ccw(point p, point q, point r)
    {
        return Vector<T>(p, q).cross(Vector<T>(p, r)) > 0;
    }
    bool collinear(point p, point q, point r)
    {
        return fabs(Vector<T>(p, q).cross(new Vector<T>(p, r))) < EPS;
    }
    double distToLine(point p, point a, point b){
        if(a == b) return p.dist(a);
        Vector<T> ap = Vector<T>(a, p), ab = Vector<T>(a, b);
        double u = ap.dot(ab) / ab.norm2();
        point c = a.translate(ab.scale(u));
        return p.dist(c);
    }
    double distToLineSegment(point p, point a, point b)
    {
        Vector<T> ap = Vector<T>(a, p), ab = Vector<T>(a, b);
        double u = ap.dot(ab) / ab.norm2();
        if (u < 0.0) return p.dist(a);
        if (u > 1.0) return p.dist(b);
        return distToLine(p, a, b);
    }
};

template <typename T>
struct Vector
{
    T x , y ;
    Vector(T x , T y) : x(x) , y(y) {}
    Vector(point<T> a , point<T>b){this(b.x - a.x, b.y - a.y);}
    Vector scale(double s) { return new Vector(x * s, y * s); }

    double dot(Vector v) { return (x * v.x + y * v.y); }

    double cross(Vector v) { return x * v.y - y * v.x; }

    double norm2() { return x * x + y * y; }

    Vector reverse() { return Vector(-x, -y); }

    Vector normalize()
    {
        double d = sqrt(norm2());
        return scale(1 / d);
    }
};
struct line{
    double a , b , c ;
    line(){}
    line(point<double> p , point<double> q)
    {
        if (fabs(p.x - q.x) < EPS) {
            a = 1.0;
            b = 0.0;
            c = -p.x;
        } else {
            a = -(double)(p.y - q.y) / (p.x - q.x);
            b = 1.0;
            c = -(double)(a * p.x) - p.y;
        }
    }
    line(point<double> p , double m){
        a = -m; b = 1; c = -(a * p.x + p.y);
    }
    bool parallel(line l){
        return fabs(a - l.a) < EPS && fabs(b - l.b) < EPS;
    }
    bool same(line l){
        return parallel(l) && fabs(c - l.c) < EPS;
    }
    point<double>intersect(line l){
        if(parallel(l))
            return point<double>(-1,-1);
        double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
        double y;
        if(fabs(b) < EPS)
            y = -l.a * x - l.c;
        else
            y = -a * x - c;

        return point<double>(x, y);
    }
    point<double>closestPoint(point<double> p){
        if(fabs(b) < EPS) return point<double>(-c, p.y);
        if(fabs(a) < EPS) return point<double>(p.x, -c);
        return intersect(line(p, 1 / a));
    }
};
struct lineSegment{
    point <double> p , q ;
    lineSegment(point<double> p , point<double>q) : p(p) , q(q){}
    bool intersect(lineSegment ls)
    {
        line l1 = line(p, q), l2 = line(ls.p, ls.q);
        if(l1.parallel(l2))
        {
            if(l1.same(l2))
                return p.between(ls.p, ls.q) || q.between(ls.p, ls.q) || ls.p.between(p, q) || ls.q.between(p, q);
            return false;
        }
        point<double> c = l1.intersect(l2);
        return c.between(p, q) && c.between(ls.p, ls.q);
    }
};
double area(double a, double b, double c){
    double s = (a + b + c) / 2.0 ;
    return sqrt(s * (s - a) * (s - b) * (s - c)) ;
}
double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * (ab + bc + ca));
}
double rInCircle(point<double> a, point<double> b, point<double> c) {
    return rInCircle(a.dist(b), b.dist(c), c.dist(a));
}
point<double> inCircle(point<double> p1 , point<double> p2 , point<double> p3)
{
    double a = p1.dist(p2) ;
    double b = p2.dist(p3) ;
    double c = p3.dist(p1) ;
    double p = a + b + c ;
    return point<double>{(a * p1.x + b * p2.x + c * p3.x) / p , (a * p1.y + b * p2.y + c * p3.y) / p};
}
double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
double rCircumCircle(point<double> a, point<double> b, point<double> c) {
    return rCircumCircle(a.dist(b), b.dist(c), c.dist(a));
}
point<double> rotate(double theta , point<double> p , point<double> curr)
{
    double xx = -p.x , yy = -p.y ;
    // translate
    point<double> around = {curr.x + xx , curr.y + yy};
    //rotate
    double c = cos(theta * acos(-1.0) / 180.0) ;
    double s = sin(theta * acos(-1.0) / 180.0) ;
    around = {around.x * c - around.y * s , around.x * s + around.y * c} ;
    // translate back
    around.x -= xx ;
    around.y -= yy ;
    return around ;
}
point<double> centerCircumCircle(point<double>a , point<double>b , point<double>c) {
    point<double> a_perp = rotate(90.0 , {(a.x + b.x) / 2.0 , (a.y + b.y) / 2.0}, a);
    point<double> b_perp = rotate(90.0 , {(a.x + b.x) / 2.0 , (a.y + b.y) / 2.0}, b);
    line l1 = {a_perp , b_perp} ;
    a_perp = rotate(-90.0 , {(a.x + c.x) / 2.0 , (a.y + c.y) / 2.0}, a);
    b_perp = rotate(-90.0 , {(a.x + c.x) / 2.0 , (a.y + c.y) / 2.0}, c);
    line l2 = {a_perp , b_perp};
    return l1.intersect(l2) ;
}

int main() {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    return 0 ;
}