https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                      dp[i][j] = dp[i-1][j - 1]+dp[i-1][j];
                     }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        /*for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return dp[n][m];
    }
};
