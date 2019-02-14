#include <bits/stdc++.h>
#define long long long

using namespace std ;

vector<vector<int > > adjList ;
int V , counter  , SCC ;
vector<int > dfs_num , dfs_low ;
vector<bool > inSCC ;
stack<int > stack1 ;

void tarjanSCC(int u)
{
    dfs_num[u] = dfs_low[u] = ++counter;
    stack1.push(u);

    for(int v: adjList[u])
    {
        if(!dfs_num[v])
            tarjanSCC(v);
        if(!inSCC[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_num[u] == dfs_low[u])
    {
        SCC++;
        while(true)
        {
            int v = stack1.top(); stack1.pop() ;
            inSCC[v] = true;
            if(v == u)
                break;
        }
    }
}

void tarjanSCC()
{
    for(int i = 0; i < V; ++i)
        if(dfs_num[i] == 0)
            tarjanSCC(i);
}


int main ()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    return  0 ;
}