#include <bits/stdc++.h>

using namespace std;

int N ;
vector<int > sz ;
vector<int > depth ;
vector<int > parent ;
vector<vector<int >> adjList ;

int getSize(int u , int p)
{
    sz[u] = 1 ;
    for(int v : adjList[u])
        if(v != p && depth[v] == -1)
            sz[u] += getSize(v , u) ;
    return sz[u] ;
}

int getCentroid(int u , int p , int n)
{
    for(int v : adjList[u])
        if(v != p && depth[v] == -1 && sz[v] * 2 > n)
            return getCentroid(v , u , n) ;
    return u ;
}

int decompose(int u , int lvl)
{
    int centroid = getCentroid(u , -1 , getSize(u , -1)) ;

    depth[centroid] = lvl ;

    for(int v : adjList[centroid])
        if(depth[v] == -1)
            parent[decompose(v , lvl + 1)] = centroid ;
    return centroid ;
}

int main()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    cin >> N  ;
    sz = vector<int >(N , 0);
    depth = vector<int >(N , -1 ) ;
    parent = vector<int >(N );
    adjList.assign(N , vector<int >()) ;
    for(int i  = 0 ; i < N - 1 ;i++) {
        int u , v  ;
        cin >> u >> v ;
        u -- , v -- ;
        adjList[u].push_back(v) ;
        adjList[v].push_back(u) ;
    }

    parent[decompose(0 , 0)] = -1 ;


    return 0;
}