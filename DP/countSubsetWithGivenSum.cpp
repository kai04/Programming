//https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include<bits/stdc++.h>
using namespace std;

int solveUtils(int i ,int sum1,vector<int> &a,map<int,vector<int>> &dp){
	int n = a.size();
	//base case
	if(sum1==0)
		return 1;
		
	if(i==n)
		return 0;
	//memoization
		if(dp[sum1][i]!=0){
			return dp[sum1][i];
		}
	//choice
	dp[sum1][i] = solveUtils(i+1,(sum1-a[i]),a,dp) + solveUtils(i+1,sum1,a,dp);
	return dp[sum1][i]; 
		
}

int solve(vector<int> &a,int sum){
	int n = a.size();
	int minsum=0,maxsum=0;
	map<int,vector<int>> dp;
	for(int i=0;i<n;i++){
		minsum = min(minsum,minsum+a[i]);
		maxsum = max(maxsum,maxsum+a[i]);
	}
	for(int i=minsum;i<=maxsum;i++){
		dp[i].resize(n);
	}
	
	return solveUtils(0,sum,a,dp);
}

int countSubsetWithGivenSum(vector<int> &a,int sum){
	int n = a.size();
	int minval = 0;
	for(int i=0;i<n;i++)
		minval = min(minval,a[i]);
	//shift origin based on minval
	for(int i=0;i<n;i++)
		a[i] = a[i] + minval;
	vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
	
	//base case
	for(int i=0;i<=n;i++)
		dp[i][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j>=a[i-1]){
				dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}
int main(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int res = countSubsetWithGivenSum(a,x);
	//int res = solve(a,x);
	cout<<res<<endl;
	return 0;
}
