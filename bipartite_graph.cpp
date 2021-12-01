#include<bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int> Graph[],int *visited,int src,int parent,int color) {
    
    visited[src] = color;

    for(auto nbr : Graph[src]) {
        if(visited[nbr] == 0) {
            
            bool yaha_milega = dfs_helper(Graph,visited,nbr,src,3-color);
            
            if(yaha_milega == false) {
                return false;
            }

        }
        else if(nbr != parent && visited[nbr]==color) {
            return false;
        } 
    }

    return true;

}

void dfs(vector<int> Graph[],int N) {
    
    int visited[N] = {0};

    int color = 1;
    bool ans = dfs_helper(Graph,visited,0,-1,color);
    if(ans == true) {
        cout << "Yes it is bipartite";
    }
    else {
        cout << "No it is not bipartite";
    }
}

int main() {
    
    int n,m;
    cin >> n >> m;

    vector<int> Graph[n];

    while(m--) {
        int x,y;
        cin >> x >> y;

        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    dfs(Graph,n);


    return 0;
}