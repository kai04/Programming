//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,W;
	    cin>>n>>W;
	    vector<int> profit(n);
	    vector<int> weight(n);
	    for(int i=0;i<n;i++){
	        cin>>profit[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>weight[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
	    //base case
	    for(int i=0;i<=n;i++){
	        dp[i][0] = 0;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=W;j++){
	            if(weight[i-1]<=j){
	            	dp[i][j] = max(profit[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);// Comment if repetion not allowed
	            	//dp[i][j] = max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);// Comment if repetetion allowed
	            }
	            else{
	                dp[i][j] = max(dp[i][j],dp[i-1][j]);
	            }
	        }
	    }
	    /*for(int i=0;i<=n;i++){
	        for(int j=0;j<=W;j++){
	         cout<<dp[i][j]<<" ";   
	        }
	        cout<<endl;
	    }
	    cout<<"-----------------------------"<<endl;
	    cout<<"ans:"<<dp[n][W]<<endl;
	    cout<<"====================================="<<endl;*/
	    cout<<dp[n][W]<<endl;
	}
	return 0;
}