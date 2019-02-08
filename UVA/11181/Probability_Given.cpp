#include <bits/stdc++.h>

using namespace std ;

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;
    
    int cases = 1 ;
    
    vector<double > p ;
    vector<double > ans ;

    while(1)
    {

        int n , m ; cin >> n >> m ;

        if(!n && !m)break;

        cout << "Case "<<(cases++) << ":\n" ;

        p.assign(n , 0) , ans.assign(n, 0);

        for(double &x : p) cin >> x ;

        double all = 0 ;

        for(int msk = 0 ; msk < 1 << n ; msk ++)
            if(__builtin_popcount(msk) == m)
            {
                double prop = 1 ;

                for(int i = 0 ; i < n ; i++)
                    if(msk & 1 << i) prop *= p[i];
                    else prop *= 1 - p[i] ;
                all += prop ;

                for(int i = 0 ; i < n ; i++)
                    if(msk & 1 << i) ans[i] += prop;

            }

        for(double x : ans) cout << setprecision(6) << x / all << '\n' ;
    }



    return 0 ;
}