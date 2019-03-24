#include <bits/stdc++.h>

using namespace std ;

int main()
{
    double s , r;    string st ;

    while(cin >> s >> r >> st)
    {
        if(st[0] == 'd')
        {
            if(r > 180) r = 360 - r ;
            double arc = 2 * acos(-1.0) * (s + 6440.0) * r / 360.0 ;
            double chord = 2 * (s + 6440.0) * sin((r / 2.0) * acos(-1)/180) ;
            printf("%.6f %.6f\n" , arc , chord) ;
        } else
        {
            double arc = 2 * acos(-1.0) * (s + 6440.0) * r / 21600.0 ;
            double chord = 2 * (s + 6440.0) * sin((r / 120.0) * acos(-1)/180) ;
            printf("%.6f %.6f\n" , arc , chord) ;
        }

    }
    return 0 ;
}