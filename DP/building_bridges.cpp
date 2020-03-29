//https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int res =0;
int solve(int i,int j,int k,vector<int> &a,vector<int> &b,vector<vector<vector<int>>> &dp){
	//base case
	int n = a.size();
	cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
	if(i==n-1){
		if(j<a[i] && k<b[i])
			return 1;
		else
			return 0;
	}
	//memoization
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	int p = solve(i+1,j,k,a,b,dp);
	if(j<a[i] && k<b[i]){
		dp[i][j][k] = max(1+solve(i+1,a[i],b[i],a,b,dp),p);	
	}	
	else{
		dp[i][j][k] = p;
	}
		
	res = max(res,dp[i][j][k]);
	return dp[i][j][k];
}
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> b(n+1);
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (n+1,vector<int>(n+1,-1)));
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		cin>>b[i];
	}
	int ans = 0;
	/*for(int i=1;i<=n;i++){
		//cout<<"i:"<<i<<endl;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
					dp[i][j][k] = dp[i-1][j][k];
					if(j<a[i] && k<b[i]){
						dp[i][j][k] = max(dp[i][j][k],1+dp[i-1][a[i]][b[i]]);
					}
					ans = max(ans,dp[i][j][k]);
					//cout<<dp[i][j][k]<<" ";
			}
			//cout<<endl;
		}
		//cout<<"---------------------------------------"<<endl;
	}*/
	ans = solve(1,0,0,a,b,dp);
	cout<<"ans:"<<ans<<endl;
	cout<<"RES:"<<res<<endl;
    return 0;
}
