//https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(int j=0;j<n;j++){
            for(int i=1;i<=amount;i++){
                if(i>=coins[j]){
                    dp[i] +=dp[i-coins[j]]; 
                }
            }
        }
        /*for(auto it:dp)
            cout<<it<<" ";
        cout<<endl;*/
        return dp[amount];
    }
};