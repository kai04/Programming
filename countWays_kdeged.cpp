//http://www.geeksforgeeks.org/count-possible-paths-source-destination-exactly-k-edges/
#include <bits/stdc++.h>
using namespace std;
int n,u,v,k;
int countways(int x,int y,int z,vector<vector<int>> &graph,vector<vector<vector<int>>> &dp){
    if(z<0)
        return 0;
    if(z==0){
        if(x==y)
            return 1;
        else{
            return 0;
        }
    }
    if(dp[x][y][z]!=-1)
        return dp[x][y][z];
    int ans=0;
    for(int i=0;i<n;i++){
        if(graph[x][i]==1){
            ans+=countways(i,y,z-1,graph,dp);
        }
    }
    dp[x][y][z]=ans;
    return dp[x][y][z];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<int>> graph(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cin>>graph[i][j];
            }
        }
        cin>>u>>v>>k;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int count1=0;
        count1=countways(u,v,k,graph,dp);
        cout<<count1<<endl;
    }
	//code
	return 0;
}
