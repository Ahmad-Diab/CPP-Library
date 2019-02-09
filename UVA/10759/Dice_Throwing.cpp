#include <bits/stdc++.h>
#define long unsigned long long

using namespace std ;
const int N = 25 ;
const int X = 5001 ;

long dp[N][X] ;

long solve (int rem , int total , int x)
{
    if(rem == 0)
        return total >= x ? 1 : 0;

    long &ret = dp[rem][total] ;

    if(~ret) return ret ;

    ret = 0 ;

    for(int i = 1 ; i <= 6 ; i++)
        ret += solve(rem - 1, total + i , x) ;

    return  ret ;

}

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    while(true)
    {
        long n , x ;
        cin >> n >> x ;

        if(!n && !x)
            break  ;
        memset(dp , -1 , sizeof dp) ;

        long sampleSpace = (pow(6 , n)) ;
        long event = solve(n , 0 , x) ;

        long g = __gcd(sampleSpace , event) ;
        event /= g , sampleSpace /= g ;

        if(event == 0)
            cout << 0 << '\n' ;
        else if(event == sampleSpace)
            cout << 1 << '\n' ;
        else
            cout << event << '/' << sampleSpace << '\n' ;

    }

    return 0 ;
}