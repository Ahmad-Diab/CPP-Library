#include <bits/stdc++.h>
#define long long long

using namespace std ;

int N ;
vector<vector<int > > adjList , dp_down;
vector<int > dp_up ;
vector<bool > vis ;

void dfs1(int u , int p = -1)
{
    for (int v : adjList[u]) {
        if (v == p)
            continue;

        dfs1(v, u);

        dp_down[u][0] = dp_down[v][2] + 1;

        sort(dp_down[u].begin() , dp_down[u].end());
    }


}

void dfs2(int u, int p = -1) {

    for (int v : adjList[u]) {
        if (p == v)
            continue;

        int down_use = dp_down[u][2];

        if (down_use  == dp_down[v][2] + 1)
            down_use = dp_down[u][1];

        dp_up[v] = 1 + max(dp_up[u], down_use  );

        dfs2(v, u);

    }

}

int getDiameter()
{
    dp_down.assign(N , vector<int > (3)) ;
    dp_up.assign(N , 0) ;

    dfs1(0) ;
    dfs2(0) ;

    int diameter = 0 ;

    for(int i = 0 ; i < N ;i++)
        diameter = max(diameter , dp_up[i] + dp_down[i][2]) ;

    return diameter ;
}

int findRoot()
{
    int deg[N] ;
    memset(deg , 0 , sizeof deg) ;
    queue<int > q ;

    for(int i = 0 ; i < N ; i++)
        if((deg[i] = int(adjList[i].size())) == 1)
            q.push(i);

    int root = 0 ;
    while(!q.empty())
    {
        root = q.front(); q.pop() ;
        for(int v : adjList[root])
            if(--deg[v] == 1)
                q.push(v);
        
    }
    return root;


}

int main ()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;




    return  0 ;
}