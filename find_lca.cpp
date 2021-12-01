#include<bits/stdc++.h>
using namespace std;

const int M = 22;
vector<int> dep;
vector<vector<int> > parent;
vector<vector<int> > gr;

void dfs(int src,int par)
{	
	dep[src] = dep[par] + 1;

	parent[src][0] = par;

	for(int i = 1; i < M; i++) {
		parent[src][i] = parent[parent[src][i-1]][i-1];
	}

	for(auto x : gr[src])
	{
		if(x != par) {
			dfs(x, src);
		}
	}

}

int findLca(int u,int v)
{
	if(u == v) return u;
	
	if(dep[u] < dep[v]) {swap(u, v);}

	int diff = dep[u] - dep[v];

	for(int i = M-1; i >= 0; i--) {
		if((diff >> i) & 1) {
			u = parent[u][i];
		}
	}

	for(int i = M-1; i >= 0; i--) {
		if(parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];

}

vector<int> LCA(int n, vector<vector<int>>edges, vector<vector<int>>queries)
{	
	dep = vector<int>(n + 1, 0);
	gr = vector<vector<int> >(n + 1, vector<int>());
	parent = vector<vector<int> >(n + 1, vector<int>(M, 0));

    for(auto x : edges) {
    	int u = x[0];
    	int v = x[1];
    	gr[u].push_back(v);
    	gr[v].push_back(u);
    }

    dfs(1, 0);

    vector<int> ans;

    for(auto q : queries) {
    	int x = findLca(q[0], q[1]);
    	ans.push_back(x);
    }

    return ans;

}


int main()
{


	return 0;
}


















