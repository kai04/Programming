//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
/* INPUT:
8 14 0
0 1 4
0 7 8
1 7 11
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 8 7
6 8 6
8 2 2
2 5 4
3 5 14
OUTPUT:
Distance of destination vertex:0 from source:0 is equal to 0
Distance of destination vertex:1 from source:0 is equal to 4
Distance of destination vertex:2 from source:0 is equal to 12
Distance of destination vertex:3 from source:0 is equal to 19
Distance of destination vertex:4 from source:0 is equal to 21
Distance of destination vertex:5 from source:0 is equal to 11
Distance of destination vertex:6 from source:0 is equal to 9
Distance of destination vertex:7 from source:0 is equal to 8
Distance of destination vertex:8 from source:0 is equal to 14
*/
#include<bits/stdc++.h>
using namespace std;

void inputGraph(vector<vector<pair<int,int>>> &graph,int v,int e){
	for(int i=0;i<e;i++){
		int p,q,w;
		cin>>p>>q>>w;
		graph[p].push_back(make_pair(q,w));
		graph[q].push_back(make_pair(p,w));
	}
}
class myComparator 
{ 
public: 
    int operator() (const pair<int,int> &p1, const pair<int,int>& p2) 
    { 
        return p1.first > p2.first; 
    } 
};
void singleSourceShortestPath(vector<vector<pair<int,int>>> &graph,int src,int vertices,vector<int> &dist){
	vector<int> visited(vertices+1,-1);
	priority_queue <pair<int,int>, vector<pair<int,int>>, myComparator > dp;
	dp.push(make_pair(0,src));
	dist[src] = 0;
	while(dp.size()!=0){
		pair<int,int> p = dp.top();
		dp.pop();
		int u = p.second;
		visited[u] = 1;
		for(int i=0;i<graph[u].size();i++){
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if(visited[v]==-1 && dist[v]> dist[u]+w){
				dp.push(make_pair(dist[u]+w,v));
				dist[v] = dist[u]+w;
			} 
		}
	}
}
int main(){
	int v,e,src;
	cin>>v>>e>>src;
	vector<vector<pair<int,int>>> graph(v+1);
	inputGraph(graph,v,e);
	vector<int> dist(v+1,INT_MAX);
	singleSourceShortestPath(graph,src,v,dist);
	for(int i=0;i<=v;i++){
		cout<<"Distance of destination vertex:"<<i<<" from source:"<<src<<" is equal to "<<dist[i]<<endl;	
	}
	
	return 0;
}