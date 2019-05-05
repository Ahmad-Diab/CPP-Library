#include <bits/stdc++.h>

using namespace std ;

const double EPS = 1e-9 ;
struct point{
    double x , y ;
    point(){}
    point(double x, double y) : x(x) , y(y){}

    double sq(double z){ return z * z ;}

    double dist (point &b){
        return sqrt(sq(x - b.x) + sq(y - b.y));
    }
};
struct line {
    double a , b , c ;
    line(){}
    line(point p , point q){
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
    bool parallel(line l){
        return fabs(a - l.a) < EPS && fabs(b - l.b) < EPS;
    }
    point intersect(line l){
        if(parallel(l))
            return {-1,-1};
        double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
        double y;
        if(fabs(b) < EPS)
            y = -l.a * x - l.c;
        else
            y = -a * x - c;
        return {x , y};
    }
};
istream& operator >> (istream&in , point &p){
    in >> p.x >> p.y ;
    return in ;
}
ostream& operator << (ostream& out , point &p){
    out << p.x << ' ' << p.y ;
    return out ;
}
point a , b , c ;

double area(double ab , double bc , double ca){
    double s = 0.5 * (ab + bc + ca) ;
    return sqrt(s * (s - ab) * (s - bc)  * (s - ca)) ;
}
double rCircumCircle(double ab , double bc , double ca){
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
double rCircumCircle() {
    return rCircumCircle(a.dist(b), b.dist(c), c.dist(a));
}

point rotate(double theta , point p , point curr)
{
    double xx = -p.x , yy = -p.y ;
    // translate
    point around = {curr.x + xx , curr.y + yy};
    //rotate
    double c = cos(theta * acos(-1.0) / 180.0) ;
    double s = sin(theta * acos(-1.0) / 180.0) ;
    around = {around.x * c - around.y * s , around.x * s + around.y * c} ;
    // translate back
    around.x -= xx ;
    around.y -= yy ;
    return around ;
}
point centerCircumCircle() {
    point a_perp = rotate(90.0 , {(a.x + b.x) / 2.0 , (a.y + b.y) / 2.0}, a);
    point b_perp = rotate(90.0 , {(a.x + b.x) / 2.0 , (a.y + b.y) / 2.0}, b);
    line l1 = {a_perp , b_perp} ;
    a_perp = rotate(-90.0 , {(a.x + c.x) / 2.0 , (a.y + c.y) / 2.0}, a);
    b_perp = rotate(-90.0 , {(a.x + c.x) / 2.0 , (a.y + c.y) / 2.0}, c);
    line l2 = {a_perp , b_perp};
    return l1.intersect(l2) ;
}

int main()
{
    while(cin >> a >> b >> c) {
        double r = rCircumCircle() ;
        point center = centerCircumCircle() ;
        double h = center.x ;
        double k = center.y ;
        double c = -2.0 * h ;
        double d = -2.0 * k ;
        double e = h * h + k * k - r * r ;
        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n" , (h > EPS)  ? '-' : '+', (h < EPS) ? h * -1 : h  , (k > EPS) ? '-' : '+', (k < EPS) ? k * -1.0 : k , (r < EPS) ? r * -1.0 : r) ;
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n" , c < EPS ? '-' : '+' , c < EPS ? -1.0 * c : c, d < EPS ? '-' : '+' , d < EPS ? -1.0 * d : d , e < EPS ? '-' : '+' , e < EPS ? -1.0 * e : e);
    }
    return 0 ;
}
