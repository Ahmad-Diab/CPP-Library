#include <bits/stdc++.h>

using namespace std ;

int main()
{
    string s ;

    while(cin >> s)
    {
        list <string >l ;
        string curr ;
        bool lst = 1 ;

        for(char c : s)
        {
            if(c != '[' && c != ']')
                curr += c ;
            else if(c == '[') {
                if(lst)
                    l.push_back(curr) ;
                else
                    l.push_front(curr) ;

                curr = "" ;
                lst = 0;
            }
            else {
                if(lst)
                    l.push_back(curr) ;
                else
                    l.push_front(curr) ;

                curr = "" ;
                lst = 1;
            }

        }
        if(!curr.empty()) {
            if (lst)
                l.push_back(curr);
            else
                l.push_front(curr);
        }

        while (!l.empty()) {
            cout << *l.begin() ;
            l.pop_front();

        }
        cout << '\n' ;
    }

    return 0 ;
}