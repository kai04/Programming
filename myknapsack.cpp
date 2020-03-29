#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int W,n;
        cin>>W>>n;
        vector<int> wt(n);
        vector<int> val(n);
        for(int i=0;i<n;i++){
            cin>>wt[i]>>val[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(W+1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
               if(j-wt[i-1]>=0){
                   dp[i][j]=max(dp[i-1][j],(val[i-1]+dp[i-1][j-wt[i-1]]));
               }
               else{
                   dp[i][j]=dp[i-1][j];
               }
           } 
        }
       /* for(int i=0;i<=n;i++){
           for(int j=0;j<=W;j++){
               cout<<dp[i][j]<<" ";
           }
            cout<<endl;
        }*/
        cout<<dp[n][W]<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

