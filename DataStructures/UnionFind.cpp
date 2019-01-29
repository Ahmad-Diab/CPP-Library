#include <bits/stdc++.h> 

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

    void unionSet(int i, int j) 
	{ 
		if (isSameSet(i, j)) 
			return;
		numSets--; 
		int x = findSet(i), y = findSet(j);
		if(rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else
		{	p[x] = y; setSize[y] += setSize[x];
			if(rank[x] == rank[y]) rank[y]++; 
		} 
	}

    int numDisjointSets() { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};