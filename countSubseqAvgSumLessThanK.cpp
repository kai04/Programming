#include <bits/stdc++.h>
using namespace std;
int solve(std::vector<int> &a,vector<vector<vector<int>>> &dp,int cnt,int i,int s,int k){
    //cout<<"i:"<<i<<" s:"<<" cnt:"<<cnt<<endl;
    //base case
    if(i==a.size()){
        if(s<=k){
            return cnt;
        }
        else{
            return INT_MIN;
        }
    }

    //memoization
    if(dp[i][s][k]!=0){
        return dp[i][s][k];
    }
    //recursion
    if((((s*cnt)+a[i])/(cnt+1))<=k)
        dp[i][s][cnt]=max(solve(a,dp,cnt+1,i+1,((s*cnt)+a[i])/(cnt+1),k),solve(a,dp,cnt,i+1,s,k));
    else
        dp[i][s][cnt]=solve(a,dp,cnt,i+1,s,k);

    return dp[i][s][cnt];


}

int solve1(std::vector<int> &a,vector<vector<vector<int>>> &dp,int cnt,int i,int s,int k){
    //cout<<"i:"<<i<<" s:"<<" cnt:"<<cnt<<endl;
    //base case
    if(i==a.size()){
        if(s<=k){
            return 0;
        }
        else{
            return INT_MIN;
        }
    }

    //memoization
    if(dp[i][s][k]!=0){
        cout<<"i:"<<i<<" s:"<<s<<" cnt:"<<cnt<<" dp[i][s][k]:"<<dp[i][s][k]<<endl;
        return dp[i][s][k];
    }
    //recursion
    if((((s*cnt)+a[i])/(cnt+1))<=k)
        dp[i][s][cnt]=max(1+solve1(a,dp,cnt+1,i+1,((s*cnt)+a[i])/(cnt+1),k),solve1(a,dp,cnt,i+1,s,k));
    else
        dp[i][s][cnt]=solve1(a,dp,cnt,i+1,s,k);

    cout<<"i:"<<i<<" s:"<<s<<" cnt:"<<cnt<<" dp[i][s][k]:"<<dp[i][s][k]<<endl;
    return dp[i][s][cnt];


}

int main() {
    int n,k;
    cin>>n>>k;
    // int n = s.length();
    // vector<int> dp(n+1,-1);
    // cout<<"here1"<<endl;
    vector<vector<vector<int> >> dp(n,vector<vector<int>> (n,vector<int> (n,0)));
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // cout<<solve(a,dp,0,0,0,k)<<endl;
    cout<<solve1(a,dp,0,0,0,k)<<endl;
	return 0;
}