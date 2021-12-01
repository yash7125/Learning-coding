#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

struct graph {

	vector<pair<int,int> > *gr;
	int n;
	graph(int n) {
		this->n = n;
		gr = new vector<pair<int,int>>[n];
	}

	void edge(int u,int v,int wt) {
		gr[u].push_back({v, wt});
		gr[v].push_back({u, wt});
	}

	void shortest_path() {

		set<pii> s;
		map<int,int> dis;
		for(int i = 0; i < n; i++) {
			dis[i] = INT_MAX;
		}
		
		s.insert({0, 0});
		dis[0] = 0;

		while(!s.empty())
		{
			auto x = *s.begin();
			int dist = x.first;
			int src = x.second;

			for(auto nbr : gr[src]) {
				if((nbr.second + dist) < dis[nbr.first]) {
					int des = nbr.first;
					auto f = s.find({dis[des], des});
					if(f!=s.end()) {
						s.erase(f);
					}
					dis[des] = dist + nbr.second;
					s.insert({dis[des], des});
				}
			}
		}

		for(auto x : dis) {
			cout << x.first << ' ' << x.second <<'\n';
		}
	}

};

int main() {

	c_p_c();

	int n,m;
	cin >> n >> m;

	graph gr(n);

	for(int i = 0; i < m; i++) {
		int x, y, wt;
		cin>>x>>y>>wt;
		gr.edge(x-1,y-1,wt);
	}

	gr.shortest_path();
	
	return 0;

}