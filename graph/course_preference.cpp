/*static void DFS1(int u,vector<int> &visited,vector<vector<int>> &graph,stack<int> &s){
    int n = visited.size();
    visited[u] = 1;
    for(int i=0;graph[u].size();i++){
        int v  = graph[u][i];
        if(visited[v]!=1){
            DFS1(v,visited,graph,s);
        }
    }
    s.push(u);
}*/
#include<bits/stdc++.h>
using namespace std;
static int time1 = 0;
static bool isCycle = false;
void show(vector<vector<int>> &graph){
	cout<<"Printing...."<<endl;
	int n = graph.size();
	for(int i=1;i<n;i++){
		cout<<i<<"==> ";
		for(int j=0;j<graph[i].size();j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"========================"<<endl;
}
void dfs(int u,vector<int> &visited,vector<int> &disc,vector<vector<int>> &graph){
    int n = visited.size();
    visited[u] = 1;
    // discovery time
    disc[u] = time1;
    time1++;
    // cout<<"h2:"<<u<<endl;
    for(int i=0;graph[u].size();i++){
        int v  = graph[u][i];
        int p = graph[u].size();
        cout<<"SIZE:"<<p<<endl;
         cout<<"h3 u:"<<u<<" v:"<<v<<endl;
        if(v<=n && v!=u && disc[v]<disc[u]){
            //back edge detected
            isCycle = true;
            return;
        }
        if(visited[v]!=1 ){
            dfs(v,visited,disc,graph);
        }
    }
}
int solve(int A, vector<int> &B, vector<int> &C) {
    int n = B.size();
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n;i++){
        graph[B[i]].push_back(C[i]);
    }
    vector<int> visited(n+1,0);
    vector<int> disc(n+1,0);
    isCycle = false;
    show(graph);
    for(int i=1;i<=n;i++){
        if(!visited[i] && !isCycle)
            dfs(i,visited,disc,graph);
        if(isCycle)
            break;
    }
    int ans = 1;
    if(isCycle)
        ans = 0;
    return ans;
       
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int ans = solve(n,a,b);
	cout<<"OUTPUT:"<<ans<<endl;
	return 0;
}
