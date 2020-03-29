//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/shivam-shantam-and-their-absolute-difference-3/description/

#include <bits/stdc++.h>
using namespace std;
int n,q;
void setreset(int &f,int j){
    if(j<0)
        {
            f=1;
        }
        else{
            f=0;
        }
}
int solve(int i,int j,int f,vector<int> a,vector<int> b,vector<vector<vector<int>>> dp){
    if(i==n){
        if(j<=q)
            return 1;
        else
            return 0;
    }
    if(f)
    {
        j=-j;
    }
    int ans=0;
    int tempj;
    if(dp[i][j][f]==-1){
        tempj=j;
        setreset(f,tempj);
        ans += solve(i+1,tempj,f,a,b,dp);
        
        tempj=j+a[i];
        setreset(f,tempj);
        ans += solve(i+1,tempj,f,a,b,dp);
        
        tempj=j-b[i];
        setreset(f,tempj);
        ans += solve(i+1,tempj,f,a,b,dp);
        
        tempj=j+abs(a[i]-b[i]);
        setreset(f,tempj);
        ans += solve(i+1,tempj,f,a,b,dp);
        dp[i][j][f]=ans;
    }
    return dp[i][j][f];
}
int main()
{
    
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    //int q;
    cin>>q;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2001,vector<int>(2,-1)));
    cout<<solve(0,0,0,a,b,dp)<<endl;
    return 0;
}

