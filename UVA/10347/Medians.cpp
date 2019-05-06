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
         printf("%.3f\n" , s * (s - a) * (s - b) * (s - c) < EPS ? -1.0 : 4.0 / 3.0 * A) ;
    }
    return 0 ;
}