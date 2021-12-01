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
vector<int> gr[N];
int vis[N],low[N],disc[N];
int tme = 1;
vector<pair<int,int> > bridges;
set<int> art_points;

void dfs(int src, int par)
{
	vis[src] = 1;
	disc[src] = low[src] = tme++;
	int child = 0;

	for(auto sub : gr[src]) {
		if(!vis[sub]) {
			
			dfs(sub, src);
			child++;

			low[src] = min(low[src], low[sub]);

			if(low[sub] > disc[src]) {
				bridges.push_back({src, sub});
			}
			if(low[sub] >= disc[src] and par!=0) {
				art_points.insert(src);
			}
		}
		else if(sub != par) {
			low[src] = min(low[src], disc[sub]);
		}
	}

	if(child > 1 and par==0) {
		art_points.insert(1);
	}
	return;
}

int main()
{
	c_p_c();
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1, 0);
	cout << "bridges ->";
	for(auto x : bridges) {
		cout << x.first << " " << x.second << endl;
	}
	cout << "articulation points ->" << endl;
	for(auto x : art_points) {
		cout << x << endl;
	}






	return 0;
}