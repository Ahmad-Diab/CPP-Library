#include <bits/stdc++.h>

#define long long long

using namespace std ;
const int INF = (int)1e9 ;

char mat[1001][1001] ;
int distFire[(int)1e6 + 10] , distJoe[(int)1e6 + 10] ;
int dx [4] = {-1, 1 ,  0 , 0};
int dy [4] = {0 , 0 , -1 , 1};
int R , C ;

bool isValid(int i , int j , int curr)
{
    return i >= 0 && j >= 0 && i < R && j < C && mat[i][j] == '.' &&  distFire[curr] + 1 < distFire[i * C + j] ;
}
bool isValidJoe(int i , int j , int curr)
{
    return i >= 0 && j >= 0 && i < R && j < C && mat[i][j] == '.' && distJoe[curr] + 1 < distJoe[i * C + j] && distJoe[curr] + 1 < distFire[i * C + j];
}

int main()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int TC ;
    cin >> TC ;

    while(TC--)
    {
        cin >> R >> C ;

        for(int i = 0 ;i  < R; i++)cin >> mat[i] ;

        for(int i = 0 ; i < R ;i++)
            for(int j = 0 ; j < C ;j++)
                distFire[i * C + j] = INF  , distJoe[i * C + j] = INF;

        queue<int > qFire ;
        queue<int > q ;

        for(int i = 0 ; i < R ;i++)
            for(int j = 0 ; j < C ;j++)
                if(mat[i][j] == 'F')
                {
                    int curr = i * C + j ;
                    distFire[curr] = 0 ;
                    qFire.push(curr) ;
                }
                else if(mat[i][j] == 'J')
                {
                    int curr = i * C + j ;
                    distJoe[curr] = 0 ;
                    q.push(curr) ;
                }

        while(!qFire.empty())
        {
            int curr = qFire.front() ; qFire.pop() ;
            int i = curr / C , j = curr % C ;

           for(int k = 0 ; k < 4 ; k++)
            {
                int ii = i + dx[k] , jj = j + dy[k] ;
                int nxt = ii * C + jj ;
                if (isValid(i + dx[k], j + dy[k] , curr))
                {
                    distFire[nxt] = distFire[curr] + 1 ;
                    qFire.push(nxt) ;
                }
            }
        }

        while(!q.empty())
        {
            int curr = q.front() ; q.pop() ;
            int i = curr / C , j = curr % C ;

            for(int k = 0 ; k < 4 ; k++)
            {
                int ii = i + dx[k] , jj = j + dy[k] ;

                int nxt = ii * C + jj ;
                if(isValidJoe(i  + dx[k] , j + dy[k] , curr))
                {
                    distJoe[nxt] = distJoe[curr] + 1 ;
                    q.push(nxt) ;
                }
            }
        }

        int ans = INF ;
        for(int i = 0 ;i < R ;i++)
            for(int j = 0 ; j < C ;j++)
                if ((i == 0 || j == 0 || i == R - 1 || j == C - 1) && (mat[i][j] == '.' || mat[i][j] == 'J'))
                    ans = min(ans, distJoe[i * C + j] + 1);

        if(ans < INF)cout << ans << '\n' ;
        else cout << "IMPOSSIBLE\n" ;
    }
   return 0 ;
}