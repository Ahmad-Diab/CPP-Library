#include <bits/stdc++.h>

using namespace std ;

int main()
{
    double cars , cows , show ;

    while(cin >> cows >> cars >> show)
        printf("%.5lf\n", ((cows / (cars + cows)) * (cars / (cars + cows - show - 1))) + ((cars / (cars + cows)) * ((cars - 1)/ (cars + cows - show - 1))));

    return 0 ;
}