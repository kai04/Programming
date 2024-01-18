//https://leetcode.com/contest/weekly-contest-366/problems/apply-operations-to-make-two-strings-equal/
class Solution {
public:
    int dp[502][502];
    int solved(vector<int> &d, int i, int x, int n){
        //base case
        if(i==d.size()){
            if(n==0){
                return 0;
            } else{
                return 999999;                
            }
        } 
        // memoization
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        
        int res = INT_MAX;
        //case 1
        if(i<d.size()-1){
            res = min(res, (d[i+1]-d[i]+ solved(d,i+2,x,n)));
        }
        //case 2
        res = min(res, (x+solved(d,i+1,x,n+1)));
        //case 3
        if(n>0){
            res = min(res, solved(d,i+1,x,n-1));
        }
        
        dp[i][n] = res;
        
        return dp[i][n];
    }
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        vector<int> d;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                d.push_back(i);
            }
        }
        int m = d.size();
        if(m%2==1){
            return -1;
        }
        memset(dp, -1,sizeof dp);
        int ans = solved(d,0,x,0);
        return ans;
    }
};