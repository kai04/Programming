//http://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag/0
#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX/2)
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        vector<int> c;
        vector<int> wt;
        //c.push_back(0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            c.push_back(x);
            wt.push_back(i+1);
        }
        
        vector<vector<int>> dp(w+1,vector<int>(n+1,(INT_MAX/2)));
        
        /*for(int i=0;i<=w;i++){
            dp[0][i]=INF;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
              if(j>=wt[i-1]){
                  dp[i][j]=min((dp[i-1][j-wt[i-1]]+c[i-1]),(dp[i-1][j]));
              }
              else{
                  dp[i][j]=dp[i-1][j];
              }
            }
        }
        
        cout<<dp[n][w]<<endl;*/
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=w;i++){
            for(int j=0;j<n;j++){
                if(c[j]!=-1 && i-j-1>=0){
                    dp[i][j+1]=min(dp[i][j],dp[i-j-1][j+1]+c[j]);
                    //cout<<i<<" "<<j+1<<" "<<dp[i][j+1]<<endl;
                    
                }
                else{
                    dp[i][j+1]=dp[i][j];
                }
            }
        }
        for(int i=0;i<=w;i++){
            for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
                
            }
            cout<<endl;
        }
            
        if(dp[w][n]==(INT_MAX/2)){
            cout<<-1<<endl;
        }
        else{
            cout<<dp[w][n]<<endl;
        }
    }
	//code
	return 0;
}
