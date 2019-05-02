#include <bits/stdc++.h>
using namespace std ;

const double EPS  = 1e-9;
const double PI = acos(-1.0);

double degToRad(double d) { return d * PI / 180.0; }

double radToDeg(double r) { return r * 180.0 / PI; }

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

    bool ccw(point p, point q, point r){
        return Vector<T>(p, q).cross(Vector<T>(p, r)) > 0;
    }
    bool collinear(point p, point q, point r){
        return fabs(Vector<T>(p, q).cross(new Vector<T>(p, r))) < EPS;
    }
    double distToLine(point p, point a, point b){
        if(a == b) return p.dist(a);
        Vector<T> ap = Vector<T>(a, p), ab = Vector<T>(a, b);
        double u = ap.dot(ab) / ab.norm2();
        point c = a.translate(ab.scale(u));
        return p.dist(c);
    }
    double distToLineSegment(point p, point a, point b){
        Vector<T> ap = Vector<T>(a, p), ab = Vector<T>(a, b);
        double u = ap.dot(ab) / ab.norm2();
        if (u < 0.0) return p.dist(a);
        if (u > 1.0) return p.dist(b);
        return distToLine(p, a, b);
    }
};

int main(){
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    return 0 ;
}

