#include <bits/stdc++.h>
#define long long long

using namespace std ;

int getDerangement(int k)
{
    if(k <= 1) return k ^ 1 ;

    return (k - 1) * (getDerangement(k - 1) + getDerangement(k - 2)) ;
}


int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    int TC , n ;
    cin >> TC ;

    while(TC --)
    {
        cin >> n ;

        int sampleSpace = 1 ,event = getDerangement(n);

        for(int i = 2 ; i <= n ; i++)sampleSpace *= i ;

        cout << getDerangement(n) <<'/' << sampleSpace << '\n';

    }

}