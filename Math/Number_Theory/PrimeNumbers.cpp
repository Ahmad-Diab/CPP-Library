#include <bits/stdc++.h>
#define long long long

using namespace std ;

/*
	 * 1. Sieve of Eratosthenes: generate all primes in [2, N]
*/

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

/*
	 * 2. Primality Test
	 *
	 * Preprocessing: call sieve with sqrt(N), O(sqrt(N) log log sqrt(N)) Query:
	 * best case O(1), worst case O(sqrt(N) / log sqrt(N))
	 */

bool isPrime(int N)
{
    if(N < isComposite.size())
        return isComposite[N] ;

    for(int p : primes)
        if(N % p == 0)
            return 0 ;
    return 1 ;
}
/*
	 * 3. Sieve of Eratostheses in linear time
	 */

void sieveLinear(int N) {
    primes.clear() ;
    int lp [N + 1];
    memset(lp , 0 , sizeof lp) ;

    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
            primes.push_back(i) , lp[i] = i ;

        int curLP = lp[i];

        for (int p : primes)
            if (p > curLP || p * i > N)
                break;
            else
                lp[p * i] = i;
    }
}
