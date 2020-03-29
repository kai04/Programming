//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/149383/Easy-DP-solution-using-state-machine-O(n)-time-complexity-O(1)-space-complexity
//ref:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/200126/simple-c%2B%2B-DP-beats-99.66-with-explanation
class Solution {
public:
	int maxProfit1(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return n;
        vector<int> profit_front(n+1,0);
        vector<int> profit_back(n+1,0);
        int minBuy=prices[0];
        int maxSell=prices[n-1];
        for(int i=1;i<=n;i++){
            minBuy=min(minBuy,prices[i-1]);
            profit_front[i]=max(profit_front[i-1],prices[i-1]-minBuy);
        }
        for(int i=n-1;i>=0;i--){
            maxSell=max(maxSell,prices[i]);
            profit_back[i]=max(profit_back[i+1],maxSell-prices[i]);
        }
        /*for(int i=0;i<=n;i++){
            cout<<profit_front[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<=n;i++){
            cout<<profit_back[i]<<" ";
        }
        cout<<endl;*/
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,profit_front[i]+profit_back[i]);
        }
        return ans;
                
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return n;
        int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;
        
        for(int i=0;i<n;i++){
            s1=max(s1,-prices[i]);
            s2=max(s2,s1+prices[i]);
            s3=max(s3,s2-prices[i]);
            s4=max(s4,s3+prices[i]);
            
        }
        int ans = max(0,s4);
        return ans;
                
    }
};
