//https://leetcode.com/problems/maximal-square/submissions/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        if(n==0)
            return 0;
        if(n==1){
            for(int i=0;i<matrix[0].size();i++){
                if(matrix[0][i]=='1'){
                    return 1;
                }
            }
            return 0;
        }
        int m = matrix[0].size();
        if(m==1){
            for(int i=0;i<matrix.size();i++){
                if(matrix[i][0]=='1'){
                    return 1;
                }
            }
            return 0;
        }
        int ans = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                {
                    dp[i][j] = 1;
                    ans =1;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i][j]==1){
                    int min1 = min(dp[i-1][j],dp[i][j-1]);
                    min1 = min(min1,dp[i-1][j-1]);
                    dp[i][j] = min1 + dp[i][j];
                    
                }
                else{
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return (ans*ans);
        
    }
};
