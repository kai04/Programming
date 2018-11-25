//http://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int LIS_TopDown(vector<int> nums){
    if(nums.size()==1||nums.size()==0)
        return nums.size();
    //base case
    //by default each element is increasing seq of length 1
    vector<int> dp(nums.size(),1);
    dp[0]=1;
    for(int j=1;j<nums.size();j++){
        for(int i=0;i<j;i++){
            if(nums[i]<nums[j]){
                dp[j]=max(dp[j],1+dp[i]);
            }
        }
    }
    int len=*max_element(dp.begin(),dp.end());
    return len;
}

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
