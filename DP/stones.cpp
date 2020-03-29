//https://leetcode.com/problems/stone-game/submissions/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n =piles.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //initialize
        int sum=0;
        for(int i=0;i<n;i++){
            dp[i][i] = piles[i];
            sum+=piles[i];
        }
        
        for(int L=n-1;L>=0;L--){
            for(int R=L;R<n;R++){
                if(L==R){
                    dp[L][R] = piles[L];
                }
                else{
                    dp[L][R] = max((piles[L]-dp[L+1][R]),(piles[R]-dp[L][R-1]));
                }
            }
            
        }
        if(dp[0][n-1]>0){
            return true;
        }
        return false;
    }
};