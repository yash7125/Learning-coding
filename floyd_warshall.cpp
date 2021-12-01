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


#define inf 10000

void shortest_path(vector<vector<int>> p) {
    
    int v = p.size();
    vector<vector<int> > dis(p);

    for(int k = 0; k < v; k++) {

        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                
                if(dis[i][j] > (dis[i][k] + dis[k][j])) {

                    dis[i][j] = dis[i][k] + dis[k][j];

                }
            }
        }
    }

    for(int k = 0; k < v; k++) {

        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                
                if((dis[i][j] != inf) && dis[i][j] > (dis[i][k] + dis[k][j])) {
                    cout << "-ve cycle found" << endl;
                    return;
                }
            }
        }
    }
    
    for(int i = 0; i < v; i++) {
       for(int j = 0; j < v; j++) {
           cout << dis[i][j] << " "; 
       }
       cout << endl;
    }

}


int main() {
    
    vector<vector<int>> p = {
                             {0,3,inf},
                             {inf,0,5},
                             {10,inf,0}
    };

    shortest_path(p);

    return 0;
}