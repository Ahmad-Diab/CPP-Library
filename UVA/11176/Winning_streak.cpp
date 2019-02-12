#include <bits/stdc++.h>
#define long long long

using namespace std ;

const int MAX = int(502) ;
double memo [2][MAX][MAX] ;
double p ;
int n ;
double dp(int idx , int longest , int lst)
{
    if(idx == 0) return longest ;

    double &ret = memo[lst][idx][longest] ;

    if(ret > -10) return ret ;

    double win =  0 ;
    double lose = (1 - p) * dp(idx - 1 , longest , 0);
    double pw = p ;

    for(int streak = 1 ; streak <= idx && lst == 0; streak++ , pw *= p)
        win += pw * dp(idx - streak, max(longest, streak) , 1) ;

    return  ret = win + lose ;

}
int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    while(true)
    {
        cin >> n ;
        if(!n) break ;

        cin >> p ;
        memset(memo , -20 , sizeof memo) ;

        cout << setprecision(8) << dp(n, 0, 0) << endl;
    }

    return 0;
}