#include <bits/stdc++.h>

#define long long long
#define VISITED  2
#define EXPLORED  1
#define UNVISITED  0

using namespace std ;

int V ;
vector<bool > visited ;
vector<vector<bool> > adjMat ;
vector<vector<int > > adjList ;

void dfs(int u)
{
    visited[u] = true ;

    for(int v: adjList[u])
        if(!visited[v])
            dfs(v);

    for(int i = 0; i < V; ++i)
        if(adjMat[u][i] && !visited[i])
            dfs(i);


}
void preTraversal()
{
    for(int i = 0 ; i < V ; i++)
    {
        if(!visited[i])
            dfs(i) ;
    }
}


void bfs(int s, int t)
{
    queue<int > q ;
    q.push(s);
    visited[s] = true;
    while(!q.empty())
    {
        int u = q.front() ; q.pop();


        for(int v: adjList[u])
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
    }
}


vector<int > parent, status;
static void edgeType(int u)
{
    status[u] = EXPLORED;
    for(int v: adjList[u])
        if(status[v] == UNVISITED)
        {
            printf("Edge from %d to %d is %s\n", u, v, "tree edge");
            parent[v] = u;
            dfs(v);
        }
        else if(status[v] == VISITED)
            printf("Edge from %d to %d is %s\n", u, v, "forwad/cross edge");
        else if(parent[u] == v)
            printf("Edge from %d to %d is %s\n", u, v, "bidirectional edge");
        else // status-> EXP  & par[u] != v
        {
            printf("Edge from %d to %d is %s\n", u, v, "back edge");
            printf("Cycle!\n");
        }
    status[u] = VISITED;
}

vector<int > color;
bool bipartitieCheck(int u)
{
    for(int v: adjList[u])
        if(color[v] == -1)
        {
            color[v] = 1 ^ color[u];
            if(!bipartitieCheck(v))
                return false;
        }
        else
        if(color[v] == color[u])
            return false;
    return true;
}

static vector<vector<char > > grid;
static int R, C;
int dx [4]= {-1, 1, 0, 0};
int dy [4] = {0, 0, -1, 1};

bool valid(int i, int j , int R , int C)
{
    return i != -1 && j != -1 && i != R && j != C && grid[i][j] == '.';
}

void dfs2(int i, int j)
{
    grid[i][j] = 'X';
    for(int k = 0; k < 4; ++k)
    {
        int x = i + dx[k], y = j + dy[k];
        if(valid(x, y , R , C) && grid[x][y] != 'X')
            dfs2(x, y);
    }
}

stack<int > st ;

void toposortDFS(int u)
{
    visited[u] = true;

    for(int v: adjList[u])
        if(!visited[v])			//if v is explored -> failure, not a DAG!
            dfs(v);
    st.push(u);
}

vector<int > sortedArray ;

void toposortBFS()
{
    int p [V];
    memset(p , 0 , sizeof p) ;

    for(int i = 0; i < V; ++i)
        for(int v: adjList[i])
            ++p[v];
    queue<int > roots ;

    for(int i = 0; i < V; ++i)
        if(p[i] == 0)
            roots.push(i);

    while(!roots.empty())
    {
        int u = roots.front(); roots.pop() ;
        sortedArray.push_back(u);
        for(int v: adjList[u])
            if(--p[v] == 0)
                roots.push(v);
    }

}


int main ()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    return  0 ;
}