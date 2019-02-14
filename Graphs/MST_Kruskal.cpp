#include <bits/stdc++.h>

#define long long long

#define INF int(1e9)
#define Edge tuple <int , int ,int >
#define w(p) get<0>(p)
#define u(p) get<1>(p)
#define v(p) get<2>(p)

using namespace std ;

struct UnionFind
{
    int *p , *rank , *setSize , numSets;

    UnionFind(int N)
    {
        p = new int[numSets = N];
        rank = new int[N];
        setSize = new int[N];
        for (int i = 0; i < N; i++) {  p[i] = i; setSize[i] = 1; }
    }

    int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    bool unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return false;
        numSets--;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
        else
        {	p[x] = y; setSize[y] += setSize[x];
            if(rank[x] == rank[y]) rank[y]++;
        }
        return true;
    }

    int numDisjointSets() { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vector<Edge > edgeList ;
int V ;

int kruskal()
{
    int mst = 0;
    sort(edgeList.begin() , edgeList.end());
    UnionFind uf (V);

    for(Edge e: edgeList)
        if(uf.unionSet(u(e), v(e)))
            mst += w(e);
    return mst;
}

int main ()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    return  0 ;
}