#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pi (3.141592653589)
#define mod 1000000007
#define ll long long
#define float double
#define pb push_back
#define mp make_pair
#define fs first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Graph {
    vector<pair<int,int> > *l;
    int V;

public:
    
    Graph(int V) {
        this->V = V;
        l = new vector<pair<int,int> > [V];
    }

    void addEdge(int x,int y,int wt) {
        l[x].push_back(mp(y,wt));
        l[y].push_back(mp(x,wt));
    }

    int mst() {

        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > q;
        
        q.push({0,0});
        int ans = 0;

        bool *visited = new bool[V+1] {0};
        
        while(!q.empty()) {

            auto got = q.top();
            q.pop();

            int wt = got.first;
            int node = got.second;

            if(visited[node] == true) {
                continue;
            }

            ans += wt;
            visited[node] = true;

            for(auto p : l[node]) {
                if(visited[p.first] == false) {
                    q.push({p.second,p.first});
                }
            }
        }

        return ans;
    }

};

int32_t main(){

c_p_c();

int v,e;
cin >> v >> e;

Graph p(v);

for(int i = 1; i <= e; i++) {
    int x,y,wt;
    cin >> x >> y >> wt;
    p.addEdge(x,y,wt);
}

cout << p.mst() << endl;

return 0;
}
