#include <bits/stdc++.h>
#define long long long

using namespace std ;

int len , n ;
vector<int > ans ;
vector<int > arr ;

bool canMake(int idx , int taken , int tot)
{
    if(taken == n) return tot % n == 0 ;

    if(idx == len) return tot % n == 0 && taken == n;

    ans[taken] = arr[idx] ;

    if(canMake(idx + 1 , taken + 1 , tot + arr[idx])) return true ;

    if(canMake(idx + 1 , taken , tot))return true ;

    
    return false ;
}

int main()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    while(true)
    {
        cin >> n ;
        if(!n) break ;

        len = (n  * 2) - 1 ;

        arr.assign(len , 0) ;
        ans.assign(n , 0) ;

        for(int &x : arr) cin >> x ;

        if(canMake(0 , 0 , 0))
        {
            cout << "Yes\n" ;
            for(int i = 0 ;i < n ;i++)
            {
                if(i > 0) cout << " " ;
                cout << ans[i] ;
            }
            cout << "\n" ;

        }
        else
            cout << "No\n" ;
    }

    return 0 ;
}