#include<bits/stdc++.h>
using namespace std;

class Graph {

map<int,list<int>> l;

public :

    void addEdge(int src,int des) {
        l[src].push_back(des);
        l[des].push_back(src);
    }  

    void bfs(int src) {

        queue<int> q;
        map<int,int> distance;

        q.push(src);

        for(auto x : l) {
            int node = x.first;
            distance[node] = INT_MAX;
        }

        distance[src] = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            //  cout << node << " ";

            for(int neighbour : l[node]) {
                
                if(distance[neighbour] == INT_MAX) {
                    q.push(neighbour);
                    distance[neighbour] = distance[node] + 1;
                }
            }
        } 

        for(auto p : distance) {
            int node = p.second;
            cout <<"Distance from node (" <<p.first <<")->"<< node << endl;
        }
    }
  
};


int main() {

    Graph p;
    
    p.addEdge(0,1);
    p.addEdge(0,3);
    p.addEdge(1,2);
    p.addEdge(2,3);
    p.addEdge(3,4);
    p.addEdge(4,5);

    p.bfs(5);


    return 0;
}