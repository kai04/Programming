/*http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/*/



#include <bits/stdc++.h>
using namespace std;
int cost(vector<vector<int>> &A,int i,int j,vector<vector<int>> &dp,int n){
    if(i<0 || j<0 || i>=n ||j>=n){
        return (INT_MAX)/2;
    }
    if(dp[i][j]==-1){
        dp[i][j]= A[i][j]+min(cost(A,i-1,j,dp,n),cost(A,i,j-1,dp,n));
        dp[i][j] = min(dp[i][j],A[i][j]+cost(A,i-1,j-1,dp,n));
    }
    return dp[i][j];
}
int main() {
    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        vector<vector<int>> A(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cin>>A[i][j];
            }
        }
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        dp[0][0]=A[0][0];
        dp[n-1][n-1]=cost(A,n-1,n-1,dp,n);
            cout<<dp[n-1][n-1]<<endl;
        
        
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
            }
        cout<<endl;
        }*/
    }
        
	//code
	return 0;
}