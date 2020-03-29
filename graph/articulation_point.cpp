#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e12L +5;
void get_input_graph(int n,int e,vector<vector<int>> &edges){
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		edges[x].push_back(y);
		//# uncomment if undirected graph
		edges[y].push_back(x); 
	}
}
static int t = 0;
void dfs(int u,vector<bool> &visited,vector<int> &discovery,
	 vector<vector<int>> &edges,vector<int> &low,
	 vector<bool> &cut_vertex,vector<int> &parent){
	visited[u] = true;
	t++;
	discovery[u] = t;
	low[u] = t;
	int children=0;
	for(unsigned int i=0;i<edges[u].size();i++){
		int v = edges[u][i];
		//low(v): it  is the lowest discovery time of
		//any vertex that is either in the dfs subtree
		//rooted at v (including v itself) or connected
        //to a vertex in that subtree by a back edge
		if(!visited[v]){
			children++;
			parent[v] = u;
			dfs(v,visited,discovery,edges,low,cut_vertex,parent);
			low[u] = min(low[u],low[v]);
			//checking for Articulation point
		
			// its AP if its root and more than 1 children
			if(parent[u]==-1 && children>1){
				cut_vertex[u] = true;
			}
			// AP[u] = true if any of children of u say v 
			// and subtree(v) has low[v] >  disc[u]
			if(parent[u]!=-1 && low[v]>=discovery[u]){
				cut_vertex[u] = true;
			}
		}
		else if(parent[v]!=u){
			// u-v is a back edge
			low[u] = min(low[u],discovery[v]);
		}
	}
}


int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> edges(n);
    vector<bool> visited(n,false);
    vector<bool> cut_vertex(n,false);
    vector<int> discovery(n,2*n);
    vector<int> parent(n,-1);
    vector<int> low(n,2*n);
    get_input_graph(n,e,edges);
    for(int i=0;i<n;i++){
		if(!visited[i]){
			if(edges[i].size()<=1){
				cut_vertex[i] = false;
			}
			dfs(i,visited,discovery,edges,low,cut_vertex,parent);
		}
	}
	cout<<"Discovery time are as follows...."<<endl;
	for(int i=0;i<discovery.size();i++){
			cout<<"Discovey time of vertex:"<<i<<" is:"<<discovery[i]<<endl;
	}
	
	cout<<"List of Articulation point are as follows...."<<endl;
	for(int i=0;i<cut_vertex.size();i++){
		if(cut_vertex[i])
			cout<<"Vertex:"<<i<<" is cut vertex"<<endl;
	}
	
    
    return 0;
}
