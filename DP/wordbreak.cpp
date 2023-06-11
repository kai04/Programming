//https://leetcode.com/problems/word-break/
class Solution {
public:
    bool solve(int i,int j,string s,vector<vector<int>> &dp, vector<string>& wordDict){
        //base cases
            
        //memoization
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=0;
        int len = j-i+1;
        string pref_all = s.substr(i,len);
        if((find(wordDict.begin(),wordDict.end(),pref_all)!=wordDict.end())){
                dp[i][j] = 1;
                return true; 
        }
        else{
            for(int p=1;p<len;p++){
                string pref = s.substr(i,p);
                if((find(wordDict.begin(),wordDict.end(),pref)!=wordDict.end())){
                        dp[i][i+p-1] = 1;
                        dp[i][j] = dp[i][j] || (dp[i][i+p-1] && solve(i+p,j,s,dp,wordDict)); 
                }
            }
        }
                
        return dp[i][j];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        bool res = solve(0,n-1,s,dp,wordDict);
        return res;
    }
};