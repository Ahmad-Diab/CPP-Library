#include <bits/stdc++.h>
#define long long long

using namespace std ;

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    int cases = 1 ;
    while(true)
    {
        int B , S  ;
        cin >> B >> S ;
        if(!B && !S) break;
        cout << "Case "<< cases++ << ": ";

        if(B == 1)
            cout << ":-\\\n" ;
        else if(S >= B)
            cout << ":-|\n" ;
        else if(1ll * S * (B - 1) < 1ll * B * (S - 1))
            cout << ":-)\n" ;
        else if(1ll * S * (B - 1) > 1ll * B * (S - 1))
            cout << ":-(\n" ;
        else  if(1ll * S * (B - 1) == 1ll * B * (S - 1))
            cout << ":-|\n" ;
    }
    return 0;
}