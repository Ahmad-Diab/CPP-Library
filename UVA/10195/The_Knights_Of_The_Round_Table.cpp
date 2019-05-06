#include <bits/stdc++.h>

using namespace std ;

const double EPS = 1e-9 ;

int main()
{
    double a , b, c ;
    while(cin >> a >> b >> c) {
        double s = (a + b + c) * 0.5 ;
        double A = sqrt(s * (s - a) * (s - b) * (s - c)) ;
        printf("The radius of the round table is: %.3f\n",fabs(s) < EPS ? 0 : A / s) ;
    }
    return 0 ;
}
