#include <bits/stdc++.h>

using namespace std  ;

string s ;
string mid ;
string currS ;
string currMid ;
vector<int >  adjList[26][50] ;
vector<int >  revList[26][50] ;
int memo [50][50] ;

int dp(int i , int j)
{
    if(memo[i][j] != -1)return memo[i][j] ;
    int ans = 0 ;
    for(int c = 0 ; c < 26 ; c++)
        for(int x : adjList[c][i])
            for(int y : revList[c][j])
                if (i == y && j == x)
                    ans = max(ans, 1);
                else if(x == y)
                    ans = max(ans , 2) ;
                else if(x < y)
                    ans = max(ans, dp(x , y) + 2);
    return memo[i][j] = ans ;
}

void trace(int i , int j)
{
    if(i >= j) return ;
    int ans = dp(i, j) ;
    for(int c = 0 ; c < 26 ; c++)
        for(int x : adjList[c][i])
            for(int y : revList[c][j])
                if (i == y && j == x )
                {
                    if(ans ==  1)
                    {
                        mid = ((char) ('A' + c));
                        if((currS.empty() && currMid.empty()) || (s + mid) < (currS + currMid))
                        {
                            currS = s ;
                            currMid = mid ;
                        }

                    }
                }
                else if(x == y)
                {
                    if(ans == 2)
                    {
                        s += ((char) ('A' + c));
                        if(currS.empty() || (s) < (currS))
                        {
                            currS = s ;
                            currMid = mid ;
                        }
                        s.pop_back();
                    }
                }
                else if(x < y)
                {
                    if (ans == dp(x, y) + 2)
                    {
                        s += ((char) ('A' + c));
                        trace(x, y);
                        s.pop_back() ;
                    }
                }
}
int main()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    int TC ;
    cin >> TC ;
    while(TC--)
    {
        for(int i = 0 ;i < 26 ; i++)
            for(int j = 0 ; j < 50 ; j++)
                adjList[i][j].clear() , revList[i][j].clear() ;
        memset(memo , -1 , sizeof memo) ;
        s.clear() ;
        mid.clear() ;
        currS.clear() ;
        currMid.clear() ;
        int n ;
        cin >> n ;
        for(int i = 0 ; i < n ; i ++)
        {
            string ss ;
            cin >> ss ;

            for (int j = 0; j < n; j++)
            {
                if(ss[j] != '*')
                {
                    if(i < j)
                        adjList[ss[j] - 'A'][i].push_back(j);
                    else
                        revList[ss[j] - 'A'][i].push_back(j) ;
                }
            }
        }

        if(!dp(0 , n - 1) && currMid.empty())
        {
            cout << "NO PALINDROMIC PATH\n" ;
        }
        else
        {
            trace(0, n - 1);
            string rev = currS;
            reverse(rev.begin(), rev.end());
            cout << currS << currMid << rev << '\n';
        }
    }
    return 0 ;
}