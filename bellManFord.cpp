/*
test case1:
4 4
0 1 1
1 2 -1
2 3 -1
3 0 -1

testcase2:
7 10
0 1 6
0 2 5
0 3 5
2 1 -2
3 2 -2
2 4 1
1 4 -1
3 5 -1
4 6 3
5 3 3
testcase 3:
4 5
0 1 4
0 3 5
1 3 5
3 2 3
2 1 -10
*/

#include <bits/stdc++.h>
# define INF 100000
using namespace std;
typedef struct edge{
    int src;
    int des;
    double wt;
    /*edge(int a,int b,double c){
        src=a;
        des=b;
        wt=c;
    }*/
} edge;

vector<int> printNegativeCycle(vector<int> parent,vector<int> dist){
    vector<bool> visited(dist.size(),false);
    vector<int> res;
    int i;
    //find negative distant vertex 
    for(i=0;i<dist.size();i++){
        if(dist[i]<0){
            break;
        }
    }
    int p=i;
    while(parent[p]!=p && visited[p]==false){
        res.push_back(p);
        visited[p]=true;
        p=parent[p];
        
    }
        
        res.push_back(p);
    
    return res;
}
bool detectNegativeCycle(vector<edge> graph,vector<int> &dist,vector<int> &parent){
    bool flag=false;
    for(int e=0;e<graph.size();e++){
            if(dist[graph[e].des]>(dist[graph[e].src]+graph[e].wt)){
                dist[graph[e].des]=(dist[graph[e].src]+graph[e].wt);
                if(dist[graph[e].des]<0)
                    flag=true;
            }
        }
    return flag;
}
vector<int> bellmanFord(vector<edge> graph,int V,int src,vector<int> &parent){
    vector<int> dist(V,INF);
    //initialize src node to 0 and parent of src is itself
    dist[src]=0;
    parent[src]=src;
    //run for V-1 iterations 
    for(int i=1;i<=V-1;i++){
        for(int e=0;e<graph.size();e++){
            if(dist[graph[e].des]>(dist[graph[e].src]+graph[e].wt)){
                dist[graph[e].des]=(dist[graph[e].src]+graph[e].wt);
                parent[graph[e].des]=graph[e].src;
            }
        }
    }
    return dist;
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<edge> graph(e);
    for(int i=0;i<e;i++){
        int a,b;
        double f;
        cin>>graph[i].src>>graph[i].des>>graph[i].wt;
    }
    vector<int> parent(n);
    
    vector<int> dist=bellmanFord(graph,n,0,parent);
    //copy path distance vector
    vector<int> dist_copy(dist);
    bool flag=detectNegativeCycle(graph,dist_copy,parent);
    if(flag){
        cout<<"Following negative weight cycle exist:"<<endl;
        /*cout<<"printing distance..."<<endl;
        for(auto it:dist_copy)
            cout<<it<<" ";
        cout<<endl;
        cout<<"printing parent..."<<endl;
        for(auto it:parent)
            cout<<it<<" ";
        cout<<endl;*/
        vector<int> cycle=printNegativeCycle(parent,dist_copy);
        for(auto it:cycle)
            cout<<it<<" ";
        cout<<endl;
    }
    else{
        cout<<"No negative weight cycle exist"<<endl;
        cout<<"shortest path to all nodes as follows:"<<endl;
        for(auto it:dist)
            cout<<it<<" ";
        cout<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

