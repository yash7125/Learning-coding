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

const int N = 101;
int dis[N][N];
int dp[N][N];

int tsp(int setOfCities, int city, int n) 
{
	if(setOfCities == ((1 << n) - 1)) {
		return dis[city][0];
	}

	if(dp[setOfCities][city]!=-1) {
		return dp[setOfCities][city];
	}

	int ans = 1e9;

	for(int i = 0; i < n; i++) {
		if((setOfCities & (1 << i)) == 0) {
			int sub = dis[city][i] + tsp(setOfCities | (1<<i), i, n);
			ans = min(ans, sub);
		}
	}

	return dp[setOfCities][city] = ans;

}

int main() {

	c_p_c();

	int n;
	cin >> n;
	// memset(dis,0,sizeof(dis));
	memset(dp,-1,sizeof(dp));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> dis[i][j];
		}
	}

	int ans = tsp(1, 0, n);
	cout << ans << endl;

	return 0;
}
