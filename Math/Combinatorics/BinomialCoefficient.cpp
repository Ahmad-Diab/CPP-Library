#include <bits/stdc++.h>
#define long long long

using namespace std ;

vector<vector<long >> comb ;

// Top-down approach

long nCr(int n , int k)
{
    if(n < k)return 0 ;

    if(k == 0 || k == n )return 1 ;

    long &ret = comb[n][k] ;

    if(~ret) return ret ;

    ret = 0 ;

    if(n - k < k) return ret = nCr(n , n - k) ;

    return ret = nCr(n - 1 , k - 1 ) + nCr(n - 1 , k) ;
}

// Bottom-up approach

void nCr2 (int N) // O(N ^ 2)
{
    comb.assign(N , vector<long  > (N)) ;

    comb[0][0] = 1;

    for(int i = 1 ; i < N ; i++)
    {
        comb[i][0] = 1 ;

        for(int j = 1 ; j <= i ; j++)
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1] ;
    }
}

// Multiplicative formula: iterative

long nCr3(int N , int K) // O(K)
{
    if(K > N)return 0 ;

    long res = 1 ;

    for(int i = 1 ; i <= K ; i++)
        res = (N - K + i) * res / i ;

    return res ;
}

// Multiplicative formula: with modInv


long modPow(long b, int e , int mod)
{
    long res = 1;
    while(e > 0)
    {
        if((e & 1) == 1)
            res = res * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return res;
}
long nCr4(int N, int K , int mod)
{
    if(K > N)
        return 0;
    long res = 1;
    for(int i = 1; i <= K; ++i)
        res = (N - K + i) * res % mod * modPow(i, mod - 2 , mod) % mod;
    return (int)res;
}
