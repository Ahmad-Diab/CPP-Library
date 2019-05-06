#include <bits/stdc++.h>

using namespace std ;

const double EPS = 1e-9 ;

int main()
{
    double a , b , c ;
    while (cin >> a >> b >> c)
    {
        double s = 0.5 * (a + b + c) ;
        double A = sqrt(s * (s - a) * (s - b) * (s - c)) ;
        double r = A / s ;
        if(s < EPS)r = 0 ;
        double a1 = acos(-1.0) * r * r ;
        double a2 = A - a1 ;
        double R = (a * b * c) / (4.0 * A) ;
        double a3 = acos(-1.0) * R * R - A ;
        printf("%.4f %.4f %.4f\n" , a3 , a2 , a1);
    }
    return 0 ;
}