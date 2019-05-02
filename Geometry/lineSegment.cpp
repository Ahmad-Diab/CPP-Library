#include <bits/stdc++.h>

using namespace std ;

const double EPS  = 1e-9;
const double PI = acos(-1.0);

struct lineSegment{
    point <double> p , q ;
    lineSegment(point<double> p , point<double>q) : p(p) , q(q){}
    bool intersect(lineSegment ls)
    {
        line l1 = line(p, q), l2 = line(ls.p, ls.q);
        if(l1.parallel(l2))
        {
            if(l1.same(l2))
                return p.between(ls.p, ls.q) || q.between(ls.p, ls.q) || ls.p.between(p, q) || ls.q.between(p, q);
            return false;
        }
        point<double> c = l1.intersect(l2);
        return c.between(p, q) && c.between(ls.p, ls.q);
    }
};

int main() {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    return 0 ;
}