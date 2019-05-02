#include <bits/stdc++.h>

using namespace std ;

int n , r , k ;
int memo[2][40][40][20] ;
const int UP = 1 , DOWN = 0 ;
int dx [2]= {1 , 1};
int dy [2]= {-1 ,1};
int dp(int x , int y , int r , int lst)
{
    if(y > 2 * n || r < 0 || x > 2 * n || x < 0 || y < 0) return 0 ;
    if(x == 2 * n && y == 0 && r == 0)return 1 ;
    int &ret = memo[lst][x][y][r] ;
    if(~ret) return ret ;
    ret = 0 ;
    for(int curr = 0 ; curr < 2 ; curr++){
        if(curr == DOWN && lst == UP && y == k)
            ret += dp(x + dx[curr]  , y + dy[curr] , r - 1 , curr);
        else
            ret += dp(x + dx[curr] , y + dy[curr] , r  , curr) ;
    }
    return ret ;
}
int main() {
    while(cin >> n >> r >> k)
    {
        memset(memo , -1 , sizeof memo) ;
        cout << dp(0 , 0 , r , 0) << '\n';
    }
    return 0 ;
}
