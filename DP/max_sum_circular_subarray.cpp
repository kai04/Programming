//https://leetcode.com/problems/maximum-sum-circular-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=nums[0];
        int maxsum=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            maxsum=max(maxsum,dp[i]);
        }
        return maxsum;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        for(int x:A)
            sum+=x;
        int pos_sum = maxSubArray(A); 
        for(int i=0;i<n;i++){
            A[i] = -A[i];
        }
        int neg_sum = INT_MIN;
        neg_sum = maxSubArray(A);
        if(abs(sum)==abs(neg_sum))
            return pos_sum;
            
        return max((sum+neg_sum),pos_sum);
    }
};
