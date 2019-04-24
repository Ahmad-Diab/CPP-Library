#include <bits/stdc++.h>

using namespace std;

int N , chainNo , sIdx , K;
vector<int > nodeVal ;
vector<int > chainHead;
vector<int > chainIdx ;
vector<int > segIdx ;
vector<int > subSize ;
vector<int > L ;
vector<vector<int > >adjList ;
vector<vector<int > > P ;

template <typename T >
struct SegementTree
{
    vector<T > sTree , array ;
    int N ;
    T defaultVal ;
    SegementTree() {};

    SegementTree(vector<T > &in , T d)
    {
        N = int(in.size()) - 1 ;
        d = defaultVal ;
        // don't forget to initialize default value
        array = in ;
        sTree = vector<int >(N << 1 , defaultVal) ;
        build(1 , 1 , N) ;
    };
    inline void combine(int node ){sTree[node] = sTree[node << 1] + sTree[node << 1 | 1] ;}
    inline T combine(T left , T right){return left + right ;}

    void build(int node , int b , int e)
    {
        if(b == e)
            sTree[node] = array[b] ;
        else
        {
            int mid = b+ e >> 1 ;
            build(node << 1 , b , mid) ;
            build(node << 1 | 1 , mid + 1 , e) ;
            combine(node) ;
        }
    }

    void update_point(int node , int val)
    {
        node += N - 1 ;
        sTree[node] = val ;

        while(node > 1)
        {
            node >>= 1 ;
            combine(node) ;
        }
    }
    T query(int node , int b , int e , int i , int j)
    {
        if(e < i || j < b) return defaultVal ;
        if(b <= i && j <= e) return sTree[node] ;
        int mid = b + e >> 1 ;
        return combine(query(node << 1 , b , mid , i , j) , query(node << 1 | 1 , mid + 1 , i , j)) ;
    }
    T query(int i , int j){ return query(1 , 1 , N , i , j) ;}
};
SegementTree <int > st ;
int dfs(int u , int p )
{
    P[0][u] = p ;
    subSize[u] = 1 ;
    for(int v : adjList[u])
        if(v != p)
        {
            L[v] = L[u] + 1 ;
            subSize[u] += dfs(v , u ) ;
        }
    return subSize[u] ;
}
void hld(int u , int p)
{
    if(u == p) chainHead[chainNo] = u ;
    chainIdx[u] = chainNo ;
    segIdx[u] = ++sIdx ;

    int heavy = -1 , maxSize = -1 ;

    for(int v : adjList[u])
        if(v != P[0][u] && maxSize < subSize[v])
            maxSize = subSize[heavy = v] ;

    if(~heavy) hld(heavy , p) ;

    for(int light : adjList[u])
        if(light != P[0][u] && light != heavy)
            chainNo ++ , hld(light , light) ;

}
void preprocess(int root = 0)
{
    K = 0 , chainNo = 0 , sIdx = 0;
    while(1 << (K + 1) <= N) K ++ ;
    P.assign(K + 1 , vector<int >(N)) ;
    subSize = vector<int >(N) ;
    L = vector<int >(N) ;
    nodeVal = vector<int > (N) ;
    chainHead = vector<int > (N);
    chainIdx = vector<int >(N) ;
    segIdx = vector<int >(N) ;

    dfs(root , -1) ;

    for(int i = 1 ; i <= K ; i++)
        for(int j = 0 ; j < N ; j++)
            if(P[i - 1][j] != -1)
                P[i][j] = P[i - 1][P[i - 1][j]] ;

    hld(root , root);

    int n = 1 ; while(1 << n < N )n <<= 1 ;
    int defaultVal = 0 ;
    vector<int > in(n , defaultVal) ;
    for(int i = 0 ; i < N ; i++)
        in[segIdx[i]] = nodeVal[i] ;

    st = SegementTree(in , defaultVal) ;
}
int getLCA(int p , int q)
{
    if(L[p] < L[q]) swap(p , q) ;

    for(int i = K;  i>=0 ; i--)
        if(L[p] - (1 << i) >= L[q])
            p = P[i][p] ;

    if(p == q)return p ;

    for(int i = K ; i >= 0 ; i --)
        if(P[i][p] != -1 && P[i][p] != P[i][q])
            p = P[i][p] , q = P[i][q] ;
    return P[0][p] ;
}
int query_up(int u , int v)
{
    int uChain = chainIdx[u] , vChain = chainIdx[v] , ans = 0;

    while(uChain != vChain)
    {
        ans += st.query(segIdx[chainHead[vChain]] , segIdx[v]) ;
        v = P[0][chainHead[vChain]] ;
        vChain = chainIdx[v] ;
    }
    return ans + st.query(segIdx[u] , segIdx[v]) ;
}
int query(int u , int v)
{
    int lca = getLCA(u , v) ;
    return query_up(lca , u) + query_up(lca , v) - nodeVal[lca] ;
}
void update(int node , int val)
{
    nodeVal[node] = val ;
    st.update_point(node , val) ;
}

int main()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    cin >> N ;
    nodeVal = vector<int >(N) ;
    for(int &x : nodeVal) cin >> x ;
    adjList.assign(N , vector<int >()) ;

    for(int i = 0 ; i < N - 1 ; i++)
    {
        int u , v ; cin >> u >> v ;
        adjList[u].push_back(v) ;
        adjList[v].push_back(u) ;
    }

    preprocess();
    
    return 0;
}