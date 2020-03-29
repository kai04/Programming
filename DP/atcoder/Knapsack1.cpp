//https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,W;
    cin>>n>>W;
    vector<ll> w(n);
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(W+1,0));
    for(ll j=1;j<=W;j++){
        for(ll i=1;i<=n;i++){
            if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];   
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<"------------------------"<<endl;
    cout<<dp[n][W]<<endl;    
    return 0;
}
