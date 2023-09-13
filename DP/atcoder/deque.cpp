//https://atcoder.jp/contests/dp/tasks/dp_l
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int i, int j, int turn,vector<ll> &A, vector<vector<vector<ll>>> &dp){
    // cout<<"i:"<<i<<" j:"<<j<<endl;
    if(i==j){
        if(turn==0){
            dp[i][j][turn] = A[i];
            return A[i];
        } else{
            dp[i][j][turn] = -1*A[i];
            return -1*A[i];
        }
    }

    // memoization
    if(dp[i][j][turn]!=-1){
        return dp[i][j][turn];
    }
    ll ret;
    if(turn==0){
        ret = max(A[i]+solve(i+1,j,1-turn, A, dp), A[j]+solve(i,j-1,1-turn, A, dp));
    } else{
        ret = min(solve(i+1,j,1-turn, A, dp)- A[i], solve(i,j-1,1-turn, A, dp)- A[j]);       
    }
    dp[i][j][turn] = ret;
    return ret;
}
int main(){
  	int n;
  	cin>>n;
  	vector<ll> A(n);
  	for(int i=0;i<n;i++){
  		cin>>A[i];
  	}
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(2,-1)));
  	ll ans = solve(0,n-1,0,A,dp);
    cout<<ans<<endl;

    return 0;
}
