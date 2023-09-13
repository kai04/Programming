//https://leetcode.com/problems/valid-palindrome-ii/
class Solution {
public:
    int lcs(int i,int j, string s, string t, vector<vector<int>> &dp){
        //base case
        if(i==0 || j==0){
            return 0;
        }
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j]){
            dp[i][j] = 1+lcs(i-1,j-1,s,t,dp);
        } else{
            dp[i][j] = max(lcs(i-1,j,s,t,dp),lcs(i,j-1,s,t,dp));
        }
        return dp[i][j];
    }
    bool check_pallindrome(int i, int j, string s, pair<int,int> &p){
        bool pal = true;
        int n = s.length();
        while(i<j && i<n && j>=0){
            if(s[i]==s[j]){
                i++;
                j--;
            } else{
                p.first = i;
                p.second = j;
                pal = false;
                break;
            }
        }
        return pal;
    }

    bool validPalindrome(string s) {
        /*
            abca
            acba

            abc
            cba
        */
        int n = s.length();
        // string t = string(s.rbegin(), s.rend());
        
        pair<int,int> p = {-1,-1};
        bool c1 = check_pallindrome(0,n-1,s,p);
        pair<int,int> q = p;
        // cout<<"c1:"<<c1<<" i:"<<p.first<<" j:"<<p.second<<endl;
        if(c1){
            return true;
        } else {
            bool c2 = check_pallindrome(p.first+1,p.second,s,p);
            bool c3 = check_pallindrome(q.first,q.second-1,s,p);
            // cout<<"c2:"<<c2<<" c3:"<<c3<<endl;
            return (c2 || c3);
        }
        // vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        // // int ans = lcs(n-1,n-1,s,t,dp);
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         } else{
        //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // int ans = dp[n][n];
        // if(n-ans<=1){
        //     return true;
        // }
        return false;
       
    }

};