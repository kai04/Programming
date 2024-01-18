//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
class Solution {
public:
    int f(int i,int j, vector<vector<int>> &dp,vector<int> &cut){
        //base case
        if(i>=j){
            cout<<"i:"<<i<<" j:"<<j<<" ret:"<<0<<endl;
            return 0;
        }
        //memoization
        if(dp[i][j]!=INT_MAX/2){
            return dp[i][j];
        }
        int res =  INT_MAX/2;
        for(int k=0;k<cut.size();k++){
            if(cut[k]>i && cut[k]<j){
                int temp1 =  f(i,cut[k],dp,cut);
                int temp2 = f(cut[k],j,dp,cut);
                // cout<<"temp1:"<<temp1<<" temp2:"<<temp2<<" k:"<<k<<" cut[k]:"<<cut[k]<<endl;
                res = min(res,(temp1+temp2+(j-i)));
            }
        }
        
        
        if(res==INT_MAX/2){
            res=0;
        }
        cout<<"i:"<<i<<" j:"<<j<<" ret:"<<res<<endl;
        dp[i][j] = res;
        return res;
    }
    int solve(int n, vector<int>& cuts){
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MAX/2));
        for(int i=0;i<m-1;i++){
            dp[i][i+1] = 0;
        }
        for(int l=2;l<m;l++){
            for(int i=0;i<m;i++){
                int j = i+l;
                if(j<m){
                    int L = cuts[i];
                    int R = cuts[j];
                    for(int k=i+1;k<j;k++){
                        int K = cuts[k];
                        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+(R-L));
                    }
                }
            }
        }
        return dp[0][m-1];

    }
    int minCost(int n, vector<int>& cuts) {
        int ans = solve(n,cuts);
        return ans;
    }
};