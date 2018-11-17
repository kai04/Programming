//https://practice.geeksforgeeks.org/problems/coin-change/0
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int m;
        //m no of coins
        cin>>m;
        vector<int> a(m);
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        //make sum n
        int n;
        cin>>n;
        //dp[i][j] denotes no of ways to make sum i with taking coin from 1 to j(j no of coins) 
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //initilize
        //there are no ways to make sum i with 0 no of coins
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        //there is only 1 way to make sum 0 with any no of coins(1 to j) i.e do not take any coins among j coins  
        for(int i=0;i<=m;i++)
            dp[0][i]=1;
        
        /*dp[i][j] is sum of two terms:
         * 1) either include jth coin in solution then our problem reduced to no of ways of forming sum i-a[j-1] with j coins(1 to j) i.e (dp[a[j-1]][j]) 
         *    note indexing starts from 0
         * 2) does not include jth coin in the solution at all i.e forming sum i with only j-1 coins
         */
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i>=a[j-1])
                    dp[i][j]=dp[i-a[j-1]][j]+dp[i][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
        cout<<dp[n][m]<<endl;
    }
	//code
	return 0;
}
