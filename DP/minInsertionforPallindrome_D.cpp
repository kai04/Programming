//https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
#include <bits/stdc++.h>
using namespace std;

int LCS(string s){
    string s1 = s;
    reverse(s1.begin(),s1.end());
    string s2 = s;
    int n = s1.length();
    int m = s2.length();
    cout<<"s1:"<<s1<<" s2:"<<s2<<endl;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	   // cout<<"LCS:"<<LCS(s)<<endl;
	   int x  =  LCS(s);
       cout<<"x:"<<x<<endl;
	   cout<<s.length()-x<<endl;
	}
	return 0;
}
