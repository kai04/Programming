//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int LPS(string s){
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 2;
            }else{
                dp[i][i+1] = 1;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<n;i++){
                int j = i+len-1;
                if(j<n){
                // cout<<"i:"<<i<<" j:"<<j<<endl;
                    if(s[i]==s[j]){
                        dp[i][j] = max(dp[i][j],2+dp[i+1][j-1]);
                    }
                    else{
                        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    }
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        int n = s.length();
        int x = LPS(s);
        int ans = n-x;
        return ans;
    }
};

int main(){
    string s;
    cin>>s;
    Solution p;
    int ans = p.minInsertions(s);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}