
#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std ;

template <typename  T> struct Vector ;

template <typename T>
struct Vector{
    T x , y ;

    Vector(T a , T b){x = a , y = b;}

    Vector(Point<T> a, Point<T> b){Vector(b.x - a.x , b.y - a.x) ;}

    Vector scale(double s){ return Vector(x * s , y * s) ;}

    double dot(Vector v){ return x * v.x + y * v.y ; }

    double cross (Vector v){ return x * v.y - y * v.x ;}

    double norm2(){ return x * x + y * y ;}

    Vector reverse(){ return Vector(-x , -y) ;}

    Vector normalize(){return scale(1 / sqrt(norm2())) ;}
};

int main(){
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    return 0 ;
}