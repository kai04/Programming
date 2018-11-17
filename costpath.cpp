#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
int min3(int a,int b,int c){
    return min(min(a,b),c);
}
int mincost_rec(int m,int n,vector<vector<int>> &a){
    if(m<0||n<0)
        return INT_MAX;
    else if(m==0 && n==0)
        return a[m][n];
    else{
        return (a[m][n]+min3(mincost_rec(m-1,n-1,a),mincost_rec(m-1,n,a),mincost_rec(m,n-1,a)));
    }
}

int mincost(int m,int n,vector<vector<int>> &a,vector<vector<int>> &dp){
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(i==0 && n==0)
            dp[i][j]=a[i][j];
        else if(i==0)
            dp[i][j]=a[i][j]+dp[i][j-1];
        else if(j==0)
            dp[i][j]=a[i][j]+dp[i-1][j];
        else{
            dp[i][j]=a[i][j]+min3(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
        }
    }
    
}
    return dp[m-1][n-1];
}
int main() {
    int m,n,x;
    cin>>m>>n;
    vector<vector<int>> a(m);
    vector<vector<int>> dp(m);
    for(int i=0;i<m;i++){
        a[i].resize(n);
        dp[i].resize(n);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            a[i][j]=x;
            dp[i][j]=9999;
        }
    }
    
   
    
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
         cout<<a[i][j]<<" ";   
        }
        cout<<endl;
    }*/
    cout<<mincost_rec(m-1,n-1,a)<<endl;
    cout<<mincost(m,n,a,dp)<<endl;
    
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
         cout<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
