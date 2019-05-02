#include <bits/stdc++.h>

using namespace std ;

const double EPS  = 1e-9;
const double PI = acos(-1.0);

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
int main() {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    return 0 ; 
  }