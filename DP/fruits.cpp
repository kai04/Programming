#include <bits/stdc++.h> 
using namespace std;
int solve(int i, int j,vector<vector<int>> &dp, vector<int>& prices){
    int n = prices.size();
    //base case
    if(i>=n-1){
        if(i<=(2*j+1)){
            dp[i][j] = 0;
            return 0;
        } else{
            dp[i][j] = prices[i];
            return prices[i];
        }
    }
    
    //memoization
    if(dp[i][j]!=INT_MAX/2){
        return dp[i][j];
    }
    
    int ans = 0;
    if(i<=(2*j+1)){
        ans += min(solve(i+1,i,dp,prices)+prices[i],solve(i+1,j,dp,prices));
    } else{
        ans +=solve(i+1,i,dp,prices)+prices[i];
    }
    dp[i][j] = ans;
    return dp[i][j];
}

// int solve_new(vector<int>& prices,vector<vector<int>> &dp){
//     int n = prices.size();
//     dp[0] = prices[0];

//     for(int i=1;i<n;i++){
//       int k = (i-1)/2;
//       for(int p=i-1;p>=0 && p>j;p--){

//       }  
//     }
// }

int minimumCoins(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX/2));
    int ans = prices[0]+solve(0,0,dp,prices);
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = minimumCoins(a);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}