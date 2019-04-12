#include <bits/stdc++.h>
#define long long long

using namespace std ;

int main()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    long x ;
    while(cin >> x)
    {

        int ans = 0 ;

        while(x)
        {

            if(x & 1)
            {
                int nxt = (x + 1) / 2 ;
                int z1 = 0 ;
                for(int i = 0 ; nxt && i < 30 ; i++)
                    if(nxt & (1 << i))
                        break ;
                    else
                        z1 ++ ;

                nxt = (x - 1) / 2 ;
                int z2 = 0 ;
                for(int i = 0 ; nxt && i < 30 ; i++)
                    if(nxt & (1 << i))
                        break ;
                    else
                        z2 ++ ;
                
                if(z1 < z2 || x <= 3)
                    x -- ;
                else
                    x ++ ;

                x /= 2 ;

                if(x)ans += 2 ;
                else ans ++ ;
            }
            else
                ans ++ , x /= 2 ;

        }
        cout << ans <<'\n';


    }

    return 0 ;
}