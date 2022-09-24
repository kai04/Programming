//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfitNew(vector<int> &prices){
        int lsf = INT_MAX; // least so far
        int op = 0; // overall profit
        int pist = 0; // profit if sold today
        
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < lsf){ // if we found new buy value which is more smaller then previous one
                lsf = prices[i]; // update our least so far
            }
            pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
            if(op < pist){ // if pist is more then our previous overall profit
                op = pist; // update overall profit
            }
        }
        return op; // return op 
    }
    int maxProfit(vector<int>& prices) {
     int n=prices.size();
        vector<int> maxSell(n);
            vector<int> minBuy(n);
        int maxs=INT_MIN;
        int minb=INT_MAX;
        for(int i=0;i<n;i++){
            minb=min(minb,prices[i]);
            maxSell[i]=minb;
        }
        
        for(int i=n-1;i>=0;i--){
            maxs=max(maxs,prices[i]);
            minBuy[i]=maxs;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,abs(maxSell[i]-minBuy[i]));
        }
        return ans;
    }
};
