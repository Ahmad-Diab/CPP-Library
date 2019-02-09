#include <bits/stdc++.h>

using namespace std ;

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    int TC ;
    cin >> TC ;

    while(TC--) {

        int n;
        cin >> n;
        double y;
        cin >> y;

        double x = 1 - y;

        double ans = 0;
        int I  ;
        cin >> I ;

        for (int i = 0; i <= 1000; i += n)
            ans += pow(x, (i + I - 1)) * y;

        printf("%.4lf\n" , ans);

    }

    return 0 ;
}