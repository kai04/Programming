//https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/submissions/
static int solve(int i,int j,int k,int d,vector<int>& job,vector<vector<vector<int>>> &dp){
    //base case
    int n = job.size();
    if(i==n){
        if(j==d)
            return k;
        else
            return (INT_MAX/2);
    }
    if(j==d){
        return solve(i+1,j,max(k,job[i]),d,job,dp);
    }
    //memoization
    if(dp[i][j][k]!=INT_MAX/2){
        return dp[i][j][k];
    }
    int p = solve(i+1,j,max(k,job[i]),d,job,dp);
    int q = solve(i+1,j+1,job[i],d,job,dp)+k;
    dp[i][j][k] = min(dp[i][j][k],min(p,q));
    return dp[i][j][k];
}
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d>n){
            return -1;
        }
        int s = 0;
        for(int i =0;i<n;i++){
            s = max(s,jobDifficulty[i]);
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(d+1,vector<int>(s+1,INT_MAX/2)));
        int ans = solve(1,1,jobDifficulty[0],d,jobDifficulty,dp);
        if(ans==INT_MAX/2)
            return -1;
        return ans;
    }
};