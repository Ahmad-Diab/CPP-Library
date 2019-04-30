#include <bits/stdc++.h>

using namespace std ;

int main() {
    int idx = 1 ;
    while(true){
        int N ;
        cin >> N ;
        if(!N)break;
        long long ans = 0 ;
        for(int r = 1 ; r <= N ; r++)
        {
            int from = N - 2 * r - 1 ;
            int to = (N - r) / 2 ;
            from = N - r - from ;
            to = N - r - to ;
            if(to <= from) break;
            ans += to - from  ;
        }
        printf("Case %lld: %lld\n",idx ++ , ans);
    }
    return 0 ;
}