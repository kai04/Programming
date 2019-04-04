//https://www.geeksforgeeks.org/count-distinct-subsequences/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n = s.length();
    // dp[i] is going to store count of distinct 
    // subsequences of length i.
    vector<int> dp(n+1,-1);
    map<char,int> last;
    for(int i=0;i<n;i++){
        last[s[i]]=-1;
    }

    // Empty substring has only one subsequence
    dp[0]=1;
    // Traverse through all lengths from 1 to n. 
    for(int i=1;i<=n;i++){
        // Number of subsequences with substring 
        dp[i]=2*dp[i-1];
        // If current character has appeared 
        // before, then remove all subsequences 
        // ending with previous occurrence. 
        if(last[s[i-1]]!=-1){
            dp[i]=dp[i]-dp[last[s[i-1]]];
        }
        // Mark occurrence of current character 
        last[s[i-1]]=i-1;
    }
    cout<<dp[n]<<endl;
	return 0;
}