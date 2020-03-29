//                                                                                                                                                                                                                                                                                  https://leetcode.com/problems/target-sum/
class Solution {
public:
//Note: we have shifted origin to 1000 because it is given that sum of all numbers in array(nums) is less than 1000
//      so even if we take negative sign for all no still our index is positive
    int solve(int s,vector<int>& nums,int i,int S,vector<vector<int>> &dp){
        int x=0,y=0;
        if(i==nums.size()&&s==S)
        {return 1;}
        else if(i==nums.size())
        {return 0;}
        else{
            if(dp[s+1000][i]!=INT_MIN)
                return dp[s+1000][i];
            x=solve(s-nums[i],nums,i+1,S,dp);
            y=solve(s+nums[i],nums,i+1,S,dp);
        }
        dp[s+1000][i]=x+y;
        return dp[s+1000][i];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp(2001,vector<int>(nums.size(),INT_MIN));
        return solve(0,nums,0,S,dp);
    }
};
