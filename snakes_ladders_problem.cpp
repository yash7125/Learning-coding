#include<bits/stdc++.h>
using namespace std;

class Graph {
    
    map<int,list<int>> p;

    public :

    void addEdge(int src,int des) {
        p[src].push_back(des);
    }

    void bfs(int src,int des) {
        
        map<int,int> distance;
        map<int,int> parent;

        parent[src] = src;
        
        for(auto x : p) {
            int node = x.first;
            distance[node] = INT_MAX;
        }

        queue<int> q;
        q.push(src);
        distance[src] = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto nbr : p[node]) {
                if(distance[nbr] == INT_MAX) {
                    q.push(nbr);
                    distance[nbr] = distance[node] + 1;
                    // parent[nbr] = node;
                }
            }
        }

        int temp = des;

        // cout << des << " ";

        // while(temp != src) {
        //     cout << parent[temp] << " ";
        //     temp = parent[temp];
        // }
        // cout << endl;
        cout << distance[des] << endl; 
    }
};


int main() {
    
    Graph v;

    int board[100]={0};
    
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[17] = -13;
    board[18] = 11;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //to find min no. of dice throws?

    for(int i = 1; i <= 36; i++) {
        for(int dice = 1; dice <= 6; dice++) {
            int j = i + dice;
            j += board[j];

            if(j <= 36) {
                v.addEdge(i,j);
            }         
        }
    }

    v.addEdge(36,36);

    v.bfs(1,36);
    return 0;
}