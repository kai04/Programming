/*
 fishes of different length are given. you have to find out how many fishes can she get of length 10 by making cuts on fish, where number of cuts are limited? ex. 20 30 15(lengths) and number of cuts=3
Ans. : 5 (20—-2(one cut of 10 10) and 30—-(2 cuts of 10 10 10))
INPUT:
3 10 3
20 30 15
OUTPUT:5

*/


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a,int i,int k,vector<vector<int>> &dp,int p){
	int n = a.size();
	//base case
	//cout<<"i:"<<i<<" k:"<<k<<endl;
	if(i==n){
		//cout<<"----------------------------"<<endl;
		return 0;
	}
	if(k==0){
		if(a[i]==p)
			return 1+solve(a,i+1,k,dp,p);
		return solve(a,i+1,k,dp,p);
	}
	/*if(a[i]==p){

		return 1 + solve(a,i+1,k,dp,p);
	}*/

	//memoization
	if(dp[i][k]!=INT_MIN/2)
		return dp[i][k];
	int c1=0,c2=0,c3=0;
	//choices
	// 1)  move to next index without cut
	c1 = solve(a,i+1,k,dp,p);
	// 2)  make a cut and remain at same index
	if(a[i]>=p){
		a[i] = a[i] - p;
		if(a[i]==p){
			c2 = 2+solve(a,i+1,k-1,dp,p);	
		}
		else{
			c2 = 1+solve(a,i,k-1,dp,p);	
		}
			
	}
	// 3)  make a cut and move to next index
	if(a[i]>=p){
		//a[i] = a[i] - p;
		c3 = 1+solve(a,i+1,k-1,dp,p);	
	}
	dp[i][k] = max(c1,c2);
	dp[i][k] = max(c3,dp[i][k]);
	cout<<"i:"<<i<<" k:"<<k<<" dp[i][k]:"<<dp[i][k]<<endl;
	cout<<"----------------------------"<<endl; 
	return dp[i][k];
}
int f(int i,int j,int s,int p,vector<int> &a,int k,vector<vector<vector<int>>> &dp){
	int n = a.size();
	int c1=0,c2=0,c3=0,c4=0;
	//base cases
	if(i>=n){
		return 0;
	}
	//memoization
		if(dp[i][j][s]!=INT_MIN/2)
			return dp[i][j][s];
	if(s==p){
		if(i<n){
			return 1 + f(i+1,j,a[i+1],p,a,k,dp);
		}
		else{
			return 1 + f(i+1,j,0,p,a,k,dp);
		}
	}
	if(j>=k){
		if(i<n){
			return f(i+1,j,a[i+1],p,a,k,dp);
		}
		else{
			return f(i+1,j,0,p,a,k,dp);
		}
	}

	//recursion
	if(s>=p){
		//make cut but remain on same state
		c1 = 1 + f(i,j+1,s-p,p,a,k,dp);
		//make cut but move to next state
		if(i<n){
			c2 = 1 + f(i+1,j+1,a[i+1],p,a,k,dp);
		}
		else{
			c2 = 1 + f(i+1,j+1,0,p,a,k,dp);
		}
		//Donot make cut
		if(i<n){
			c3 = f(i+1,j,a[i+1],p,a,k,dp);
		}
		else{
			c3 = f(i+1,j,0,p,a,k,dp);
		}
	}
	else{
		//Do not make cut
		if(i<n){
			c4 = f(i+1,j,a[i+1],p,a,k,dp);
		}
		else{
			c4 = f(i+1,j,0,p,a,k,dp);
		}	
	}
	int ans = INT_MIN;
	ans = max(ans,c1);
	ans = max(ans,c2);
	ans = max(ans,c3);
	ans = max(ans,c4);
	return ans;
}

/*int top_down(){
	int n = a.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(a[i-1]<p){
				dp[i][j] = dp[i-1][j];
			}
			else if(a[i-1]==p){
				dp[i][j] = dp[i-1][j]+1;	
			}
			else if(a[i-1]==(2*p)){
				dp[i][j] = dp[i-1][j-1]+2;	
			}
			else{
				int a1 = dp[i-1][j];
				int a2 = 1 + dp[i][j-1];
				int a3 = 1 + dp[i-1][j-1];
				dp[i][j] = max(a1,a2);
				dp[i][j] = max(dp[i][j],a3);	
			}
		}
	}
}*/
int main(){
	int n,p,k;
	cin>>n>>p>>k;
	vector<int> a(n);
	int maxFishSize = INT_MIN;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxFishSize = max(maxFishSize,a[i]);
	}
	//vector<vector<int>> dp(n+1,vector<int> (k+1,INT_MIN/2));
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (k+1,vector<int>(maxFishSize+1,INT_MIN/2)));
	//int ans = solve(a,0,k,dp,p);
	int ans = f(0,0,a[0],p,a,k,dp);
	cout<<"ANS:"<<ans<<endl;
	return 0;
}