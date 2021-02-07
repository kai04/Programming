//https://leetcode.com/problems/last-stone-weight-ii/submissions/


class Solution {
public:
    int solve(int i,int sum,vector<int>& a,vector<vector<int>> &dp){
        int n = a.size();
        if(i==n)
            return abs(sum);
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        dp[i][sum] = min(solve(i+1,abs(sum+a[i]),a,dp),solve(i+1,abs(sum-a[i]),a,dp));
        return dp[i][sum];
        
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=stones[i];
    
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int ans = solve(0,0,stones,dp);
        return ans;
    }
};
