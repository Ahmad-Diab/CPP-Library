#include <bits/stdc++.h>

using namespace std ;

const double EPS = 1e-9 ;

int main()
{
    int a[3] ;
    int TC ;
    cin >> TC ;
    while (TC--)
    {
        cin >> a[0] >> a[1] >> a[2];
        sort(a , a + 3)  ;
        printf("%s\n" ,a[0] + a[1] > a[2] ? "OK" : "Wrong!!" ) ;
    }
    return 0 ;
}
