#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
     int n;
     cin>>n;
     string s;
     cin>>s;
     vector<bool> expr;
     vector<char> opr;
     for(int i=0;i<n;i++){
         if(s[i]=='T'){
             expr.push_back(true);
         }
         else if(s[i]=='F'){
             expr.push_back(false);
         }
         else if(s[i]=='|' || s[i]=='&' || s[i]=='^'){
             opr.push_back(s[i]);
         }
     }
     //vector<vector<vector<int>>> dp(expr.size(),vector<int>(expr.size(),-1));
      vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(s.size(),vector<int>(2,0)));
        for(int i=0;i<s.size();i+=2)
        {
            if(s[i]=='T')
            dp[i][i][0]++;
            else
                dp[i][i][1]++;
        }
     for(int i=1;i<expr.size();i++)
     {
         for(int j=0;j+(2*i)<s.size();j+=2)
         {
             for(int k=j+1;k<=j+(2*i);k+=2)
             {
                 //cout<<s[k]<<" "<<k<<endl;
                 if(s[k]=='&')
                 {
                     dp[j][j+(2*i)][0]+= (dp[j][k-1][0]*dp[k+1][j+(2*i)][0])%1003;
                     dp[j][j+(2*i)][1]+= (dp[j][k-1][1]*dp[k+1][j+(2*i)][0])%1003;
                     dp[j][j+(2*i)][1]+= (dp[j][k-1][0]*dp[k+1][j+(2*i)][1])%1003;
                     dp[j][j+(2*i)][1]+= (dp[j][k-1][1]*dp[k+1][j+(2*i)][1])%1003;
                 }
                 else if(s[k]=='^')
                 {
                     dp[j][j+(2*i)][0]+= (dp[j][k-1][1]*dp[k+1][j+(2*i)][0])%1003;
                     dp[j][j+(2*i)][0]+= (dp[j][k-1][0]*dp[k+1][j+(2*i)][1])%1003;
                     dp[j][j+(2*i)][1]+= (dp[j][k-1][0]*dp[k+1][j+(2*i)][0])%1003;
                     dp[j][j+(2*i)][1]+= (dp[j][k-1][1]*dp[k+1][j+(2*i)][1])%1003;
                 }
                 else if(s[k]=='|')
                 {
                     dp[j][j+(2*i)][0]+= (dp[j][k-1][0]*dp[k+1][j+(2*i)][0])%1003;
                     dp[j][j+(2*i)][0]+= (dp[j][k-1][1]*dp[k+1][j+(2*i)][0])%1003;
                     dp[j][j+(2*i)][0]+= (dp[j][k-1][0]*dp[k+1][j+(2*i)][1])%1003;
                     dp[j][j+(2*i)][1]+= (dp[j][k-1][1]*dp[k+1][j+(2*i)][1])%1003;
                 }
             }
             //cout<<j<<" "<<j+(2*i)<<" "<<dp[j][j+(2*i)][0]<<endl;
             
         }
     }
        
        cout<<dp[0][n-1][0]%1003<<endl;
    }
	//code
	return 0;
}

