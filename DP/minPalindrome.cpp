#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int rec(string s,int i,int j,vector<vector<int> > &dp){
    int n=s.length();
    if(i==j){
            return 0;
        }
    else if(i+1==j){
        if(s[i+1]!=s[j])
            return 1;
        else
            return 0;
        }
    else if(s[i]==s[j]){
        return (rec(s,i+1,j-1,dp));   
        }
    else{
        if(dp[i][j]==n){
            dp[i][j]=min((1+rec(s,i+1,j-1,dp)),(1+rec(s,i+1,j,dp)));
        }
        else{
            return dp[i][j];
        }
    }
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n =s.length();
    vector<vector<int> > dp(n);
    for(int i=0;i<n;i++){
            dp[i].resize(n,n);
    }
    //int dp[n][n]={n};
    int i =0;
    int j=n-1;
    cout<<rec(s,i,j,dp);
    //cout<<count1<<endl;
    return 0;
}
