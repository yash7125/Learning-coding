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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main()
{	
	c_p_c();

	int n,m;
	cin >> n >> m;

	int a[n][m], dis[n][m];

	queue< pair<int,int> > q;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			
			cin >> a[i][j];
			
			if(a[i][j]) {
				dis[i][j] = 0;
				q.push({i, j});
			}
			else {
				dis[i][j] = INT_MAX;
			}
		}
	}

	while(!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for(int i = 0; i < 4; i++) {
			
			int xx = x + dx[i];
			int yy = y + dy[i];

			if((xx >= 0) and (xx < n) and (yy >= 0) and (yy < m) and dis[xx][yy]==INT_MAX)
			{
				dis[xx][yy] = dis[x][y] + 1;
				q.push({xx, yy});
			}
		}

	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << dis[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;
}