#include <bits/stdc++.h>
#define long long long  

using namespace std ; 

int getDerangement(int k)
{
    if(k <= 1) return k ^ 1 ;

    return (k - 1) * (getDerangement(k - 1) + getDerangement(k - 2)) ;
}
