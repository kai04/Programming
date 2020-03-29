//https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
#define mod 1000000007
typedef long long ll;
static ll solve(int pos,int step,int n,vector<vector<ll>> &dp){
        //base cases
        if(pos>step){
            return 0;
        }
        if(pos<0 || pos>=n){
            return 0;
        }
        if(step==0){
            if(pos==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[pos][step]!=0){
            return dp[pos][step];
        }
        ll x = solve(pos+1,step-1,n,dp);
        ll y = solve(pos-1,step-1,n,dp);
        ll z = solve(pos,step-1,n,dp);
        
        // cout<<"dp[pos][step]:"<<dp[pos][step]<<" mod:"<<mod<<endl;
        dp[pos][step] = (ll)(x%mod+y%mod+z%mod)%(ll)mod;
    return dp[pos][step];
    }
class Solution {
public:
    //int ans = 0;
    
    int numWays(int steps, int arrLen) {
        int ans  = 0;
        vector<vector<ll>> dp(arrLen,vector<ll>(steps+1,0));
        ans  = solve(0,steps,arrLen,dp);
        return ans;
    }
};