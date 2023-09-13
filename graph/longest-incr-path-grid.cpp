// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/
class Solution {
public:
    int dir_x[4] = {-1,0,1,0};
    int dir_y[4] = {0,-1,0,1};
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n, int prev){
        // base case
        if(i<0 || j<0 || i>=m|| j>=n|| matrix[i][j]<=prev){
            return 0;
        }
        
        //memoization
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int d=0;d<4;d++){
            int x = 1+dfs(i+dir_x[d],j+dir_y[d], matrix, dp,m,n,matrix[i][j]);
            dp[i][j] = max(x, dp[i][j]);
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans =0;
        vector<vector<int>> dp(m+1, vector<int> (n+1,-1)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = dfs(i,j,matrix,dp,m,n,-1);
                ans = max(ans, x);
            }
        }
        return ans;
    }
};