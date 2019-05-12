#include <bits/stdc++.h>

using namespace std  ;
/**
 *
 * get B1 :-
 *        L , theta , phi are given
 *        B1 is required
 *
 *        L = H1 sin(theta)
 *        B1 = H1  cos(theta)
 *        B1 = (L / sin(theta)) * cos(theta)  = L / tan(theta)

          L = H2 sin(phi)
 *        B2 = H2  cos(phi)
 *        B2 = (L / sin(phi)) * cos(phi)  = L / tan(phi)

          answer = B1 + B2
 *
 *
 */
int main()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    double x1 , y1 , x2 , y2 , theta , phi;
    while(cin >> x1 >> y1 >> x2 >> y2 >> theta >> phi)
    {
        double L = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) ;
        double B1 = L / tan(theta * acos(-1.0) / 180.0) ;
        double B2 = L / tan(phi* acos(-1.0) / 180.0) ;
        printf("%.3f\n" , B1 + B2) ;
    }
    return 0 ;
}