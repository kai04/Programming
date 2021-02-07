//https://leetcode.com/problems/predict-the-winner/submissions/
static int solve(int start,int end,vector<vector<int>> &dp,vector<int>& a){
    //base case
    if(start==end){
        return a[start];
    }
    if(start>end)
        return 0;
    //memoization
    if(dp[start][end]!=INT_MIN/2){
        return dp[start][end];
    }
    dp[start][end] = max(a[start]-solve(start+1,end,dp,a),a[end]-solve(start,end-1,dp,a));
    return dp[start][end];
    
}
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN/2));
        int ans = solve(0,n-1,dp,nums);
        if(ans>=0)
            return true;
        return false;
    }
};