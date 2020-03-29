//https://practice.geeksforgeeks.org/problems/longest-zig-zag-sub-sequence/0
#include <bits/stdc++.h>
using namespace std;
int longestzigzag(int i,int order,vector<int> &a,vector<vector<int>> &dp){
    int n = a.size();
    if(i==n)
        return 0;
    if(dp[i][order]!=1)
        return dp[i][order];
    // int x = INT_MIN;
    if(order==0){
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                dp[i][order] = max(dp[i][order],1+longestzigzag(j,abs(order-1),a,dp));
                }
            else{
                dp[i][order]=max(dp[i][order],longestzigzag(j,order,a,dp));
            }
        }
    }
    else{
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                dp[i][order] = max(dp[i][order],1+longestzigzag(j,abs(order-1),a,dp));
                }
            else{
                dp[i][order]=max(dp[i][order],longestzigzag(j,order,a,dp));
            }
        }
    }
    return dp[i][order];
}
int solve(vector<int> &a){
    int n =a.size();
    //0 mean increasing
    //1 mean decreasing
   vector<vector<int>> dp(n,vector<int>(2,1));
   int ans1 = longestzigzag(0,0,a,dp);
   int ans2 = longestzigzag(0,1,a,dp);
   return max(ans1,ans2);
    
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans = solve(a);
        cout<<ans<<endl;
    }
	//code
	return 0;
}
