#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n = s.length();
    vector<int> dp(n+1,-1);
    map<char,int> last;
    for(int i=0;i<n;i++){
        last[s[i]]=-1;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        if(last[s[i-1]]!=-1){
            dp[i]=dp[i]-dp[last[s[i-1]]];
        }
        last[s[i-1]]=i-1;
    }
    cout<<dp[n]<<endl;
	return 0;
}