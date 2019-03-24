#include <bits/stdc++.h>
using namespace std ;

template <typename  T>struct Point ;

template <typename  T >
struct Point
{
    T x, y;

    Point(T _x, T _y):x(_x), y(_y){}
    Point (){x = 0 , y = 0;}

    Point operator+(const Point & p) const { return pt(x + p.x, y + p.y); }

    Point operator-(const Point & p) const { return pt(x - p.x, y - p.y); }

    Point&operator += (const Point &t){
        x += t.x ;
        y += t.y;
        return *this ;
    }
    Point&operator -= (const Point &t){
        x -= t.x ;
        y -= t.y;
        return *this ;
    }
    Point& operator*=(T t) {
        x *= t;
        y *= t;
        return *this;
    }
    Point& operator/=(T t) {
        x /= t;
        y /= t;
        return *this;
    }

    bool operator< (const Point& p) const
    {

        if(abs(x - p.x) > EPS) return x < p.x;
        if(abs(y - p.y) > EPS) return y < p.x;
        return false;

        /* IF x and y are integers
        if(x != p.x)
            return x < p.x ;
        return y < p.y ;
         */
    }
    bool operator== (const Point& p) const
    {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
        /* IF x and y are integers
         *  return x == p.x &&  y == p.y ;
         */
    }

    T cross(const Point & p) const { return x * p.y - y * p.x; }
    T dot(const Point & p) const { return x * p.x + y * p.y; }
    T cross(const Point & a, const Point & b) const { return (a - *this).cross(b - *this); }
    T dot(const Point & a, const Point & b) const { return (a - *this).dot(b - *this); }
    T sq(T x){ return x * x ; }
    T dist(const Point &p) const { return sqrt(sq(x - p.x) + sq(y - p.y)) ;}
    Point rotate(T angle)
    {
        double c = cos(angle) , s = sin(angle) ;
        return Point(x * c - y * s , x * s + y * c) ;
    }


};

int main()
{

    return 0 ;
}

