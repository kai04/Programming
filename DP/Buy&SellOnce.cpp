//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
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
