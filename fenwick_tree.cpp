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
int bit[N];

void update(int i,int ele, int n)
{
	while(i <= n) {
		bit[i] += ele;
		i += (i & (-i));
	}
}

void build(int a[], int n)
{
	for(int i = 1; i <= n; i++)
	{
		update(i, a[i-1], n);
	}
}

int query(int i)
{
	int ans = 0;
	while(i > 0) {
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

int main()
{	
	c_p_c();
	
	int n;
	cin >> n;
	memset(bit,0,sizeof(bit));
	
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	build(a, n);
	//(3,6)
	int ans = query(6) - query(2);
	cout << ans << endl; 



	return 0;
}