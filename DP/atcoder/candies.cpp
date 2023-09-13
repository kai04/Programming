//https://atcoder.jp/contests/dp/tasks/dp_m
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int solve(int i, vector<int> &A, int k, vector<vector<int>> &dp){
    int n = A.size();
    //base case
    if(i==n && k==0){
        return 1;
    }
    if(i>=n || k<0){
        return 0;
    }
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    dp[i][k] = 0;
    for(int j=0;j<=A[i];j++){
        int x = k-j;
        if(x>=0){
            dp[i+1][x] = solve(i+1, A, x, dp) % mod;
            dp[i][k] = (dp[i][k] + dp[i+1][x])%mod;
        }     
    }
    return dp[i][k];
}

int solve_new(int i, vector<int> &A, int k, vector<vector<int>> &dp){
    int n = A.size();
    for(int j=0;j<=A[0];j++){
        dp[0][j] = 1;
    }
    // bottom up
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            for(int p=0;p<=A[i];p++){
                if(j>=p){
                    dp[i][j] += dp[i-1][j-p];    
                } else{
                    break;
                }
            }       
        }
    }

    return dp[n-1][k];
}

int solve_optimize(vector<int> &A, int k){
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1,0));
    vector<vector<int>> pref(n+1, vector<int>(k+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
        pref[i][0] = 1;
    }

    for(int j=0;j<=k;j++){
        pref[0][j] = 1;   
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j-A[i-1]>0){
                dp[i][j] = (pref[i-1][j] - pref[i-1][j-A[i-1]-1])%mod;    
            } else {
                dp[i][j] = pref[i-1][j]%mod;
            }
            pref[i][j] = (pref[i][j-1] + dp[i][j])%mod;    
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][k];
}

int main(){
  	int n,k;
  	cin>>n>>k;
  	vector<int> A(n);
  	for(int i=0;i<n;i++){
  		cin>>A[i];
  	}
    vector<vector<int>> dp(n+1, vector<int>(k+1,0));
    // int ans = solve_new(0, A, k, dp);
  	// int ans = solve(0, A, k, dp);
    int ans = solve_optimize(A,k);
    cout<<ans<<endl;

    return 0;
}
