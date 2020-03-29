#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<int>> &dp){
    for(unsigned int i=1;i<dp.size();i++){
        for(unsigned int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int dijikstaUtils(int u,int v,vector<vector<int>> &edges,vector<vector<int>> &dp){
    if(dp[u][v]!=((INT_MAX)/2)){
        return dp[u][v];
    }
    for(unsigned int k=0;k<edges[u].size();k++){
        int w = edges[u][k];
        dp[u][v] = min(dp[u][v],1+dijikstaUtils(w,v,edges,dp));
    }
    return dp[u][v];
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> edges(n+1);
        for(int i=1;i<=n;i++){
            int j = i+1;
            int k = 3*i;
            if(j<=n){
                edges[i].push_back(j);
            }
            if(k<=n){
                edges[i].push_back(k);
            }
        }
        // int n = edges.size();
        // cout<<"EDGES:"<<endl;
        // printMatrix(edges);
        vector<vector<int>> dp(n+2,vector<int>(n+2,(INT_MAX)/2));
        for(int i=0;i<=n;i++){
            dp[i][i] = 0;
        }
        int res = dijikstaUtils(1,n,edges,dp);
        // printMatrix(dp);
        cout<<res<<endl;

    }
    // int x;
    // cin>>x;
	//code
	return 0;
}