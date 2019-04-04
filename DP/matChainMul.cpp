//https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int matChainMul(int i,int j,vector<int> p,vector<vector<int>> &dp){
    // cout<<"i:"<<i<<" j:"<<j<<endl;
    if(i==j)
        return 0;
    if(dp[i][j]!=INT_MAX/2)
        return dp[i][j];
    for(int k=i;k<j;k++){
        int count1=matChainMul(i,k,p,dp)+matChainMul(k+1,j,p,dp)+(p[i-1]*p[k]*p[j]);
        dp[i][j]=min(dp[i][j],count1);
    }
    return dp[i][j];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> p(n);
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX/2));
        for(int i=0;i<n;i++){
            cin>>p[i];
            dp[i][i]=0;
        }
        
        // vector<vector<int>> dp(n,vector<int>(n,INT_MAX/2));
        // cout<<matChainMul(1,n-1,p,dp)<<endl;
        for(int l=1;l<=n-1;l++){
            for(int i=1;i<n;i++){
                int j=i+l;
                if(i<j && j<n && i+1< n){
                    for(int k=i;k<j;k++){
                        // cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
                        dp[i][j]=min(dp[i][j],(dp[i][k]+dp[k+1][j]+(p[i-1]*p[k]*p[j])));
                    }
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<dp[1][n-1]<<endl;
    }
    //code
    return 0;
}