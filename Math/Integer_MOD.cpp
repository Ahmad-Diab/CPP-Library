#include <bits/stdc++.h>

using namespace std ;

struct Integer{
    int x ;
    int MOD = 1e9 + 7 ;
    Integer(){}
    Integer(int x): x(x) {}
    bool operator < (const int y) { return x < y ;}
    bool operator < (const Integer y) { return x < y.x ;}
    bool operator > (const int y) { return x > y ;}
    bool operator > (const Integer y) { return x > y.x ;}
    bool operator <= (const int y) { return x <= y ;}
    bool operator <= (const Integer y) { return x <= y.x ;}
    bool operator >= (const int y) { return x >= y ;}
    bool operator >= (const Integer y) { return x >= y.x ;}
    bool operator == (const int y) { return x == y ;}
    bool operator == (const Integer y) { return x == y.x ;}
    bool operator != (const int y) { return x != y ;}
    bool operator != (const Integer y) { return x != y.x ;}
    int operator + (const int y) { int ans = x + y ; if(ans >= MOD) return ans -= MOD ; return ans ;}
    int operator - (const int y) { int ans = x - y ; if(ans < 0) return ans += MOD ; return ans ;}
    int operator * (const int y) { return (1ll * x * y) % MOD ;}
    int operator + (const Integer y) {int ans = this->x + y.x ; if(ans >= MOD) return ans -= MOD ; return ans ;}
    int operator - (const Integer y) {int ans = this->x - y.x ; if(ans < 0) return ans += MOD ; return ans ;}
    int operator * (const Integer y) { return (1ll * this->x * y.x) % MOD ;}
    int operator ~ (){ return ~x ;}
    int operator += (const int y){ return *this + y;}
    int operator *= (const int y){ return *this * y;}
    int operator -= (const int y){ return *this - y;}
    int operator += (const Integer y){ return *this + y;}
    int operator *= (const Integer y){ return *this * y;}
    int operator -= (const Integer y){ return *this - y;}
    int operator ++  (){ return (*this + Integer(1)) ;}
    int operator --  (){ return *this - Integer(1) ;}
    Integer powMod(int a , int e)
    {
        Integer ans = 1 ;
        while(e > 0)
        {
            if(e & 1)
                ans *= a ;
            a *= a ;
            e >>= 1;
        }
        return ans ;
    }
    Integer powMod(Integer a , int e)
    {
        Integer ans = 1 ;
        while(e > 0)
        {
            if(e & 1)
                ans *= a ;
            a *= a ;
            e >>= 1;
        }
        return ans ;
    }
    int operator / (const int y){ return *this * powMod(y , MOD - 2) ;}
    int operator / (const Integer y){ return *this * powMod(y , MOD - 2) ;}
    int operator /= (const int y){ return *this / y ;}
    int operator /= (const Integer y){ return *this / y ;}
    int operator % (const int y){ return x % y ;}
    int operator % (const Integer y){ return x % y.x ;}
    int operator %= (const int y){ return x % y ;}
    int operator %= (const Integer y){ return x % y.x ;}
};
istream& operator>>(istream &in, Integer& i){
    in >> i.x ;
    return in;
}
ostream& operator<<(ostream &out, const Integer& i){
    out << i.x ;
    return out;
}

int main() {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    return 0 ;
}
