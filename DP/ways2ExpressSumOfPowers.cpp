//https://leetcode.com/contest/biweekly-contest-109/problems/ways-to-express-an-integer-as-sum-of-powers/
#include<math.h>
const int mod = 1e9+7;
class Solution {
public:
    
    int helper(int n, int x, int i, unordered_map<string,int> &dp){
        //base case
        if(n==0){
            return 1;
        }
        
        if(n<0 || pow(i, x)>n){
            return 0;
        }
        ostringstream os1,os2;
        os1<<n;
        os2<<i;
        string key = os1.str() + ":" + os2.str();  
        // memoization
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        
        int include_ans = helper((n-pow(i,x)), x, i+1,dp)% mod;
        int exclude_ans = helper( n, x, i+1,dp)% mod;
        
        int total_ans = (include_ans + exclude_ans)% mod;
        dp[key] = total_ans;
        return total_ans;
    }
    
    int f(int n, int x){
        vector<int> coins;
        for(int i=1; pow(i,x)<=n;i++){
            int p = pow(i,x);
            if(p<=n)
                coins.push_back(p);
        }
        int m = coins.size();
        
        //base case
        // dp[i][j] :  No of ways to create sum i with cosidering coins from 0 to j
        
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
            dp[i][0] = 0;
        
        for(int j=0;j<coins.size();j++)
            dp[0][j] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i>=coins[j-1]){ //include
                    dp[i][j] = (dp[i-coins[j-1]][j-1] + dp[i][j-1])%mod;
                } else{ //exclude
                    dp[i][j] = dp[i][j-1]%mod;
                }
            }
        }
        return dp[n][m];
    }
    
    int numberOfWays(int n, int x) {
        unordered_map<string,int> m;
        // int ans = helper(n, x, 1, m);
        int ans = f(n,x);
        return ans;
        
    }
};