//https://leetcode.com/problems/longest-arithmetic-sequence/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int ans = 1;
        int n = A.size();
        if(n==0)
            return 0;
        vector<map<int,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = (A[j]-A[i]);
                int curr_len = 2;
                if(dp[i].find(diff)!=dp[i].end()){
                    curr_len = max(curr_len,dp[i][diff]+1);
                }
                dp[j][diff] = curr_len;
                ans = max(ans,curr_len);
            }
        }
        return ans;
    }
};