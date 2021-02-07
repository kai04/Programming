//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/submissions/w
#define INF 1e6
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
        //base case
        dp[0][0] = 0;
        for(int i=1;i<=s1.length();i++)
            dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int j=1;j<=s2.length();j++)
            dp[0][j] = dp[0][j-1] + s2[j-1];
        //recursion
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int s1_asc = (int)s1[i-1];
                    int s2_asc = (int)s2[j-1];
                    dp[i][j] = min(dp[i][j],s1_asc+dp[i-1][j]);
                    dp[i][j] = min(dp[i][j],s2_asc+dp[i][j-1]);
                    dp[i][j] = min(dp[i][j],s1_asc+s2_asc+dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};