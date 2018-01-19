#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mincost(vector<int> &a,vector<vector<int>>& dp,int i,int j){
    int mini;
    if(i>j)
            return 0;
    if(i==j)
        return 1;
    if(dp[i][j]==-1){
            
         //mini=mincost(a,dp,i+1,j)+1;
        dp[i][j]=mincost(a,dp,i+1,j)+1;
        int x=101;
            for(int k=i+1;k<=j;k++){
                if(a[i]==a[k])
                { 
                    dp[i][j]=min(dp[i][j],(mincost(a,dp,i+1,k-1)+mincost(a,dp,k+1,j)));
                }
        }
            
    }
    return dp[i][j];
}
int main() {
  ios_base::sync_with_stdio(false);
    //cin.tie(null);
    int n;
     cin >> n;
    vector<int> a(n);
  for (int i = 0; i < n; ++i){
        int x;
      cin>>x;
      a[i]=x;
  }
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    
    cout<<mincost(a,dp,0,n-1)<<endl;
    

   return 0;
}
