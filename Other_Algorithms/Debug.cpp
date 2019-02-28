#include <bits/stdc++.h>
#define long long long

using namespace std ;

string to_string(string s){return '"' + s + '"';}

string to_string(const char* s) { return to_string((string) s);}

string to_string(bool b) { return (b ? "true" : "false");}

template <typename A, typename B>
string to_string(pair<A, B> &p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A>
string to_string(A &v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef ONLINE_JUDGE
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

int main()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    vector<int > vec ;
    vec.push_back(2) ;
    vec.push_back(3) ;
    vec.push_back(4) ;
    
    debug(vec) ;


    return  0 ;

}

