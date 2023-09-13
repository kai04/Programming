//https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
const int mod = 1e9+7;
class Solution {
public:
    int dir_x[4] = {-1,1,0,0};
    int dir_y[4] = {0,0,-1,1};
    int dfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& dp, int prev){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int path =1;
        for(int d=0;d<4;d++){
            path = (path + dfs(i+dir_x[d],j+dir_y[d], grid, dp, grid[i][j]))%mod;
        }
        dp[i][j] = path;
        return dp[i][j];

    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int paths = 0;
        int prev = -1;
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                paths = (paths + dfs(i,j, grid, dp, prev))%mod;
            }
        }
        return paths;
    }
};