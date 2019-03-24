#include <bits/stdc++.h>

#define PI acos(-1.0)

using namespace std ;

int main()
{

    string s ;

    getline(cin , s) ;

    istringstream sss(s) ;

    int TC ;

    sss >> TC ;

    while(TC--)
    {

        double r1 , r2 , t  ;

        bool f = 0 ;
        getline(cin , s) ;
        istringstream ssss(s) ;

        for(char c : s) if(c == ' ') f = true;



        if(f)
        {

            ssss >> r1 >> r2 ;
            double R = r1 + r2 ;

            double ans =  PI * R * R - PI * r1 * r1 - PI * r2 * r2 ;

            printf("%.4f\n" , ans) ;
        }
        else
        {
            ssss >> t ;
            double R = t / 2 ;
            r1 = r2 = R / 2 ;

            double ans =  PI * R * R - PI * r1 * r1 - PI * r2 * r2 ;

            printf("%.4f\n" , ans) ;
        }

    }
    return 0 ;
}