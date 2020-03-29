/*
5 7     
1 4
1 3
1 2
3 2
4 2
4 5
5 2
5 3
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int bfs(int u,vector<vector<int>> &graph,int n,int dest){
	queue<pair<int,int>> q;
	int ans = INT_MAX;
	q.push(make_pair(u,0));
	vector<int> visited(n+1,-1);
	parent.resize(n+1,-1);
	visited[u] =1;
	while(q.size()!=0){
		pair<int,int> p1  = q.front();
		int u = p1.first;
		int h = p1.second;
		q.pop();
		if(u==dest){
			ans = min(ans,h);
		}
		for(int i=0;i<graph[u].size();i++){
			int v = graph[u][i];
			if(visited[v]==-1){
				visited[v] = 1;
				q.push(make_pair(v,h+1));
				parent[v] = u;
			}	
		}
		
	}
	return ans;
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<vector<int>> graph(v+1);
	for(int i=0;i<e;i++){
		int r,s;
		cin>>r>>s;
		graph[r].push_back(s);
		graph[s].push_back(r);
	}
	int src,dest;
	cin>>src>>dest;
	int ans =bfs(src,graph,v,dest);
	vector<char> destpath;
	int i = dest;
	string ansPath ="";
	
	while(i!=-1){
		char c = i + '0';
		ansPath +=  c;
		 ansPath += " "; 
		i =parent[i];
	}
	reverse(ansPath.begin(),ansPath.end());
	cout<<ansPath<<endl;
	return 0;
}