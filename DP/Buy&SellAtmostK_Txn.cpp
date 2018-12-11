class Solution {
public:
     int quickSolve(vector<int> prices) {
        int len = prices.size(), profit = 0;
        for (int i = 1; i < len; i++)
            // as long as there is a price gap, we gain a profit.
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k>=n/2)
            return quickSolve(prices);
        //inititilize
        //dp[i][j][k]:it denotes max profit after jth day when i txn already completed with k stocks in our hand
        
       vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(n+1,vector<int>(2,INT_MIN)));
        //if zero transaction remaining then no profit can be gain irrespective of how many days are left
        for(int i=0;i<=n;i++){
            dp[0][i][0]=0;
        }
        // if 0 days are left then no profit can be gain irrespective of how many txn are left
        for(int i=0;i<=k;i++){
            dp[i][0][0]=0;
        }
        // recursion
        for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                //ref:https://www.youtube.com/watch?v=oDhu5uGq_ic&t=963s
                //max profit we can gain by buying between day 1 to j-1 and selling at day j
                //Note: dp[i-1][j-1][0]: it is max profit we get so far after one less transaction till day j-1
                dp[i][j][1]=max(dp[i][j-1][1],dp[i-1][j-1][0]-prices[j-1]);
                // Note trx complete after selling stock that is why dp[i][j][1] not dp[i-1][j][1]
                //either not transacting on day j or max profit gain so far till day j with one stock on our hand(already buy) and selling on day j 
                dp[i][j][0]=max(dp[i][j-1][0],dp[i][j][1]+prices[j]);
            }
        }
        
        return dp[k][n-1][0];
    }
};
