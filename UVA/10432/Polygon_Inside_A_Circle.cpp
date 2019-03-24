#include <bits/stdc++.h>

int main()
{
    double r , n ;

    while(std :: cin >> r >> n) printf("%.3f\n" , n * r * sin(acos(-1.0) / n) * r * sqrt(1 - sin(acos(-1.0) / n) * sin(acos(-1.0) / n))) ;
    
    return 0 ;
}