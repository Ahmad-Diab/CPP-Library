#include <bits/stdc++.h>

using namespace std  ;

const double EPS = 0.000001;
const double PI = acos(-1.0) ;

int main()
{
    int TC ;
    cin >> TC ;
    for(int i = 0 ; i < TC ; i++)
    {
        if(i > 0)printf("\n") ;
        double B , H ;
        cin >> B >> H ;
        double ans = 0 ;
        double A = sqrt(H * H + 0.25 * B * B) ;
        double S = 0.5 * (2.0 * A + B) ;
        double area = 0.5 * B * H ;
        double r = area / S ;
        while(true)
        {
            if(r < EPS) break ;
            ans += 2.0 * PI * r ;
            double newH = H - 2.0 * r ;
            r *= newH / H ;
            H = newH ;
        }
        printf("%13.6lf\n" , ans) ;

    }

    return 0 ;
}