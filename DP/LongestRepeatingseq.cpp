#include <bits/stdc++.h>
using namespace std;
int LCS(string s1,string s2,int i,int j,vector<vector<int>> &dp){
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]==-1){
        if(i!=j&&s1[i]==s2[j]){
            dp[i][j]= 1+LCS(s1,s2,i-1,j-1,dp);
        }
        else{
            dp[i][j]= max(LCS(s1,s2,i,j-1,dp),LCS(s1,s2,i-1,j,dp));
        }
    }
    return dp[i][j];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        //cout<< LCS(s,s,n-1,n-1,dp)<<endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(i!=j&&s[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        cout<<dp[n][n]<<endl;
    }
	//code
	return 0;
}