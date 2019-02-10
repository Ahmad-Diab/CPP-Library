#include <bits/stdc++.h> 
#define long long long 

using namespace std ; 

vector<long > catalan ; 

long cat(int n)
{
    if(n <= 1)return 1 ; 

    long &ret = catalan[n] ;

    if(~ret) return ret ; 

    ret = 0 ; 

    for(int i = 0 ; i  < n ;i++)
        ans += catalan(n - i - 1) * catalan(i) ; 

    return ans ; 
}