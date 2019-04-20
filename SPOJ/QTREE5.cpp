#include <bits/stdc++.h>

using namespace std;
struct Pair {
	int a, b;
	Pair(int x, int y) {a = x, b = y;}

	bool operator < (const Pair &y) const {
		return y.b < b;
	}
	bool operator () (const Pair &x , const Pair &y) const{
		return y.b < x.b;
	}
};

const int INF = (int) 1e9;
vector<vector<int> > adjList, P;
vector<int> parent, L, ans, sz, depth, color;
int N, K = 20;
vector<priority_queue<Pair> > pq;

void dfs(int u, int p) {
	P[0][u] = p;

	for (int v : adjList[u])
		if (v != p) {
			L[v] = L[u] + 1;
			dfs(v, u);
		}
}
void preprocess() {

	P.assign(K + 1, vector<int>(N, -1));
	L.assign(N, 0);

	dfs(0, -1);

	for (int k = 1; k <= K; k++)
		for (int i = 0; i < N; i++)
			if (P[k - 1][i] != -1)
				P[k][i] = P[k - 1][P[k - 1][i]];
}
int LCA(int p, int q) {
	if (L[p] < L[q]) {
		p ^= q;
		q ^= p;
		p ^= q;
	}

	int remDist = L[p] - L[q];

	for (int i = K; i >= 0; i--)
		if ((remDist & (1 << i)) != 0)
			p = P[i][p];

	if (p == q)
		return p;

	for (int i = K; i >= 0; i--)
		if (P[i][p] != -1 && P[i][p] != P[i][q]) {
			p = P[i][p];
			q = P[i][q];
		}
	return P[0][p];
}
int getDist(int u, int v) {
	return L[u] + L[v] - (L[LCA(u, v)] << 1);
}
int getSize(int u, int p) {
	sz[u] = 1;

	for (int v : adjList[u])
		if (v != p && depth[v] == -1)
			sz[u] += getSize(v, u);

	return sz[u];
}
int getCentroid(int u, int p, int n) {
	for (int v : adjList[u])
		if (v != p && depth[v] == -1 && sz[v] * 2 > n)
			return getCentroid(v, u, n);
	return u;
}
int decompose(int u, int p = -1, int lvl = 0) {
	int centroid = getCentroid(u, -1, getSize(u, -1));

	depth[centroid] = lvl;

	for (int v : adjList[centroid])
		if (depth[v] == -1)
			parent[decompose(v, -1, lvl + 1)] = centroid;
	return centroid;
}

void update(int u) {
	int original = u;
	color[u] ^= 1;
	if (color[u] == 0) {
		while (u != -1) {
			while (!pq[u].empty() && color[pq[u].top().a] == 0)
				pq[u].pop();

			ans[u] = pq[u].empty() ? INF : pq[u].top().b;
			u = parent[u];
		}
	} else {
		while (u != -1) {
			pq[u].push({original, getDist(original, u)});
			while (!pq[u].empty() && color[pq[u].top().a] == 0)
				pq[u].pop();
			ans[u] = min(ans[u], pq[u].top().b);
			u = parent[u];
		}
	}

}

int query(int u) {
	int original = u;
	int ret = INF;
	while (u != -1) {
		ret = min(ret, getDist(original, u) + ans[u]);
		u = parent[u];
	}
	return ret == INF ? -1 : ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	parent.assign(N, 0);
	sz.assign(N, 0);
	depth.assign(N, -1);
	ans.assign(N, INF);
	color.assign(N, 0);
	adjList.assign(N, vector<int>());
	pq.assign(N, priority_queue<Pair>());
	for(int i = 0 ; i < N - 1 ;i++)
	{
		int u , v ; cin >> u >> v ; u -- , v -- ;
		adjList[u].push_back(v) ;
		adjList[v].push_back(u) ;

	}
	preprocess();
	parent[decompose(0)] = -1;

	int m;
	cin >> m;
	while (m-- > 0) {
		int op, num;
		cin >> op >> num;
		if (op == 0)
			update(num - 1);
		else
			cout << query(num - 1)  << '\n';
	}

	return 0;
}
