//https://atcoder.jp/contests/dp/tasks/dp_h
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9L +5;
int main(){
    ll h,w;
    cin>>h>>w; 
    vector<vector<ll>> A(h,vector<ll> (w));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            char c;
            cin>>c;
            if(c=='.'){
                A[i][j] = 1;
            } else{
                A[i][j] = 0;
            }
        }
    }
    
    vector<vector<ll>> dp(h,vector<ll> (w,0));
    dp[0][0] = 1;
    for(ll i=1;i<h;i++){
        if(A[i][0]==1){
            dp[i][0] = dp[i-1][0];
        } else{
            dp[i][0] = 0;
        }
    }
    for(ll j=1;j<w;j++){
        if(A[0][j]==1){
            dp[0][j] = dp[0][j-1];
        } else{
            dp[0][j] = 0;
        }   
    }

    for(ll i=1;i<h;i++){
        for(ll j=1;j<w;j++){
            if(A[i][j]){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;

            } else{
                dp[i][j] = 0;
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
 
    return 0;
}
