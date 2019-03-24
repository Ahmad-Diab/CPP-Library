#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int TC ; cin>> TC ;

    while(TC--)
    {
        double l; cin >> l ;

        double w = 0.6 * l , r = 0.2 * l;

        printf("%.2f %.2f\n" , acos(-1) * r * r , l * w - acos(-1) * r * r) ;
    }
    return 0 ;
}