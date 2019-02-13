#include <bits/stdc++.h>
#define long long long

using namespace std ;

int modPow(long b, int e , int mod)
{
    long res = 1;
    while(e > 0)
    {
        if((e & 1) == 1)
            res = res * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    res %= mod ;
    return (int)res;
}

int getphi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
int generator (int p)
{
    vector<int > list ;

    int phi = getphi(p) ;
    int temp = phi ;

    for(int i = 2 ; 1l * i * i <= temp ;i++)
    {
        if(temp % i != 0) continue ;

        list.push_back(i);

        while(temp % i == 0) temp /= i ;

    }

    if(temp > 1)
        list.push_back(temp) ;

    for(int ans = 2 ; ans <= p ; ans ++)
    {
        bool ok = true ;
        for(int i = 0 ; i < list.size() && ok; i++)
            if(modPow(ans, phi / list[i], p) == 1) ok = false ;

        if(ok) return ans ;
    }
    
    return -1 ;

}
