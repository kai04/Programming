//read this https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int profit=0;
        vector<int> buy(n);
        vector<int> sell(n);
        //initialize
        buy[0]=-prices[0];
        sell[0]=0;
	// buy[i]: it denotes max profit till day i if we perform buy operation on day i
	// sell[i]: it denotes max profit till day i if we perform sell operation on day i
        for(int i=1;i<n;i++){
            buy[i]=max(buy[i-1],sell[i-1]-prices[i]);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]-fee);
            // cout<<"i:"<<i<<" buy:"<<buy[i]<<" sell:"<<sell[i]<<endl;
            
        }
        return sell[n-1];
    }
};
