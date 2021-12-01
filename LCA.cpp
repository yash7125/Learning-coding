#include<bits/stdc++.h>
using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 + 1;
const int M = 22;
vector<int> gr[N];
int dep[N], parent[N][M];

void dfs(int src,int par)
{
	dep[src] = dep[par] + 1;

	parent[src][0] = par;

	for(int j = 1; j < M; j++)
	{
		parent[src][j] = parent[parent[src][j-1]][j-1];
	}

	for(auto x : gr[src]) {
		if(x != par) {
			dfs(x, src);
		}
	}

}

int find(int u,int v)
{
	if(u==v) return u;

	if(dep[u] < dep[v]) swap(u, v);

	int diff = dep[u] - dep[v];

	for(int i = M-1; i >= 0; i--)
	{
		if((diff >> i) & 1) {
			u = parent[u][i];
		}
	}

	for(int i = M-1; i >= 0; i--)
	{
		if(parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];

}

int len(int u,int v)
{
	int lca = find(u, v);
	int ans = dep[u] - dep[lca] + dep[v] - dep[lca];
	return ans;
}

int main()
{	
	c_p_c();
	int n;
	cin >> n;

	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1, 0);

	// for(int i = 1; i <= n; i++) {
	// 	cout << i << "-> ";
	// 	for(int j = 0; j < 4; j++) {
	// 		cout << parent[i][j] << ' ';
	// 	}
	// 	cout<<'\n';
	// }

	// int u = find(9, 11);
	// cout<<u<<'\n';
	// cout<<find(9, 12)<<'\n';
	// cout<<find(4, 12)<<'\n';

	cout<<len(10, 12);	

	return 0;
}