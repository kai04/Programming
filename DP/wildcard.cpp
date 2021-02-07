//https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}
// } Driver Code Ends


/*You are required to complete this method*/
/*bool isMatch(int i, int j ,string &pat,string &str){
    if(i==str.length()||j==pat.length()){
        if(i==str.length()&&j==pat.length())
    }
}*/
int wildCard(string pattern,string str)
{
    int n = str.length();
    int m = pattern.length();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;
    //base case
    
    if(m>0 && pattern[0]=='*'){
        int k=1;
        while(k<m && pattern[k-1]=='*'){
            dp[0][k] = true;
            k++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(pattern[j-1]=='*'){
                dp[i][j] = dp[i][j] || dp[i-1][j-1] || dp[i-1][j]|| dp[i][j-1];
            }
            else if(pattern[j-1]=='?'){
                dp[i][j] = dp[i][j] || dp[i-1][j-1];
            }
            else{
                if(pattern[j-1]==str[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-1];
                }
            }
            // cout<<"i:"<<i<<" j:"<<j<<" str[i]:"<<str[i-1]<<" pat[j-1]:"<<pattern[j-1]<<" dp[i][j]:"<<dp[i][j]<<endl;
        }
    }
    
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    return (int)dp[n][m];
}