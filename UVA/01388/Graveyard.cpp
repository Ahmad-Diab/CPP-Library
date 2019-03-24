#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int n , m ;

    while(cin >> n >> m)
    {
        double rate = 10000.0 / n  , newRate = 10000.0 / (n + m);
        double ans = 0 ;
        bool vis[n + m] ;
        memset(vis , false , sizeof vis) ;
        for(int i = 1 ; i < n ; i++)
        {
            double curr = i * rate ;
            double mn = 1e30 ;
            int state = i ;
            for(int j = 1 ; j < n + m ; j++)
            {
                double nxt = j * newRate ;
                if(fabs(nxt - curr) < mn)
                {
                    mn = fabs(nxt - curr) ;
                    state = j ;
                }
            }
            vis[state] = true ;
            ans += mn ;
        }
       printf("%.4f\n" , ans ) ;
    }

    return 0 ;
}