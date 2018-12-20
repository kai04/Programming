//https://leetcode.com/problems/distinct-subsequences-ii/submissions/
typedef long long ll;
ll mod = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
       int n = s.length();
    vector<int> dp(n+1,-1);
    map<char,int> last;
    for(int i=0;i<n;i++){
        last[s[i]]=-1;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        //dp[i]=2*dp[i-1]
        dp[i]=(dp[i-1]+mod+dp[i-1])%mod;
        if(last[s[i-1]]!=-1){
            //dp[i]=dp[i]-{repeatition}
            dp[i]=((dp[i]+mod-dp[last[s[i-1]]])%mod);
        }
        last[s[i-1]]=i-1;
    }
        return dp[n]-1;
    }
};
