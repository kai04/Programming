//https://atcoder.jp/contests/dp/tasks/dp_o
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

void dfs(int u, int parent, vector<vector<int>> &graph, vector<vector<ll>> &dp){
    //color=0 => white, color=1, => black

    dp[u][0]=1; // no of ways
    dp[u][1]=1;
    for(int v:graph[u]){
        if(v!=parent){
            dfs(v,u,graph,dp);
            dp[u][0] = (dp[u][0] *(dp[v][0] + dp[v][1])%mod)%mod;
            dp[u][1] = (dp[u][1] *(dp[v][0])%mod)%mod ;
        }
    }
}

int main(){
  	int n;
  	cin>>n;
  	vector<vector<int>> graph(n+1, vector<int>());
    vector<vector<ll>> dp(n+1, vector<ll>(2,0));
  	for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
  	}
    dfs(1,-1,graph, dp);
    ll ans = (dp[1][0]+dp[1][1])%mod;
    cout<<ans<<endl;

    return 0;
}
