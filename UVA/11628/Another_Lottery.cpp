#include <bits/stdc++.h>
#define long long long

using namespace std ;

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr);

    while(true)
    {
        int n , m;

        cin >> n >> m ;

        if(!n && !m) break ;

        int arr [n] ;

        for(int i = 0 ; i < n ; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i];


        int total = 0 ;

        for(int i = 0 ; i < n ;i++) total += arr[i];


        for(int i = 0 ; i < n ; i++)
        {
            int g = __gcd(arr[i] , total) ;
            cout << arr[i] / g << " / " << total / g <<'\n' ;
        }

    }
    return 0 ;
}