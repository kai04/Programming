//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
//https://leetcode.com/problems/longest-palindromic-subsequence/submissions/
#include <bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        //if length of string is 1 then LPS is 1 only
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int start=0;start+len-1<n;start++){
                int end=start+len-1;
                if(s[start]==s[end] && start+1==end)
                    dp[start][end]=2;
                else if(s[start]==s[end])
                    dp[start][end] = 2+dp[start+1][end-1];
                else
                    dp[start][end]=max(dp[start+1][end],dp[start][end-1]);
            }
        }
        
        return dp[0][n-1];
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       int n=s.length();
       vector<vector<bool>> dp(n,vector<bool>(n,false));
       for(int i=0;i<n;i++)
        {dp[i][i]=true;}
       for(int i=0;i<n-1;i++)
        {if(s[i]==s[i+1])
            dp[i][i+1]=true;
        else
            dp[i][i+1]=false;
        }
        for(int i=3;i<=n;i++){
            for(int j=0;j<n-1;j++){
                int k=j+i-1;
                if(k<n){
                    if(s[j]==s[k])
                        dp[j][k]=dp[j+1][k-1];
                    else
                        dp[j][k]=false;
                }
            }
        }
        
        int start1=0;
        int end1=0;
        int max_len=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                int k=i+j-1;
                if(k<n){
                if(dp[i][k]){
                    if((k-i+1)>max_len){
                        max_len=k-i+1;
                        start1 =i;
                        end1=k;
                    }
                }
                }
            }
        }
        for(int p=start1;p<=end1;p++){
            cout<<s[p];
        }
        cout<<endl;
        
    }
	//code
	return 0;
}