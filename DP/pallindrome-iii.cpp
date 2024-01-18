//https://leetcode.com/problems/palindrome-partitioning-iii/description/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;  
void calcuate_pallindrome_edit(string &s, vector<vector<int>> &chgPal){
    int n = s.length();
    chgPal.resize(n, vector<int>(n,0));
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            chgPal[i][i+1] = 1;
        }
    }

    for(int l=3;l<=n;l++){
        for(int i=0;i<n;i++){
            int j = i+l-1;
            if(j<n){
                if(s[i]!=s[j]){
                    chgPal[i][j] = chgPal[i+1][j-1] + 1;
                } else{
                    chgPal[i][j] = chgPal[i+1][j-1];
                }
            }
        }
    }

}
int f(int start, string &s, vector<vector<int>> &chgPal, vector<vector<int>> &dp, int k){
    int n = s.length();
    //base case
    // if(start>=n-1) return 0;
    if(start==n-1){
        if(k==1){
            return 0;
        } else{
            return INT_MAX/2;
        }
    }
    if(k==1){
        return chgPal[start][n-1];
    }

    int res = INT_MAX/2;
    
    
    if(dp[start][k]!=-1){
        return dp[start][k];
    }
    for(int i=start;i<n-1;i++){
        int temp = chgPal[start][i] + f(i+1,s,chgPal,dp,k-1);
        res = min(res,temp);
    }
    // cout<<"START:"<<start<<" RES:"<<res<<endl;
    dp[start][k] = res;
    return res;
}
int palindromePartition(string s, int k) {
    vector<vector<int>> A;
    calcuate_pallindrome_edit(s,A);
    int n = s.length();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    int res = f(0,s,A,dp,k);
    return res;
}

int main(){
    int k;
    string s;
    cin>>s>>k;
    int ans = palindromePartition(s,k);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}