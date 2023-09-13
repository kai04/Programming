https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int ans =0;
        vector<int> dp(n+1, INT_MIN/2);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int t = nums[i]-nums[j];
                if(abs(t)<=target){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        if(dp[n-1]>=0)
            return dp[n-1];
        return -1;
    }
};