#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<m;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(i>=0 && j>=0)
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
        cout<<dp[n-1][m-1]<<endl;
    }
	//code
	return 0;
}
