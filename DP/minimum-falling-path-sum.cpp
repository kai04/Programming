//https://leetcode.com/problems/minimum-falling-path-sum/submissions/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX/2));
        for(int i=0;i<n;i++){
            dp[0][i]=A[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j-1>=0 && j+1<n){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+A[i][j]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+A[i][j]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j+1]+A[i][j]);
                }
                else if(j-1>=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+A[i][j]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+A[i][j]);
                    // dp[i][j]=max(dp[i][j],dp[i-1][j]+A[i][j+1]);
                }
                else if(j+1<n){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+A[i][j]);
                    // dp[i][j]=max(dp[i][j],dp[i-1][j-1]+A[i][j]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j+1]+A[i][j]);
                }
                else{
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+A[i][j]);
                }
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};
