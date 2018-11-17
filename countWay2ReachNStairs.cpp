//https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0
#include <bits/stdc++.h>
#define mod  1000000007
using namespace std;

vector<int> calculate(){
    int n=100000;
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    return dp;
}
int main() {
    int t;
    cin>>t;
    vector<int> ans=calculate();
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
        
    }
	//code
	return 0;
}
