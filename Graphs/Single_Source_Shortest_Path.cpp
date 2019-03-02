#include <bits/stdc++.h>

#define long long long
#define INF int(1e9)
#define Edge pair<int , int >
#define to(p) p.second
#define cost(p) p.first

using namespace std ;

vector<vector<Edge > > adjList ;
int V ;

int dijkstra(int S, int T)
{
    int dist [V];
    memset(dist, INF , sizeof dist);

    priority_queue< Edge, vector<Edge >, greater<Edge > > pq ;

    dist[S] = 0;

    pq.push(Edge(0, S));

    while(!pq.empty())
    {
        Edge cur = pq.top(); pq.pop() ;

        if(to(cur) == T) return dist[T];
        if(cost(cur) > dist[to(cur)])continue;

        for(Edge nxt: adjList[to(cur)])
            if(cost(cur) + cost(nxt) < dist[to(nxt)])
                pq.push(Edge(dist[to(nxt)] = cost(curr) + cost(nxt)  , to(nxt)));
    }
    return -1;
}

bool bellmanFord(int S)
{
    int dist [V];
    memset(dist, INF , sizeof dist);
    dist[S] = 0;
    bool modified = true ;

    for(int k = 0; modified && k < V - 1; ++k)
    {
        modified = false;
        for(int u = 0; u < V; ++u)
            for(Edge nxt: adjList[u])
                if(dist[u] + cost(nxt) < dist[to(nxt)])
                {
                    modified = true;
                    dist[to(nxt)] = dist[u] + cost(nxt);
                }
    }

    bool hasNegCycle = false;
    for(int u = 0; u < V; ++u)
        for(Edge nxt: adjList[u])
            if(dist[u] + cost(nxt) < dist[to(nxt)])
                hasNegCycle = true;

    return hasNegCycle;

}

int main ()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    return  0 ;
}