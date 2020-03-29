//https://leetcode.com/problems/house-robber/
class Solution {
public:
    int sol(vector<int>& nums,int last,int i,vector<vector<int>> &dp){
        //base case
        if(i==nums.size())
            return 0;
        if(dp[i][last]!=-1)
            return dp[i][last];
        
        if(last==0){
            dp[i][last]=max(dp[i][last],nums[i]+sol(nums,1,i+1,dp));
            dp[i][last]=max(dp[i][last],sol(nums,0,i+1,dp));
        }
        else{
            dp[i][last]=max(dp[i][last],sol(nums,0,i+1,dp));
        }
        return dp[i][last];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        int ans = sol(nums,0,0,dp);
        return ans;
    }
};
