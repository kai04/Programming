//https://atcoder.jp/contests/dp/tasks/dp_o
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int limit = 1e7+7;
ll helper(ll avail, vector<vector<int>> &A, vector<ll> &dp){
    int i = __builtin_popcount(avail);
    int n = A[0].size();
    //base case
    if(i>=n){
        int n = A[0].size();
        ll p = ((1<<n)-1);//https://atcoder.jp/contests/dp/tasks/dp_o
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int limit = 1e7+7;
ll helper(ll avail, vector<vector<int>> &A, vector<ll> &dp){
    int i = __builtin_popcount(avail);
    int n = A[0].size();
    //base case
    if(i>=n){
        int n = A[0].size();
        ll p = ((1<<n)-1);
        if(avail==p){
            // dp[i][avail] = 1;
            return 1;    
        } else{
            // dp[i][avail] = 0;
            return 0;
        }
    }
    // memoization
    if(dp[avail]!=-1){
        return dp[avail];
    }
    ll ret = 0;
    for(int j=0;j<A[i].size();j++){
        if(A[i][j]==1 && !(avail & (1<<j))) {
            avail = (avail | (1<<j));
            ret = (ret + helper(avail, A, dp))%mod;
            avail = (avail ^ (1<<j));
        }
    }
    dp[avail] = ret;
    return ret;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    vector<ll> dp((1<<n)+1, -1);
    int ans = helper(0,A,dp);
    cout<<ans<<endl;

    return 0;
}

        if(avail==p){
            // dp[i][avail] = 1;
            return 1;    
        } else{
            // dp[i][avail] = 0;
            return 0;
        }
    }
    // memoization
    if(dp[avail]!=-1){
        return dp[avail];
    }
    ll ret = 0;
    for(int j=0;j<A[i].size();j++){
        if(A[i][j]==1 && !(avail & (1<<j))) {
            avail = (avail | (1<<j));
            ret = (ret + helper(avail, A, dp))%mod;
            avail = (avail ^ (1<<j));
        }
    }
    dp[avail] = ret;
    return ret;
}

int main(){
  	int n;
  	cin>>n;
  	vector<vector<int>> A(n, vector<int>(n));
  	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
  		    cin>>A[i][j];
        }
  	}
    vector<ll> dp((1<<n)+1, -1);
    int ans = helper(0,A,dp);
    cout<<ans<<endl;

    return 0;
}
