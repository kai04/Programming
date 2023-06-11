//https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> ta;
vector<int> td;
void dfs(int u, vector<bool> &visited, vector<vector<int>> &g){
	visited[u] = true;
	t++;
	ta[u] = t;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i];
		if(!visited[v]){
			dfs(v,visited,g);
		}
	}
	t++;
	td[u] = t;
}
int main() {
	int n;
	cin>>n;
	vector<vector<int>> g(n+1);
	for(int i=0;i<n-1;i++){
		int p,q;
		cin>>p>>q;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	ta.resize(n+1);
	td.resize(n+1);
	vector<bool> visited(n+1,false);
	dfs(1,visited,g);
	int q;
	cin>>q;
	while(q--){
		int a,x,y;
		cin>>a>>x>>y;
		if(a==1){
			int r = x;
			x = y;
			y = r;
		}
		if(ta[x]<ta[y] && td[y]<td[x]){
			cout<<"YES"<<endl;
		} else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}