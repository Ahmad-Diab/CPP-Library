#include <bits/stdc++.h>

using namespace std ;

double win[17][17] ;

vector<double > solve (int l , int r)
{
    vector<double > curr (16 , 1);

    if(l == r)
        return curr;

    int mid = (l + r) >> 1 ;

    vector <double > left = solve(l , mid) , right = solve(mid + 1 , r);

    for(int i = l ; i <= mid ; i++)curr[i] = left[i] ;
    for(int i = mid + 1 ; i <= r ; i++)curr[i] = right[i] ;

    for(int i = l ; i <= mid ; i++) // win
    {
        double currWin = 0 ;

        for (int j = mid + 1; j <= r; j++) // lose
            currWin += win[i][j] / 100 * right[j] ;

        curr[i] *= currWin ;
    }

    for(int i = mid + 1 ; i <= r ; i++) // win
    {
        double currWin = 0 ;

        for (int j = l ; j <= mid; j++) // lose
            currWin += win[i][j] / 100 * left[j] ;

        curr[i] *= currWin ;
    }

    return curr ;

}

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    char name [16][100] ;

    for(int i = 0 ; i < 16 ; i++)cin >> name[i] ;

    for(int i = 0 ; i < 16; i++)
        for(int j = 0 ; j < 16 ; j++)
            cin >> win[i][j];

    vector<double > ans = solve(0 , 15) ;

    for(int i = 0  ; i < 16 ; i++)
        printf("%-10s p=%.2lf%%\n", name[i], ans[i]*100);

    return 0 ;
}