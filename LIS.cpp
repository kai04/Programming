//http://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int LIS(vector<int> &a,vector<int> &dp,int j,vector<bool> &flag){
    for(int i=0;i<j;i++){
        if(a[i]<a[j]){
            dp[j]=max(dp[j],1+LIS(a,dp,i,flag));
        }
    }
    flag[j]=true;
    return dp[j];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> dp(n,1);
        vector<bool> flag(n,false);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<LIS(a,dp,n-1,flag);
    }
	//code
	return 0;
}
