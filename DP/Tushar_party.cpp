//https://www.interviewbit.com/problems/tushars-birthday-party/
#include <bits/stdc++.h>
using namespace std;
 
static int f(int i,int k,const vector<int> &A, const vector<int> &B, const vector<int> &C,vector<vector<int>> &dp){
    int N = A.size();
    //base case
    // cout<<"i:"<<i<<" k:"<<k<<endl;
    if(i>=N){
        return 0;
    }
    if(k==0){
        if(i==N-1){
            return 0;
        }
        else{
            return f(i+1,A[i+1],A,B,C,dp);
        }
    }
    //memoization
    if(dp[i][k]!=INT_MAX/2){
        return dp[i][k];
    }
    for(int j=0;j<B.size();j++){
        if(B[j]<=k)
            dp[i][k] = min(dp[i][k],(C[j]+f(i,k-B[j],A,B,C,dp)));
    }
    return dp[i][k];
}
int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n = A.size();
    int m = 0;
    for(int p = 0;p<n;p++){
        m = max(m,A[p]);
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX/2));
    int ans = f(0,A[0],A,B,C,dp);
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    std::vector<int> a(n),b(m),c(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    cout<<"Here:"<<endl;
    int ans = solve(a,b,c);
    cout<<ans<<endl;
    return 0;
}