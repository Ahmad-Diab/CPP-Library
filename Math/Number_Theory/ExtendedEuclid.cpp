#include <bits/stdc++.h>

using namespace std ;

int extendedEuclid(int a , int b , int &x , int &y)
{
    if(b == 0){x = 1 ; y = 0 ;return a ;}

    int g = extendedEuclid(b , a % b , x , y) ;

    int x1 = y ;
    int y1 = x - a / b * y ;

    x = x1 ; y = y1 ;
    return g ;
}
