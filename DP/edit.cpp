//https://leetcode.com/problems/edit-distance/
//https://www.geeksforgeeks.org/edit-distance-dp-5/
#include <bits/stdc++.h>
using namespace std;
//#include <string>
typedef long long ll;
static int p;
static int q;
int min1(int x,int y,int z){
	return(min(min(x,y),z));
}
int minDistance(string word1, string word2) {
    int n=word1.length();
    int m=word2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,INT_MAX));
    //initialize
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
        // dp[0][i]=0;
    }

    for(int i=0;i<=m;i++){
        dp[0][i]=i;
        // dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                // dp[i][j]=min(dp[i][j],dp[i-1][j]);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                // dp[i][j]=min(dp[i][j],dp[i][j-1]);
            }
            else{
                dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
                dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
                dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
            }
        }
    }
    /*for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/


    // cout<<dp[n][m]<<endl;

    return dp[n][m];
    }
int edit(string s1,string s2,int m,int n,vector<vector<int> > &dp){
    
    if(m==0)
        return n;
    if(n==0)
        return m;
   if(dp[m][n]==-1){   
  if(s1[m-1]==s2[n-1])
		dp[m][n] =edit(s1,s2,m-1,n-1,dp);
	else
		dp[m][n] =1+min1(edit(s1,s2,m-1,n,dp),edit(s1,s2,m,n-1,dp),edit(s1,s2,m-1,n-1,dp));
    }
    return dp[m][n];
    
}
int main()
{
long long T,x,y;
    string s1,s2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s1>>s2;
    
    int m=s1.length();
    int n=s2.length();
    p=m;
    q=n;
    vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
    int res=edit(s1,s2,m,n,dp);
    cout<<res<<endl;

    return 0;
}
