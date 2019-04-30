#include <bits/stdc++.h>

using namespace std ;

int main() {
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    int n ;
    cin >> n ;
    vector<int > cnt (n , 0);
    vector<int > color(n , 0) ;
    vector<bool > big(n , false) ;
    vector<int > sz(n , 0) ;
    vector<vector<int > > adjList(n , vector<int >()) ;
    for(int &x : color)
        cin >> x ;
    function<void (int , int  , int ) >add = [&](int u , int p , int x)
    {
        cnt[color[u]] += x ;
        for(int v : adjList[u])
            if(v != p && !big[u])
                add(v , u , x) ;
    };
    function<void (int , int  , int ) >dfs = [&](int u , int p , bool keep)
    {
        int mx = -1 , bigChild = -1 ;
        for(int v: adjList[u])
            if(v != p && sz[v] > mx)
                mx = sz[bigChild = v] ;
        for(int v : adjList[u])
            if(v != p && v != bigChild)
                dfs(v , u , 0) ;
        if(bigChild != -1)
            dfs(bigChild , u , 1) , big[bigChild] = 1 ;
        add(u , p , 1) ;
        // answer query
        
        if(bigChild != -1)
            big[bigChild] = 0 ;
        if(!keep)
            add(u , p , -1) ;
    };
    
    return 0 ;
}