#include <bits/stdc++.h>

using namespace std ;

const double PI = acos(-1.0);

template <typename T >
struct point
{
    T x , y ;
    point(){x = y = 0;}
    point(T x , T y) : x(x) , y(y) {}
    double dist (point<T> p1 , point<T> p2){
        return hypot(p1.x - p2.x , p1.y - p2.y) ;
    }
    double dist (point<T> p){
        return dist(point<double>(this->x , this->y) , p) ;
    }
};

double area(double a, double b, double c){
    double s = (a + b + c) / 2.0 ;
    return sqrt(s * (s - a) * (s - b) * (s - c)) ;
}
double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
double rCircumCircle(point<double> a, point<double> b, point<double> c) {
    return rCircumCircle(a.dist(b), b.dist(c), c.dist(a));
}
int main() {
    point<double> a , b , c ;
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)
        printf("%.2f\n" , 2 * PI * rCircumCircle(a , b , c)) ;
    return 0 ;
}