//https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e12L +5;
int main(){
    ll n,W,sum=0;
    cin>>n>>W;
    vector<ll> w(n);
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>w[i]>>v[i];
        sum+=v[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,INF));
    //base case
    for(ll i=0;i<n;i++){
        dp[i][0] = 0;
    }
    for(ll j=1;j<=sum;j++){
        for(ll i=1;i<=n;i++){
            if(v[i-1]<=j){
                dp[i][j] = min(dp[i-1][j],w[i-1]+dp[i-1][j-v[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];   
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------------"<<endl;
    ll answer = 0;
    for(ll i=0;i<=sum;i++){
        if(dp[n][i]<=W){
            answer = max(answer,i);
        }
    }
    cout<<answer<<endl;    
    return 0;
}
