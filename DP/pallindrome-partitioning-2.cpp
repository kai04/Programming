//https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    int f(int i, string &s, vector<int> &dp,vector<vector<bool>> &isPal){
        int n = s.length();
        //base case
        if(i==n){
            return 0;
        }
        //memoization
        if(dp[i]!=-1){
            return dp[i];
        }
        int min_cost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPal[i][j]){
                int curr_cost = 1+f(j+1,s,dp,isPal);
                min_cost = min(min_cost,curr_cost);
            }
        }
        dp[i] = min_cost;
        return dp[i];
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            isPal[i][i] = true;
        }
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                isPal[i-1][i] = true;
            }
        }
        
        for(int len=3;len<=n;len++){
            for(int i=0;i<n;i++){
                int  j = i+len-1;
                if(j<n){
                    if(s[i]==s[j] && isPal[i+1][j-1]){
                        isPal[i][j] = true;
                    }
                }
            }        
        }
        int res = f(0, s,dp,isPal);
        return res-1;
    }
};