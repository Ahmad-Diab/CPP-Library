#include <bits/stdc++.h>

#define long long long

using namespace std ;

vector<vector<int >> adjMatrix ;
vector<vector<int > > p ;
int V ;

void floyd()
{
    p.assign(V , vector<int > (V)) ;

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            p[i][j] = i;

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
                {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    p[i][j] = p[k][j];
                }



}
void printPath(int i, int j)
{
    if(i != j) 					// use (P[i][j] != i) in case adjMat[i][i] != 0
        printPath(i,p[i][j]);	// i.e. paths of the form 1, 2, 3, 1 are allowed
    cout << j << ' ';
}

int main ()
{
    ios_base :: sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr) ;

    return  0 ;
}