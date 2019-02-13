#include <bits/stdc++.h>
#define long long long

using namespace std ;

inline int mult(int a, int b , int mod)
{
    return (int) ((1ll * a * b ) % mod) ;
}

long discreteLog (int a , int b , int mod)
{   // a ^ (np) = b a ^ q(mod m)

    if(b == 1) return 0 ;

    int n = (int)sqrt(mod) + 1 , an = 1;

    unordered_map<int , int> mp ;  // values of a ^ pq -> p

    for(int i = 0 ; i < n ; i++) an = mult(an, a, mod) ;

    for(int p = 1 , curr = an ; p <= n ; p++ , curr = mult(curr, an, mod)) mp[curr] =  p;

    for(int q = 0 , curr = b; q <= n ; q ++ , curr = mult(curr, a, mod))
        if(mp.find(curr) != mp.end())
            return 1l * n * mp[curr] - q ;

    return -1 ;

}