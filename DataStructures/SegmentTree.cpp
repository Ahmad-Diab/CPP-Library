#include <bits/stdc++.h> 

using namespace std ; 

struct SegmentTree
{
    int N  , *array , *sTree , *lazy;

    SegmentTree(int *in , int len)
    {
        array = in  , N = len - 1;
        sTree = new int [N << 1] ; 
        lazy = new int [N << 1] ; 
        build(1 , 1 , N) ;  
    }

    void build(int node ,  int b , int e)
    {
        if(b == e)
            sTree[node] = array[b] ; 
        else
        {
            int mid = b + e >> 1 ; 
            build(node << 1 , b , mid) ; 
            build(node << 1 | 1 , mid + 1 , e) ;
          	sTree[node] = sTree[node<<1]+sTree[node<<1|1];
		 
        }
        
    }
    void update_point(int index, int val)		
	{
		index += N - 1;				
		sTree[index] += val;			
		while(index>1)				
		{
			index >>= 1;
			sTree[index] = sTree[index<<1] + sTree[index<<1|1];		
		}
	}
    void update_range(int i, int j, int val)		
	{
		update_range(1,1,N,i,j,val);
	}
	
	void update_range(int node, int b, int e, int i, int j, int val)
	{
		if(i > e || j < b)		
			return;
		if(b >= i && e <= j)		
		{
			sTree[node] += (e-b+1)*val;			
			lazy[node] += val;				
		}							
		else		
		{
			int mid = b + e >> 1;
			propagate(node, b, mid, e);
			update_range(node<<1,b,mid,i,j,val);
			update_range(node<<1|1,mid+1,e,i,j,val);
			sTree[node] = sTree[node<<1] + sTree[node<<1|1];		
		}
		
	}
    void propagate(int node, int b, int mid, int e)		
	{
		lazy[node<<1] += lazy[node];
		lazy[node<<1|1] += lazy[node];
		sTree[node<<1] += (mid-b+1)*lazy[node];		
		sTree[node<<1|1] += (e-mid)*lazy[node];	
		
		lazy[node] = 0;
		
	}
	
	int query(int i, int j)
	{
		return query(1,1,N,i,j);
	}
	
	int query(int node, int b, int e, int i, int j)
	{
		if(i>e || j <b)
			return 0;		
		if(b>= i && e <= j)
			return sTree[node];
		int mid = b + e >> 1;
		propagate(node, b, mid, e);
		
		int q1 = query(node<<1,b,mid,i,j);
		int q2 = query(node<<1|1,mid+1,e,i,j);
		return q1 + q2;	
				
	}
	
	

};

// MIN 

struct SegmentTreeMIN
{
    int N  , *array , *sTree , *lazy;

    SegmentTreeMIN(int *in , int len)
    {
        array = in  , N = len - 1;
        sTree = new int [N << 1] ; 
        memset(sTree , (1 << 31) - 1 , sizeof sTree);
        lazy = new int [N << 1] ; 
        build(1 , 1 , N) ;  
    }
    void merge(int node)
    {
         	sTree[node] = min(sTree[node<<1],sTree[node<<1|1]);
		 
    }
    void build(int node ,  int b , int e)
    {
        if(b == e)
            sTree[node] = array[b] ; 
        else
        {
            int mid = b + e >> 1 ; 
            build(node << 1 , b , mid) ; 
            build(node << 1 | 1 , mid + 1 , e) ;
            merge(node);

        }
        
    }

    void update_point(int index, int val)		
	{
		index += N - 1;				
		sTree[index] += val;			
		while(index>1)				
		{
			index >>= 1;
            merge(index);
		}
	}
    void update_range(int i, int j, int val)		
	{
		update_range(1,1,N,i,j,val);
	}
	
	void update_range(int node, int b, int e, int i, int j, int val)
	{
		if(i > e || j < b)		
			return;
		if(b >= i && e <= j)		
		{
			sTree[node] += val;			
			lazy[node] += val;				
		}							
		else		
		{
			int mid = b + e >> 1;
			propagate(node, b, mid, e);
			update_range(node<<1,b,mid,i,j,val);
			update_range(node<<1|1,mid+1,e,i,j,val);
			merge(node);
            	
		}
		
	}
    void propagate(int node, int b, int mid, int e)		
	{
		lazy[node<<1] += lazy[node];
		lazy[node<<1|1] += lazy[node];
		sTree[node<<1] += lazy[node];		
		sTree[node<<1|1] += lazy[node];	
		lazy[node] = 0;
		
	}
	
	int query(int i, int j)
	{
		return query(1,1,N,i,j);
	}
	
	int query(int node, int b, int e, int i, int j)
	{
		if(i>e || j <b)
			return 0;		
		if(b>= i && e <= j)
			return sTree[node];
		int mid = b + e >> 1;
		propagate(node, b, mid, e);
		
		int q1 = query(node<<1,b,mid,i,j);
		int q2 = query(node<<1|1,mid+1,e,i,j);
		return min(q1 , q2);	
				
	}
	
	

};

