//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include <bits/stdc++.h>
using namespace std;
int lps(string s1,string s2,vector<vector<int> > &dp){
    int n=s1.length();
    int m=s2.length();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
string printLCS(string s1,string s2,vector<vector<int> >&dp){
    string ret="";
    int n=s1.length();
    int m=s2.length();
    int i=n;
    int j=m;
    while(i!=0 || j!=0){
        if(s1[i-1]==s2[j-1]){
            ret=s1[i-1]+ret;
            i--;
            j--;
        }
        else{
            (dp[i-1][j]>=dp[i][j-1])?i--:j--;
        }

    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        vector<vector<int> > dp(n+1,vector<int> (m+1,0));
        int res=lps(s1,s2,dp);
        cout<<res<<endl;
        string lcsResult=printLCS(s1,s2,dp);
        cout<<lcsResult<<endl;
        cout<<"---------------------------------------"<<endl;
    }
	return 0;
}