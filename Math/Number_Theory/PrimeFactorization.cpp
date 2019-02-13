#include <bits/stdc++.h>
#define long long long

using namespace std ;

vector<int > primes ;
vector<bool > isComposite ;

void sieve(int N)
{
    isComposite.assign(N + 1, 0) ;
    isComposite[0] = isComposite[1] = 1 ;
    primes.clear() ;

    for(int i = 2 ; i <= N ; i++)
        if(!isComposite[i])
        {
            primes.push_back(i) ;

            if(1ll * i * i <= N)
                for(int j = i * i ; j <= N ; j+= i)
                    isComposite[j] = 1 ;
        }

}
vector<int > primeFactors(int N)
{
    vector<int > factors ;
    int idx = 0 , p = primes[idx] ;

    while(1ll * p * p <= N)
    {
        while(N % p == 0){factors.push_back(p); N /= p ; }

        p = primes[++idx] ;
    }
    if(N > 1)
        factors.push_back(N) ;

    return factors;
}
long pw(long a, int n)
{
    long res = 1;
    while(n != 0)
    {
        if((n & 1) == 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}
long sumDiv(int N)
{
    int idx = 0, p = primes[0];
    long ans = 1;
    while(p * p <= N)
    {
        int e = 0;
        while(N % p == 0) { N /= p; ++e; }
        ans *= (pw(p, e + 1) - 1) / (p - 1);
        p = primes[++idx];
    }
    if(N != 1)
        ans *= (pw(N, 2) - 1) / (N - 1);
    return ans;
}
int phi(int N)
{
    int ans = N, idx = 0, p = primes[0];
    while(p * p <= N)
    {
        if(N % p == 0)
            ans -= ans / p;
        while(N % p == 0)
            N /= p;
        p = primes[++idx];
    }

    if(N != 1)
        ans -= ans / N;
    return ans;
}


long numDiv(long N)
{
    long PF_idx = 0 , PF = primes[int(PF_idx)] , ans = 1;

    while(PF * PF <= N)
    {
        long power = 0 ;
        while (N % PF == 0)
            N /= PF , power ++ ;

        ans *= (power + 1);
        PF = primes[int(++PF_idx)];
    }
    if (N != 1)
        ans *= 2;
    return ans;
}


int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr);



    return 0 ;
}