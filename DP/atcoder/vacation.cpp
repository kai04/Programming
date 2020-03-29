//https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a;
    for(int i=0;i<n;i++){
        vector<int> b(3);
        cin>>b[0]>>b[1]>>b[2];
        a.push_back(b);
    }
    vector<vector<int>> dp(n,vector<int>(3,-1));
    for(int j=0;j<3;j++){
        dp[0][j] = a[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k!=j){
                    dp[i][j] = max(dp[i][j],dp[i-1][k]+a[i][j]);       
                }
            }
        }
    }

    int ans=0;
    for(int j=0;j<3;j++){
        ans = max(ans,dp[n-1][j]);
    }
    cout<<ans<<endl;
    return 0;
}
