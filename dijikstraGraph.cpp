#include <bits/stdc++.h>
using namespace std;
class Graphedge{
    int u,v,w;
public:
    Graphedge(int x,int y,int z){
        u=x;
        v=y;
        w=z;
    }
    pair<int,int> getVertices(){
        return make_pair(u,v);
    }
    int getWeight(){
        return w;
    }
};
/*bool myComparator(Graphedge e1,Graphedge e2){
    return (e1.getWeight()>e2.getWeight());
}*/

class myComparator 
{ 
public: 
    int operator() (Graphedge& p1, Graphedge& p2) 
    { 
        return p1.getWeight() > p2.getWeight(); 
    } 
};

void PrintEdges(priority_queue<Graphedge,vector<Graphedge>,myComparator> pq){
    cout<<"Printing Edges......"<<endl;
    while(!pq.empty()){
        Graphedge e1 = pq.top();
        pair<int,int> p = e1.getVertices();
        cout<<"("<<p.first<<","<<p.second<<"), weight:"<<e1.getWeight()<<endl;
        pq.pop();
    }
    /*for(priority_queue<edge,vector<edge>,myComparator> ::iterator it =pq.begin();it!=pq.end();it++){
        pair<int,int> p = it->getVertices();
        cout<<"("<<p.first<<","<<p.second<<") ,weight:"<<it->getWeight()<<endl;
    }*/ 
    cout<<"---------------------------------------------"<<endl;
}

vector<int> disjikstra(int n,int src,int dest,vector<vector<Graphedge>> &edges,priority_queue<Graphedge,vector<Graphedge>,myComparator> &pq){
        vector<int> dist(n+1,INT_MAX/2);
        vector<int> visited(n+1,0);
        dist[src] = 0;
        int curr = src;
        visited[src] = 1;
        while(!pq.empty()){
            Graphedge e1 = pq.top();
            pair<int,int> p = e1.getVertices();
            int weight = e1.getWeight();
            dist[p.second] =  min(dist[p.second],(dist[p.first]+weight));
            pq.pop();
            curr =  p.second;
            if(!visited[curr]){
                for(int i=0;i<edges[curr].size();i++){
                    Graphedge e2 = edges[curr][i];
                    // pair<int,int> p1 = e2.getVertices();
                    // p1.second()
                    pq.push(e2);
                }
            }          
        }

}int main() {
    int v,e;
    cin>>v>>e;
    vector<vector<Graphedge>> edges(v+1);
    // priority_queue<Graphedge,vector<Graphedge>,myComparator> pq;
    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        Graphedge e1(v1,v2,w);
        edges[v1].push_back(e1);
        // pq.push(e1);
        // edges[i] = make_pair(make_pair(v1,v2),w);
    }
    PrintEdges(pq);
     
	return 0;
}