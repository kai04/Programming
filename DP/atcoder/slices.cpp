//https://atcoder.jp/contests/dp/tasks/dp_n
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> &A){
   int n = A.size();
   vector<vector<ll>> dp(n+1,vector<ll>(n+1,LONG_MAX/2));
   vector<ll> sum(n+1,0);
   for(int i=0;i<n;i++){
        dp[i][i] = 0;
        sum[i+1]=sum[i]+A[i];
   }
   for(int l=2;l<=n;l++){
        for(int i=0;i+l-1<n;i++){
        int j = i+l-1;
        for(int k=i;k<j;k++){
            ll x = dp[i][k] + dp[k+1][j] + sum[j+1]-sum[i];
            dp[i][j] = min(dp[i][j], x);
        }
     }
   }
   // for(int i=0;i<n;i++){
   //  for(int j=0;j<n;j++){
   //      cout<<dp[i][j]<<" ";
   //  }
   //  cout<<endl;
   // }
   return dp[0][n-1];
}
int main(){
  	int n;
  	cin>>n;
  	vector<ll> A(n);
  	for(int i=0;i<n;i++){
  		cin>>A[i];
  	}
  	ll ans = solve(A);
    cout<<ans<<endl;

    return 0;
}
