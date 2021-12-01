#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int matrixCM(int m[],int i,int j) {

    if(i==j) {
        dp[i][j] = 0;
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        ans = min(ans, matrixCM(m,i,k) + matrixCM(m,k + 1,j) + (m[i-1] * m[k] * m[j]));
    }

    return dp[i][j] = ans;

}

int matrixChainMultiplication(int m[],int n) {

    for(int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    
    for(int p = 2; p < n; p++) {
        for(int i = 1; i <= n-p; i++) {
            
            int j = i + p - 1;
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (m[i-1] * m[k] * m[j]));
            }
        }
    }
    
    return dp[1][n-1];

}

int main() {
   
    int m[] = {1,2,3,4};
    int n = sizeof(m)/sizeof(int);

    memset(dp,-1,sizeof dp);

    // cout << matrixCM(m,1,n-1) << endl;

    // for(int i = 1; i < n; i++) {
    //     for(int j = 1; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << matrixChainMultiplication(m,n) << endl;

   return 0;

}