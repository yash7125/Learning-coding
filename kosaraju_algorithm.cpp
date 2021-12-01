#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
vector<int> rgr[N];
int vis[N], a[N];
vector<int> top_sort;
int comp;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void dfs(int src,int par)
{
	vis[src] = 1;
	for(auto x : gr[src]) {
		if(!vis[x]) {
			dfs(x, src);
		}
	}

	top_sort.push_back(src);
	return;
}

void dfs_helper(int src,int par)
{
	vis[src] = 1;
	a[src] = comp;

	for(auto x : rgr[src]) {
		if(!vis[x]) {
			dfs_helper(x, src);
		}
	}

	return;
}

int main(int argc, char const *argv[])
{
	c_p_c();

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		rgr[y].push_back(x);
	}

	dfs(14, 0);

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) {
			dfs(i, 0);
		}
	}

	reverse(top_sort.begin(),top_sort.end());
	memset(vis,0,sizeof(vis));
	comp = 1;

	for(auto x : top_sort)
	{
		if(!vis[x]) {
			dfs_helper(x, 0);
			comp++;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		cout << i << " " << a[i] << endl;
	}

	return 0;
}