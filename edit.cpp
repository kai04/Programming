#include <bits/stdc++.h>
using namespace std;
//#include <string>
typedef long long ll;
static int p;
static int q;
int min1(int x,int y,int z){
	return(min(min(x,y),z));
}
int edit(string s1,string s2,int m,int n,vector<vector<int> > &dp){
    
    if(m==0)
        return m;
    if(n==0)
        return n;
   if(dp[m-1].at(n-1)==-1){   
  if(s1[m-1]==s2[n-1])
		dp[m].at(n) =edit(s1,s2,m-1,n-1,dp);
	else
		dp[m].at(n) =1+min1(1+edit(s1,s2,m-1,n,dp),1+edit(s1,s2,m,n-1,dp),1+edit(s1,s2,m-1,n-1,dp));
    }
    
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
    //int dp[m][n];
    //vector<vector<int>v(n) > dp(m);
    vector<vector<int> > dp(m);
    for ( int i = 0 ; i < m ; i++ )
        dp[i].resize(n);
      //cout<<"M:"<<dp.size()<<endl;
      //cout<<"N:"<<dp[0].size()<<endl;
          for(int i=1;i<m;i++){
              for(int j=1;j<n;j++){
                //cout<<"i:"<<i<<" j:"<<j<<endl;
              dp[i].at(j)=-1 ;   
              }
          }
    /*for(int i=1;i<=m;i++){
        for(int j=1;i<=n;i++){
    dp[i][j]=edit(s1,s2,i,j);
        }
    }*/
    int res=edit(s1,s2,m,n,dp);
    cout<<res<<endl;

    return 0;
}
