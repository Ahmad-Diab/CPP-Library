#include <bits/stdc++.h>

#define long long long

using namespace std ;

vector<vector<int > > adjList , tree ;
stack<int > stack1 ;
vector<int > dfs_low , dfs_num , bridgeComp ;
int V, counter ;

void extract(int u)
{
    while(true)
    {
        int v = stack1.top(); stack1.pop();
        bridgeComp[v] = u;
        if(v == u)
            break;
    }
}
void dfs(int u, int p)
{
    dfs_num[u] = dfs_low[u] = ++counter;
    stack1.push(u);

    for(int v: adjList[u])
        if(v != p) {
            if (dfs_num[v] == 0) {
                dfs(v, u);
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                if (dfs_low[v] > dfs_num[u])
                    extract(v);
            } else

                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    if(p == -1)
        extract(u);
}


void bridgeTree()
{
    counter = 0;
    dfs_low.assign(V , 0);
    dfs_num.assign(V , 0);
    bridgeComp.assign(V , 0 );
    tree.assign(V , vector<int >()) ;

    for(int i = 0; i < V; ++i)
        if(dfs_num[i] == 0)
            dfs(i, -1);
    for(int u = 0; u < V; ++u)
        for(int v: adjList[u])
        {
            int x = bridgeComp[u], y = bridgeComp[v];
            if(x != y)
                tree[x].push_back(y);
        }
}

int main ()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    return  0 ;
}