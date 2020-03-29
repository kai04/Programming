//https://leetcode.com/problems/unique-binary-search-trees/submissions/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll nCr(ll n,ll r,vector<vector<ll>> &dp){
        if(n==r || r==0){
            return 1;
        }
        if(dp[n][r]!=-1)
            return dp[n][r];
        else{
            dp[n][r] = nCr(n-1,r-1,dp)+nCr(n-1,r,dp); 
        }
        return dp[n][r];
    }
    int numTrees(int n) {
        vector<vector<ll>> dp((2*n)+1,vector<ll>(n+1,-1));
        ll x  =  nCr(2*n,n,dp);
        ll ans = x/(n+1);
        return ans;
        
    }
};

int main(){
    Solution s;
    int n; 
    cin>>n;  
    cout<<s.numTrees(n)<<endl;
    return 0;
}