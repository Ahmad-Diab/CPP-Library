#include <bits/stdc++.h>
#define long long long

using namespace std ;

const int MAX = 1001 ;
double memo [1001][101] ;
double p ;

double dp(int men , int rem)
{
    if(rem == 0)return (men & 1) == 0 ;

    double &ret = memo[men][rem] ;

    if(ret > -10)return ret ;

    return ret = p * dp(men + 1 , rem - 1) + (1 - p) * dp(men , rem - 1) ;
}

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    while(true)
    {
        int M, W, C;
        cin >> M >> W >> C ;
        if(!M && !W) break;

        p = (double(M) / (M + W));
        
        memset(memo , -20 , sizeof memo ) ;

        cout << setprecision(7) << dp(0 , C) << endl ;

    }


    return 0;
}