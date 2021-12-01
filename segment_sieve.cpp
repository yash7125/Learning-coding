#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100000;
vector<int> primes;
int p[100000] = {0};

void sieve() {

  for(int i = 2; i * i <= N; i++) {
      if(p[i] == 0) {
          primes.push_back(i);
         for(int j = i; j <= N; j += i) {
             p[j] = 1;
         } 
      }
  }

}

int main() {

    int t;
    cin >> t;
     sieve();

    while(t--) {

    ll m,n;
    cin >> m >> n;

    bool range[n - m + 1];

    for(int i = 0; i < n - m + 1; i++) {
        range[i] = 0;
    }
    
    for(auto x : primes) {
        
        if((x * x) > n) {
            break;
        }
        
        int start = (m/x) * x;

        if(start == 0) {
            start = x << 1;
        }

        for(ll i = start; i <= n; i += x) {
            range[i - m] = 1;
        }
    }

    for(int i = m; i <= n; i++) {
        if(range[i - m] == 0 and i != 1) {
            cout << (i) << " "; 
        }
    }

 }


    return 0;
}