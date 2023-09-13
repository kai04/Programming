//https://atcoder.jp/contests/dp/tasks/dp_g
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int u,vector<vector<int>> &edges,
	vector<bool> &visited,vector<int> &in_degree,vector<int> &dist){
	visited[u] = true;
	for(int v:edges[u]){
		dist[v] = max(dist[v],dist[u]+1);
		--in_degree[v];
		//cout<<"u:"<<u<<" v:"<<v<<" indegree[v]:"<<in_degree[v]<<endl;
		if(in_degree[v]==0){
			dfs(v,edges,visited,in_degree,dist);
		}
	}
	
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    vector<bool> visited(n+1,false);
    vector<int> dist(n+1,0);
    vector<int> in_degree(n+1,0);
    
    while(m--){
		int a,b;
		cin>>a>>b;
		edges[a].push_back(b);
		++in_degree[b];
	}
	
	for(int i=1;i<=n;i++){
		if(in_degree[i]==0 && !visited[i])
		dfs(i,edges,visited,in_degree,dist);
	}
	int answer = 0;
	for(int i=1;i<=n;i++){
		answer = max(answer,dist[i]);
	}
	// for(auto it:dist)
	// 	cout<<it<<" ";
	// cout<<endl;
	
	
    cout<<answer<<endl;
    return 0;
}
